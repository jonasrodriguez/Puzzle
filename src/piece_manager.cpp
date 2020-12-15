#include "piece_manager.h"

#include <QDebug>
#include <random>

#include "types.h"

PieceManager::PieceManager(QObject *parent)
    : QAbstractListModel(parent), total_pieces_(0) {}

QHash<int, QByteArray> PieceManager::roleNames() const {
  QHash<int, QByteArray> roles;

  roles[posXRole] = "posX";
  roles[posYRole] = "posY";
  roles[rowRole] = "row";
  roles[columnRole] = "column";
  roles[rotationRole] = "rotation";

  return roles;
}

int PieceManager::rowCount(const QModelIndex & /* parent */) const {
  return pieces_.size();
}

QVariant PieceManager::data(const QModelIndex &index, int role) const {
  if (!index.isValid()) return QVariant();

  if (index.row() >= pieces_.size() || index.row() < 0) return QVariant();

  switch (role) {
    case PiecesRoles::posXRole: {  /// TODO - Delete
      float posX = pieces_.at(index.row()).row;
      return posX;
    }
    case PiecesRoles::posYRole: {  /// TODO - Delete
      float posY = pieces_.at(index.row()).column;
      return posY;
    }
    case PiecesRoles::rowRole: {
      return pieces_.at(index.row()).row;
    }
    case PiecesRoles::columnRole: {
      return pieces_.at(index.row()).column;
    }
    case PiecesRoles::rotationRole:
      return pieces_.at(index.row()).rotation;
    default:
      return QVariant();
  }
}

void PieceManager::startPuzzle(const int &height, const int &width) {
  std::random_device rd;   // obtain a random number from hardware
  std::mt19937 gen(rd());  // seed the generator
  // define the height range
  std::uniform_int_distribution<> dist_height(0, height);
  // define the height range
  std::uniform_int_distribution<> dist_width(0, width);
  // define rotation range (4 * 90º possible possitions)
  std::uniform_int_distribution<> dist_rota(0, 3);

  // Randomize all pieces position and rotation
  for (int i = 0; i < total_pieces_; i++) {
    emit randomizePieces(i, dist_height(gen), dist_width(gen), dist_rota(gen));
  }
}

void PieceManager::pressedPiece(const int &id) {
  qDebug() << "pressedPiece";

  for (auto p : pieces_) {
    if (p.id_left == id) {
      qDebug() << "Vecino Derecho: " << p.id;
    }
    if (p.id_right == id) {
      qDebug() << "Vecino Izquierdo: " << p.id;
    }
    if (p.id_top == id) {
      qDebug() << "Vecino Abajo: " << p.id;
    }
    if (p.id_bottom == id) {
      qDebug() << "Vecino Arriba: " << p.id;
    }
  }
}
void PieceManager::releasedPiece() {}

void PieceManager::LoadPieceValues(const int &total_pieces) {
  total_pieces_ = total_pieces;

  CalculatePieceSize();
  FillPieceVector();

  emit piecesChanged();
}

void PieceManager::CalculatePieceSize() {
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
}

void PieceManager::FillPieceVector() {
  for (int index = 0; index < total_pieces_; index++) {
    puz::piece piece;

    piece.id = index;
    piece.rotation = puz::a0;
    piece.id_cluster = -1;
    piece.row = (int)(index / num_rows_);
    piece.column = index % num_rows_;
    FindNeighbours(index, piece);

    beginInsertRows(QModelIndex(), pieces_.size(), pieces_.size() + 1);
    pieces_.push_back(piece);
    endInsertRows();
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
