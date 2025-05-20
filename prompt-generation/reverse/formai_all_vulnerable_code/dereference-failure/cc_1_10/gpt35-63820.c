//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// change these values to get different ascii representations
#define MAX_PIXEL_VALUE 255
#define ASCII_ART_CHARACTERS " .-:=+*#%@"

// declaration of functions
char convert_pixel_to_ascii(int pixel);
void convert_image_to_ascii_art(char *input_file_name, char *output_file_name, int width, int height);

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s [input-image-file] [output-file] [width]\n", argv[0]);
        exit(1);
    }

    char *input_file_name = argv[1];
    char *output_file_name = argv[2];
    int image_width = atoi(argv[3]);
    int image_height;

    // open the input image file
    FILE *input_file = fopen(input_file_name, "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file %s\n", input_file_name);
        exit(1);
    }

    // read the header of the input file to get the image dimensions
    char header[54];
    fread(header, sizeof(char), 54, input_file);
    image_height = *(int*)&header[18];

    // close the input file
    fclose(input_file);

    // convert the image to ascii art
    convert_image_to_ascii_art(input_file_name, output_file_name, image_width, image_height);

    return 0;
}

char convert_pixel_to_ascii(int pixel) {
    int ascii_index = ((float)pixel / MAX_PIXEL_VALUE) * (strlen(ASCII_ART_CHARACTERS) - 1);
    return ASCII_ART_CHARACTERS[ascii_index];
}

void convert_image_to_ascii_art(char *input_file_name, char *output_file_name, int width, int height) {
    // open the input image file
    FILE *input_file = fopen(input_file_name, "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file %s\n", input_file_name);
        exit(1);
    }

    // open the output file for writing ascii art
    FILE *output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file %s\n", output_file_name);
        exit(1);
    }

    // write the header of the output file
    fprintf(output_file, "P2\n%d %d\n%d\n", width, height, strlen(ASCII_ART_CHARACTERS) - 1);

    // allocate memory to hold the pixel data
    int pixel_data_size = width * height * 3;
    unsigned char *pixel_data = malloc(pixel_data_size);

    // read the pixel data from the input file
    fseek(input_file, 54, SEEK_SET);
    fread(pixel_data, sizeof(unsigned char), pixel_data_size, input_file);

    // loop through the pixel data and convert each pixel to ascii character
    for (int i = 0; i < pixel_data_size; i += 3) {
        int pixel_value = (int)(0.299 * pixel_data[i] + 0.587 * pixel_data[i + 1] + 0.114 * pixel_data[i + 2]);
        char ascii_character = convert_pixel_to_ascii(pixel_value);
        fprintf(output_file, "%c ", ascii_character);
    }

    // free dynamically allocated memory
    free(pixel_data);

    // close the input and output files
    fclose(input_file);
    fclose(output_file);

    printf("Conversion Complete. Output file name: %s\n", output_file_name);
}