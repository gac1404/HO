#ifndef MQTTMENAGER_H
#define MQTTMENAGER_H

#include <iostream>
#include <mqtt/async_client.h>


class MqqtUserClient
{
public:


    MqqtUserClient();

private:
    mqtt::async_client client;
    mqtt::connect_options connectionOption;

    const std::string URL = "tcp://test.mosquitto.org:1883";

};

#endif // MQTTMENAGER_H
