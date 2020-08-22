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
    
        std::string assembledMessage = sipMessage.GetAssembledMessage();
        std::string expectedMessage = "REGISTER sip:example.com SIP/2.0\r\n";
        TS_ASSERT_EQUALS(assembledMessage, expectedMessage);
    }
};