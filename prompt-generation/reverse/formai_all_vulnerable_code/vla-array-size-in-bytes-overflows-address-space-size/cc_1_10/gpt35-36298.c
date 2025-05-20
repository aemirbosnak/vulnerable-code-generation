//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct pixel {
    int red;
    int green;
    int blue;
} Pixel;

int main() {
    int width, height;
    printf("Enter the width of the image: ");
    scanf("%d", &width);
    printf("Enter the height of the image: ");
    scanf("%d", &height);

    Pixel image[width][height];
    srand(time(NULL)); // seed the random number generator

    // loop through each pixel in the image
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            // generate a random color for the pixel
            image[x][y].red = rand() % 256;
            image[x][y].green = rand() % 256;
            image[x][y].blue = rand() % 256;
        }
    }

    // print the image as ASCII art
    printf("\n");
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // choose a character to represent each pixel based on its brightness
            int brightness = (image[x][y].red + image[x][y].green + image[x][y].blue) / 3;
            char c;
            if (brightness < 64) {
                c = ' ';
            } else if (brightness < 128) {
                c = '.';
            } else if (brightness < 192) {
                c = '*';
            } else {
                c = '#';
            }
            // print the character in the appropriate color
            printf("\033[38;2;%d;%d;%dm%c\033[0m", image[x][y].red, image[x][y].green, image[x][y].blue, c);
        }
        printf("\n");
    }

    return 0;
}