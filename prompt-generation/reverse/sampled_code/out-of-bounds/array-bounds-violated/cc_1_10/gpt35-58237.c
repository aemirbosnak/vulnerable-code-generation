//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 78
#define HEIGHT 45

int main()
{
    char ascii[HEIGHT][WIDTH];

    // load image file
    FILE *fp = fopen("image.bmp", "rb");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fseek(fp, 18, SEEK_SET);

    int imgWidth = 0, imgHeight = 0;
    fread(&imgWidth, sizeof(int), 1, fp);
    fread(&imgHeight, sizeof(int), 1, fp);

    fseek(fp, 54, SEEK_SET);

    unsigned char imgData[imgWidth][imgHeight][3];

    // read image data
    for (int i = 0; i < imgHeight; i++) {
        for (int j = 0; j < imgWidth; j++) {
            fread(&imgData[i][j][2], sizeof(unsigned char), 1, fp);
            fread(&imgData[i][j][1], sizeof(unsigned char), 1, fp);
            fread(&imgData[i][j][0], sizeof(unsigned char), 1, fp);
        }

        fseek(fp, (imgWidth % 4), SEEK_CUR);
    }

    fclose(fp);

    // convert to ascii art
    const char *shadeTable = " .-:=+*#%@ ";

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int x = j * (imgWidth - 1) / (WIDTH - 1);
            int y = i * (imgHeight - 1) / (HEIGHT - 1);

            int r = imgData[y][x][0];
            int g = imgData[y][x][1];
            int b = imgData[y][x][2];

            int brightness = (r + g + b) / 3;

            int shade = brightness / 25;

            if (shade < 0) shade = 0;
            if (shade > 9) shade = 9;

            ascii[i][j] = shadeTable[shade];
        }
    }

    // output ascii art
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", ascii[i][j]);
        }

        printf("\n");
    }

    return 0;
}