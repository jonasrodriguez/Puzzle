#ifndef PUZZLE_IMAGE_H
#define PUZZLE_IMAGE_H

#include <QAbstractListModel>
#include <QImage>

#include "types.h"

class ImageManager : public QAbstractListModel {
 public:
  ImageManager(QObject *parent = nullptr);

  enum PieceRoles {
    idRole = Qt::UserRole + 1,
    posRole,
    nameRole,
    surnameRole,
    emailRole,
    dobRole
  };

  int rowCount(const QModelIndex &parent = QModelIndex()) const override;
  QVariant data(const QModelIndex &index,
                int role = Qt::DisplayRole) const override;
  QHash<int, QByteArray> roleNames() const override;

  bool LoadImage(const QString &);

 private:
  QImage puzzle_image_;
  QVector<puz::piece> pieces_;
  QVector<puz::cluster> clusters_;
};

#endif  // PUZZLE_IMAGE_H
