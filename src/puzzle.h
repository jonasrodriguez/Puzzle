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
  Q_PROPERTY(int numberOfPieces MEMBER numberOfPieces_ NOTIFY puzzleChanged)

 public:
  static Puzzle *instance();
  static QObject *qmlInstance(QQmlEngine *engine, QJSEngine *scriptEngine);

 signals:
  void puzzleChanged();

 public slots:
  void loadNewImage(QString file_name);

 private:
  int numberOfPieces_;
  float imageHeight_;
  float imageWidth_;
  std::vector<puz::piece> pieces_;
  std::unique_ptr<image_manager> image_;

  static Puzzle *this_;
  explicit Puzzle(QObject *parent = nullptr);
};

#endif  // PUZZLE_H
