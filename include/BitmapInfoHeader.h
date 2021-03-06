#pragma once

#include <cstdint>

using namespace std;

// Avoids padding in the struct.
#pragma pack(2)

namespace bitmap  {

struct BitmapInfoHeader {
  int32_t header_size{40};
  int32_t width;
  int32_t height;
  int16_t planes{1};
  int16_t bits_per_pixel{24};
  int32_t compression{0};
  int32_t data_size{0};
  int32_t horizontal_resolution{2400};
  int32_t vertical_resolution{2400};
  int32_t colors{0};
  int32_t important_colors{0};
};

}
