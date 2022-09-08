#include "mqqtUserClient.h"
#include <windows.h>

void MqqtUserClient::run() {
  while (true) {
    Sleep(3000);
    setIsConnected(true);
    Sleep(3000);
    setIsConnected(false);
  }
}

bool MqqtUserClient::isConnected() const { return m_isConnected; }

void MqqtUserClient::setIsConnected(bool isConnected) {
  if (m_isConnected != isConnected) {
    m_isConnected = isConnected;
    emit isConnectedChanged(m_isConnected);
  }
}
