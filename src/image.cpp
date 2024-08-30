#include "image.h"
using namespace std;

Image::Image(Header header)
{
    this->header = header;
    this->width = header.width;
    this->height = header.height;
}

void Image::addPixel(Pixel pixel)
{
    this->pixels.push_back(pixel);
}