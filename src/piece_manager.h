#ifndef PIECE_MANAGER_H
#define PIECE_MANAGER_H

#include <QImage>
#include <QObject>

#include "types.h"

class PieceManager : public QObject {
  Q_PROPERTY(int pieceWidth MEMBER pieceWidth_ NOTIFY nameChanged)
  Q_PROPERTY(int pieceHeight MEMBER pieceHeight_ NOTIFY nameChanged)
 public:
  PieceManager(QObject *parent = nullptr);
  void LoadPieceValues(const int &piece_height, const int &piece_width_);

 private:
  int piece_width_;
  int piece_height;
  QVector<puz::piece> pieces_;
};

#endif  // PIECE_MANAGER_H
