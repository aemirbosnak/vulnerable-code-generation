//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define WIDTH 100
#define HEIGHT 50

int image[HEIGHT][WIDTH];

void readImage(char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Cannot open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char* buffer = (char*)malloc(size);
    if (buffer == NULL) {
        printf("Cannot allocate memory\n");
        exit(1);
    }

    fread(buffer, 1, size, fp);
    fclose(fp);

    int i = 0;
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int value = (int)buffer[i++];
            image[y][x] = value;
        }
    }
}

void printAsciiArt(int threshold) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (image[y][x] >= threshold) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <image_filename> <threshold>\n", argv[0]);
        return 1;
    }

    readImage(argv[1]);

    int threshold = atoi(argv[2]);

    printAsciiArt(threshold);

    return 0;
}