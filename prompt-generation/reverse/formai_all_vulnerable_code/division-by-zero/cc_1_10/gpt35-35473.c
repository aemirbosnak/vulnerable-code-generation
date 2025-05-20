//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generatePixelArt(int pixels, int colors);

int main() {
    int num_pixels, num_colors;

    printf("Enter number of pixels: ");
    scanf("%d", &num_pixels);

    printf("Enter number of colors: ");
    scanf("%d", &num_colors);

    generatePixelArt(num_pixels, num_colors);

    return 0;
}

void generatePixelArt(int pixels, int colors) {
    int pixel[pixels];
    int i, j, k;
    srand(time(NULL));

    for (i = 0; i < pixels; i++) {
        pixel[i] = rand() % colors + 1;
    }

    for (i = 0; i < pixels; i++) {
        if (pixel[i] == 1) {
            printf("#");
        } else if (pixel[i] == 2) {
            printf("@");
        } else if (pixel[i] == 3) {
            printf("*");
        } else if (pixel[i] == 4) {
            printf("+");
        } else if (pixel[i] == 5) {
            printf("-");
        } else if (pixel[i] == 6) {
            printf(":");
        } else if (pixel[i] == 7) {
            printf("=");
        } else if (pixel[i] == 8) {
            printf("&");
        } else if (pixel[i] == 9) {
            printf("$");
        } else {
            printf(" ");
        }
        if ((i+1) % (pixels/10) == 0) {
            printf("\n");
        }
    }
}