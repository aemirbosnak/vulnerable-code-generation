//MISTRAL-7B DATASET v1.0 Category: Data recovery tool ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define BUF_SIZE 1024

int main(int argc, char **argv) {
    FILE *input_file, *output_file;
    unsigned char buffer[BUF_SIZE];
    unsigned int magic_number = 0x1A2B3C4D;
    int bytes_read;

    // Check if the correct number of arguments is provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open the input file for reading
    input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    // Check if the file exists and is a regular file
    if (access(argv[1], F_OK | W_OK) != 0) {
        fprintf(stderr, "File %s does not exist.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Open the output file for writing
    output_file = fopen("output.bin", "wb");
    if (output_file == NULL) {
        perror("Error opening output file");
        fclose(input_file);
        exit(EXIT_FAILURE);
    }

    // Read the first 4 bytes of the input file to check the magic number
    bytes_read = fread(buffer, 1, 4, input_file);
    if (bytes_read != 4) {
        perror("Error reading input file");
        fclose(input_file);
        fclose(output_file);
        exit(EXIT_FAILURE);
    }

    // Check if the magic number is found
    if (memcmp(buffer, (unsigned char *)&magic_number, 4) != 0) {
        fprintf(stderr, "Invalid magic number in input file\n");
        fclose(input_file);
        fclose(output_file);
        exit(EXIT_FAILURE);
    }

    printf("Valid magic number found. Recovering data...\n");

    // Write the data to the output file in chunks of 1024 bytes
    while ((bytes_read = fread(buffer, 1, BUF_SIZE, input_file)) > 0) {
        fwrite(buffer, 1, bytes_read, output_file);
    }

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    printf("Data recovery completed. output.bin file created.\n");

    return EXIT_SUCCESS;
}