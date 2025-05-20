//GEMINI-pro DATASET v1.0 Category: File handling ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom error handling function
void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

// Safe file reading function
char *read_file(const char *filename) {
    // Open file in read-only mode
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        error("fopen");
    }

    // Get file size
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Allocate memory for file contents
    char *buf = malloc(size + 1);
    if (buf == NULL) {
        error("malloc");
    }

    // Read file contents
    if (fread(buf, sizeof(char), size, fp) != size) {
        error("fread");
    }

    // Null-terminate string
    buf[size] = '\0';

    // Close file
    fclose(fp);

    // Return file contents
    return buf;
}

// Safe file writing function
void write_file(const char *filename, const char *buf) {
    // Open file in write-only mode
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        error("fopen");
    }

    // Write file contents
    if (fwrite(buf, sizeof(char), strlen(buf), fp) != strlen(buf)) {
        error("fwrite");
    }

    // Close file
    fclose(fp);
}

// Example usage
int main() {
    // Read file
    char *file_contents = read_file("data.txt");

    // Process file contents
    // ...

    // Write file
    write_file("output.txt", file_contents);

    // Free memory
    free(file_contents);

    return 0;
}