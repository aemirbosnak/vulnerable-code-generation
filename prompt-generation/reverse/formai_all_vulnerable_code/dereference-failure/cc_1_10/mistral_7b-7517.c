//MISTRAL-7B DATASET v1.0 Category: Pixel Art Generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 10
#define HEIGHT 10
#define PALETTE_SIZE 3

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel;

pixel palette[PALETTE_SIZE] = { { 255, 0, 0 }, { 0, 255, 0 }, { 0, 0, 255 } };

void generate_cat(char mood[5], pixel *image) {
    int x, y, i;

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            if (x < 3 || x > WIDTH - 3 || y < 3 || y > HEIGHT - 3) {
                image[y * WIDTH + x].r = image[y * WIDTH + x].g = image[y * WIDTH + x].b = 0;
                continue;
            }

            if (strcmp(mood, "happy") == 0) {
                i = x < 5 ? y % 2 == 0 ? 0 : 1 : 2;
                image[y * WIDTH + x] = palette[i];
            } else if (strcmp(mood, "sad") == 0) {
                image[y * WIDTH + x].r -= 50;
                image[y * WIDTH + x].g -= 50;
                image[y * WIDTH + x].b -= 50;
            } else if (strcmp(mood, "angry") == 0) {
                image[y * WIDTH + x].r += 50;
                image[y * WIDTH + x].g += 50;
                image[y * WIDTH + x].b += 50;
            }
        }
    }
}

int main() {
    char mood[5];
    pixel *image = malloc(WIDTH * HEIGHT * sizeof(pixel));

    printf("Enter the cat's mood (happy, sad, or angry): ");
    scanf("%s", mood);

    generate_cat(mood, image);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%d %d %d", image[y * WIDTH + x].r, image[y * WIDTH + x].g, image[y * WIDTH + x].b);
        }
        printf("\n");
    }

    free(image);
    return 0;
}