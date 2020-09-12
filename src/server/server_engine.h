#ifndef SERVER_ENGINE
#define SERVER_ENGINE

#include "json_logging.h"
#include "udp_server.h"

/**
 * @brief The ServerEngine class
 *
 * This is the 'game' engine, that will continuously loop;
 *   receiving, handling/processing message and sending out messages
 */
class ServerEngine {
public:
    ServerEngine();
    ~ServerEngine();
    void mainServerLoop();

private:
    UdpServer *m_pUdpServer = nullptr;
    JsonLogging *m_jsonLogging = nullptr;

    // TODO get from ENV
    std::string m_supportedDomainName = "example.com";
};

#endif // SERVER_ENGINE
