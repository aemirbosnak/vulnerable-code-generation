//MISTRAL-7B DATASET v1.0 Category: System administration ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char *filename;
    size_t size;
    char *buffer;

    // Check if the correct number of arguments are provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Allocate memory for the buffer
    filename = argv[1];
    size = 1024;
    buffer = (char *) malloc(size);

    // Open the file in read-only mode
    fp = fopen(filename, "r");

    if (fp == NULL) {
        perror("Error opening file");
        free(buffer);
        return 1;
    }

    // Read the contents of the file into the buffer
    size_t bytes_read = fread(buffer, 1, size, fp);

    if (bytes_read == 0) {
        fprintf(stderr, "Error reading file\n");
        fclose(fp);
        free(buffer);
        return 1;
    }

    // Print the contents of the file to the console
    printf("%s\n", buffer);

    // Free the memory allocated for the buffer
    free(buffer);

    // Close the file
    fclose(fp);

    return 0;
}