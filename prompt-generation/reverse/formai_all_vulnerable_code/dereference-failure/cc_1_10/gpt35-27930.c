//FormAI DATASET v1.0 Category: File Backup System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

/**
 * Main function
 */
int main(int argc, char *argv[]) {
    char input_file[BUFFER_SIZE];
    char output_file[BUFFER_SIZE];

    // Check if arguments are passed
    if (argc < 2) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Copy input and output filenames
    strcpy(input_file, argv[1]);
    strcpy(output_file, argv[2]);

    // Create file pointers for input and output files
    FILE *input_fp, *output_fp;

    // Open input file in read mode
    input_fp = fopen(input_file, "rb");
    if (input_fp == NULL) {
        fprintf(stderr, "Error: Failed to open %s\n", input_file);
        exit(EXIT_FAILURE);
    }

    // Open output file in write mode
    output_fp = fopen(output_file, "wb");
    if (output_fp == NULL) {
        fprintf(stderr, "Error: Failed to open %s\n", output_file);
        fclose(input_fp);
        exit(EXIT_FAILURE);
    }

    // Copy input file data to output file
    char buffer[BUFFER_SIZE];
    size_t length;
    while ((length = fread(buffer, 1, BUFFER_SIZE, input_fp)) > 0) {
        fwrite(buffer, 1, length, output_fp);
    }

    // Close file pointers
    fclose(input_fp);
    fclose(output_fp);

    printf("File backup successful!\n");

    return 0;
}