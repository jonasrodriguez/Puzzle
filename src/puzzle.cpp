#include "puzzle.h"

#include <QJSEngine>
#include <QQmlEngine>

Puzzle *Puzzle::this_ = nullptr;

Puzzle::Puzzle(QObject *parent) : QObject(parent), loading_puzzle_(false) {
  image_manager_ = std::unique_ptr<ImageManager>(new ImageManager());
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

ImageManager *Puzzle::getImageProvider() { return image_manager_.get(); }

int Puzzle::getPiecesXRow() { return puz::puzzle3000RowPieces; }
int Puzzle::getPiecesXColumn() { return puz::puzzle3000ColumnPieces; }

QImage Puzzle::requestImage(const int &id) {
  return image_manager_->GetImageFromVector(id);
}

void Puzzle::loadNewImage(QString file_name) {
  int piece_height = 0;
  int piece_width = 0;
  if (!image_manager_->LoadImage(file_name, puz::puzzle3000Pieces, piece_height,
                                 piece_width)) {
    qDebug() << "Error loading the image";
    return;
  }

  loading_puzzle_ = true;
  emit puzzleChanged();
}
