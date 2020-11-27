#include "puzzle.h"

#include <QJSEngine>
#include <QQmlEngine>

Puzzle *Puzzle::this_ = nullptr;

Puzzle::Puzzle(QObject *parent) : QObject(parent) {
  image_ = std::unique_ptr<ImageManager>(new ImageManager());
}

Puzzle *Puzzle::instance() {
  if (this_ == nullptr)  // avoid creation of new instances
    this_ = new Puzzle;
  return this_;
}

QObject *Puzzle::qmlInstance(QQmlEngine *engine, QJSEngine *scriptEngine) {
  Q_UNUSED(engine);
  Q_UNUSED(scriptEngine);
  // C++ and QML instance are the same instance
  return Puzzle::instance();
}

void Puzzle::loadNewImage(QString file_name) { image_->LoadImage(file_name); }
