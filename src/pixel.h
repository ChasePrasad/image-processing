#pragma once

using namespace std;

struct Pixel
{
    char blue;
    char green;
    char red;
    float normBlue;
    float normGreen;
    float normRed;

    Pixel(char blue, char green, char red);
};