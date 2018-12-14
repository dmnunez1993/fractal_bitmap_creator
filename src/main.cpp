
#include <iostream>


#include <FractalBitmap.h>

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
