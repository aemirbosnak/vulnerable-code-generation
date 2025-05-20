//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print a pixel art image
void print_pixel_art(char *image, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%c", image[y * width + x]);
        }
        printf("\n");
    }
}

// Function to generate a random pixel art image
void generate_pixel_art(char *image, int width, int height) {
    srand(time(NULL));
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int color = rand() % 6;
            switch (color) {
                case 0:
                    image[y * width + x] = '.';
                    break;
                case 1:
                    image[y * width + x] = 'o';
                    break;
                case 2:
                    image[y * width + x] = 'x';
                    break;
                case 3:
                    image[y * width + x] = '#';
                    break;
                case 4:
                    image[y * width + x] = '+';
                    break;
                case 5:
                    image[y * width + x] = '-';
                    break;
            }
        }
    }
}

int main() {
    int width, height;
    printf("Enter the width of the pixel art image: ");
    scanf("%d", &width);
    printf("Enter the height of the pixel art image: ");
    scanf("%d", &height);

    char *image = malloc(width * height);
    generate_pixel_art(image, width, height);
    print_pixel_art(image, width, height);

    free(image);
    return 0;
}