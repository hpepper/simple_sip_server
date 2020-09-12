//

#include "server_engine.h"
#include <unistd.h> // sleep-

#include "sip_message_register.h"

ServerEngine::ServerEngine()
{
    m_pUdpServer = new UdpServer();
    m_jsonLogging = new JsonLogging();
}

ServerEngine::~ServerEngine()
{
    if (m_pUdpServer != nullptr)
    {
        delete (m_pUdpServer);
    }
    if (m_jsonLogging != nullptr)
    {
        delete (m_jsonLogging);
    }
}

void ServerEngine::mainServerLoop()
{
    m_jsonLogging->logText("INFO", "Server engine started", __FILE__, __LINE__);

    while (1)
    {
        // Get messages from SIP devices (outside in)
        // TODO also get information so that messages can be sent back to the client.
        std::string message = m_pUdpServer->getCompleteMessage();
        // TODO have one function for handling messages from UAC
        // TODO have a function for handling messages from upstream authenticator
        // TODO have a function for handling messages from storage?
        // TODO will there als be connections between the server, e.g. via RabbitMQ?
        if (!message.empty())
        {
            size_t endOfMethodString = message.find(" ");
            std::string sipMethod = message.substr(0, endOfMethodString);
            printf("DDD sip method: %s\n", sipMethod.c_str());
            // TODO create a register class and call the interpreter on this message to extract everything, substring from after the method
            if (sipMethod.compare("REGISTER") == 0)
            {
                SipMessageRegister *sipMessageRegisterPointer = new SipMessageRegister(message.substr(endOfMethodString));
                int nStatus = sipMessageRegisterPointer->DisectMessage();
                /* 10.3 Processing REGISTER Requests
                 * REGISTER requests MUST be processed by a registrar in the order that they are received.
                 * REGISTER requests MUST also be processed atomically, meaning that a particular REGISTER request is either processed completely or not at all.
                 * Each REGISTER message MUST be processed independently of any other registration or binding changes.
                 */
                // TODO 1. The registrar inspects the Request-URI to determine whether it has access to bindings for the domain identified in the Request-URI
                if ( ( nStatus == 0 ) && ( m_supportedDomainName.compare(sipMessageRegisterPointer->GetDomain()) != 0))
                {

                }
                // TODO 2. the registrar MUST process the Require header field values as described for UASs in Section 8.2.2.
                // TODO 3. A registrar SHOULD authenticate the UAC.  Mechanisms for the authentication of SIP user agents are described in Section 22.
                // TODO 4. The registrar SHOULD determine if the authenticated user is authorized to modify registrations for this address-of-record.
                // TODO 5. The registrar extracts the address-of-record from the To header field of the request.  If the address-of-record is not valid for the domain in the Request-URI, the registrar MUST send a 404 (Not Found) response and skip the remaining steps.
                // TODO 5b. The URI MUST then be converted to a canonical form.  To do that, all URI parameters MUST be removed (including the user-param), and any escaped characters MUST be converted to their unescaped form.
                // TODO The result serves as an index into the list of bindings.
                // TODO 6. The registrar checks whether the request contains the Contact header field.  If not, it skips to the last step.
                // TODO 7. The registrar now processes each contact address in the Contact header field in turn. (VERY LONG LIST OF DESCRIPTIONS)
                /*
                 * TODO  8. The registrar returns a 200 (OK) response.
                 *   The response MUST contain Contact header field values enumerating all current bindings.
                 *   Each Contact value MUST feature an "expires" parameter indicating its expiration interval chosen by the registrar.
                 *   The response SHOULD include a Date header field.
                 */
            }
            else
            {
                // TODO '8.2.1 Method Inspection' 405 (Method Not Allowed)
                printf("EEE Missing support for method: '%s'\n", sipMethod.c_str());
            }
        }

        sleep(5);
    }
}