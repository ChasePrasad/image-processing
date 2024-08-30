#include <fstream>
#include "image.h"
#include <iostream>
#include <string>
// #include <vector>
#include <cstring>
using namespace std;

Image readFile(string path);
void writeFile(string path, Image image);
void compFiles(Image image1, Image image2);

// Image task1(string path1, string path2);
// Image task2(string path1, string path2);
// Image task3(string path1, string path2);
// Image task4(string path1, string path2);
// Image task5(string path1, string path2);
// Image task6(string path1);
// Image task7(string path1);
// vector<Image> task8(string path1);
// Image task9(string path1, string path2, string path3);
// Image task10(string path1);

Image multiply(Image image1, string path2);
Image subtract(Image image1, string path2);
Image overlay(Image image1, string path2);
Image screen(Image image1, string path2);
Image combine(Image image1, string path2, string path3);
Image flip(Image image1);
Image onlyblue(Image image1);
Image onlygreen(Image image1);
Image onlyred(Image image1);
Image addblue(Image image1, int amount);
Image addgreen(Image image1, int amount);
Image addred(Image image1, int amount);
Image scaleblue(Image image1, int amount);
Image scalegreen(Image image1, int amount);
Image scalered(Image image1, int amount);

int main(int argc, char *argv[])
{
    // Image image1 = task1("input/layer1.tga", "input/pattern1.tga");
    // writeFile("output/part1.tga", image1);
    // compFiles(image1, readFile("examples/EXAMPLE_part1.tga"));

    // Image image2 = task2("input/car.tga", "input/layer2.tga");
    // writeFile("output/part2.tga", image2);
    // compFiles(image2, readFile("examples/EXAMPLE_part2.tga"));

    // Image image3 = task3("input/layer1.tga", "input/pattern2.tga");
    // writeFile("output/part3.tga", image3);
    // compFiles(image3, readFile("examples/EXAMPLE_part3.tga"));

    // Image image4 = task4("input/layer2.tga", "input/circles.tga");
    // writeFile("output/part4.tga", image4);
    // compFiles(image4, readFile("examples/EXAMPLE_part4.tga"));

    // Image image5 = task5("input/layer1.tga", "input/pattern1.tga");
    // writeFile("output/part5.tga", image5);
    // compFiles(image5, readFile("examples/EXAMPLE_part5.tga"));

    // Image image6 = task6("input/car.tga");
    // writeFile("output/part6.tga", image6);
    // compFiles(image6, readFile("examples/EXAMPLE_part6.tga"));

    // Image image7 = task7("input/car.tga");
    // writeFile("output/part7.tga", image7);
    // compFiles(image7, readFile("examples/EXAMPLE_part7.tga"));
    
    // vector<Image> images8 = task8("input/car.tga");
    // writeFile("output/part8_b.tga", images8[0]);
    // writeFile("output/part8_g.tga", images8[1]);
    // writeFile("output/part8_r.tga", images8[2]);
    // compFiles(images8[0], readFile("examples/EXAMPLE_part8_b.tga"));
    // compFiles(images8[1], readFile("examples/EXAMPLE_part8_g.tga"));
    // compFiles(images8[2], readFile("examples/EXAMPLE_part8_r.tga"));

    // Image image9 = task9("input/layer_blue.tga", "input/layer_green.tga", "input/layer_red.tga");
    // writeFile("output/part9.tga", image9);
    // compFiles(image9, readFile("examples/EXAMPLE_part9.tga"));

    // Image image10 = task10("input/text2.tga");
    // writeFile("output/part10.tga", image10);
    // compFiles(image10, readFile("examples/EXAMPLE_part10.tga"));

    if (argc == 1 || strcmp(argv[1], "--help") == 0)
    {
        cout << "Project 2: Image Processing, Summer 2024" << endl << endl;
        cout << "Usage:\n\t./project2.out [output] [firstImage] [method] [...]";
        return 0;
    }

    string outputFile = argv[1];
    if (outputFile.find(".tga") == string::npos || argc < 3)
    {
        cout << "Invalid file name.";
        return 0;
    }
    if (outputFile.find("output/") == string::npos)
    {
        outputFile = "output/" + outputFile;
    }
    
    string inputFile = argv[2];
    if (inputFile.find(".tga") == string::npos)
    {
        cout << "Invalid file name.";
        return 0;
    }
    if (inputFile.find("input/") == string::npos)
    {
        inputFile = "input/" + inputFile;
    }
    ifstream temp(inputFile, ios::binary);
    if (!temp)
    {
        cout << "File does not exist.";
        return 0;
    }
    temp.close();
    
    Image trackingImage = readFile(inputFile);

    if (argc < 4)
    {
        cout << "Invalid method name.";
        return 0;
    }

    int count = 3;
    while (count < argc)
    {
        string method = argv[count];
        if (method == "multiply")
        {
            if (argc < count + 2)
            {
                cout << "Missing argument.";
                return 0;
            }

            inputFile = argv[count + 1];
            if (inputFile.find(".tga") == string::npos)
            {
                cout << "Invalid argument, invalid file name.";
                return 0;
            }
            if (inputFile.find("input/") == string::npos)
            {
                inputFile = "input/" + inputFile;
            }

            temp.open(inputFile, ios::binary);
            if (!temp)
            {
                cout << "Invalid argument, file does not exist.";
                return 0;
            }
            temp.close();

            trackingImage = multiply(trackingImage, inputFile);
            count += 2;
        }
        else if(method == "subtract")
        {
            if (argc < count + 2)
            {
                cout << "Missing argument.";
                return 0;
            }

            inputFile = argv[count + 1];
            if (inputFile.find(".tga") == string::npos)
            {
                cout << "Invalid argument, invalid file name.";
                return 0;
            }
            if (inputFile.find("input/") == string::npos)
            {
                inputFile = "input/" + inputFile;
            }

            temp.open(inputFile, ios::binary);
            if (!temp)
            {
                cout << "Invalid argument, file does not exist.";
                return 0;
            }
            temp.close();

            trackingImage = subtract(trackingImage, inputFile);
            count += 2;
        }
        else if(method == "overlay")
        {
            if (argc < count + 2)
            {
                cout << "Missing argument.";
                return 0;
            }

            inputFile = argv[count + 1];
            if (inputFile.find(".tga") == string::npos)
            {
                cout << "Invalid argument, invalid file name.";
                return 0;
            }
            if (inputFile.find("input/") == string::npos)
            {
                inputFile = "input/" + inputFile;
            }

            temp.open(inputFile, ios::binary);
            if (!temp)
            {
                cout << "Invalid argument, file does not exist.";
                return 0;
            }
            temp.close();

            trackingImage = overlay(trackingImage, inputFile);
            count += 2;
        }
        else if(method == "screen")
        {
            if (argc < count + 2)
            {
                cout << "Missing argument.";
                return 0;
            }

            inputFile = argv[count + 1];
            if (inputFile.find(".tga") == string::npos)
            {
                cout << "Invalid argument, invalid file name.";
                return 0;
            }
            if (inputFile.find("input/") == string::npos)
            {
                inputFile = "input/" + inputFile;
            }

            temp.open(inputFile, ios::binary);
            if (!temp)
            {
                cout << "Invalid argument, file does not exist.";
                return 0;
            }
            temp.close();

            trackingImage = screen(trackingImage, inputFile);
            count += 2;
        }
        else if(method == "combine")
        {
            if (argc < count + 3)
            {
                cout << "Missing argument.";
                return 0;
            }

            inputFile = argv[count + 1];
            if (inputFile.find(".tga") == string::npos)
            {
                cout << "Invalid argument, invalid file name.";
                return 0;
            }
            if (inputFile.find("input/") == string::npos)
            {
                inputFile = "input/" + inputFile;
            }

            temp.open(inputFile, ios::binary);
            if (!temp)
            {
                cout << "Invalid argument, file does not exist.";
                return 0;
            }
            temp.close();

            string inputFile2 = argv[count + 2];
            if (inputFile2.find(".tga") == string::npos)
            {
                cout << "Invalid argument, invalid file name.";
                return 0;
            }
            if (inputFile2.find("input/") == string::npos)
            {
                inputFile2 = "input/" + inputFile2;
            }

            temp.open(inputFile2, ios::binary);
            if (!temp)
            {
                cout << "Invalid argument, file does not exist.";
                return 0;
            }
            temp.close();

            trackingImage = combine(trackingImage, inputFile, inputFile2);
            count += 3;
        }
        else if (method == "flip")
        {
            trackingImage = flip(trackingImage);
            count++;
        }
        else if (method == "onlyblue")
        {
            trackingImage = onlyblue(trackingImage);
            count++;
        }
        else if (method == "onlygreen")
        {
            trackingImage = onlygreen(trackingImage);
            count++;
        }
        else if (method == "onlyred")
        {
            trackingImage = onlyred(trackingImage);
            count++;
        }
        else if (method == "addblue")
        {
            if (argc < count + 2)
            {
                cout << "Missing argument.";
                return 0;
            }

            int amount;
            try
            {
                amount = stoi(argv[count + 1]);
            }
            catch (invalid_argument)
            {
                cout << "Invalid argument, expected number.";
                return 0;
            }

            trackingImage = addblue(trackingImage, amount);
            count += 2;
        }
        else if (method == "addgreen")
        {
            if (argc < count + 2)
            {
                cout << "Missing argument.";
                return 0;
            }

            int amount;
            try
            {
                amount = stoi(argv[count + 1]);
            }
            catch (invalid_argument)
            {
                cout << "Invalid argument, expected number.";
                return 0;
            }

            trackingImage = addgreen(trackingImage, amount);
            count += 2;
        }
        else if (method == "addred")
        {
            if (argc < count + 2)
            {
                cout << "Missing argument.";
                return 0;
            }

            int amount;
            try
            {
                amount = stoi(argv[count + 1]);
            }
            catch (invalid_argument)
            {
                cout << "Invalid argument, expected number.";
                return 0;
            }

            trackingImage = addred(trackingImage, amount);
            count += 2;
        }
        else if (method == "scaleblue")
        {
            if (argc < count + 2)
            {
                cout << "Missing argument.";
                return 0;
            }

            int amount;
            try
            {
                amount = stoi(argv[count + 1]);
            }
            catch (invalid_argument)
            {
                cout << "Invalid argument, expected number.";
                return 0;
            }

            trackingImage = scaleblue(trackingImage, amount);
            count += 2;
        }
        else if (method == "scalegreen")
        {
            if (argc < count + 2)
            {
                cout << "Missing argument.";
                return 0;
            }

            int amount;
            try
            {
                amount = stoi(argv[count + 1]);
            }
            catch (invalid_argument)
            {
                cout << "Invalid argument, expected number.";
                return 0;
            }

            trackingImage = scalegreen(trackingImage, amount);
            count += 2;
        }
        else if (method == "scalered")
        {
            if (argc < count + 2)
            {
                cout << "Missing argument.";
                return 0;
            }

            int amount;
            try
            {
                amount = stoi(argv[count + 1]);
            }
            catch (invalid_argument)
            {
                cout << "Invalid argument, expected number.";
                return 0;
            }

            trackingImage = scalered(trackingImage, amount);
            count += 2;
        }
        else
        {
            cout << "Invalid method name.";
            return 0;
        }
    }

    writeFile(outputFile, trackingImage);

    return 0;
}

