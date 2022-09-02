#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <uiconnector.h>
//#include <mqttmenager.h>
#include <boost/asio.hpp>
//#include <MQTTClient.h>
//#include <MQTTAsync.h>
#include <mqtt/async_client.h>

//static int c = 0;
//void connected(void* context, char* cause)
//{
//    std::cout << "connected" << std::endl;
//    c++;
//}

//void onSuccess(void* context, MQTTAsync_successData* response)
//{
//    std::cout << "onSuccess" << std::endl;
//}

//void connlost(void *context, char *cause)
//{
//    printf("\nConnection lost\n");
//    printf("     cause: %s\n", cause);
//}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    mqtt::async_client a();

    UiConnector uiConnector;


    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("uiConnector", &uiConnector);
    const QUrl url(u"qrc:/HO/qml/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);



    return 0;//app.exec();
}
