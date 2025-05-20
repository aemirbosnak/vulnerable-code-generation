//FormAI DATASET v1.0 Category: Image Editor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read the image data from file
unsigned char* read_image(char* filename, int* width, int* height) {
    // Open the file in binary mode
    FILE* f = fopen(filename, "rb");
    if (f == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }
    
    // Read the image header
    char header[54];
    fread(header, sizeof(char), 54, f);
    
    // Extract the image width and height from the header
    *width = *(int*)&header[18];
    *height = *(int*)&header[22];
    
    // Calculate the size of the image data
    int data_size = *width * *height * 3;
    
    // Allocate memory for the image data
    unsigned char* data = malloc(data_size);
    
    // Read the image data from the file
    fread(data, sizeof(unsigned char), data_size, f);
    
    // Close the file and return the image data
    fclose(f);
    return data;
}

// Function to write the image data to file
void write_image(char* filename, unsigned char* data, int width, int height) {
    // Open the file in binary mode
    FILE* f = fopen(filename, "wb");
    if (f == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }
    
    // Create the image header
    char header[54];
    memset(header, 0, 54);
    header[0] = 'B';
    header[1] = 'M';
    *(int*)&header[2] = 54 + width * height * 3;
    *(int*)&header[10] = 54;
    *(int*)&header[14] = 40;
    *(int*)&header[18] = width;
    *(int*)&header[22] = height;
    *(short*)&header[26] = 1;
    *(short*)&header[28] = 24;
    
    // Write the image header to the file
    fwrite(header, sizeof(char), 54, f);
    
    // Write the image data to the file
    fwrite(data, sizeof(unsigned char), width * height * 3, f);
    
    // Close the file
    fclose(f);
}

// Function to invert the colors of an image
void invert_colors(unsigned char* data, int width, int height) {
    for (int i = 0; i < width * height * 3; i++) {
        data[i] = 255 - data[i];
    }
}

// Function to grayscale an image
void grayscale(unsigned char* data, int width, int height) {
    for (int i = 0; i < width * height * 3; i += 3) {
        unsigned char r = data[i];
        unsigned char g = data[i + 1];
        unsigned char b = data[i + 2];
        unsigned char gray = 0.21 * r + 0.72 * g + 0.07 * b;
        data[i] = gray;
        data[i + 1] = gray;
        data[i + 2] = gray;
    }
}

int main() {
    // Read the image data from file
    int width, height;
    unsigned char* data = read_image("input.bmp", &width, &height);
    
    // Invert the colors of the image
    invert_colors(data, width, height);
    
    // Grayscale the image
    grayscale(data, width, height);
    
    // Write the processed image data to file
    write_image("output.bmp", data, width, height);
    
    // Free the memory for the image data
    free(data);
    
    return 0;
}