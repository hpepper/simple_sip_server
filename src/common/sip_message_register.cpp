#include "sip_message_register.h"


/**
 * @brief SipMessageRegister::SipMessageRegister
 *
 */
SipMessageRegister::SipMessageRegister()
{
    m_sipMethod = "REGISTER";
}

SipMessageRegister::~SipMessageRegister()
{
}

std::string SipMessageRegister::GetAssembledMessage()
{
    std::string returnString = SipMessageBase::GetAssembledMessage();
    // TODO this may need a port number as well; see: 19.1.1 SIP and SIPS URI Components
    returnString += "Request-URI: " + GetDomain() + CRLF;
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
    return(returnString);
}