Image readFile(string path)
{
    ifstream input(path, ios::binary);

    char idLength;
    input.read(&idLength, 1);

    char colorMapType;
    input.read(&colorMapType, 1);

    char dataTypeCode;
    input.read(&dataTypeCode, 1);

    short colorMapOrigin;
    input.read(reinterpret_cast<char*>(&colorMapOrigin), 2);

    short colorMapLength;
    input.read(reinterpret_cast<char*>(&colorMapLength), 2);

    char colorMapDepth;
    input.read(&colorMapDepth, 1);

    short xOrigin;
    input.read(reinterpret_cast<char*>(&xOrigin), 2);

    short yOrigin;
    input.read(reinterpret_cast<char*>(&yOrigin), 2);

    short width;
    input.read(reinterpret_cast<char*>(&width), 2);

    short height;
    input.read(reinterpret_cast<char*>(&height), 2);

    char bitsPerPixel;
    input.read(&bitsPerPixel, 1);

    char imageDescriptor;
    input.read(&imageDescriptor, 1);

    Header header(idLength, colorMapType, dataTypeCode, colorMapOrigin, colorMapLength, colorMapDepth, xOrigin, yOrigin, width, height, bitsPerPixel, imageDescriptor);
    Image image(header);

    for (int i = 0; i < image.width * image.height; i++)
    {
        char blue;
        input.read(&blue, 1);

        char green;
        input.read(&green, 1);

        char red;
        input.read(&red, 1);

        Pixel pixel(blue, green, red);
        image.addPixel(pixel);
    }

    input.close();

    return image;
}

