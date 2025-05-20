//Falcon-180B DATASET v1.0 Category: Error handling ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// Function prototypes
void handle_error(char *msg);
int read_file(FILE *fp, char *buffer, int size);

// Main function
int main() {
    FILE *fp;
    char buffer[1024];
    int size;

    // Open file for reading
    fp = fopen("example.txt", "r");

    // Check if file was opened successfully
    if (fp == NULL) {
        handle_error("Error opening file");
        return 1;
    }

    // Read file into buffer
    size = read_file(fp, buffer, sizeof(buffer));

    // Check if file was read successfully
    if (size <= 0) {
        handle_error("Error reading file");
        return 1;
    }

    // Print buffer to console
    printf("File contents:\n%s", buffer);

    // Close file
    if (fclose(fp)!= 0) {
        handle_error("Error closing file");
        return 1;
    }

    return 0;
}

// Function to handle errors
void handle_error(char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(EXIT_FAILURE);
}

// Function to read file
int read_file(FILE *fp, char *buffer, int size) {
    int bytes_read;

    // Read file into buffer
    bytes_read = fread(buffer, 1, size, fp);

    // Check for errors
    if (bytes_read == 0) {
        if (ferror(fp)) {
            handle_error("Error reading file");
        }
    } else if (bytes_read < 0) {
        handle_error("Error reading file");
    }

    return bytes_read;
}