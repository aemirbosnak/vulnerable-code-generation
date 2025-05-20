//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define WIDTH 500
#define HEIGHT 500

#define RGB_RED 0x00FF0000
#define RGB_GREEN 0x0000FF00
#define RGB_BLUE 0x000000FF

struct Pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

void generateRandomMatrix(struct Pixel *matrix) {
    srand(time(NULL));
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        matrix[i].red = rand() % 256;
        matrix[i].green = rand() % 256;
        matrix[i].blue = rand() % 256;
    }
}

void embedMessage(struct Pixel *matrix, unsigned char *message, int messageLength) {
    int index = 0;
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        if (index < messageLength) {
            matrix[i].red = matrix[i].red ^ message[index];
            index++;
        }
    }
}

void extractMessage(struct Pixel *matrix, unsigned char *message, int messageLength) {
    int index = 0;
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        if (index < messageLength) {
            message[index] = matrix[i].red ^ message[index];
            index++;
        }
    }
}

int main() {
    struct Pixel *matrix = (struct Pixel *)malloc(WIDTH * HEIGHT * sizeof(struct Pixel));
    generateRandomMatrix(matrix);

    unsigned char *message = "Hello, world!";
    int messageLength = strlen(message);

    embedMessage(matrix, message, messageLength);

    FILE *file = fopen("image.bmp", "wb");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    fwrite(matrix, sizeof(struct Pixel), WIDTH * HEIGHT, file);

    fclose(file);

    return 0;
}