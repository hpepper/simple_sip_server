#ifndef SIP_MESSAGE_REGISTER
#define SIP_MESSAGE_REGISTER

#include "sip_message_base.h"

// Section: ?

/**
 * @brief The SipMessageBase class
 *
 * 
 */
class SipMessageRegister : public SipMessageBase {
public:
    SipMessageRegister();
    ~SipMessageRegister();

    // TODO create a get message function that adds to the base with the rest of the 10.2 Constructing the REGISTER Request
    // TODO 7.3 Header Fields

protected:
    JsonLogging *m_jsonLogging = nullptr;
};

#endif // SIP_MESSAGE_REGISTER