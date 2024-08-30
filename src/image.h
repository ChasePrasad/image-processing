#pragma once

#include "header.h"
#include "pixel.h"
#include <vector>
using namespace std;

struct Image
{
    Header header;
    short width;
    short height;
    vector<Pixel> pixels;

    Image(Header header);

    void addPixel(Pixel pixel);
};