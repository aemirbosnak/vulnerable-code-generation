//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This function generates the ASCII art string from the given image buffer.
char* image_to_ascii(unsigned char* image, int width, int height) {
    // Define the ASCII characters to represent the image.
    const char ascii_chars[] = " .:-=+*#%@";
    const int num_ascii_chars = strlen(ascii_chars);
    
    // Allocate the ASCII art string buffer.
    int ascii_str_size = width * height + height + 1;
    char* ascii_str = (char*)malloc(ascii_str_size);
    ascii_str[ascii_str_size - 1] = '\0';
    
    // Generate the ASCII art string.
    int ascii_index = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Get the pixel value.
            unsigned char* pixel = image + (y * width + x) * 3;
            int r = pixel[0];
            int g = pixel[1];
            int b = pixel[2];
            
            // Calculate the grayscale value.
            float gray_value = 0.299 * r + 0.587 * g + 0.114 * b;
            
            // Scale the grayscale value to the range [0, num_ascii_chars-1].
            int ascii_value = (int)(gray_value / 255.0 * (num_ascii_chars - 1));
            
            // Add the corresponding ASCII character to the string.
            ascii_str[ascii_index] = ascii_chars[ascii_value];
            ascii_index++;
        }
        // Add newline character after each row.
        ascii_str[ascii_index] = '\n';
        ascii_index++;
    }
    
    return ascii_str;
}

int main(int argc, char** argv) {
    // Load the image file into memory.
    FILE* image_file = fopen("image.bmp", "rb");
    fseek(image_file, 0, SEEK_END);
    long file_size = ftell(image_file);
    fseek(image_file, 0, SEEK_SET);
    unsigned char* image_buffer = (unsigned char*)malloc(file_size);
    fread(image_buffer, file_size, 1, image_file);
    fclose(image_file);
    
    // Parse the BMP header to get the image dimensions.
    int width = *(int*)&image_buffer[18];
    int height = *(int*)&image_buffer[22];
    
    // Convert the image to ASCII art.
    char* ascii_str = image_to_ascii(image_buffer + 54, width, height);
    
    // Print the ASCII art to the console.
    printf("%s", ascii_str);
    
    // Free the memory.
    free(image_buffer);
    free(ascii_str);
    
    return 0;
}