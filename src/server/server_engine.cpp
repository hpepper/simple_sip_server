//

#include "server_engine.h"
#include <unistd.h> // sleep-

ServerEngine::ServerEngine() {
    m_pUdpServer = new UdpServer();  
}

ServerEngine::~ServerEngine() {
    if (m_pUdpServer != nullptr) {
    delete(m_pUdpServer);
    }
}

void ServerEngine::mainServerLoop()
{
    while(1)
    {
        sleep(5);
    }
}