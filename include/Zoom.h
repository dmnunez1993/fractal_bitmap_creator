#pragma once

#include <vector>
#include <utility>

namespace bitmap    {

struct Zoom  {
    int x{0};
    int y{0};
    double scale{0};

    Zoom(int x, int y, double scale):   x(x), y(y), scale(scale) {}
};

class ZoomList  {
private:
    int width_{0};
    int height_{0};
    std::vector<Zoom> zooms_;

    double x_center_{0};
    double y_center_{0};
    double scale_{1.0};
public:
    ZoomList(int width, int height);
    void add(const Zoom& zoom);
    std::pair<double, double> doZoom(int x, int y);
};

}