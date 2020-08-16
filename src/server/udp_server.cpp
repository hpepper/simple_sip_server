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
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_flags = AI_PASSIVE;

    std::string portString = std::to_string(serverPort);
     // TODO read up on this
    // TODO take the port number from the private var.
    getaddrinfo(0, portString.c_str(), &hints, &bindAddress);


    int socket_listen;
    socket_listen = socket(bindAddress->ai_family,
            bindAddress->ai_socktype, bindAddress->ai_protocol);
    if (socket_listen == -1) {
        // TODO is there a perror call?
        // TODO how to handle print in C++
        // fprintf(stderr, "socket() failed. (%d)\n", errno());
        exit(1);
    }

    if (bind(socket_listen,
                bindAddress->ai_addr, bindAddress->ai_addrlen)) {
        // fprintf(stderr, "bind() failed. (%d)\n", errno());
        exit(2);
    }
}

UdpServer::~UdpServer()
{
    freeaddrinfo(bindAddress);

}
