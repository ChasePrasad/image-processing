#pragma once

using namespace std;

struct Header
{
    char idLength;
    char colorMapType;
    char dataTypeCode;
    short colorMapOrigin;
    short colorMapLength;
    char colorMapDepth;
    short xOrigin;
    short yOrigin;
    short width;
    short height;
    char bitsPerPixel;
    char imageDescriptor;

    Header(char idLength = 0, char colorMapTyp = 0, char dataTypeCode = 0, short colorMapOrigin = 0, short colorMapLength = 0, char colorMapDepth = 0, short xOrigin = 0, short yOrigin = 0, short width = 0, short height = 0, char bitsPerPixel = 0, char imageDescriptor = 0);
};