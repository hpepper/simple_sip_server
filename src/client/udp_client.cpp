#include "udp_client.h"

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
 * @brief UdpClient::UdpClient
 *
 * TODO enable providing port number and target address, possibly also 
 * Only use 'connect()' for the client, see p106
 */
UdpClient::UdpClient()
{
    m_jsonLogging = new JsonLogging();

    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_flags = AI_PASSIVE;

    std::string portString = std::to_string(ClientPort);

    m_jsonLogging->logText("INFO", "Client init port " + portString, __FILE__, __LINE__);
    // TODO read up on this
    // TODO take the port number from the private var.
    getaddrinfo("127.0.0.1", portString.c_str(), &hints, &m_peerAddress);

    printf("Remote address is: ");
    char address_buffer[100];
    char service_buffer[100];
    getnameinfo(m_peerAddress->ai_addr, m_peerAddress->ai_addrlen,
                address_buffer, sizeof(address_buffer),
                service_buffer, sizeof(service_buffer),
                NI_NUMERICHOST | NI_NUMERICSERV);
    printf("%s %s\n", address_buffer, service_buffer);

    m_socketListen = socket(m_peerAddress->ai_family,
                            m_peerAddress->ai_socktype, m_peerAddress->ai_protocol);
    if (m_socketListen == -1)
    {
        m_jsonLogging->logText("CRITICAL", "socket() failed with error: " + m_jsonLogging->convertErrnoToErrString(errno), __FILE__, __LINE__);
        exit(1);
    }
}

UdpClient::~UdpClient()
{
    freeaddrinfo(m_peerAddress);

    if (m_jsonLogging != nullptr)
    {
        delete (m_jsonLogging);
    }
}

void UdpClient::sendMessage(std::string message)
{
    printf("Sending: %s\n", message.c_str());
    int bytes_sent = sendto(m_socketListen,
                            message.c_str(), message.size(),
                            0,
                            m_peerAddress->ai_addr, m_peerAddress->ai_addrlen);
    printf("Sent %d bytes.\n", bytes_sent);
}
