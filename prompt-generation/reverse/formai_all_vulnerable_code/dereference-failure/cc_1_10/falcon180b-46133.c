//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define WIDTH 512
#define HEIGHT 512
#define MAX_COLOR 255
#define IMAGE_SIZE WIDTH * HEIGHT
#define BITS_PER_PIXEL 8
#define BITS_PER_BYTE 8
#define BYTES_PER_LINE (IMAGE_SIZE / BITS_PER_BYTE)
#define BYTES_PER_PIXEL (BITS_PER_PIXEL / BITS_PER_BYTE)

struct pixel {
    char red;
    char green;
    char blue;
};

struct pixel *image;

void create_image() {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            int color = rand() % MAX_COLOR;
            image[i * WIDTH + j].red = (color >> 16) & 0xFF;
            image[i * WIDTH + j].green = (color >> 8) & 0xFF;
            image[i * WIDTH + j].blue = color & 0xFF;
        }
    }
}

void hide_message(char *message, int message_size) {
    int i, j, k, l;
    for (i = 0, k = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (k < message_size) {
                image[i * WIDTH + j].red += message[k];
                image[i * WIDTH + j].green += message[k];
                image[i * WIDTH + j].blue += message[k];
                k++;
            }
        }
    }
}

void show_image() {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", (image[i * WIDTH + j].red << 16) | (image[i * WIDTH + j].green << 8) | image[i * WIDTH + j].blue);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    image = (struct pixel *)malloc(IMAGE_SIZE * sizeof(struct pixel));
    create_image();
    char *message = "This is a secret message hidden in an image using steganography.";
    int message_size = strlen(message);
    hide_message(message, message_size);
    show_image();
    free(image);
    return 0;
}