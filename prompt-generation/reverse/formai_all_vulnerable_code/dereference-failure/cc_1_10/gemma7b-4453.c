//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct Pixel
{
    int r, g, b, a;
} Pixel;

void encode(Pixel **pixels, int size, char *msg)
{
    int i = 0, j = 0, k = 0;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            pixels[i][j].r = pixels[i][j].r & 0xFC | (msg[k] & 0x03) << 2;
            pixels[i][j].g = pixels[i][j].g & 0xFC | (msg[k] & 0x0C) << 2;
            pixels[i][j].b = pixels[i][j].b & 0xFC | (msg[k] & 0x30) << 2;
            k++;
        }
    }
}

void decode(Pixel **pixels, int size, char **msg)
{
    int i = 0, j = 0, k = 0;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            msg[k] = (pixels[i][j].r & 0x03) >> 2 | (pixels[i][j].g & 0x0C) >> 2 | (pixels[i][j].b & 0x30) >> 2;
            k++;
        }
    }
}

int main()
{
    Pixel **pixels = (Pixel **)malloc(MAX_SIZE * sizeof(Pixel *));
    for (int i = 0; i < MAX_SIZE; i++)
    {
        pixels[i] = (Pixel *)malloc(MAX_SIZE * sizeof(Pixel));
    }

    char msg[] = "SECRET MESSAGE";

    encode(pixels, MAX_SIZE, msg);

    char **decoded_msg = (char **)malloc(MAX_SIZE * sizeof(char *));
    for (int i = 0; i < MAX_SIZE; i++)
    {
        decoded_msg[i] = (char *)malloc(MAX_SIZE * sizeof(char));
    }

    decode(pixels, MAX_SIZE, decoded_msg);

    printf("Decoded message: %s\n", decoded_msg[0]);

    return 0;
}