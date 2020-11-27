#include "image_manager.h"

#include <QDebug>
#include <QFile>

ImageManager::ImageManager(QObject *parent) : QAbstractListModel(parent) {}

bool ImageManager::LoadImage(const QString &imageName) {
  puzzle_image_ = QImage(imageName);
  return !puzzle_image_.isNull();
}

int ImageManager::rowCount(const QModelIndex &) const { return pieces_.size(); }

QVariant ImageManager::data(const QModelIndex &index, int role) const {
  if (!index.isValid()) {
    return QVariant();
  }

  if (index.row() < 0) {
    return QVariant();
  }

  switch (role) {
    case PieceRoles::posRole:
      return 1;
    case PieceRoles::idRole:
      return 2;
    default:
      return QVariant();
  }
}

QHash<int, QByteArray> ImageManager::roleNames() const {
  QHash<int, QByteArray> roles;

  roles[idRole] = "id";
  roles[posRole] = "pos";
  roles[nameRole] = "name";
  roles[surnameRole] = "surname";
  roles[emailRole] = "email";
  roles[dobRole] = "dob";

  return roles;
}