void writeFile(string path, Image image)
{
    ofstream output(path, ios::binary);

    output.write(&image.header.idLength, 1);
    output.write(&image.header.colorMapType, 1);
    output.write(&image.header.dataTypeCode, 1);
    output.write(reinterpret_cast<char*>(&image.header.colorMapOrigin), 2);
    output.write(reinterpret_cast<char*>(&image.header.colorMapLength), 2);
    output.write(&image.header.colorMapDepth, 1);
    output.write(reinterpret_cast<char*>(&image.header.xOrigin), 2);
    output.write(reinterpret_cast<char*>(&image.header.yOrigin), 2);
    output.write(reinterpret_cast<char*>(&image.header.width), 2);
    output.write(reinterpret_cast<char*>(&image.header.height), 2);
    output.write(&image.header.bitsPerPixel, 1);
    output.write(&image.header.imageDescriptor, 1);

    for (int i = 0; i < image.width * image.height; i++)
    {
        output.write(&image.pixels[i].blue, 1);
        output.write(&image.pixels[i].green, 1);
        output.write(&image.pixels[i].red, 1);
    }

    output.close();
}

void compFiles(Image image1, Image image2)
{
    for (int i = 0; i < image1.width * image1.height; i++)
    {
        if (image1.pixels[i].blue != image2.pixels[i].blue || image1.pixels[i].green != image2.pixels[i].green || image1.pixels[i].red != image2.pixels[i].red)
        {
            cout << "Images are different at pixel " << i << endl << "Blue Channel: Image 1 - " << (int)(unsigned char)image1.pixels[i].blue << " Image 2 - " << (int)(unsigned char)image2.pixels[i].blue << endl << "Green Channel: Image 1 - " << (int)(unsigned char)image1.pixels[i].green << " Image 2 - " << (int)(unsigned char)image2.pixels[i].green << endl << "Red: Image 1 - " << (int)(unsigned char)image1.pixels[i].red << " Image 2 - " << (int)(unsigned char)image2.pixels[i].red << endl;
            return;
        }
    }

    cout << "Images are the same" << endl;
}

