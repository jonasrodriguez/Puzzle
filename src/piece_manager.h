#ifndef PIECE_MANAGER_H
#define PIECE_MANAGER_H

#include <QAbstractListModel>
#include <QImage>

#include "types.h"

class PieceManager : public QAbstractListModel {
  Q_OBJECT
  Q_PROPERTY(int totalPieces MEMBER total_pieces_ NOTIFY piecesChanged)
  Q_PROPERTY(int numRows MEMBER num_rows_ NOTIFY piecesChanged)
  Q_PROPERTY(int numColumns MEMBER num_columns_ NOTIFY piecesChanged)

 public:
  PieceManager(QObject *parent = nullptr);

  enum PiecesRoles {
    posXRole = Qt::DisplayRole,
    posYRole,
    rowRole,
    columnRole,
    rotationRole
  };

  int rowCount(const QModelIndex &parent = QModelIndex()) const override;
  QVariant data(const QModelIndex &index,
                int role = Qt::DisplayRole) const override;
  QHash<int, QByteArray> roleNames() const override;

  void LoadPieceValues(const int &total_pieces);

  int getTotalPieces();
  int getNumColumns();
  int getNumRows();

 signals:
  void piecesChanged();
  void randomizePieces(const int &id, const int &x, const int &y,
                       const int &rot);

 public slots:
  void startPuzzle(const int &height, const int &width);
  void pressedPiece(const int &id);
  void releasedPiece();

 private:
  void CalculatePieceSize();
  void FillPieceVector();
  void FindNeighbours(const int &index, puz::piece &piece);

 private:
  int total_pieces_;
  int num_rows_;
  int num_columns_;
  bool game_started_;
  QVector<puz::piece> pieces_;
};

#endif  // PIECE_MANAGER_H
