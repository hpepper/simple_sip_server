#include "sip_message_register.h"

/**
 * @brief SipMessageRegister::SipMessageRegister
 *
 */
SipMessageRegister::SipMessageRegister()
{
    m_sipMethod = "REGISTER";
}

SipMessageRegister::SipMessageRegister(std::string message) : SipMessageBase(message)
{
    SipMessageRegister();
}

/**
 * TODO disect the message and store all relevant data in member variables
 */
int SipMessageRegister::DisectMessage()
{
    int nStatus = 0;
    // TODO maybe if status is != 0 set a string to add to the error being reported back to the UAC
    size_t startOfHeader = 0;
    size_t endOfHeader = m_messageRecieved.find("\r\n", startOfHeader);
    std::string headerLine = m_messageRecieved.substr(startOfHeader, endOfHeader - startOfHeader);
    printf("DDD headerLine: '%s'\n", headerLine.c_str());

    size_t startOfNextToken = 0;
    size_t endOfNextToken = headerLine.find(" ", startOfNextToken);
    std::string m_sipMethod = headerLine.substr(startOfNextToken, endOfNextToken - startOfNextToken);

    startOfNextToken = endOfNextToken += 1;
    endOfNextToken = headerLine.find(" ", startOfNextToken);
    std::string requestUri = headerLine.substr(startOfNextToken, endOfNextToken - startOfNextToken);

    size_t endOfField = requestUri.find(":");
    m_scheme = requestUri.substr(0, endOfField);
    m_domain = requestUri.substr(endOfField + 1);

    startOfNextToken = endOfNextToken += 1;
    std::string m_sipVersionString = headerLine.substr(startOfNextToken);
    if (IsSipVersionSupported(m_sipVersionString))
    {
        nStatus = 1;
    }

    // Loop through the rest of the headers, until done or until an error had been detected.
    // The '-4' is for the last '\r\n\r\n
    while ((nStatus == 0) && (endOfHeader < m_messageRecieved.length() - 4))
    {
        startOfHeader = endOfHeader + 2;
        endOfHeader = m_messageRecieved.find("\r\n", startOfHeader);
        std::string headerLine = m_messageRecieved.substr(startOfHeader, endOfHeader - startOfHeader);
        printf("DDD headerLine='%s'\n", headerLine.c_str());
        // TODO support short, I think it can be recognized by '=' in second char.
        size_t endOfField = headerLine.find(":");
        std::string headerName = headerLine.substr(0, endOfField);
        std::string headerValue = headerLine.substr(endOfField + 2);
        printf("DDD headerName='%s'  headerValue='%s'\n", headerName.c_str(), headerValue.c_str());
        // TODO support tolower
        if (headerName.compare("To")==0)
        {
            printf("DDD TO '%s' : '%s'\n", headerName.c_str(), headerValue.c_str());
            // sip:801@example.com
            // TODO also be able to handle "Name" and <xxx>
            size_t endOfField = headerValue.find(":");
            m_scheme = headerValue.substr(0, endOfField);
            std::string userAndDomain = headerValue.substr(endOfField + 1);
            endOfField = userAndDomain.find("@");
            m_userInfo = userAndDomain.substr(0, endOfField);
            std::string toDomain = userAndDomain.substr(endOfField + 1);
            printf("DDD m_scheme='%s' m_userInfo='%s' toDomain='%s'\n",m_scheme.c_str(), m_userInfo.c_str(), toDomain.c_str());
            if ( toDomain.compare(m_domain) !=0 )
            {
                nStatus = 2;
            }
        }
        else if (headerName.compare("From")==0)
        {
            printf("DDD FROM '%s' : '%s'\n", headerName.c_str(), headerValue.c_str());
        }
        else if (headerName.compare("Call-ID")==0)
        {
            printf("DDD '%s' : '%s'\n", headerName.c_str(), headerValue.c_str());
        }
        else if (headerName.compare("CSeq")==0)
        {
            printf("DDD '%s' : '%s'\n", headerName.c_str(), headerValue.c_str());
        }
        else if (headerName.compare("Expires")==0)
        {
            registrationExpirationSeconds = std::stoi(headerValue);
            // TODO fail if above 32bit
            // TODO what if this server has a MinExpires time?
        }
        else
        {
            printf("WWW ignored header: '%s'\n", headerLine.c_str());
        }
        puts("---");
    }

    return (nStatus);
}

SipMessageRegister::~SipMessageRegister()
{
}

std::string SipMessageRegister::GetAssembledMessage()
{
    std::string returnString = SipMessageBase::GetAssembledMessage();
    // TODO this may need a port number as well; see: 19.1.1 SIP and SIPS URI Components
    // TODO wiresgark doesn't recognice this: returnString += "Request-URI: " + GetScheme() + ":" + GetDomain() + CRLF;
    std::string toField = GetScheme() + ":" + GetUserInfo() + "@" + GetDomain();
    // TODO can you register multiple 'to' in the same register?
    returnString += "To: " + toField + CRLF;
    returnString += "From: " + toField + CRLF;
    /*
     * TODO flesh this out: 8.1.1.4 Call-ID
     * Using cryptographically random identifiers provides some
     * protection against session hijacking and reduces the likelihood of
     * unintentional Call-ID collisions.
     * 
     * Maybe use the random part as a sort of salt and then add the userinfo thus hopefully getting even closer to a unique ID.
     */
    std::string tempRandomCallId = "f81d4fae-7dec-11d0-a765-00a0c91e6bf6@";
    returnString += "Call-ID: " + tempRandomCallId + GetDomain() + CRLF;

    returnString += "CSeq: " + std::to_string(GetCommandSequenceNumber()) + " " + GetMethod() + CRLF;

    /* 
     * 8.1.1.8 Contact
     * Who should decide what to write in here?
     * 
     * TODO 20.19 Expires
     */
    //messageForCalculateSize += "Contact: " +  + CRLF;
    returnString += "Expires: " + std::to_string(GetRegistrationExpirationSeconds()) + CRLF;

    // TODO calculate length of messageForCalculateSize
    returnString += "Content-Length: 0" + CRLF;

    // If no body is present in a message, then the Content-Length header field value MUST be set to zero.
    returnString += CRLF;
    //printf("DDD GetAssembledMessage: '%s'", returnString.c_str());
    return (returnString);
}