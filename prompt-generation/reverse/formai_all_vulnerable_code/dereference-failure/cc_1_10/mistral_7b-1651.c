//MISTRAL-7B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <math.h>

#define WIDTH 300
#define HEIGHT 300
#define MAX_PIXEL_VALUE 255

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} Pixel;

void flip_image(Pixel *image, int width, int height);
void change_brightness(Pixel *image, int width, int height, int brightness);
void change_contrast(Pixel *image, int width, int height, int contrast);

int main(int argc, char **argv) {
    int fd;
    char filename[30];

    if (argc != 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    strcpy(filename, argv[1]);

    fd = open(filename, O_RDWR);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    size_t image_size = WIDTH * HEIGHT * sizeof(Pixel);
    Pixel *image = mmap(NULL, image_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    if (image == MAP_FAILED) {
        perror("Error mapping file to memory");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Loading image...\n");
    // Add your loading code here

    printf("\nApplying post-apocalyptic effects...\n");

    flip_image(image, WIDTH, HEIGHT);
    change_brightness(image, WIDTH, HEIGHT, 50);
    change_contrast(image, WIDTH, HEIGHT, 100);

    printf("\nSaving image...\n");
    // Add your saving code here

    munmap(image, image_size);
    close(fd);

    printf("Image processing complete.\n");

    return EXIT_SUCCESS;
}

void flip_image(Pixel *image, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Pixel temp = image[y * WIDTH + x];
            image[y * WIDTH + x] = image[(height - y - 1) * WIDTH + x];
            image[(height - y - 1) * WIDTH + x] = temp;
        }
    }
}

void change_brightness(Pixel *image, int width, int height, int brightness) {
    for (int i = 0; i < width * height; i++) {
        Pixel *pixel = &image[i];

        pixel->red += brightness;
        if (pixel->red > MAX_PIXEL_VALUE)
            pixel->red = MAX_PIXEL_VALUE;

        pixel->green += brightness;
        if (pixel->green > MAX_PIXEL_VALUE)
            pixel->green = MAX_PIXEL_VALUE;

        pixel->blue += brightness;
        if (pixel->blue > MAX_PIXEL_VALUE)
            pixel->blue = MAX_PIXEL_VALUE;
    }
}

void change_contrast(Pixel *image, int width, int height, int contrast) {
    int slope = contrast * (MAX_PIXEL_VALUE / 100.0);

    for (int i = 0; i < width * height; i++) {
        Pixel *pixel = &image[i];

        int new_red = pow(pixel->red / 255.0, 2.2) * slope + 50;
        if (new_red > MAX_PIXEL_VALUE)
            new_red = MAX_PIXEL_VALUE;
        pixel->red = new_red > 0 ? new_red : 0;

        int new_green = pow(pixel->green / 255.0, 2.2) * slope + 50;
        if (new_green > MAX_PIXEL_VALUE)
            new_green = MAX_PIXEL_VALUE;
        pixel->green = new_green > 0 ? new_green : 0;

        int new_blue = pow(pixel->blue / 255.0, 2.2) * slope + 50;
        if (new_blue > MAX_PIXEL_VALUE)
            new_blue = MAX_PIXEL_VALUE;
        pixel->blue = new_blue > 0 ? new_blue : 0;
    }
}