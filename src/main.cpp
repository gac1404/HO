#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlEngine>
#include <uiconnector.h>
#include <mqtt/async_client.h>

#include <windows.h>
#include <string>
#include <thread>

void foo()
{

}


int main(int argc, char *argv[])
{
    UiConnector uiConnector;

    QGuiApplication app(argc, argv);

    //qmlRegisterType<UiConnector>("Adam" ,1 ,0 ," UiConnector"); //not working

    mqtt::async_client client("tcp://test.mosquitto.org:1883", "testApAG", "./");
    auto connOpts = mqtt::connect_options_builder()
        .clean_session()
        .finalize();

    client.set_connection_lost_handler([](const std::string& str) {
        std::cout << "*** Connection Lost  ***" << str << std::endl;
    });

    client.set_connected_handler([](const std::string& cause){
        std::cout << "*** set_connected_handler  ***" << cause << std::endl;
    });

    auto conntok = client.connect(connOpts);

    conntok->wait();
    //auto ret = conntok->get_connect_response();

    std::cout << "connected???" << std::endl;

    std::thread t1([&](){
        uiConnector.Dupa();
    });

    t1.detach();


    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("uiConnector", &uiConnector);
    const QUrl url(u"qrc:/HO/qml/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
//    engine.rootContext()->setContextProperty("uiConnector", &uiConnector);

    return app.exec();
}
