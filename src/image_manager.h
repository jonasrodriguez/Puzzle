#ifndef PUZZLE_IMAGE_H
#define PUZZLE_IMAGE_H

#include <QImage>
#include <QObject>
#include <string>

#include "types.h"

class image_manager {
 public:
  image_manager();

  bool LoadImage(const QString &);

 private:
  QImage puzzle_image_;
};

#endif  // PUZZLE_IMAGE_H
