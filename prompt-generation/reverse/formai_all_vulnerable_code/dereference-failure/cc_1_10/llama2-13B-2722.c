//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <errno.h>

#define WIDTH 640
#define HEIGHT 480
#define BPP 32

typedef struct {
    unsigned char *data;
    size_t size;
} image_t;

image_t *load_image(const char *filename) {
    // Open the image file
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening image file");
        return NULL;
    }

    // Get the image size
    struct stat stat;
    fstat(fd, &stat);
    size_t size = stat.st_size;

    // Map the image file into memory
    image_t *image = mmap(NULL, size, PROT_READ, MAP_FILE | MAP_PRIVATE, fd, 0);
    if (image == MAP_FAILED) {
        perror("Error mapping image file");
        close(fd);
        return NULL;
    }

    // Close the file descriptor
    close(fd);

    return image;
}

void draw_line(image_t *image, int x1, int y1, int x2, int y2, int color) {
    // Calculate the line's slope and y-intercept
    int slope = (y2 - y1) / (x2 - x1);
    int y_intercept = y1 + slope * x1;

    // Iterate over each pixel on the line
    for (int x = x1; x <= x2; x++) {
        // Calculate the pixel's coordinates
        int y = y_intercept + slope * x;

        // Set the pixel's color
        image->data[y * WIDTH * BPP + x * BPP] = color;
    }
}

void draw_circle(image_t *image, int x, int y, int radius, int color) {
    // Calculate the circle's center coordinates
    int center_x = x;
    int center_y = y;

    // Calculate the circle's radius
    int radius_squared = radius * radius;

    // Iterate over each pixel on the circle
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            // Calculate the distance between the pixel and the center
            int distance_squared = (x - center_x) * (x - center_x) + (y - center_y) * (y - center_y);

            // Check if the pixel is inside the circle
            if (distance_squared <= radius_squared) {
                // Set the pixel's color
                image->data[y * WIDTH * BPP + x * BPP] = color;
            }
        }
    }
}

int main(int argc, char **argv) {
    // Load the image
    image_t *image = load_image("image.jpg");
    if (image == NULL) {
        return 1;
    }

    // Draw a line on the image
    draw_line(image, 100, 100, 300, 300, 0xFF0000);

    // Draw a circle on the image
    draw_circle(image, 200, 200, 50, 0x00FF00);

    // Unmap the image from memory
    munmap(image->data, image->size);

    return 0;
}