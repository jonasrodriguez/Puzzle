#ifndef IMAGE_MANAGER_H
#define IMAGE_MANAGER_H

#include <QImage>
#include <QQuickImageProvider>

#include "types.h"

class ImageManager : public QQuickImageProvider {
 public:
  ImageManager();

  QImage requestImage(const QString &id, QSize *size,
                      const QSize &requestedSize) override;

  bool LoadImage(const QString &image_name, const int &total_pieces,
                 int &piece_height, int &piece_width);

  QImage GetImageFromVector(const int &id);

 private:
  void LoadImageVector(const int &piece_height, const int &piece_width);
  QImage CreateSubImage(QImage *image, const QRect &rect);

 private:
  QImage *puzzle_image_;
  QVector<QImage> piece_images_;
};

#endif  // IMAGE_MANAGER_H
