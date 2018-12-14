#pragma once

#include <cstdint>

using namespace std;

// Avoids padding in the struct.
#pragma pack(2)

namespace bitmap  {

struct BitmapFileHeader {
  char header[2]{'B', 'M'};
  int32_t file_size;
  int32_t reserved{0};
  int32_t data_offset;
};

}
