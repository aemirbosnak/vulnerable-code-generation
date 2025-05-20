//FormAI DATASET v1.0 Category: Image Editor ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define BMP_HEADER_SIZE 54

int main(int argc, char *argv[]) {
    FILE *f_in, *f_out;
    char *input_file = argv[1];
    char *output_file = "output.bmp";
    unsigned char bmp_header[BMP_HEADER_SIZE];
    unsigned char *bmp_data;
    int bmp_width, bmp_height, bmp_padding, bmp_size, i;

    if (argc != 2) {
        printf("Usage: ./image_editor input_file.bmp\n");
        exit(EXIT_FAILURE);
    }

    // Open input file
    f_in = fopen(input_file, "rb");
    if (f_in == NULL) {
        printf("Could not open %s\n", input_file);
        exit(EXIT_FAILURE);
    }

    // Read BMP header
    fread(bmp_header, sizeof(unsigned char), BMP_HEADER_SIZE, f_in);

    // Get BMP dimensions and padding size
    bmp_width = *(int*)&bmp_header[18];
    bmp_height = *(int*)&bmp_header[22];
    bmp_size = bmp_width * bmp_height * 3;
    bmp_padding = (4 - (bmp_width * 3) % 4) % 4;

    // Allocate memory for BMP data
    bmp_data = (unsigned char*) malloc(bmp_size);

    // Read BMP data
    fread(bmp_data, sizeof(unsigned char), bmp_size, f_in);

    // Close input file
    fclose(f_in);

    // Apply image filter
    for (i = 0; i < bmp_size; i++) {
        if (i % 3 == 0) {
            bmp_data[i] = 0; // Set blue channel to 0
        }
    }

    // Open output file
    f_out = fopen(output_file, "wb");
    if (f_out == NULL) {
        printf("Could not create %s\n", output_file);
        exit(EXIT_FAILURE);
    }

    // Write BMP header
    fwrite(bmp_header, sizeof(unsigned char), BMP_HEADER_SIZE, f_out);

    // Write BMP data
    fwrite(bmp_data, sizeof(unsigned char), bmp_size, f_out);

    // Add BMP padding if necessary
    if (bmp_padding > 0) {
        unsigned char padding_data[bmp_padding];
        fwrite(padding_data, sizeof(unsigned char), bmp_padding, f_out);
    }

    // Close output file
    fclose(f_out);

    // Free allocated memory
    free(bmp_data);

    printf("Image filter applied successfully. Output file: %s\n", output_file);

    return 0;
}