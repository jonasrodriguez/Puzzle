#include "piece_manager.h"

#include "types.h"

PieceManager::PieceManager(QObject *parent)
    : QObject(parent), total_pieces_(0), image_width_(0), image_height_(0) {}

void PieceManager::LoadPieceValues(const int &total_pieces) {
  total_pieces_ = total_pieces;

  CalculatePieceSize(":/images/japanPuzzle");
  FillPieceVector();

  emit piecesChanged();
}

void PieceManager::FillPieceVector() {
  for (int index = 0; index < total_pieces_; index++) {
    puz::piece piece;

    piece.id = index;
    piece.rotation = puz::a0;
    piece.id_cluster = -1;
    FindNeighbours(index, piece);
  }
}

void PieceManager::FindNeighbours(const int &index, puz::piece &piece) {
  if (index % 10 == 0 || index == 0) {
    piece.id_left = -1;
  } else {
    piece.id_left = index - 1;
  }

  if (index < num_rows_) {
    piece.id_top = -1;
  } else {
    piece.id_top = index - num_rows_;
  }

  if (index % num_rows_ == 0 || index == total_pieces_ - 1) {
    piece.id_right = -1;
  } else {
    piece.id_right = index + 1;
  }

  if (index > total_pieces_ - num_rows_) {
    piece.id_bottom = -1;
  } else {
    piece.id_bottom = index + num_rows_;
  }
}

void PieceManager::CalculatePieceSize(const QString &image_path) {
  QImage puzzle(image_path);

  image_width_ = puzzle.width();
  image_height_ = puzzle.height();

  switch (total_pieces_) {
    case puz::puzzle1000Pieces:
      num_rows_ = puz::puzzle1000RowPieces;
      num_columns_ = puz::puzzle1000ColumnPieces;
      break;
    case puz::puzzle3000Pieces:
      num_rows_ = puz::puzzle3000RowPieces;
      num_columns_ = puz::puzzle3000ColumnPieces;
      break;
    case puz::testPuzzle:  // Test only
      num_rows_ = puz::testRowPieces;
      num_columns_ = puz::testColumnPieces;
      break;
    default:
      return;
  }

  piece_width_ = image_width_ / num_columns_;
  piece_height_ = image_height_ / num_rows_;
}
