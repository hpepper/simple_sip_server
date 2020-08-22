#ifndef SIP_MESSAGE_BASE
#define SIP_MESSAGE_BASE

#include "json_logging.h"




// Section: ?

/**
 * @brief The SipMessageBase class
 *
 * TODO Do not allow 'SIP/SIPS' in 'To:' etc, since the connection type will be controlled by the lower layer, not the user.
 */
class SipMessageBase {
public:
    SipMessageBase();
    ~SipMessageBase();

    std::string GetAssembledMessage();
    std::string GetMethod();

    // use 'SIPS:'
    void UseSecureComTagInMessage();
    // use 'SIP:'
    void UseUnsecureComTagInMessage();

    void SetDomain(std::string);
    void SetUserInfo(std::string);


protected:
    JsonLogging *m_jsonLogging = nullptr;

    std::string m_sipVersionString = "SIP/2.0";
    std::string m_sipMethod = ""; // This will be loaded by the class that instantiate this class

    // See RFC2396 3. URI Syntactic Components
    std::string m_scheme = "sip";

    std::string m_domain = "";
    std::string m_userInfo = "";

    std::string SP = " ";
    std::string CRLF = "\r\n";

};

#endif // SIP_MESSAGE_BASE