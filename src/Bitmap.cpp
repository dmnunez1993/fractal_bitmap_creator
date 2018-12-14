#include <iostream>
#include <fstream>

#include <Bitmap.h>
#include <BitmapInfoHeader.h>
#include <BitmapFileHeader.h>

namespace bitmap  {

Bitmap::Bitmap(int width, int height): width_(width), height_(height), pixels_(new uint8_t[width * height * 3]{}) {}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
  auto pixel = pixels_.get() + x * 3 + y * 3 * width_;
  pixel[0] = blue;
  pixel[1] = green;
  pixel[2] = red;
}

bool Bitmap::write(std::string filename)  {
  BitmapInfoHeader info_header;
  BitmapFileHeader file_header;
  const int bitmap_size = width_ * height_ * 3;

  file_header.file_size = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + bitmap_size;
  file_header.data_offset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

  info_header.width = width_;
  info_header.height = height_;

  std::ofstream file;
  file.open(filename, std::ios::out|std::ios::binary);

  if (!file)  {
    return false;
  }

  file.write((char *)&file_header, sizeof(file_header));
  file.write((char *)&info_header, sizeof(info_header));
  file.write((char *)pixels_.get(), bitmap_size);

  file.close();

  return true;
}

int Bitmap::getWidth()  {
  return width_;
}

int Bitmap::getHeight()  {
  return height_;
}

Bitmap::~Bitmap() {}
}
