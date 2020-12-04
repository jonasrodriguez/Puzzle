#ifndef PIECE_MANAGER_H
#define PIECE_MANAGER_H

#include <QAbstractListModel>
#include <QImage>

#include "types.h"

class PieceManager : public QAbstractListModel {
  Q_OBJECT
  Q_PROPERTY(int totalPieces MEMBER total_pieces_ NOTIFY piecesChanged)
  Q_PROPERTY(int numColumns MEMBER num_columns_ NOTIFY piecesChanged)
  Q_PROPERTY(int numRows MEMBER num_rows_ NOTIFY piecesChanged)
  Q_PROPERTY(int imageWidth MEMBER image_width_ NOTIFY piecesChanged)
  Q_PROPERTY(int imageHeight MEMBER image_height_ NOTIFY piecesChanged)

 public:
  PieceManager(QObject *parent = nullptr);

  enum PiecesRoles { posXRole = Qt::DisplayRole, posYRole, rotationRole };

  int rowCount(const QModelIndex &parent = QModelIndex()) const override;
  QVariant data(const QModelIndex &index,
                int role = Qt::DisplayRole) const override;
  QHash<int, QByteArray> roleNames() const override;

  void LoadPieceValues(const int &total_pieces);

 signals:
  void piecesChanged();

 public slots:
  void setImageRealSize(const float &heigt, const float &width);

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
  QVector<puz::piece> pieces_;
};

#endif  // PIECE_MANAGER_H
