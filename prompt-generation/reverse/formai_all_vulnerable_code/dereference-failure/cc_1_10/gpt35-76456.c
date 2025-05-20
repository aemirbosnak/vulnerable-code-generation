//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80 // Width of the ASCII art image
#define HEIGHT 60 // Height of the ASCII art image

void convert_image_to_ascii(unsigned char* image, char* ascii){
    char ascii_char[] = {'@', '#', 'S', '%', '?', '*', '+', ';', ':', ',', '.', ' '};
    int num_chars = sizeof(ascii_char) / sizeof(char);
    
    int pixel_step = 3; // RGB images
    int image_index = 0;
    
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            int r = image[image_index];
            int g = image[image_index + 1];
            int b = image[image_index + 2];
            int gray = 0.21*r + 0.72*g + 0.07*b;
            
            // Find the appropriate ASCII character for the gray value
            int char_index = (int)((gray/255.0)*(num_chars-1));
            ascii[i*WIDTH+j] = ascii_char[char_index];
            
            // Move to the next pixel in the image
            image_index += pixel_step;
        }
    }
}

int main(){
    // Load the image from file
    FILE* f_ptr = fopen("example_image.rgb", "rb");
    if (f_ptr == NULL){
        printf("File not found.\n");
        return 1;
    }
    
    // Allocate memory for the image
    unsigned char* image = (unsigned char*)malloc(WIDTH*HEIGHT*3*sizeof(unsigned char));
    if (image == NULL){
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    // Load the image into memory
    int bytes_read = fread(image, sizeof(unsigned char), WIDTH*HEIGHT*3, f_ptr);
    if (bytes_read != WIDTH*HEIGHT*3){
        printf("Error reading the image.\n");
        return 1;
    }
    
    // Convert the image to ASCII art
    char ascii[WIDTH*HEIGHT];
    convert_image_to_ascii(image, ascii);
    
    // Print the ASCII art to the console
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            printf("%c", ascii[i*WIDTH+j]);
        }
        printf("\n");
    }
    
    // Free the memory and close the file
    free(image);
    fclose(f_ptr);
    
    return 0;
}