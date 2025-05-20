//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 640
#define HEIGHT 480

unsigned char image[WIDTH * HEIGHT * 3];

unsigned char* loadImage(const char* fileName)
{
    unsigned char* pData = NULL;
    FILE* fp = fopen(fileName, "rb");
    if (fp != NULL)
    {
        fseek(fp, 0, SEEK_END);
        long size = ftell(fp);
        fseek(fp, 0, SEEK_SET);
        pData = (unsigned char*)calloc(size, 1);
        if (pData != NULL)
        {
            fread(pData, 1, size, fp);
        }
        fclose(fp);
    }
    return pData;
}

void saveImage(const char* fileName, unsigned char* pData, int width, int height)
{
    FILE* fp = fopen(fileName, "wb");
    if (fp != NULL)
    {
        fwrite(pData, 1, width * height * 3, fp);
        fclose(fp);
    }
}

void flipImage(unsigned char* pData, int width, int height)
{
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width / 2; ++x)
        {
            for (int c = 0; c < 3; ++c)
            {
                int index1 = (y * width + x) * 3 + c;
                int index2 = (y * width + (width - x - 1)) * 3 + c;
                unsigned char tmp = pData[index1];
                pData[index1] = pData[index2];
                pData[index2] = tmp;
            }
        }
    }
}

void adjustBrightness(unsigned char* pData, int width, int height, int level)
{
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            for (int c = 0; c < 3; ++c)
            {
                int index = (y * width + x) * 3 + c;
                int value = pData[index] + level;
                if (value < 0)
                {
                    value = 0;
                }
                else if (value > 255)
                {
                    value = 255;
                }
                pData[index] = (unsigned char)value;
            }
        }
    }
}

void adjustContrast(unsigned char* pData, int width, int height, float level)
{
    float factor = (259.0f * (level + 255.0f)) / (255.0f * (259.0f - level));
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            for (int c = 0; c < 3; ++c)
            {
                int index = (y * width + x) * 3 + c;
                int value = (int)(pData[index] * factor - 128.0f * factor + 128.0f);
                if (value < 0)
                {
                    value = 0;
                }
                else if (value > 255)
                {
                    value = 255;
                }
                pData[index] = (unsigned char)value;
            }
        }
    }
}

int main()
{
    // load image
    unsigned char* pData = loadImage("lena.raw");
    if (pData == NULL)
    {
        return -1;
    }

    // flip image horizontally
    flipImage(pData, WIDTH, HEIGHT);

    // adjust brightness
    adjustBrightness(pData, WIDTH, HEIGHT, 50);

    // adjust contrast
    adjustContrast(pData, WIDTH, HEIGHT, 50.0f);

    // save image
    saveImage("output.raw", pData, WIDTH, HEIGHT);

    free(pData);
    return 0;
}