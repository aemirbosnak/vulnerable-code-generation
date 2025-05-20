//FormAI DATASET v1.0 Category: Image Editor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_FILENAME_LENGTH 256

int main() {

    char input_filename[MAX_FILENAME_LENGTH];
    char output_filename[MAX_FILENAME_LENGTH];
    FILE *input_file;
    FILE *output_file;
    unsigned int width = 0;
    unsigned int height = 0;

    // Ask user for input file name
    printf("Enter input file name: ");
    scanf("%s", input_filename);

    // Open input file for reading
    input_file = fopen(input_filename, "rb");
    if (!input_file) {
        printf("Error: Could not open file %s for reading.\n", input_filename);
        return EXIT_FAILURE;
    }

    // Read header data
    char header[54];
    fread(header, sizeof(char), 54, input_file);
    if (header[0] != 'B' || header[1] != 'M') {
        printf("Error: File %s is not a valid BMP image.\n", input_filename);
        return EXIT_FAILURE;
    }
    width = *(unsigned int*)&header[18];
    height = *(unsigned int*)&header[22];

    // Allocate memory for image data
    unsigned char *data = (unsigned char*)malloc(width * height * 3);
    if (!data) {
        printf("Error: Could not allocate memory for image data.\n");
        return EXIT_FAILURE;
    }

    // Read image data
    fread(data, sizeof(unsigned char), width * height * 3, input_file);

    // Close input file
    fclose(input_file);

    // Ask user for output file name
    printf("Enter output file name: ");
    scanf("%s", output_filename);

    // Open output file for writing
    output_file = fopen(output_filename, "wb");
    if (!output_file) {
        printf("Error: Could not open file %s for writing.\n", output_filename);
        return EXIT_FAILURE;
    }

    // Write header data to output file
    fwrite(header, sizeof(char), 54, output_file);

    // Manipulate image data (Invert colors)
    for (int i = 0; i < width * height * 3; i++) {
        data[i] = UCHAR_MAX - data[i];
    }

    // Write image data to output file
    fwrite(data, sizeof(unsigned char), width * height * 3, output_file);

    // Close output file
    fclose(output_file);

    // Free memory allocated for image data
    free(data);

    printf("Success: File %s has been modified and saved as %s.\n", input_filename, output_filename);

    return EXIT_SUCCESS;
}