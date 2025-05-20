//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Define the ASCII characters to represent the grayscale values
const char *ASCII_CHARS = " .:-=+*#%@";

// Determine the index in the ASCII_CHARS string for a given grayscale value between 0-255
int get_ascii_index(char c) {
    return (int)((c / 255.0) * (strlen(ASCII_CHARS) - 1));
}

// Recursively process a small subsection of a given grayscale image and output the corresponding ASCII art
void convert_image_section(char *image_data, int width, int height, int start_x, int start_y, int end_x, int end_y) {
    // Determine the dimensions of the current section
    int section_width = end_x - start_x + 1;
    int section_height = end_y - start_y + 1;
    
    // Allocate memory for the grayscale values of the current section
    unsigned char *grayscale_vals = calloc(section_width * section_height, sizeof(unsigned char));
    
    // Copy the grayscale values from the original image data into the section grayscale data
    for (int y = start_y; y <= end_y; y++) {
        for (int x = start_x; x <= end_x; x++) {
            grayscale_vals[(y - start_y) * section_width + (x - start_x)] = image_data[y * width + x];
        }
    }
    
    // Check if the current section is smaller than a certain threshold size (e.g. 5x5)
    if (section_width <= 5 || section_height <= 5) {
        // Output the corresponding ASCII character for each grayscale value in the section
        for (int y = 0; y < section_height; y++) {
            for (int x = 0; x < section_width; x++) {
                printf("%c", ASCII_CHARS[get_ascii_index(grayscale_vals[y * section_width + x])]);
            }
            printf("\n");
        }
    } else {
        // Recursively process four smaller subsections of the current section
        int mid_x = start_x + (end_x - start_x) / 2;
        int mid_y = start_y + (end_y - start_y) / 2;
        convert_image_section(image_data, width, height, start_x, start_y, mid_x, mid_y);
        convert_image_section(image_data, width, height, mid_x + 1, start_y, end_x, mid_y);
        convert_image_section(image_data, width, height, start_x, mid_y + 1, mid_x, end_y);
        convert_image_section(image_data, width, height, mid_x + 1, mid_y + 1, end_x, end_y);
    }
    
    // Free the memory used for the section grayscale data
    free(grayscale_vals);
}

int main() {
    // Load the grayscale image data from a file into memory
    FILE *file = fopen("image.dat", "rb");
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *image_data = malloc(file_size);
    fread(image_data, 1, file_size, file);
    fclose(file);
    
    // Define the dimensions of the image
    int width = 64;
    int height = 32;
    
    // Process the entire image as one section
    convert_image_section(image_data, width, height, 0, 0, width - 1, height - 1);
    
    // Free the memory used for the image data
    free(image_data);
    
    return 0;
}