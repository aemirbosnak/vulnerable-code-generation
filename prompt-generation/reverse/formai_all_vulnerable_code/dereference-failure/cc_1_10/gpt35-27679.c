//FormAI DATASET v1.0 Category: Image Editor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read image data from file
int read_image(FILE *f, unsigned char **data, int *width, int *height) {
    unsigned char header[54];
    int data_offset, file_size;
    
    // Read header and retrieve image information
    fread(header, sizeof(unsigned char), 54, f);
    data_offset = *(int*)&header[10];
    *width = *(int*)&header[18];
    *height = *(int*)&header[22];
    file_size = *(int*)&header[34];
    
    // Allocate memory for image data
    *data = (unsigned char*)malloc(file_size - data_offset);
    
    // Read image data from file
    fseek(f, data_offset, SEEK_SET);
    fread(*data, sizeof(unsigned char), file_size - data_offset, f);
    
    return 1;
}

// Function to write image data to file
int write_image(FILE *f, unsigned char *data, int width, int height) {
    unsigned char header[54];
    int data_offset, file_size;
    
    // Calculate header information
    data_offset = 54;
    file_size = data_offset + (width * height * 3);
    memset(header, 0, sizeof(header));
    header[0] = 'B';
    header[1] = 'M';
    *(int*)&header[2] = file_size;
    *(int*)&header[10] = data_offset;
    *(int*)&header[14] = 40;
    *(int*)&header[18] = width;
    *(int*)&header[22] = height;
    header[26] = 1;
    header[28] = 24;
    
    // Write header and image data to file
    fwrite(header, sizeof(unsigned char), 54, f);
    fwrite(data, sizeof(unsigned char), width * height * 3, f);
    
    return 1;
}

// Function to invert image colors
int invert_colors(unsigned char *data, int width, int height) {
    int i, j, offset;
    unsigned char *pixel;
    
    // Invert each pixel color
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            offset = (i * width + j) * 3;
            pixel = &data[offset];
            pixel[0] = 255 - pixel[0];
            pixel[1] = 255 - pixel[1];
            pixel[2] = 255 - pixel[2];
        }
    }
    
    return 1;
}

int main(int argc, char *argv[]) {
    FILE *f_in, *f_out;
    unsigned char *data;
    int width, height;
    
    // Check program arguments
    if (argc != 3) {
        printf("Usage: image_editor <input_file> <output_file>\n");
        return 1;
    }
    
    // Open input file
    f_in = fopen(argv[1], "rb");
    if (!f_in) {
        printf("Cannot open input file: %s\n", argv[1]);
        return 1;
    }
    
    // Read image data from file
    if (!read_image(f_in, &data, &width, &height)) {
        printf("Cannot read image data from file: %s\n", argv[1]);
        return 1;
    }
    
    // Invert image colors
    invert_colors(data, width, height);
    
    // Open output file
    f_out = fopen(argv[2], "wb");
    if (!f_out) {
        printf("Cannot open output file: %s\n", argv[2]);
        return 1;
    }
    
    // Write image data to file
    if (!write_image(f_out, data, width, height)) {
        printf("Cannot write image data to file: %s\n", argv[2]);
        return 1;
    }
    
    // Free memory and close files
    free(data);
    fclose(f_in);
    fclose(f_out);
    
    return 0;
}