// Image task1(string path1, string path2)
// {
//     Image image1 = readFile(path1);
//     Image image2 = readFile(path2);
//     Image image(image1.header);

//     for (int i = 0; i < image.width * image.height; i++)
//     {
//         char blue = (image1.pixels[i].normBlue * image2.pixels[i].normBlue) * 255 + 0.5f;

//         char green = (image1.pixels[i].normGreen * image2.pixels[i].normGreen) * 255 + 0.5f;

//         char red = (image1.pixels[i].normRed * image2.pixels[i].normRed) * 255 + 0.5f;

//         Pixel pixel(blue, green, red);
//         image.addPixel(pixel);
//     }

//     return image;    
// }

// Image task2(string path1, string path2)
// {
//     Image image1 = readFile(path1);
//     Image image2 = readFile(path2);
//     Image image(image1.header);

//     for (int i = 0; i < image.width * image.height; i++)
//     {
//         char blue;
//         char green;
//         char red;

//         if ((int)(unsigned char)image1.pixels[i].blue - (int)(unsigned char)image2.pixels[i].blue < 0)
//         {
//             blue = 0;
//         }
//         else
//         {
//             blue = image1.pixels[i].blue - image2.pixels[i].blue;
//         }

//         if ((int)(unsigned char)image1.pixels[i].green - (int)(unsigned char)image2.pixels[i].green < 0)
//         {
//             green = 0;
//         }
//         else
//         {
//             green = image1.pixels[i].green - image2.pixels[i].green;
//         }

