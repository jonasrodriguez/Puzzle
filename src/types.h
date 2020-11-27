#ifndef TYPES_H
#define TYPES_H

#include <QImage>

namespace puz {

const int puzzle1000Height = 25;
const int puzzle1000Width = 40;

const int puzzle3000Height = 40;
const int puzzle3000Width = 75;

enum location { general = 0, table1 = 1, table2 = 2 };
enum angle { a0 = 0, a90, a180, a270 };

struct piece {
  int id;

  int idLeft;
  int idTop;
  int idRight;
  int idBottom;

  angle rotation;

  int idGroup;
  QImage image;
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
