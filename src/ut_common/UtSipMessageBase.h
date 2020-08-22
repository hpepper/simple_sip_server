#include <cxxtest/TestSuite.h>
#include "../common/sip_message_base.h"

class UtSipMessageBase: public CxxTest::TestSuite
{
public:
    void test_GetAssembledMessage()
    {
        SipMessageBase sipMessage;
        std::string assembledMessage = sipMessage.GetAssembledMessage();
        std::string expectedMessage = " sip: SIP/2.0\r\n";
        TS_ASSERT_EQUALS(assembledMessage, expectedMessage);
    }
};