#ifndef UDP_SERVER
#define UDP_SERVER

#include "json_logging.h"

// https://cs.baylor.edu/~donahoo/practical/CSockets/practical/

// Section: 18.1.1 Sending Requests
#define SERVER_PORT_INSECURE 5060
#define SERVER_PORT_TLS_5061

/**
 * @brief The UdpServer class
 *
 * Create and UDP server.
 */
class UdpServer {
public:
    UdpServer();
    ~UdpServer();

    // TODO return SDP ?
    void getCompleteMessage();

private:
    JsonLogging *m_jsonLogging = nullptr;


    int serverPort = SERVER_PORT_INSECURE;
    struct addrinfo *bindAddress;
    int m_socketListen = 0;


};

#endif // UDP_SERVER
