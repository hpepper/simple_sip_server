#ifndef UDP_CLIENT
#define UDP_CLIENT

#include "json_logging.h"
#include <string>

// https://cs.baylor.edu/~donahoo/practical/CSockets/practical/

// Section: 18.1.1 Sending Requests
#define SERVERPORT_INSECURE 5060
#define SERVERPORT_TLS_5061

/**
 * @brief The UdpClient class
 *
 * Create and UDP Client.
 */
class UdpClient {
public:
    UdpClient();
    ~UdpClient();

    // TODO return SDP ?
    void sendMessage(std::string);

private:
    JsonLogging *m_jsonLogging = nullptr;


    int ClientPort = SERVERPORT_INSECURE;
    struct addrinfo *m_peerAddress;
    int m_socketListen = 0;


};

#endif // UDP_CLIENT
