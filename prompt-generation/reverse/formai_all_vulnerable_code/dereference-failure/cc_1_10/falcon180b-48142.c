//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ASCII_ART_WIDTH 80 // width of the ASCII art

void print_usage(char* program_name) {
    printf("Usage: %s <image_file> <output_file>\n", program_name);
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        print_usage(argv[0]);
        return 1;
    }

    char* input_file_path = argv[1];
    char* output_file_path = argv[2];

    FILE* input_file = fopen(input_file_path, "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file '%s'.\n", input_file_path);
        return 1;
    }

    fseek(input_file, 0, SEEK_END);
    long input_file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    unsigned char* input_buffer = malloc(input_file_size);
    if (input_buffer == NULL) {
        printf("Error: Could not allocate memory for input buffer.\n");
        fclose(input_file);
        return 1;
    }

    size_t bytes_read = fread(input_buffer, 1, input_file_size, input_file);
    if (bytes_read!= input_file_size) {
        printf("Error: Could not read input file '%s'.\n", input_file_path);
        free(input_buffer);
        fclose(input_file);
        return 1;
    }

    fclose(input_file);

    FILE* output_file = fopen(output_file_path, "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file '%s'.\n", output_file_path);
        free(input_buffer);
        return 1;
    }

    for (int y = 0; y < ASCII_ART_WIDTH; ++y) {
        for (int x = 0; x < ASCII_ART_WIDTH; ++x) {
            int pixel_index = (y * ASCII_ART_WIDTH + x) * 3;
            int pixel_value = input_buffer[pixel_index] + input_buffer[pixel_index + 1] * 256 + input_buffer[pixel_index + 2] * 256 * 256;

            if (pixel_value < 128) {
                fprintf(output_file, " ");
            } else if (pixel_value < 256) {
                fprintf(output_file, ".");
            } else {
                fprintf(output_file, "X");
            }
        }
        fprintf(output_file, "\n");
    }

    free(input_buffer);
    fclose(output_file);

    printf("ASCII art generated successfully in '%s'.\n", output_file_path);

    return 0;
}