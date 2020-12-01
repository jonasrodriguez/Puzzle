#ifndef PUZZLE_H
#define PUZZLE_H

#include <QObject>
#include <memory>

#include "image_manager.h"
#include "types.h"

class QQmlEngine;
class QJSEngine;

class Puzzle : public QObject {
  Q_OBJECT
  Q_PROPERTY(bool loadingPuzzle MEMBER loading_puzzle_ NOTIFY puzzleChanged)
  Q_PROPERTY(int piecesRow READ getPiecesXRow NOTIFY puzzleChanged)
  Q_PROPERTY(int piecesColumn READ getPiecesXColumn NOTIFY puzzleChanged)

 public:
  static Puzzle *instance();
  static QObject *qmlInstance(QQmlEngine *engine, QJSEngine *scriptEngine);

  ImageManager *getImageProvider();

  Q_INVOKABLE QImage requestImage(const int &id);

  int getPiecesXRow();
  int getPiecesXColumn();
  int getPieceSize();

 signals:
  void puzzleChanged();

 public slots:
  void loadNewImage(QString file_name);

 private:
  bool loading_puzzle_;
  int numberOfPieces_;
  std::unique_ptr<ImageManager> image_manager_;

 private:
  static Puzzle *this_;
  explicit Puzzle(QObject *parent = nullptr);
};

#endif  // PUZZLE_H
