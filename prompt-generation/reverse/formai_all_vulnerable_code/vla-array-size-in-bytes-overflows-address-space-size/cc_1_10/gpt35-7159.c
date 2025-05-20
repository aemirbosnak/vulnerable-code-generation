//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Ken Thompson
#include <stdio.h>

#define ASCII_RATIO 0.1  // change this value for different ASCII output

int main() {
    FILE *fp;
    char filename[100];
    printf("Enter the name of the image file: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    // read image file header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp);

    // extract image dimensions
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // calculate padding
    int padding = (4 - (width * 3) % 4) % 4;

    // create buffer for pixel data
    unsigned char buffer[height][width][3];

    // read pixel data into buffer
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fread(buffer[i][j], sizeof(unsigned char), 3, fp);
        }
        fseek(fp, padding, SEEK_CUR);
    }

    // close the file
    fclose(fp);

    // print ASCII art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            float intensity = 0.3 * buffer[i][j][2] + 0.59 * buffer[i][j][1] + 0.11 * buffer[i][j][0];
            char ascii = intensity * ASCII_RATIO + 32;
            printf("%c%c", ascii, ascii);
        }
        printf("\n");
    }

    return 0;
}