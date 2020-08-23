#include <cxxtest/TestSuite.h>
#include "../common/sip_message_register.h"

class UtSipMessageRegister: public CxxTest::TestSuite
{
public:
    void test_GetAssembledMessage()
    {
        SipMessageRegister sipMessage;
        TS_ASSERT_EQUALS(sipMessage.GetMethod().c_str(), "REGISTER");

        sipMessage.SetDomain("example.com");
        sipMessage.SetUserInfo("801");
    
        std::string assembledMessage = sipMessage.GetAssembledMessage();
        std::string expectedMessage = "REGISTER sip:example.com SIP/2.0\r\nRequest-URI: example.com\r\nTo: sip:801@example.com\r\nFrom: sip:801@example.com\r\nCall-ID: f81d4fae-7dec-11d0-a765-00a0c91e6bf6@example.com\r\nCSeq: 0 REGISTER\r\nExpires: 3600\r\nContent-Length: 0\r\n\r\n";
        TS_ASSERT_EQUALS(assembledMessage, expectedMessage);
    }
};