//         if ((int)(unsigned char)image1.pixels[i].red - (int)(unsigned char)image2.pixels[i].red < 0)
//         {
//             red = 0;
//         }
//         else
//         {
//             red = image1.pixels[i].red - image2.pixels[i].red;
//         }

//         Pixel pixel(blue, green, red);
//         image.addPixel(pixel);
//     }

//     return image;
// }

// Image task3(string path1, string path2)
// {
//     Image image1 = readFile(path1);
//     Image image2 = readFile(path2);
//     Image image3 = readFile("input/text.tga");
//     Image image(image1.header);

//     Image multImage = task1(path1, path2);

//     for (int i = 0; i < image.width * image.height; i++)
//     {
//         char blue = (1 - ((1 - multImage.pixels[i].normBlue) * (1 - image3.pixels[i].normBlue))) * 255 + 0.5f;

//         char green = (1 - ((1 - multImage.pixels[i].normGreen) * (1 - image3.pixels[i].normGreen))) * 255 + 0.5f;

//         char red = (1 - ((1 - multImage.pixels[i].normRed) * (1 - image3.pixels[i].normRed))) * 255 + 0.5f;

//         Pixel pixel(blue, green, red);
//         image.addPixel(pixel);
//     }

//     return image;  
// }

// Image task4(string path1, string path2)
// {
//     Image image1 = readFile(path1);
//     Image image2 = readFile(path2);
//     Image image3 = readFile("input/pattern2.tga");
//     Image image(image1.header);

//     Image multImage = task1(path1, path2);

//     for (int i = 0; i < image.width * image.height; i++)
//     {
//         char blue;
//         char green;
//         char red;

//         if ((int)(unsigned char)multImage.pixels[i].blue - (int)(unsigned char)image3.pixels[i].blue < 0)
//         {
//             blue = 0;
//         }
//         else
//         {
//             blue = multImage.pixels[i].blue - image3.pixels[i].blue;
//         }

//         if ((int)(unsigned char)multImage.pixels[i].green - (int)(unsigned char)image3.pixels[i].green < 0)
//         {
//             green = 0;
//         }
//         else
//         {
//             green = multImage.pixels[i].green - image3.pixels[i].green;
//         }

//         if ((int)(unsigned char)multImage.pixels[i].red - (int)(unsigned char)image3.pixels[i].red < 0)
//         {
//             red = 0;
//         }
//         else
//         {
//             red = multImage.pixels[i].red - image3.pixels[i].red;
//         }

//         Pixel pixel(blue, green, red);
//         image.addPixel(pixel);
//     }

//     return image;
// }

// Image task5(string path1, string path2)
// {
//     Image image1 = readFile(path1);
//     Image image2 = readFile(path2);
//     Image image(image1.header);

//     for (int i = 0; i < image.width * image.height; i++)
//     {
//         char blue;
//         char green;
//         char red;

//         if (image2.pixels[i].normBlue <= 0.5f)
//         {
//             blue = (2 * image1.pixels[i].normBlue * image2.pixels[i].normBlue) * 255 + 0.5f;
//         }
//         else
//         {
//             blue = (1 - (2 * (1 - image1.pixels[i].normBlue) * (1 - image2.pixels[i].normBlue))) * 255 + 0.5f;
//         }

//         if (image2.pixels[i].normGreen <= 0.5f)
//         {
//             green = (2 * image1.pixels[i].normGreen * image2.pixels[i].normGreen) * 255 + 0.5f;
//         }
//         else
//         {
//             green = (1 - (2 * (1 - image1.pixels[i].normGreen) * (1 - image2.pixels[i].normGreen))) * 255 + 0.5f;
//         }

//         if (image2.pixels[i].normRed <= 0.5f)
//         {
//             red = (2 * image1.pixels[i].normRed * image2.pixels[i].normRed) * 255 + 0.5f;
//         }
//         else
//         {
//             red = (1 - (2 * (1 - image1.pixels[i].normRed) * (1 - image2.pixels[i].normRed))) * 255 + 0.5f;
//         }

