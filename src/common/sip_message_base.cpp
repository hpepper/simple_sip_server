#include "sip_message_base.h"


/**
 * @brief SipMessageBase::SipMessageBase
 *
 */
SipMessageBase::SipMessageBase()
{
}

SipMessageBase::SipMessageBase(std::string message)
{
    m_messageRecieved = message;
}

SipMessageBase::~SipMessageBase()
{
}

/**
 * 7.1 Requests
 *    Request-Line  =  Method SP Request-URI SP SIP-Version CRLF
 * 
 */
std::string SipMessageBase::GetAssembledMessage()
{
    std::string returnString = m_sipMethod + SP + m_scheme + ":" + m_domain + SP + m_sipVersionString + CRLF;
    //printf("DDD GetAssembledMessage: '%s'", returnString.c_str());
    return(returnString);
}

int SipMessageBase::GetCommandSequenceNumber()
{
    return(commandSequenceNumber);
}

std::string SipMessageBase::GetMethod()
{
    return(m_sipMethod);
}

std::string SipMessageBase::GetDomain()
{
    return(m_domain);
}

bool SipMessageBase::IsSipVersionSupported(std::string versionString)
{
    bool supported = false;
    if ( versionString.compare("SIP/2.0"))
    {
        supported = true;
    }
    return(supported);
}

void SipMessageBase::SetDomain(std::string domain)
{
    // TODO V validate the string see rfc3261
    m_domain = domain;
}

UNSIGNED_INTEGER_64_BIT SipMessageBase::GetRegistrationExpirationSeconds()
{
    return(registrationExpirationSeconds);
}


std::string SipMessageBase::GetScheme()
{
    return(m_scheme);
}

std::string SipMessageBase::GetUserInfo()
{
    return(m_userInfo);
}
void SipMessageBase::SetUserInfo(std::string userinfo)
{
    // TODO V validate the string see rfc3261
    m_userInfo = userinfo;
}


void SipMessageBase::UseSecureComTagInMessage()
{
    m_scheme = "sips";
}

void SipMessageBase::UseUnsecureComTagInMessage()
{
    m_scheme = "sip";
}

