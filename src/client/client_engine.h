#ifndef CLIENT_ENGINE
#define CLIENT_ENGINE

#include "json_logging.h"
#include "udp_client.h"

/**
 * @brief The ClientEngine class
 *
 * This is the 'game' engine, that will continuously loop;
 *   receiving, handling/processing message and sending out messages
 */
class ClientEngine {
public:
    ClientEngine();
    ~ClientEngine();
    void mainClientLoop();

private:
    UdpClient *m_pUdpClient = nullptr;
    JsonLogging *m_jsonLogging = nullptr;
};

#endif // CLIENT_ENGINE
