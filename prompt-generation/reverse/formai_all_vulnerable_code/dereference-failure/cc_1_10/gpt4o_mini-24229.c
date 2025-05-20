//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_BUFFER 256

// Function to open file and handle errors
FILE *open_file(const char *filename, const char *mode) {
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        fprintf(stderr, "Error opening file '%s': %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }
    return file;
}

// Function to read a line from a file and handle errors
char *read_line(FILE *file, char *buffer, size_t size) {
    if (fgets(buffer, size, file) == NULL) {
        if (feof(file)) {
            return NULL; // End of file reached
        } else {
            fprintf(stderr, "Error reading line: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
    }
    return buffer;
}

// Function to process data and handle errors
void process_data(char *data) {
    if (data == NULL) {
        fprintf(stderr, "Error: No data to process.\n");
        return; // No data to process
    }
    
    // Simulating processing by printing the length of data
    printf("Processing data: '%s' with length: %zu\n", data, strlen(data));
}

// Main function with structured error handling
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_BUFFER];
    FILE *file = open_file(argv[1], "r");

    while (read_line(file, buffer, sizeof(buffer)) != NULL) {
        // Remove trailing newline character
        buffer[strcspn(buffer, "\n")] = '\0';
        process_data(buffer);
    }

    if (ferror(file)) {
        fprintf(stderr, "Error reading from file: %s\n", strerror(errno));
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fclose(file);
    return EXIT_SUCCESS;
}