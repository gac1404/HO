#ifndef MQTTMENAGER_H
#define MQTTMENAGER_H

#include <QObject>
#include <iostream>
//#include <mqtt/async_client.h>

class MqqtUserClient: public QObject {
    Q_OBJECT
    Q_PROPERTY(bool isConnected READ isConnected WRITE setIsConnected NOTIFY isConnectedChanged)
public:

  MqqtUserClient()
  {
    std::cout << "MqqtUserClient" << std::endl;
  }

  void run();

  bool isConnected() const;
  void setIsConnected(bool);
signals:
  void isConnectedChanged(bool isConnected);

  //    mqtt::async_client client;
  //    mqtt::connect_options connectionOption;

  //    const std::string URL = "tcp://test.mosquitto.org:1883";

private:
  bool m_isConnected{ false };

};

#endif // MQTTMENAGER_H
