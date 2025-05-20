//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

#define WIDTH 800
#define HEIGHT 600
#define BITS_PER_PIXEL 24
#define IMAGE_FILE "image.bmp"

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} RGB;

typedef struct {
    RGB pixels[WIDTH * HEIGHT];
} Image;

Image *load_image(const char *filename) {
    Image *image = malloc(sizeof(Image));
    int fd = open(filename, O_RDONLY, 0);
    if (fd == -1) {
        perror("Error opening file");
        return NULL;
    }
    if (read(fd, image->pixels, WIDTH * HEIGHT * BITS_PER_PIXEL / 8) != WIDTH * HEIGHT * BITS_PER_PIXEL / 8) {
        perror("Error reading file");
        close(fd);
        return NULL;
    }
    close(fd);
    return image;
}

void apply_filter(Image *image, int filter_number) {
    switch (filter_number) {
        case 1: // blur
            for (int i = 0; i < WIDTH * HEIGHT; i++) {
                RGB *pixel = &image->pixels[i];
                pixel->red += pixel->green + pixel->blue;
                pixel->green += pixel->red + pixel->blue;
                pixel->blue += pixel->red + pixel->green;
            }
            break;
        case 2: // sharpen
            for (int i = 0; i < WIDTH * HEIGHT; i++) {
                RGB *pixel = &image->pixels[i];
                pixel->red += (pixel->red - pixel->green) * 2;
                pixel->green += (pixel->green - pixel->blue) * 2;
                pixel->blue += (pixel->blue - pixel->red) * 2;
            }
            break;
        case 3: // colorize
            for (int i = 0; i < WIDTH * HEIGHT; i++) {
                RGB *pixel = &image->pixels[i];
                pixel->red = (pixel->red * 2) % 255;
                pixel->green = (pixel->green * 2) % 255;
                pixel->blue = (pixel->blue * 2) % 255;
            }
            break;
        default:
            printf("Invalid filter number\n");
            return;
    }
}

void save_image(Image *image, const char *filename) {
    int fd = open(filename, O_WRONLY, 0);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        RGB *pixel = &image->pixels[i];
        write(fd, pixel, BITS_PER_PIXEL / 8);
    }
    close(fd);
}

int main() {
    Image *image = load_image(IMAGE_FILE);
    if (image == NULL) {
        printf("Error loading image\n");
        return 1;
    }
    int filter_number = 1; // blur by default
    while (1) {
        printf("Current filter: %d (blur)\n", filter_number);
        apply_filter(image, filter_number);
        filter_number++;
        if (filter_number > 3) {
            filter_number = 1;
        }
        printf("Apply another filter (y/n)? ");
        char choice = getchar();
        if (choice == 'n') {
            break;
        }
    }
    save_image(image, "modified_image.bmp");
    free(image);
    return 0;
}