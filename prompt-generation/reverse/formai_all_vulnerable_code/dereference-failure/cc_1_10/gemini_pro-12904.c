//GEMINI-pro DATASET v1.0 Category: File handling ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Decentralized file handling functions
void decentralized_file_open(FILE **f, const char *path, const char *mode) {
    // If the file already exists, append the content
    if (mode[0] == 'a' && fopen(path, "r") != NULL) {
        *f = fopen(path, "a");
        return;
    }

    // Otherwise, open the file in the specified mode
    *f = fopen(path, mode);
    if (*f == NULL) {
        perror("Error opening file");
        exit(1);
    }
}

void decentralized_file_close(FILE *f) {
    fclose(f);
}

void decentralized_file_write(FILE *f, const char *buf, size_t len) {
    fwrite(buf, 1, len, f);
}

char *decentralized_file_read(FILE *f) {
    // Get the file size
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);

    // Allocate the buffer
    char *buf = malloc(size + 1);
    if (buf == NULL) {
        perror("Error allocating buffer");
        exit(1);
    }

    // Read the file into the buffer
    fread(buf, 1, size, f);
    buf[size] = '\0';

    // Return the buffer
    return buf;
}

// Example usage
int main() {
    // Open a file for writing
    FILE *f;
    decentralized_file_open(&f, "test.txt", "w");

    // Write some data to the file
    decentralized_file_write(f, "Hello world!\n", strlen("Hello world!\n"));

    // Close the file
    decentralized_file_close(f);

    // Open the file for reading
    decentralized_file_open(&f, "test.txt", "r");

    // Read the data from the file
    char *data = decentralized_file_read(f);

    // Print the data
    printf("%s", data);

    // Free the buffer
    free(data);

    // Close the file
    decentralized_file_close(f);

    return 0;
}