//Falcon2-11B DATASET v1.0 Category: Image to ASCII art converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void convertImageToAsciiArt(FILE* inputFile, FILE* outputFile, int width, int height) {
    char* line = NULL;
    size_t len = 0;

    fseek(inputFile, 0, SEEK_END);
    len = ftell(inputFile);
    fseek(inputFile, 0, SEEK_SET);

    line = (char*) malloc(len + 1);
    fread(line, 1, len, inputFile);
    line[len] = '\0';

    char* pixel = strtok(line, " \n\r\t");

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (pixel == NULL) {
                break;
            }

            int pixelValue = atoi(pixel);
            if (pixelValue < 16) {
                fprintf(outputFile, " ");
            } else if (pixelValue < 32) {
                fprintf(outputFile, "=");
            } else if (pixelValue < 48) {
                fprintf(outputFile, "|");
            } else if (pixelValue < 58) {
                fprintf(outputFile, "-");
            } else if (pixelValue < 64) {
                fprintf(outputFile, "\\");
            } else if (pixelValue < 72) {
                fprintf(outputFile, "/");
            } else if (pixelValue < 78) {
                fprintf(outputFile, "\\");
            } else if (pixelValue < 84) {
                fprintf(outputFile, "/");
            } else if (pixelValue < 90) {
                fprintf(outputFile, "+");
            } else if (pixelValue < 96) {
                fprintf(outputFile, "@");
            } else if (pixelValue < 102) {
                fprintf(outputFile, "#");
            } else {
                fprintf(outputFile, "~");
            }

            pixel = strtok(NULL, " \n\r\t");
        }

        fprintf(outputFile, "\n");
        free(line);
    }
}

int main() {
    FILE* inputFile = fopen("image.bmp", "rb");
    FILE* outputFile = fopen("ascii_art.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    int width = 640;
    int height = 480;

    convertImageToAsciiArt(inputFile, outputFile, width, height);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}