//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <math.h>

#define MAX_WIDTH 256
#define MAX_HEIGHT 256

void convertToGrayscale(unsigned char *img, int width, int height) {
    unsigned char grayValue;

    for (int i = 0; i < width * height * 3; i += 3) {
        grayValue = (0.299 * img[i]) + (0.587 * img[i+1]) + (0.114 * img[i+2]);
        img[i] = grayValue;
        img[i+1] = grayValue;
        img[i+2] = grayValue;
    }
}

int main(int argc, char **argv) {
    setlocale(LC_ALL, "");

    FILE *inputFile, *outputFile;
    unsigned char img[MAX_HEIGHT][MAX_WIDTH][3];
    int width, height, gray;
    wchar_t c;

    inputFile = fopen(argv[1], "rb");
    outputFile = fopen(argv[2], "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Read header
    char header[128];
    fgets(header, 128, inputFile);
    if (header[0] != 'P' || header[1] != '6') {
        printf("Invalid image format\n");
        return 1;
    }
    fscanf(inputFile, "%d %d %d\n", &width, &height, &gray);

    // Read image data
    unsigned char *p = (unsigned char *)img;
    size_t bytesRead;
    do {
        bytesRead = fread(p, 1, 3 * width, inputFile);
        p += bytesRead;
    } while (bytesRead == 3 * width);

    fclose(inputFile);

    // Convert to grayscale
    convertToGrayscale((unsigned char *)img, width, height);

    // Scale image down
    int scaleRatio = 4;
    int newWidth = width / scaleRatio, newHeight = height / scaleRatio;
    unsigned char scaledImg[MAX_HEIGHT][MAX_WIDTH];

    for (int i = 0; i < newHeight; i++) {
        for (int j = 0; j < newWidth; j++) {
            int sum = 0;
            for (int k = 0; k < scaleRatio; k++) {
                for (int l = 0; l < scaleRatio; l++) {
                    sum += img[i * scaleRatio + k][j * scaleRatio + l][0];
                }
            }
            scaledImg[i][j] = sum / (scaleRatio * scaleRatio);
        }
    }

    // Convert to ASCII art
    wchar_t asciiChars[11] = L" .,:;ox%#@";
    int numChars = 10;
    double charRatio = (numChars - 1) / 255.0;

    for (int i = 0; i < newHeight; i++) {
        for (int j = 0; j < newWidth; j++) {
            int index = round(scaledImg[i][j] * charRatio);
            c = asciiChars[index];
            fwrite(&c, sizeof(wchar_t), 1, outputFile);
        }
        fwrite("\n", sizeof(wchar_t), 1, outputFile);
    }

    fclose(outputFile);

    return 0;
}