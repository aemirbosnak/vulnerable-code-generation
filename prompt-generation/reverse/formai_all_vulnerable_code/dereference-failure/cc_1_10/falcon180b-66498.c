//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_CHARS "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"

void ascii_art(char* filename, int width, int height) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    unsigned char* buffer = (unsigned char*)malloc(filesize);
    fread(buffer, filesize, 1, fp);
    fclose(fp);

    int pixels = width * height;
    char* ascii = (char*)malloc(pixels * 3);

    int index = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int value = buffer[index++];

            int r = value >> 16 & 0xff;
            int g = value >> 8 & 0xff;
            int b = value & 0xff;

            int index2 = (int)((r + g + b) / 3 * (sizeof(ASCII_CHARS) - 1));
            ascii[index2 * 3] = ASCII_CHARS[index2];
            ascii[(index2 * 3) + 1] = ASCII_CHARS[index2];
            ascii[(index2 * 3) + 2] = ASCII_CHARS[index2];
        }
    }

    printf("ASCII art:\n");
    for (int i = 0; i < pixels * 3; i += 3) {
        printf("%c", ascii[i]);
    }

    free(buffer);
    free(ascii);
}

int main(int argc, char** argv) {
    if (argc!= 4) {
        printf("Usage: %s <filename> <width> <height>\n", argv[0]);
        return 1;
    }

    int width = atoi(argv[2]);
    int height = atoi(argv[3]);

    ascii_art(argv[1], width, height);

    return 0;
}