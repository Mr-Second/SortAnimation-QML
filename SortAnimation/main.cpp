#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "BubbleSort.hpp"
#include "RandomGenerator.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    auto data = rg->getData(10);
    auto cmp = [](int i, int j) ->bool {return i < j;};
    ISort *sortTool = new BubbleSort(data, cmp);
    sortTool->sort();

    return app.exec();
}
