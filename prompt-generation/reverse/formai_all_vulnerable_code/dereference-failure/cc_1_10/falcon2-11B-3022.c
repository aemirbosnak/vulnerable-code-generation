//Falcon2-11B DATASET v1.0 Category: Image to ASCII art converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXELS 10000
#define MAX_WIDTH 50
#define MAX_HEIGHT 50

typedef struct {
    int x;
    int y;
    int r;
    int g;
    int b;
} Pixel;

void drawPixel(Pixel* pixels, int width, int height, char* buffer, int index) {
    int x = index % width;
    int y = index / width;

    if (x < 0 || y < 0 || x >= width || y >= height) {
        return;
    }

    int red = pixels[index].r;
    int green = pixels[index].g;
    int blue = pixels[index].b;

    char redChar[3];
    char greenChar[3];
    char blueChar[3];

    sprintf(redChar, "%d", red);
    sprintf(greenChar, "%d", green);
    sprintf(blueChar, "%d", blue);

    int redIndex = index * 3;
    int greenIndex = redIndex + 1;
    int blueIndex = greenIndex + 1;

    buffer[redIndex] = redChar[0];
    buffer[redIndex + 1] = redChar[1];
    buffer[redIndex + 2] = redChar[2];

    buffer[greenIndex] = greenChar[0];
    buffer[greenIndex + 1] = greenChar[1];
    buffer[greenIndex + 2] = greenChar[2];

    buffer[blueIndex] = blueChar[0];
    buffer[blueIndex + 1] = blueChar[1];
    buffer[blueIndex + 2] = blueChar[2];
}

int main() {
    char buffer[MAX_PIXELS * MAX_WIDTH * MAX_HEIGHT * 3];

    int width = 0;
    int height = 0;
    int pixelsCount = 0;

    FILE* file = fopen("image.jpg", "rb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    Pixel* pixels = malloc(fileSize / sizeof(Pixel));
    if (pixels == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        fclose(file);
        return 1;
    }

    while (fileSize > pixelsCount) {
        Pixel pixel;
        fread(&pixel, sizeof(Pixel), 1, file);
        pixels[pixelsCount] = pixel;
        pixelsCount++;
    }

    fclose(file);

    width = pixelsCount % MAX_WIDTH;
    height = pixelsCount / MAX_WIDTH;

    int index = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            drawPixel(pixels, width, height, buffer, index++);
        }
    }

    printf("Image to ASCII art conversion completed!\n");
    printf("%s", buffer);

    return 0;
}