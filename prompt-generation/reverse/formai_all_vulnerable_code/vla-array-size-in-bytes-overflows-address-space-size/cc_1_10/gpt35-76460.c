//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void drawPixel(char pixel) {
    switch (pixel) {
        case '0': printf(":"); break;
        case '1': printf("."); break;
    }
}

void generatePixelArt(int width, int height) {
    srand((unsigned int) time(NULL));
    char pixels[height][width];
    int i, j, k;

    // randomly generate pixel values
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            k = rand() % 2;
            pixels[i][j] = k + '0'; // convert to ASCII code
        }
    }

    // draw the pixel art
    printf("\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            drawPixel(pixels[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int width, height;

    printf("Welcome to the Funny C Pixel Art Generator!\n");
    printf("Enter the width of the pixel art: ");
    scanf("%d", &width);
    printf("Enter the height of the pixel art: ");
    scanf("%d", &height);

    generatePixelArt(width, height);

    printf("Thank you for using the Funny C Pixel Art Generator!\n");

    return 0;
}