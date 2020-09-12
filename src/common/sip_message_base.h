#ifndef SIP_MESSAGE_BASE
#define SIP_MESSAGE_BASE

#include "json_logging.h"

#include <string>

#define UNSIGNED_INTEGER_64_BIT unsigned long long int


// Section: ?

/**
 * @brief The SipMessageBase class
 *
 * TODO Do not allow 'SIP/SIPS' in 'To:' etc, since the connection type will be controlled by the lower layer, not the user.
 */
class SipMessageBase {
public:
    SipMessageBase();
    SipMessageBase(std::string);
    ~SipMessageBase();

    int DisectMessage();
    std::string GetAssembledMessage();
    int GetCommandSequenceNumber();
    std::string GetMethod();
    UNSIGNED_INTEGER_64_BIT GetRegistrationExpirationSeconds();
    std::string GetScheme();

    bool IsSipVersionSupported(std::string);

    // use 'SIPS:'
    void UseSecureComTagInMessage();
    // use 'SIP:'
    void UseUnsecureComTagInMessage();

    std::string GetDomain();
    void SetDomain(std::string);
    std::string GetUserInfo();
    void SetUserInfo(std::string);


protected:
    JsonLogging *m_jsonLogging = nullptr;

    std::string m_sipVersionString = "SIP/2.0";
    std::string m_sipMethod = ""; // This will be loaded by the class that instantiate this class

    // See RFC2396 3. URI Syntactic Components
    std::string m_scheme = "sip";

    // TODO maybe these should be stored in asingleton class for all to access?
    std::string m_domain = "";
    std::string m_userInfo = "";

    std::string SP = " ";
    std::string CRLF = "\r\n";

    // TODO enableIncrementing the number
    UNSIGNED_INTEGER_64_BIT commandSequenceNumber = 0;

    // 20.19 Expires - gives the relative time after which the message (or content) expires.
    UNSIGNED_INTEGER_64_BIT registrationExpirationSeconds = 3600;

    std::string m_messageRecieved = "";

};

#endif // SIP_MESSAGE_BASE