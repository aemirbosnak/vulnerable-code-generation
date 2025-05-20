//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 60

#define ASCIILEVELS 10 // number of ASCII characters to convert to

char ascii[ASCIILEVELS + 1] = "@#*+=-:. "; // ASCII characters used for the conversion, in order of brightness

void convertImageToASCII(int** image, int width, int height);
int brightnessToASCII(int brightness);

int main(int argc, char *argv[]) {
    // load image from file
    if (argc < 2) {
        printf("usage: %s [image file]\n", argv[0]);
        return 1;
    }
    FILE *imageFile = fopen(argv[1], "r");
    if (!imageFile) {
        printf("Unable to open file %s\n", argv[1]);
        return 1;
    }
    
    // initialize image array
    int **image = (int**)malloc(HEIGHT * sizeof(int*));
    for (int i = 0; i < HEIGHT; i++) {
        image[i] = (int*)malloc(WIDTH * sizeof(int));
    }
    
    // read image pixel values into array
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            int value;
            fscanf(imageFile, "%d", &value);
            image[y][x] = value;
        }
    }
    
    // close file
    fclose(imageFile);
    
    // convert image to ASCII art
    convertImageToASCII(image, WIDTH, HEIGHT);
    
    // free memory
    for (int i = 0; i < HEIGHT; i++) {
        free(image[i]);
    }
    free(image);
    
    return 0;
}

/*
 * Convert the input image array to ASCII art and print it to the console
 * image: the input image array
 * width: the width of the image in pixels
 * height: the height of the image in pixels
 */
void convertImageToASCII(int** image, int width, int height) {
    int x, y;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            int brightness = image[y][x];
            int asciiIndex = brightnessToASCII(brightness);
            char asciiChar = ascii[asciiIndex];
            printf("%c", asciiChar);
        }
        printf("\n");
    }
}

/*
 * Convert the input brightness value to an index in the ascii array
 * brightness: the input brightness value (0-255)
 */
int brightnessToASCII(int brightness) {
    int levelSize = 256 / ASCIILEVELS; // the brightness range for each level of ASCII character
    int level = brightness / levelSize;
    if (level >= ASCIILEVELS) {
        level = ASCIILEVELS - 1;
    }
    return level;
}