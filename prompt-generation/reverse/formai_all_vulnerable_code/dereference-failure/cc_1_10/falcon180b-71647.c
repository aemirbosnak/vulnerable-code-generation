//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to print the ASCII art representation of an image
void print_ascii_art(char* image_data, int image_width, int image_height) {
    int i, j;
    for(i=0; i<image_height; i++) {
        for(j=0; j<image_width; j++) {
            printf("%c", image_data[i*image_width+j]);
        }
        printf("\n");
    }
}

// Function to read the image data from a file
void read_image_data(char* filename, char** image_data, int* image_width, int* image_height) {
    FILE* file = fopen(filename, "rb");
    if(file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    *image_data = (char*)malloc(file_size);
    fread(*image_data, file_size, 1, file);
    fclose(file);

    int header_size = 54;
    char* header = *image_data;
    *image_width = *(int*)&header[18];
    *image_height = *(int*)&header[22];
}

int main(int argc, char** argv) {
    if(argc!= 3) {
        printf("Usage: %s <input_image> <output_ascii_art>\n", argv[0]);
        exit(1);
    }

    char* input_image_filename = argv[1];
    char* output_ascii_art_filename = argv[2];

    char* image_data;
    int image_width, image_height;
    read_image_data(input_image_filename, &image_data, &image_width, &image_height);

    char* ascii_art_data = (char*)malloc(image_width*image_height);
    int ascii_art_index = 0;
    int max_value = 0;

    // Convert each pixel to a corresponding ASCII character
    for(int i=0; i<image_height; i++) {
        for(int j=0; j<image_width; j++) {
            int value = *(int*)&image_data[i*image_width+j];
            if(value > max_value) {
                max_value = value;
            }
            ascii_art_data[ascii_art_index++] = (char)value;
        }
    }

    // Write the ASCII art data to a file
    FILE* output_file = fopen(output_ascii_art_filename, "wb");
    if(output_file == NULL) {
        printf("Error: Could not open file %s for writing\n", output_ascii_art_filename);
        exit(1);
    }
    fwrite(ascii_art_data, ascii_art_index, 1, output_file);
    fclose(output_file);

    // Print the ASCII art representation of the image
    printf("ASCII art representation:\n");
    print_ascii_art(ascii_art_data, image_width, image_height);

    free(image_data);
    free(ascii_art_data);

    return 0;
}