//GEMINI-pro DATASET v1.0 Category: File handling ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This program reads a text file and prints its contents in a shape-shifting style.

int main() {
    // Open the text file.
    FILE *file = fopen("text.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return EXIT_FAILURE;
    }

    // Get the file size.
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    // Read the file into a buffer.
    char *buffer = malloc(size + 1);
    fread(buffer, 1, size, file);
    buffer[size] = '\0';

    // Close the file.
    fclose(file);

    // Create a pointer to the start of the buffer.
    char *ptr = buffer;

    // Loop through the buffer.
    while (*ptr != '\0') {
        // Print the current character.
        printf("%c", *ptr);

        // Move the pointer to the next character.
        ptr++;

        // Check if the pointer has reached the end of the buffer.
        if (*ptr == '\0') {
            // If the pointer has reached the end of the buffer, reset it to the start of the buffer.
            ptr = buffer;
        }
    }

    // Free the buffer.
    free(buffer);

    return EXIT_SUCCESS;
}