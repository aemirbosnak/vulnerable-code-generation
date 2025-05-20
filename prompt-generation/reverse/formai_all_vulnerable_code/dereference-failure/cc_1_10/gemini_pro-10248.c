//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LENGTH 1024

int main(int argc, char *argv[]) {
    // Check if the user provided a filename
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the file for reading
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Read the file into a buffer
    char buffer[MAX_LENGTH];
    size_t length = fread(buffer, 1, MAX_LENGTH, file);
    if (length == 0) {
        fprintf(stderr, "fread: failed to read from file\n");
        return EXIT_FAILURE;
    }

    // Close the file
    fclose(file);

    // Parse the file to find the boot optimization options
    char *options[MAX_LENGTH];
    int num_options = 0;
    char *line = strtok(buffer, "\n");
    while (line != NULL) {
        if (strncmp(line, "boot-option ", 12) == 0) {
            options[num_options++] = line + 12;
        }
        line = strtok(NULL, "\n");
    }

    // Print the boot optimization options
    for (int i = 0; i < num_options; i++) {
        printf("%s\n", options[i]);
    }

    return EXIT_SUCCESS;
}