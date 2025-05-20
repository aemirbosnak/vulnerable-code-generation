//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertToAscii(char* image) {
    FILE* fp = fopen(image, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file!\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    rewind(fp);

    unsigned char* buffer = (unsigned char*)malloc(sizeof(unsigned char) * size);
    fread(buffer, size, 1, fp);

    int width = buffer[18] + (buffer[19] << 8);
    int height = buffer[22] + (buffer[23] << 8);
    int start = buffer[10] + (buffer[11] << 8);
    int bpp = buffer[28];

    unsigned char* pixels = (unsigned char*)malloc(sizeof(unsigned char) * width * height * bpp / 8);

    memcpy(pixels, buffer + start, sizeof(unsigned char) * width * height * bpp / 8);

    fclose(fp);
    free(buffer);

    char asciiChars[11] = {' ', '.', '\'', ':', 'o', '&', '8', '#', '@', '%', '\0'};
    int count = strlen(asciiChars);

    int pixelCount = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int intensity = 0;
            for (int k = 0; k < bpp / 8; k++) {
                intensity += *(pixels + pixelCount + k);
            }
            intensity /= bpp / 8;
            int index = intensity * count / 256;
            printf("%c", asciiChars[index]);
            pixelCount += bpp / 8;
        }
        printf("\n");
    }

    free(pixels);
}

int main() {
    convertToAscii("example_image.bmp");
    return 0;
}