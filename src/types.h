#ifndef TYPES_H
#define TYPES_H

#include <QImage>

namespace puz {

const int testPuzzle = 9;
const int testRowPieces = 3;
const int testColumnPieces = 3;

const int puzzle1000Pieces = 1000;
const int puzzle1000RowPieces = 25;
const int puzzle1000ColumnPieces = 40;

const int puzzle3000Pieces = 3000;
const int puzzle3000RowPieces = 40;
const int puzzle3000ColumnPieces = 75;

enum location { general = 0, table1 = 1, table2 = 2 };
enum angle { a0 = 0, a90, a180, a270 };

struct piece {
  int id;

  int position_x;
  int position_y;

  int row;
  int column;

  int id_left;
  int id_top;
  int id_right;
  int id_bottom;

  angle rotation;

  int id_cluster;
};

struct cluster {
  int id;
};

}  // namespace puz

Q_DECLARE_METATYPE(puz::angle)
Q_DECLARE_METATYPE(puz::location)
Q_DECLARE_METATYPE(puz::piece)
Q_DECLARE_METATYPE(puz::cluster)

#endif  // TYPES_H
