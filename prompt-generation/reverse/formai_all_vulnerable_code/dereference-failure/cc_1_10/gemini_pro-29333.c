//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char uchar;

int main() {
    // Load the image
    FILE *file = fopen("image.bmp", "rb");
    if (!file) {
        printf("Error opening image file\n");
        return 1;
    }

    fseek(file, 10, SEEK_SET);
    int width, height;
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);

    int padding = (4 - (width * 3) % 4) % 4;

    int size = width * height * 3 + height * padding;
    uchar *data = malloc(size);
    fread(data, 1, size, file);
    fclose(file);

    // Create a new image
    FILE *newFile = fopen("new_image.bmp", "wb");
    if (!newFile) {
        printf("Error opening new image file\n");
        return 1;
    }

    // Write the header
    fwrite("BM", 1, 2, newFile);
    int fileSize = size + 14 + 40;
    fwrite(&fileSize, sizeof(int), 1, newFile);
    int reserved = 0;
    fwrite(&reserved, sizeof(int), 1, newFile);
    int offset = 14 + 40;
    fwrite(&offset, sizeof(int), 1, newFile);

    // Write the DIB header
    int dibHeaderSize = 40;
    fwrite(&dibHeaderSize, sizeof(int), 1, newFile);
    fwrite(&width, sizeof(int), 1, newFile);
    fwrite(&height, sizeof(int), 1, newFile);
    short planes = 1;
    fwrite(&planes, sizeof(short), 1, newFile);
    short bitsPerPixel = 24;
    fwrite(&bitsPerPixel, sizeof(short), 1, newFile);
    int compression = 0;
    fwrite(&compression, sizeof(int), 1, newFile);
    int imageSize = size;
    fwrite(&imageSize, sizeof(int), 1, newFile);
    int xResolution = 2835;
    fwrite(&xResolution, sizeof(int), 1, newFile);
    int yResolution = 2835;
    fwrite(&yResolution, sizeof(int), 1, newFile);
    int numColors = 0;
    fwrite(&numColors, sizeof(int), 1, newFile);
    int importantColors = 0;
    fwrite(&importantColors, sizeof(int), 1, newFile);

    // Write the image data
    fwrite(data, 1, size, newFile);

    // Close the files
    fclose(newFile);
    free(data);

    return 0;
}