#ifndef PUZZLE_H
#define PUZZLE_H

#include <QObject>

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

 private:
  int numberOfPieces_;
  float imageHeight_;
  float imageWidth_;
  std::vector<puz::piece> pieces_;

  static Puzzle *this_;
  explicit Puzzle(QObject *parent = nullptr);
};

#endif  // PUZZLE_H
