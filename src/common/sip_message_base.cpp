#include "sip_message_base.h"


/**
 * @brief SipMessageBase::SipMessageBase
 *
 */
SipMessageBase::SipMessageBase()
{
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

std::string SipMessageBase::GetMethod()
{
    return(m_sipMethod);
}

void SipMessageBase::SetDomain(std::string domain)
{
    // TODO V validate the string see rfc3261
    m_domain = domain;
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