//         Pixel pixel(blue, green, red);
//         image.addPixel(pixel);
//     }

//     return image;
// }

// Image task6(string path1)
// {
//     Image image1 = readFile(path1);
//     Image image(image1.header);

//     for (int i = 0; i < image.width * image.height; i++)
//     {
//         char blue;
//         char green;
//         char red;

//         blue = image1.pixels[i].blue;

//         if ((int)(unsigned char)image1.pixels[i].green + 200 > 255)
//         {
//             green = 255;
//         }
//         else
//         {
//             green = image1.pixels[i].green + 200;
//         }

//         red = image1.pixels[i].red;

//         Pixel pixel(blue, green, red);
//         image.addPixel(pixel);
//     }

//     return image;
// }

// Image task7(string path1)
// {
//     Image image1 = readFile(path1);
//     Image image(image1.header);

//     for (int i = 0; i < image.width * image.height; i++)
//     {
//         char blue = 0;

//         char green = image1.pixels[i].green;

//         char red;
//         if (image1.pixels[i].normRed * 4 > 1.0f)
//         {
//             red = 255;
//         }
//         else
//         {
//             red = (image1.pixels[i].normRed * 4) * 255 + 0.5f;
//         }

//         Pixel pixel(blue, green, red);
//         image.addPixel(pixel);
//     }

//     return image;  
// }

// vector<Image> task8(string path1)
// {
//     Image image1 = readFile(path1);
//     Image imageB(image1.header);
//     Image imageG(image1.header);
//     Image imageR(image1.header);
//     vector<Image> images;

//     for (int i = 0; i < image1.width * image1.height; i++)
//     {
//         char blue = image1.pixels[i].blue;
//         char green = image1.pixels[i].green;
//         char red = image1.pixels[i].red;

//         Pixel pixelB(blue, blue, blue);
//         imageB.addPixel(pixelB);

//         Pixel pixelG(green, green, green);
//         imageG.addPixel(pixelG);

//         Pixel pixelR(red, red, red);
//         imageR.addPixel(pixelR);
//     }

//     images.push_back(imageB);
//     images.push_back(imageG);
//     images.push_back(imageR);

//     return images;
// }

// Image task9(string path1, string path2, string path3)
// {
//     Image image1 = readFile(path1);
//     Image image2 = readFile(path2);
//     Image image3 = readFile(path3);
//     Image image(image1.header);

//     for (int i = 0; i < image1.width * image1.height; i++)
//     {
//         char blue = image1.pixels[i].blue;

//         char green = image2.pixels[i].green;

//         char red = image3.pixels[i].red;

//         Pixel pixel(blue, green, red);
//         image.addPixel(pixel);
//     }

//     return image;
// }

// Image task10(string path1)
// {
//     Image image1 = readFile(path1);
//     Image image(image1.header);

//     for (int i = 0; i < image1.width * image1.height; i++)
//     {
//         char blue = image1.pixels[image1.width * image1.height - 1 - i].blue;

//         char green = image1.pixels[image1.width * image1.height - 1 - i].green;

//         char red = image1.pixels[image1.width * image1.height - 1 - i].red;

//         Pixel pixel(blue, green, red);
//         image.addPixel(pixel);
//     }

//     return image;
// }

Image multiply(Image image1, string path2)
{
    Image image2 = readFile(path2);
    Image image(image1.header);

    for (int i = 0; i < image.width * image.height; i++)
    {
        char blue = (image1.pixels[i].normBlue * image2.pixels[i].normBlue) * 255 + 0.5f;

        char green = (image1.pixels[i].normGreen * image2.pixels[i].normGreen) * 255 + 0.5f;

        char red = (image1.pixels[i].normRed * image2.pixels[i].normRed) * 255 + 0.5f;

        Pixel pixel(blue, green, red);
        image.addPixel(pixel);
    }

    return image;
}

