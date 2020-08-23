//

#include "client_engine.h"
#include <unistd.h> // sleep-

ClientEngine::ClientEngine() {
    m_pUdpClient = new UdpClient();
    m_jsonLogging = new JsonLogging();
    m_pSipMessageRegister = new SipMessageRegister();
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
    m_pSipMessageRegister->SetDomain("example.com");
    m_pSipMessageRegister->SetUserInfo("801");
    m_pUdpClient->sendMessage(m_pSipMessageRegister->GetAssembledMessage());
    while(1)
    {
        sleep(5);
    }
}