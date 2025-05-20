//FormAI DATASET v1.0 Category: Image Editor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 640
#define HEIGHT 480
#define MAX_PIXEL_VALUE 255

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

// Function to read image data from file
void read_image_data(char* file_path, Pixel* image_data) {
    FILE* fptr = fopen(file_path, "rb");
    if (fptr == NULL) {
        printf("Error: Failed to open image file!");
        exit(1);
    }
    fseek(fptr, 54, SEEK_SET); // Skip bitmap file header
    fread(image_data, sizeof(Pixel), WIDTH*HEIGHT, fptr);
    fclose(fptr);
}

// Function to write image data to file
void write_image_data(char* file_path, Pixel* image_data) {
    FILE* fptr = fopen(file_path, "wb");
    if (fptr == NULL) {
        printf("Error: Failed to create image file!");
        exit(1);
    }
    unsigned char bmp_file_header[54] = {
        0x42, 0x4D, 0xE6, 0x21, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x36, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x80, 0x02,
        0x00, 0x00, 0xE0, 0x01, 0x00, 0x00, 0x01, 0x00, 0x18, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x20, 0x21, 0x05, 0x00, 0x13, 0x0B,
        0x00, 0x00, 0x13, 0x0B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    }; // Bitmap file header
    fwrite(bmp_file_header, sizeof(unsigned char), 54, fptr);
    fwrite(image_data, sizeof(Pixel), WIDTH*HEIGHT, fptr);
    fclose(fptr);
}

// Function to perform pixel manipulation
void manipulate_pixels(Pixel* image_data) {
    for (int i = 0; i < WIDTH*HEIGHT; i++) {
        image_data[i].red = MAX_PIXEL_VALUE - image_data[i].red;
        image_data[i].green = MAX_PIXEL_VALUE - image_data[i].green;
        image_data[i].blue = MAX_PIXEL_VALUE - image_data[i].blue;
    }
}

int main() {
    Pixel* image_data = (Pixel*)malloc(sizeof(Pixel)*WIDTH*HEIGHT);
    read_image_data("cyberpunk.bmp", image_data); // Read image data
    manipulate_pixels(image_data); // Manipulate pixels
    write_image_data("cyberpunk_edited.bmp", image_data); // Write image data
    free(image_data);
    return 0;
}