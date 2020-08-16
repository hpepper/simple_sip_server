#ifndef SERVER_ENGINE
#define SERVER_ENGINE

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

};

#endif // SERVER_ENGINE
