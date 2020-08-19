//

#include "server_engine.h"
#include <unistd.h> // sleep-

ServerEngine::ServerEngine()
{
    m_pUdpServer = new UdpServer();
    m_jsonLogging = new JsonLogging();
}

ServerEngine::~ServerEngine()
{
    if (m_pUdpServer != nullptr)
    {
        delete (m_pUdpServer);
    }
    if (m_jsonLogging != nullptr)
    {
        delete (m_jsonLogging);
    }
}

void ServerEngine::mainServerLoop()
{
    m_jsonLogging->logText("INFO", "Server engine started", __FILE__, __LINE__);

    while (1)
    {
        m_pUdpServer->getCompleteMessage();
        sleep(5);
    }
}