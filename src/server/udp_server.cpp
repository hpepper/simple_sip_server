#include "udp_server.h"

#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
// http://www.cplusplus.com/reference/string/string/
#include <string>
#include <string.h> // memset
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>


/**
 * @brief UdpServer::UdpServer
 *
 * 
 * Only use 'connect()' for the client, see p106
 */
UdpServer::UdpServer()
{
    m_jsonLogging = new JsonLogging();

    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_flags = AI_PASSIVE;

    std::string portString = std::to_string(serverPort);

    m_jsonLogging->logText("INFO", "Server init port " + portString, __FILE__, __LINE__);
     // TODO read up on this
    // TODO take the port number from the private var.
    getaddrinfo(0, portString.c_str(), &hints, &bindAddress);


    
    m_socketListen = socket(bindAddress->ai_family,
            bindAddress->ai_socktype, bindAddress->ai_protocol);
    if (m_socketListen == -1) {
        m_jsonLogging->logText("CRITICAL", "socket() failed with error: " + m_jsonLogging->convertErrnoToErrString(errno), __FILE__, __LINE__);
        exit(1);
    }

    if (bind(m_socketListen,
                bindAddress->ai_addr, bindAddress->ai_addrlen)) {
        // TODO include ai_addr
        m_jsonLogging->logText("CRITICAL", "bind() failed with error: " + m_jsonLogging->convertErrnoToErrString(errno), __FILE__, __LINE__);
        exit(2);
    }
}

UdpServer::~UdpServer()
{
    freeaddrinfo(bindAddress);

    if (m_jsonLogging != nullptr) {
        delete(m_jsonLogging);
    }
}


void UdpServer::getCompleteMessage()
{
     m_jsonLogging->logText("INFO", "Server engine started", __FILE__, __LINE__);

    // get message from udp q, if available
    // Check using the SIP rules
    struct sockaddr_storage client_address;
    socklen_t client_len = sizeof(client_address);
    char read[1024];
    int bytes_received = recvfrom(m_socketListen,
                                  read, 1024,
                                  0,
                                  (struct sockaddr *)&client_address, &client_len);
    printf("DDD Message received: '%s'\n", read);
}
