#pragma once

#include<string>

#include "Bitmap.h"
#include "Zoom.h"

namespace bitmap    {

class FractalBitmap: public Bitmap    {
private:
    std::unique_ptr<int[]> histogram_;
    std::unique_ptr<int[]> fractal_;
    bitmap::ZoomList zoom_list_;
public:
    FractalBitmap() = delete;
    FractalBitmap(int width, int height);
    virtual ~FractalBitmap();

    void generateFractal();
    void calculateIteration();
    int calculateTotal();
    void drawFractal();
};

}