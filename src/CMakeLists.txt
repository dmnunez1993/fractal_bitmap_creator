add_library(fractal_bitmap
  Bitmap.cpp
  FractalBitmap.cpp
  Mandelbrot.cpp
  Zoom.cpp
)

target_include_directories(fractal_bitmap
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)
