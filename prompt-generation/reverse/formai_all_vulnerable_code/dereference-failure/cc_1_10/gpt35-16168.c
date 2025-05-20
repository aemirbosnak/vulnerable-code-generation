//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to load image file 
void load(char *filename, unsigned char **buf, int *width, int *height) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    // Read the header of the BMP image 
    if (fseek(fp, 10, SEEK_SET)) {
        printf("Error seeking to pixel data.\n");
        exit(1);
    }
    unsigned int pixel_offset;
    if (fread(&pixel_offset, sizeof(pixel_offset), 1, fp) != 1) {
        printf("Error reading pixel offset from header.\n");
        exit(1);
    }
    if (fseek(fp, 18, SEEK_SET)) {
        printf("Error seeking to image dimensions.\n");
        exit(1);
    }
    if (fread(width, sizeof(*width), 1, fp) != 1 ||
        fread(height, sizeof(*height), 1, fp) != 1) {
        printf("Error reading image dimensions from header.\n");
        exit(1);
    }
    // Allocate memory for the pixel data 
    int row_size = (*width) * 3;
    if (row_size % 4 != 0) row_size += 4 - (row_size % 4);
    int data_size = row_size * (*height);
    *buf = malloc(data_size);
    if (*buf == NULL) {
        printf("Error allocating memory for pixel data.\n");
        exit(1);
    }
    // Read the pixel data 
    if (fseek(fp, pixel_offset, SEEK_SET)) {
        printf("Error seeking to pixel data.\n");
        exit(1);
    }
    if (fread(*buf, data_size, 1, fp) != 1) {
        printf("Error reading pixel data.\n");
        exit(1);
    }
    fclose(fp);
}

// Function to save image file 
void save(char *filename, unsigned char *buf, int width, int height) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    // Write the header of the BMP image 
    unsigned char header[54] = {
        'B','M',          // Magic number 
        0,0,0,0,          // File size (will be set later) 
        0,0,0,0,          // Reserved 
        54,0,0,0,         // Offset to pixel data 
        40,0,0,0,         // Header size 
        0,0,0,0,          // Image width 
        0,0,0,0,          // Image height 
        1,0,              // Number of color planes 
        24,0,             // Bits per pixel 
        0,0,0,0,          // Compression method 
        0,0,0,0,          // Image size (can be zero for uncompressed images) 
        0,0,0,0,          // Horizontal resolution 
        0,0,0,0,          // Vertical resolution 
        0,0,0,0,0,0,0,0   // Number of colors in the palette 
    };
    int row_size = width * 3;
    if (row_size % 4 != 0) row_size += 4 - (row_size % 4);
    int data_size = row_size * height;
    unsigned int file_size = data_size + sizeof(header);
    memcpy(&header[2], &file_size, sizeof(file_size));
    memcpy(&header[18], &width, sizeof(width));
    memcpy(&header[22], &height, sizeof(height));
    if (fwrite(header, sizeof(header), 1, fp) != 1) {
        printf("Error writing header.\n");
        exit(1);
    }
    // Write the pixel data 
    if (fwrite(buf, data_size, 1, fp) != 1) {
        printf("Error writing pixel data.\n");
        exit(1);
    }
    fclose(fp);
}

// The main function that processes the image 
int main(int argc, char *argv[]) {
    // Check command-line arguments 
    if (argc != 4) {
        printf("Usage: %s infile outfile operation\n", argv[0]);
        printf("Operations: flip, brightness, contrast.\n");
        return 1;
    }
    // Load the input image 
    unsigned char *buf;
    int width, height;
    load(argv[1], &buf, &width, &height);
    // Perform the specified operation 
    if (strcmp(argv[3], "flip") == 0) {
        // Flip the image horizontally 
        for (int y = 0; y < height; y++) {
            for (int x1 = 0, x2 = width - 1; x1 < x2; x1++, x2--) {
                int offset1 = y * width * 3 + x1 * 3;
                int offset2 = y * width * 3 + x2 * 3;
                for (int i = 0; i < 3; i++) {
                    unsigned char temp = buf[offset1 + i];
                    buf[offset1 + i] = buf[offset2 + i];
                    buf[offset2 + i] = temp;
                }
            }
        }
    } else if (strcmp(argv[3], "brightness") == 0) {
        // Adjust the brightness of the image 
        int delta = atoi(argv[4]);
        for (int i = 0; i < width * height * 3; i++) {
            int val = buf[i] + delta;
            if (val < 0) val = 0;
            if (val > 255) val = 255;
            buf[i] = val;
        }
    } else if (strcmp(argv[3], "contrast") == 0) {
        // Adjust the contrast of the image 
        float factor = atof(argv[4]);
        for (int i = 0; i < width * height * 3; i++) {
            int val = buf[i] * factor;
            if (val < 0) val = 0;
            if (val > 255) val = 255;
            buf[i] = val;
        }
    } else {
        printf("Unknown operation: %s\n", argv[3]);
        return 1;
    }
    // Save the output image 
    save(argv[2], buf, width, height);
    free(buf);
    return 0;
}