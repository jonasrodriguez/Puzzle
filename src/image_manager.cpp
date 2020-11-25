#include "image_manager.h"

#include <QDebug>
#include <QFile>

image_manager::image_manager() {}

bool image_manager::LoadImage(const QString &imageName) {
  puzzle_image_ = QImage(imageName);
  return !puzzle_image_.isNull();
}
