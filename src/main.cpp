#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlEngine>

#include <MQTTAsync.h>
#include <mqtt/async_client.h>

#include <mqqtUserClient.h>
//
#include <uiconnector.h>
#include <windows.h>
#include <string>
#include <thread>


int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);


    mqtt::async_client client("tcp://test.mosquitto.org:1883", "testApAG", "./");
//    auto connOpts = mqtt::connect_options_builder()
//        .clean_session()
//        .finalize();

//    client.set_connection_lost_handler([](const std::string& str) {
//        std::cout << "*** Connection Lost  ***" << str << std::endl;
//    });

//    client.set_connected_handler([](const std::string& cause){
//        std::cout << "*** set_connected_handler  ***" << cause << std::endl;
//    });

//    auto conntok = client.connect(connOpts);

//    conntok->wait();
//    //auto ret = conntok->get_connect_response();

//    std::cout << "connected???" << std::endl;

//    std::thread t1([&](){
//        uiConnector.Dupa();
//    });

//    t1.detach();

    UiConnector uiConnector;
    MqqtUserClient mqqtUserClient;


    //qmlRegisterType<UiConnector>("UserConnector", 1,0 , "UiConnector");
   // qmlRegisterType<ConnectionStateControlUi>("UserConnector", 1,0 , "ConnectionStateControlUi");

    std::thread t1([&](){
        mqqtUserClient.run();
    });

    t1.detach();


    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("uiConnector", &uiConnector);
    engine.rootContext()->setContextProperty("mqqtUserClient", &mqqtUserClient);
    const QUrl url(u"qrc:/HO/qml/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);


    return app.exec();
}
