#include "mqqtUserClient.h"

MqqtUserClient::MqqtUserClient(): client(URL, "testApAG", "./")
{
    auto connectionOption = mqtt::connect_options_builder()
        .clean_session()
        .finalize();

    client.set_connection_lost_handler([](const std::string& str) {
        std::cout << "*** Connection Lost  ***" << str << std::endl;
    });

    client.set_connected_handler([](const std::string& cause){
        std::cout << "*** set_connected_handler  ***" << cause << std::endl;
    });

//    auto conntok = client.connect(connectionOption);

//    conntok->wait();


    std::cout << "connected???" << std::endl;

}
