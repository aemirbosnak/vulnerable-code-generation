//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <utime.h>

#define WIDTH 640
#define HEIGHT 480
#define BITS_PER_PIXEL 32
#define IMAGE_FILE "image.ppm"

// Structure to hold the image data
typedef struct {
    unsigned char red[WIDTH * HEIGHT];
    unsigned char green[WIDTH * HEIGHT];
    unsigned char blue[WIDTH * HEIGHT];
} image_t;

// Function to read an image file
image_t* read_image(const char* filename) {
    // Open the image file
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening image file");
        return NULL;
    }

    // Read the image data
    struct stat stat_buf;
    if (fstat(fd, &stat_buf) == -1) {
        perror("Error statting image file");
        close(fd);
        return NULL;
    }

    // Calculate the size of the image data
    size_t image_size = stat_buf.st_size;

    // Allocate memory for the image data
    image_t* image = malloc(sizeof(image_t) + image_size);
    if (image == NULL) {
        perror("Error allocating memory for image data");
        close(fd);
        return NULL;
    }

    // Read the image data into the allocated memory
    size_t bytes_read = read(fd, image->red, WIDTH * HEIGHT * BITS_PER_PIXEL / 8);
    if (bytes_read != WIDTH * HEIGHT * BITS_PER_PIXEL / 8) {
        perror("Error reading image data");
        free(image);
        close(fd);
        return NULL;
    }

    // Close the image file
    close(fd);

    return image;
}

// Function to write an image file
void write_image(const char* filename, image_t* image) {
    // Open the image file
    int fd = open(filename, O_WRONLY | O_CREAT, 0666);
    if (fd == -1) {
        perror("Error opening image file");
        return;
    }

    // Write the image data
    size_t bytes_written = write(fd, image->red, WIDTH * HEIGHT * BITS_PER_PIXEL / 8);
    if (bytes_written != WIDTH * HEIGHT * BITS_PER_PIXEL / 8) {
        perror("Error writing image data");
        close(fd);
        return;
    }

    // Flush the buffer
    fsync(fd);

    // Close the image file
    close(fd);
}

// Function to draw a line on the image
void draw_line(image_t* image, int x1, int y1, int x2, int y2) {
    // Calculate the slope and y-intercept of the line
    int slope = (y2 - y1) / (x2 - x1);
    int y_intercept = y1 - slope * x1;

    // Loop through each pixel on the line
    for (int x = x1; x <= x2; x++) {
        int y = y_intercept + slope * x;
        image->red[y * WIDTH + x] = 255;
        image->green[y * WIDTH + x] = 0;
        image->blue[y * WIDTH + x] = 0;
    }
}

// Function to draw a rectangle on the image
void draw_rectangle(image_t* image, int x1, int y1, int x2, int y2) {
    // Loop through each pixel on the rectangle
    for (int x = x1; x <= x2; x++) {
        for (int y = y1; y <= y2; y++) {
            image->red[y * WIDTH + x] = 255;
            image->green[y * WIDTH + x] = 0;
            image->blue[y * WIDTH + x] = 0;
        }
    }
}

int main() {
    // Load the image file
    image_t* image = read_image(IMAGE_FILE);
    if (image == NULL) {
        perror("Error loading image file");
        return 1;
    }

    // Draw a line on the image
    draw_line(image, 100, 100, 200, 200);

    // Draw a rectangle on the image
    draw_rectangle(image, 150, 150, 250, 250);

    // Write the modified image to a new file
    char new_filename[] = "modified_image.ppm";
    write_image(new_filename, image);

    // Free the memory allocated for the image data
    free(image);

    return 0;
}