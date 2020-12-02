#ifndef PIECE_MANAGER_H
#define PIECE_MANAGER_H

#include <QImage>
#include <QObject>

#include "types.h"

class PieceManager : public QObject {
  Q_OBJECT
  Q_PROPERTY(int totalPieces MEMBER total_pieces_ NOTIFY piecesChanged)
  Q_PROPERTY(int numColumns MEMBER num_columns_ NOTIFY piecesChanged)
  Q_PROPERTY(int numRows MEMBER num_rows_ NOTIFY piecesChanged)
  Q_PROPERTY(float pieceWidth MEMBER piece_width_ NOTIFY piecesChanged)
  Q_PROPERTY(float pieceHeight MEMBER piece_height_ NOTIFY piecesChanged)
  Q_PROPERTY(int imageWidth MEMBER image_width_ NOTIFY piecesChanged)
  Q_PROPERTY(int imageHeight MEMBER image_height_ NOTIFY piecesChanged)

 public:
  PieceManager(QObject *parent = nullptr);
  void LoadPieceValues(const int &total_pieces);

 signals:
  void piecesChanged();

 private:
  void CalculatePieceSize(const QString &image_path);
  void FillPieceVector();
  void FindNeighbours(const int &index, puz::piece &piece);

 private:
  int total_pieces_;
  int num_columns_;
  int num_rows_;
  float piece_width_;
  float piece_height_;
  int image_width_;
  int image_height_;
  QVector<QVector<puz::piece>> pieces_matrix_;
};

#endif  // PIECE_MANAGER_H
