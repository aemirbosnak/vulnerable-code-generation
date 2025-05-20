//FormAI DATASET v1.0 Category: Error handling ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void read_file(char *filename) {
    FILE *file;
    char *buffer;
    long file_size;

    // Open the file
    file = fopen(filename, "rb");
    if (file == NULL) {
        // Print an error message and exit if opening the file fails
        fprintf(stderr, "Error opening file. %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);

    // Allocate memory for the buffer
    buffer = (char *) malloc(file_size);
    if (buffer == NULL) {
        // Print an error message and exit if allocating memory fails
        fprintf(stderr, "Error allocating memory. %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Read the file into the buffer
    if (fread(buffer, 1, file_size, file) != file_size) {
        // Print an error message and exit if reading the file fails
        fprintf(stderr, "Error reading file. %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Close the file
    if (fclose(file) != 0) {
        // Print an error message and exit if closing the file fails
        fprintf(stderr, "Error closing file. %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Print the contents of the file
    printf("%s", buffer);

    // Free the memory allocated for the buffer
    free(buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        // Print an error message and exit if the number of arguments is not correct
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    read_file(argv[1]);

    return 0;
}