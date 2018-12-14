#pragma once

#include <iostream>

#include "FractalBitmap.h"
#include "Mandelbrot.h"

namespace bitmap    {

FractalBitmap::FractalBitmap(int width, int height): Bitmap::Bitmap(width, height),
                                                     histogram_((new int[Mandelbrot::MAX_ITERATIONS + 1]{0})),
                                                     fractal_(new int[width * height]{0}), zoom_list_(width, height)   {
    zoom_list_.add(bitmap::Zoom(getWidth() / 2, getHeight() / 2, 4.0 / getWidth()));
    zoom_list_.add(bitmap::Zoom(295, getHeight() - 202, 0.1));
    zoom_list_.add(bitmap::Zoom(312, getHeight() - 304, 0.1));
}

FractalBitmap::~FractalBitmap()   {}

void FractalBitmap::generateFractal()   {
    std::cout << "calculating iteration" << std::endl;
    calculateIteration();
    std::cout << "drawing fractal" << std::endl;
    drawFractal();
}

void FractalBitmap::calculateIteration()   {
    for (int y = 0; y < getHeight(); y++)  {
        for (int x = 0; x < getWidth(); x++) {
            auto coords = zoom_list_.doZoom(x, y);

            int iterations = bitmap::Mandelbrot::getIterations(coords.first, coords.second);

            fractal_[y * getWidth() + x] = iterations;

            if (iterations != bitmap::Mandelbrot::MAX_ITERATIONS) {
                histogram_[iterations]++;
            }
        }
    }
}

int FractalBitmap::calculateTotal()    {
    int total = 0;

    for (int i = 0; i < bitmap::Mandelbrot::MAX_ITERATIONS; i++)  {
        total += histogram_[i];
    }

    return total;
}

void FractalBitmap::drawFractal()  {
    int total = calculateTotal();
    for (int y = 0; y < getHeight(); y++)  {
        for (int x = 0; x < getWidth(); x++) {
            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;

            int iterations = fractal_[y * getWidth() + x];

            if (iterations != bitmap::Mandelbrot::MAX_ITERATIONS) {
                double hue = 0.0;
                for (int i = 0; i <= iterations; i++) {
                    hue += static_cast<double>(histogram_[i]) / total;
                }

                green = hue * 255;
            }

            setPixel(x, y, red, green, blue);
        }
    }
}

}