Image subtract(Image image1, string path2)
{
    Image image2 = readFile(path2);
    Image image(image1.header);

    for (int i = 0; i < image.width * image.height; i++)
    {
        char blue;
        char green;
        char red;

        if ((int)(unsigned char)image1.pixels[i].blue - (int)(unsigned char)image2.pixels[i].blue < 0)
        {
            blue = 0;
        }
        else
        {
            blue = image1.pixels[i].blue - image2.pixels[i].blue;
        }

        if ((int)(unsigned char)image1.pixels[i].green - (int)(unsigned char)image2.pixels[i].green < 0)
        {
            green = 0;
        }
        else
        {
            green = image1.pixels[i].green - image2.pixels[i].green;
        }

        if ((int)(unsigned char)image1.pixels[i].red - (int)(unsigned char)image2.pixels[i].red < 0)
        {
            red = 0;
        }
        else
        {
            red = image1.pixels[i].red - image2.pixels[i].red;
        }

        Pixel pixel(blue, green, red);
        image.addPixel(pixel);
    }

    return image;
}

Image overlay(Image image1, string path2)
{
    Image image2 = readFile(path2);
    Image image(image1.header);

    for (int i = 0; i < image.width * image.height; i++)
    {
        char blue;
        char green;
        char red;

        if (image2.pixels[i].normBlue <= 0.5f)
        {
            blue = (2 * image1.pixels[i].normBlue * image2.pixels[i].normBlue) * 255 + 0.5f;
        }
        else
        {
            blue = (1 - (2 * (1 - image1.pixels[i].normBlue) * (1 - image2.pixels[i].normBlue))) * 255 + 0.5f;
        }

        if (image2.pixels[i].normGreen <= 0.5f)
        {
            green = (2 * image1.pixels[i].normGreen * image2.pixels[i].normGreen) * 255 + 0.5f;
        }
        else
        {
            green = (1 - (2 * (1 - image1.pixels[i].normGreen) * (1 - image2.pixels[i].normGreen))) * 255 + 0.5f;
        }

        if (image2.pixels[i].normRed <= 0.5f)
        {
            red = (2 * image1.pixels[i].normRed * image2.pixels[i].normRed) * 255 + 0.5f;
        }
        else
        {
            red = (1 - (2 * (1 - image1.pixels[i].normRed) * (1 - image2.pixels[i].normRed))) * 255 + 0.5f;
        }

        Pixel pixel(blue, green, red);
        image.addPixel(pixel);
    }

    return image;
}

Image screen(Image image1, string path2)
{
    Image image2 = readFile(path2);
    Image image(image1.header);

    for (int i = 0; i < image.width * image.height; i++)
    {
        char blue = (1 - ((1 - image2.pixels[i].normBlue) * (1 - image1.pixels[i].normBlue))) * 255 + 0.5f;

        char green = (1 - ((1 - image2.pixels[i].normGreen) * (1 - image1.pixels[i].normGreen))) * 255 + 0.5f;

        char red = (1 - ((1 - image2.pixels[i].normRed) * (1 - image1.pixels[i].normRed))) * 255 + 0.5f;

        Pixel pixel(blue, green, red);
        image.addPixel(pixel);
    }

    return image;
}

Image combine(Image image1, string path2, string path3)
{
    Image image2 = readFile(path2);
    Image image3 = readFile(path3);
    Image image(image1.header);

    for (int i = 0; i < image1.width * image1.height; i++)
    {
        char blue = image3.pixels[i].blue;

        char green = image2.pixels[i].green;

        char red = image1.pixels[i].red;

        Pixel pixel(blue, green, red);
        image.addPixel(pixel);
    }

    return image;
}

Image flip(Image image1)
{
    Image image(image1.header);

    for (int i = 0; i < image1.width * image1.height; i++)
    {
        char blue = image1.pixels[image1.width * image1.height - 1 - i].blue;

        char green = image1.pixels[image1.width * image1.height - 1 - i].green;

        char red = image1.pixels[image1.width * image1.height - 1 - i].red;

        Pixel pixel(blue, green, red);
        image.addPixel(pixel);
    }

    return image;
}

Image onlyblue(Image image1)
{
    Image image(image1.header);

    for (int i = 0; i < image1.width * image1.height; i++)
    {
        char blue = image1.pixels[i].blue;

        Pixel pixel(blue, blue, blue);
        image.addPixel(pixel);
    }

    return image;
}

