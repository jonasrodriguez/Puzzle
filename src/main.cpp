#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "image_manager.h"
#include "puzzle.h"

int main(int argc, char *argv[]) {
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;
  const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
  qmlRegisterSingletonType<Puzzle>("com.jonas.puzzle", 1, 0, "Puzzle",
                                   &Puzzle::qmlInstance);
  engine.addImageProvider("imageProvider",
                          Puzzle::instance()->getImageProvider());

  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreated, &app,
      [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl) QCoreApplication::exit(-1);
      },
      Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}
