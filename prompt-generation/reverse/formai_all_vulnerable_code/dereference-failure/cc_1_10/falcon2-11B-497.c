//Falcon2-11B DATASET v1.0 Category: Digital Watermarking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>
#include <math.h>
#include <string.h>

#define BMP_FILE_MAGIC 0x4d42
#define BMP_FILE_EXT ".bmp"

// Function to extract the image data from a BMP file
void extract_image_data(const char* filename, unsigned char** image_data, int* image_width, int* image_height) {
    int fd;
    struct stat st;
    int bytes_read = 0;
    unsigned char* buffer = NULL;
    int buffer_size = 0;

    // Open the BMP file
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("Error opening file %s: %s\n", filename, strerror(errno));
        exit(1);
    }

    // Get the file size
    fstat(fd, &st);
    buffer_size = st.st_size;

    // Allocate memory for the image data
    buffer = malloc(buffer_size);
    if (buffer == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }

    // Read the BMP file into the buffer
    bytes_read = pread(fd, buffer, buffer_size, 0);
    if (bytes_read!= buffer_size) {
        printf("Error reading file\n");
        exit(1);
    }

    // Close the BMP file
    close(fd);

    // Extract the image data from the BMP file header
    int bmp_header_size = 54; // Size of the BMP file header
    unsigned char* bmp_header = malloc(bmp_header_size);
    memcpy(bmp_header, buffer, bmp_header_size);

    // Extract the image width and height from the BMP file header
    unsigned short* width = (unsigned short*) &(bmp_header[14]);
    *image_width = *width;
    unsigned short* height = (unsigned short*) &(bmp_header[18]);
    *image_height = *height;

    // Extract the image data from the BMP file
    unsigned char* bmp_data = malloc(buffer_size - bmp_header_size);
    memcpy(bmp_data, buffer + bmp_header_size, buffer_size - bmp_header_size);

    // Free the memory used by the BMP file header
    free(bmp_header);

    // Free the memory used by the BMP file data
    *image_data = bmp_data;
}

// Function to embed a digital watermark into an image file
void embed_digital_watermark(const char* filename, unsigned char* watermark, int watermark_width, int watermark_height, int* image_data, int image_width, int image_height) {
    int watermark_x = 0;
    int watermark_y = 0;
    int i = 0;

    // Loop over the image data and embed the watermark
    for (i = 0; i < image_width * image_height; i++) {
        if (i % (image_width * image_height / 10) == 0) {
            printf("Embedding watermark %d%%\r", i * 10 / (image_width * image_height));
            fflush(stdout);
        }

        int image_index = i % image_width * image_height;
        int watermark_index = i % watermark_width * watermark_height;
        int pixel = *(image_data + image_index);
        int watermark_pixel = *(watermark + watermark_index);

        // Embed the watermark pixel into the image pixel
        if (watermark_pixel == 0) {
            pixel = pixel | 0x80; // Set the least significant bit of the pixel to 1
        } else if (watermark_pixel == 255) {
            pixel = pixel & 0x7f; // Clear the least significant bit of the pixel
        }

        *(image_data + image_index) = pixel;
    }

    // Write the modified image data back to the file
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd == -1) {
        printf("Error opening file %s: %s\n", filename, strerror(errno));
        exit(1);
    }

    int bytes_written = 0;
    for (i = 0; i < image_width * image_height; i++) {
        if (i % (image_width * image_height / 10) == 0) {
            printf("Writing image %d%%\r", i * 10 / (image_width * image_height));
            fflush(stdout);
        }

        int image_index = i % image_width * image_height;
        int pixel = *(image_data + image_index);
        int bytes_to_write = 1;
        int bytes_written = write(fd, &pixel, bytes_to_write);
        if (bytes_written!= bytes_to_write) {
            printf("Error writing file\n");
            exit(1);
        }
    }

    close(fd);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <image_file> <watermark_file> <watermark_size>\n", argv[0]);
        return 1;
    }

    const char* image_file = argv[1];
    const char* watermark_file = argv[2];
    int watermark_width = atoi(argv[3]);
    int watermark_height = watermark_width; // Assuming square watermark

    // Open the image file
    int fd = open(image_file, O_RDONLY);
    if (fd == -1) {
        printf("Error opening file %s: %s\n", image_file, strerror(errno));
        return 1;
    }

    // Open the watermark file
    int watermark_fd = open(watermark_file, O_RDONLY);
    if (watermark_fd == -1) {
        printf("Error opening file %s: %s\n", watermark_file, strerror(errno));
        return 1;
    }

    // Extract the image data from the BMP file
    unsigned char* image_data = NULL;
    int image_width;
    int image_height;
    extract_image_data(image_file, &image_data, &image_width, &image_height);

    // Extract the watermark data from the BMP file
    unsigned char* watermark_data = NULL;
    extract_image_data(watermark_file, &watermark_data, &watermark_width, &watermark_height);

    // Embed the watermark into the image
    embed_digital_watermark(image_file, watermark_data, watermark_width, watermark_height, image_data, image_width, image_height);

    // Close the files
    close(fd);
    close(watermark_fd);

    return 0;
}