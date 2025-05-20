//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    // Check for the correct number of arguments.
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the input file.
    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Open the output file.
    FILE *output = fopen(argv[2], "w");
    if (output == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Read the input file.
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), input) != NULL) {
        // Write the buffer to the output file.
        if (fputs(buffer, output) == EOF) {
            fprintf(stderr, "Error writing to output file: %s\n", strerror(errno));
            return EXIT_FAILURE;
        }
    }

    // Close the input file.
    if (fclose(input) == EOF) {
        fprintf(stderr, "Error closing input file: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Close the output file.
    if (fclose(output) == EOF) {
        fprintf(stderr, "Error closing output file: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}