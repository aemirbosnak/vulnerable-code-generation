//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 80

void printASCII(char ascii[][WIDTH+1], int width, int height);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <image>\n", argv[0]);
        return 1;
    }

    FILE *f;
    if ((f = fopen(argv[1], "rb")) == NULL)
    {
        printf("Error opening image file.\n");
        return 1;
    }

    unsigned char header[54];
    if (fread(header, sizeof(unsigned char), 54, f) != 54 || header[0] != 'B' || header[1] != 'M')
    {
        printf("Not a BMP image.\n");
        return 1;
    }

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int rowSize = (width * 3 + 3) & ~3;
    unsigned char *data = (unsigned char*)malloc(rowSize * height);
    fread(data, sizeof(unsigned char), rowSize * height, f);
    fclose(f);

    char ascii[HEIGHT][WIDTH+1];
    memset(ascii, ' ', HEIGHT * (WIDTH + 1));

    int i;
    for (i = 0; i < height; i++)
    {
        int j;
        for (j = 0; j < width; j++)
        {
            int px = i * rowSize + j * 3;
            int b = data[px];
            int g = data[px + 1];
            int r = data[px + 2];
            int gray = (r + g + b) / 3;
            int c = gray * 10 / 256;
            if (c < 0)
                c = 0;
            if (c > 10)
                c = 10;
            ascii[i][j] = " .:-=+*#%@ "[c];
        }
    }

    printASCII(ascii, width, height);

    free(data);
    return 0;
}

void printASCII(char ascii[][WIDTH+1], int width, int height)
{
    int i;
    for (i = 0; i < height; i++)
        printf("%s\n", ascii[i]);
}