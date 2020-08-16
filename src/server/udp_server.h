#ifndef UDP_SERVER
#define UDP_SERVER

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

private:

    int serverPort = SERVER_PORT_INSECURE;
    struct addrinfo *bindAddress;


};

#endif // UDP_SERVER
