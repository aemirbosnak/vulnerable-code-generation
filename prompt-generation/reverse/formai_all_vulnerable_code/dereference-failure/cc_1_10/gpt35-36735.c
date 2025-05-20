//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 640
#define HEIGHT 480

unsigned char input[HEIGHT][WIDTH];
unsigned char output[HEIGHT][WIDTH];

void readImage(char* filename)
{
    FILE* file;
    char* buffer;
    long fileLen;

    file = fopen(filename, "rb");
    fseek(file, 0, SEEK_END);
    fileLen = ftell(file);
    fseek(file, 0, SEEK_SET);

    buffer = (char*) malloc(fileLen);

    fread(buffer, fileLen, 1, file);

    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            input[i][j] = buffer[i*WIDTH+j];
        }
    }
    fclose(file);
}

void writeImage(char* filename)
{
    FILE* file;
    char* buffer;
    long fileLen;

    buffer = (char*) calloc(WIDTH * HEIGHT, 1);

    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            buffer[i*WIDTH+j] = output[i][j];
        }
    }
    file = fopen(filename, "wb");
    fwrite(buffer, WIDTH*HEIGHT, 1, file);
    fclose(file);
}

unsigned char clip(int x)
{
    if(x < 0)
    {
        return 0;
    }
    if(x > 255)
    {
        return 255;
    }
    return (unsigned char) x;
}

void flipVertical()
{
    for(int i = 0; i < HEIGHT/2; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            unsigned char tmp = input[i][j];
            input[i][j] = input[HEIGHT-i-1][j];
            input[HEIGHT-i-1][j] = tmp;
        }
    }
}

void adjustBrightness(int delta)
{
    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
           output[i][j] = clip(input[i][j] + delta);
        }
    }
}

void adjustContrast(float alpha)
{
    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            output[i][j] = clip(alpha * (input[i][j] - 128) + 128);
        }
    }
}

int main()
{
    readImage("image.raw");

    flipVertical();
    writeImage("flip_vertical.raw");

    adjustBrightness(-50);
    writeImage("brightness-50.raw");

    adjustBrightness(50);
    writeImage("brightness+50.raw");

    adjustContrast(0.5);
    writeImage("contrast+0.5.raw");

    adjustContrast(2.0);
    writeImage("contrast+2.0.raw");

    return 0;
}