//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    char *filename = argv[1];
    char *output_filename = argv[2];
    int file_size = 0;

    // Check if the input file exists
    if (access(filename, F_OK) == -1) {
        printf("Input file does not exist.\n");
        exit(1);
    }

    // Open the input file for reading
    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Get the size of the input file
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);

    // Allocate memory for the file contents
    char *file_contents = malloc(file_size);
    if (file_contents == NULL) {
        printf("Error allocating memory.\n");
        exit(1);
    }

    // Read the contents of the input file into memory
    while (fread(buffer, 1, BUFFER_SIZE, file) > 0) {
        memcpy(file_contents + file_size - fread(buffer, 1, BUFFER_SIZE, file), buffer, fread(buffer, 1, BUFFER_SIZE, file));
    }

    // Close the input file
    fclose(file);

    // Open the output file for writing
    file = fopen(output_filename, "wb");
    if (file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Write the file contents to the output file
    fwrite(file_contents, 1, file_size, file);

    // Close the output file
    fclose(file);

    // Free the memory used for the file contents
    free(file_contents);

    printf("File successfully recovered.\n");

    return 0;
}