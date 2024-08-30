#include "pixel.h"
using namespace std;

Pixel::Pixel(char blue, char green, char red)
{
    this->blue = blue;
    this->green = green;
    this->red = red;
    this->normBlue = (float)(unsigned char)blue / 255;
    this->normGreen = (float)(unsigned char)green / 255;
    this->normRed = (float)(unsigned char)red / 255;
}