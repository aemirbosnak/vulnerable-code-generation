//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 320
#define HEIGHT 240

typedef struct {
    int width;
    int height;
    unsigned char* image;
} Image;

void create_image(Image* image, char* filename) {
    FILE* f = fopen(filename, "wb");
    if (!f) {
        printf("Error opening file\n");
        exit(1);
    }

    image->width = WIDTH;
    image->height = HEIGHT;
    image->image = (unsigned char*) malloc(WIDTH * HEIGHT * 3);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            image->image[y * WIDTH * 3 + x * 3] = (x + y) % 256;
            image->image[y * WIDTH * 3 + x * 3 + 1] = (x + y) % 256;
            image->image[y * WIDTH * 3 + x * 3 + 2] = (x + y) % 256;
        }
    }

    fwrite(image->image, WIDTH * HEIGHT * 3, 1, f);
    fclose(f);
}

void read_image(Image* image, char* filename) {
    FILE* f = fopen(filename, "rb");
    if (!f) {
        printf("Error opening file\n");
        exit(1);
    }

    fread(image->image, WIDTH * HEIGHT * 3, 1, f);
    fclose(f);

    image->width = WIDTH;
    image->height = HEIGHT;
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <payload>\n", argv[0]);
        exit(1);
    }

    char* filename = argv[1];
    char* payload = argv[2];

    Image image;
    create_image(&image, filename);
    read_image(&image, payload);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int index = y * WIDTH * 3 + x * 3;
            image.image[index] ^= payload[y * WIDTH * 3 + x * 3];
        }
    }

    create_image(&image, filename);

    return 0;
}