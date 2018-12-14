#include <cstdint>
#include <iostream>
#include <math.h>
#include <memory>

#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"

#include "Bitmap.h"
#include "Mandelbrot.h"
#include "Zoom.h"
#include "FractalBitmap.h"

int main(int argc, char *argv[])  {
  if (argc != 4) {
    std::cout << "Must include the parameters" << std::endl;
    return 1;
  }
  int width = std::stoi(argv[1]);
  int height = std::stoi(argv[2]);
  char *filename = argv[3];
  bitmap::FractalBitmap bitmap(width, height);
  bitmap.generateFractal();

  bitmap.write(filename);
  std::cout << "Finished!!" << std::endl;
  return 0;

}
