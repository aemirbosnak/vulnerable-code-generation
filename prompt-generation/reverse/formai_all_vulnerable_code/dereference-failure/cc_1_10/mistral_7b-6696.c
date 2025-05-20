//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 10
#define HEIGHT 5

void print_ascii_char(int value) {
    if (value < 0) {
        printf("   ");
    } else if (value >= 32 && value <= 126) {
        putchar(value);
    } else {
        printf(" ? ");
    }
}

void print_ascii_row(int* row, int width) {
    for (int i = 0; i < width; i++) {
        print_ascii_char(row[i]);
    }
    printf("\n");
}

void print_ascii_image(int** image, int width, int height) {
    for (int i = 0; i < height; i++) {
        print_ascii_row(image[i], width);
    }
}

int main() {
    int** image = (int**)malloc(HEIGHT * sizeof(int*));

    for (int i = 0; i < HEIGHT; i++) {
        image[i] = (int*)calloc(WIDTH, sizeof(int));

        for (int j = 0; j < WIDTH; j++) {
            image[i][j] = (i % 2 == 0) ? (j % 2 == 0 ? 48 : 32) : (j % 2 == 0 ? 64 : 124);
        }
    }

    print_ascii_image(image, WIDTH, HEIGHT);

    for (int i = 0; i < HEIGHT; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}