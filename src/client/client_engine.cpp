//

#include "client_engine.h"
#include <unistd.h> // sleep-

ClientEngine::ClientEngine() {
    m_pUdpClient = new UdpClient();
    m_jsonLogging = new JsonLogging();
}

ClientEngine::~ClientEngine() {
    if (m_pUdpClient != nullptr) {
        delete(m_pUdpClient);
    }
    if (m_jsonLogging != nullptr) {
        delete(m_jsonLogging);
    }
}

void ClientEngine::mainClientLoop()
{
    m_jsonLogging->logText("INFO", "Client engine started", __FILE__, __LINE__);
    m_pUdpClient->sendMessage();
    while(1)
    {
        sleep(5);
    }
}