Image onlygreen(Image image1)
{
    Image image(image1.header);

    for (int i = 0; i < image1.width * image1.height; i++)
    {
        char green = image1.pixels[i].green;

        Pixel pixel(green, green, green);
        image.addPixel(pixel);
    }

    return image;
}

Image onlyred(Image image1)
{
    Image image(image1.header);

    for (int i = 0; i < image1.width * image1.height; i++)
    {
        char red = image1.pixels[i].red;

        Pixel pixel(red, red, red);
        image.addPixel(pixel);
    }

    return image;
}

Image addblue(Image image1, int amount)
{
    Image image(image1.header);

    for (int i = 0; i < image.width * image.height; i++)
    {
        char blue;
        char green;
        char red;

        if ((int)(unsigned char)image1.pixels[i].blue + amount > 255)
        {
            blue = 255;
        }
        else if ((int)(unsigned char)image1.pixels[i].blue + amount < 0)
        {
            blue = 0;
        }
        else
        {
            blue = image1.pixels[i].blue + amount;
        }

        green = image1.pixels[i].green;

        red = image1.pixels[i].red;

        Pixel pixel(blue, green, red);
        image.addPixel(pixel);
    }

    return image;
}

Image addgreen(Image image1, int amount)
{
    Image image(image1.header);

    for (int i = 0; i < image.width * image.height; i++)
    {
        char blue;
        char green;
        char red;

        blue = image1.pixels[i].blue;

        if ((int)(unsigned char)image1.pixels[i].green + amount > 255)
        {
            green = 255;
        }
        else if ((int)(unsigned char)image1.pixels[i].green + amount < 0)
        {
            green = 0;
        }
        else
        {
            green = image1.pixels[i].green + amount;
        }

        red = image1.pixels[i].red;

        Pixel pixel(blue, green, red);
        image.addPixel(pixel);
    }

    return image;
}

Image addred(Image image1, int amount)
{
    Image image(image1.header);

    for (int i = 0; i < image.width * image.height; i++)
    {
        char blue;
        char green;
        char red;

        blue = image1.pixels[i].blue;

        green = image1.pixels[i].green;

        if ((int)(unsigned char)image1.pixels[i].red + amount > 255)
        {
            red = 255;
        }
        else if ((int)(unsigned char)image1.pixels[i].red + amount < 0)
        {
            red = 0;
        }
        else
        {
            red = image1.pixels[i].red + amount;
        }

        Pixel pixel(blue, green, red);
        image.addPixel(pixel);
    }

    return image;
}

Image scaleblue(Image image1, int amount)
{
    Image image(image1.header);

    for (int i = 0; i < image.width * image.height; i++)
    {
        char blue;
        if (image1.pixels[i].normBlue * amount > 1.0f)
        {
            blue = 255;
        }
        else
        {
            blue = (image1.pixels[i].normBlue * amount) * 255 + 0.5f;
        }

        char green = image1.pixels[i].green;

        char red = image1.pixels[i].red;

        Pixel pixel(blue, green, red);
        image.addPixel(pixel);
    }

    return image;
}

Image scalegreen(Image image1, int amount)
{
    Image image(image1.header);

    for (int i = 0; i < image.width * image.height; i++)
    {
        char blue = image1.pixels[i].blue;

        char green;
        if (image1.pixels[i].normGreen * amount > 1.0f)
        {
            green = 255;
        }
        else
        {
            green = (image1.pixels[i].normGreen * amount) * 255 + 0.5f;
        }

        char red = image1.pixels[i].red;

        Pixel pixel(blue, green, red);
        image.addPixel(pixel);
    }

    return image;
}

Image scalered(Image image1, int amount)
{
    Image image(image1.header);

    for (int i = 0; i < image.width * image.height; i++)
    {
        char blue = image1.pixels[i].blue;

        char green = image1.pixels[i].green;

        char red;
        if (image1.pixels[i].normRed * amount > 1.0f)
        {
            red = 255;
        }
        else
        {
            red = (image1.pixels[i].normRed * amount) * 255 + 0.5f;
        }

        Pixel pixel(blue, green, red);
        image.addPixel(pixel);
    }

    return image;
}