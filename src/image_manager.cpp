#include "image_manager.h"

#include <QDebug>
#include <QFile>

ImageManager::ImageManager()
    : QQuickImageProvider(QQuickImageProvider::Image) {}

QImage ImageManager::GetImageFromVector(const int &id) {
  return piece_images_.at(id);
}

QImage ImageManager::requestImage(const QString &id, QSize *size,
                                  const QSize &requestedSize) {
  (void)size;
  (void)requestedSize;
  return piece_images_.at(id.toInt());
}

bool ImageManager::LoadImage(const QString &image_name, const int &total_pieces,
                             int &piece_height, int &piece_width) {
  /// TODO - Use parameter image name
  (void)image_name;
  puzzle_image_ = new QImage(":/images/japanPuzzle");
  if (puzzle_image_->isNull()) {
    return false;
  }

  // Add size values to piece vector
  switch (total_pieces) {
    case puz::puzzle1000Pieces:
      piece_width = puzzle_image_->width() / puz::puzzle1000ColumnPieces;
      piece_height = puzzle_image_->height() / puz::puzzle1000RowPieces;
      break;
    case puz::puzzle3000Pieces:
      piece_width = puzzle_image_->width() / puz::puzzle3000ColumnPieces;
      piece_height = puzzle_image_->height() / puz::puzzle3000RowPieces;
      break;
    default:
      return false;
  }

  // Split image and load pieces on vector
  LoadImageVector(piece_height, piece_width);

  return true;
}

void ImageManager::LoadImageVector(const int &piece_height,
                                   const int &piece_width) {
  QRect rect;
  for (int y = 0; y < puz::puzzle3000RowPieces; y++) {
    for (int x = 0; x < puz::puzzle3000ColumnPieces; x++) {
      rect =
          QRect(x * piece_width, y * piece_height, piece_width, piece_height);
      piece_images_.push_back(CreateSubImage(puzzle_image_, rect));
    }
  }
}

QImage ImageManager::CreateSubImage(QImage *image, const QRect &rect) {
  size_t offset =
      rect.x() * image->depth() / 8 + rect.y() * image->bytesPerLine();
  return QImage(image->bits() + offset, rect.width(), rect.height(),
                image->bytesPerLine(), image->format());
}
