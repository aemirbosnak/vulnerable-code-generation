//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_FILE_CONTENT_LENGTH 1024

// Function to read a file and handle errors appropriately.
void read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file '%s': %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }

    char content[MAX_FILE_CONTENT_LENGTH];
    while (fgets(content, sizeof(content), file) != NULL) {
        printf("%s", content);
    }

    if (ferror(file)) {
        fprintf(stderr, "Error reading file '%s': %s\n", filename, strerror(errno));
        fclose(file);
        exit(EXIT_FAILURE);
    }

    if (fclose(file) != 0) {
        fprintf(stderr, "Error closing file '%s': %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }
}

// Function to write to a file and handle errors appropriately.
void write_file(const char *filename, const char *content) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file '%s' for writing: %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (fputs(content, file) == EOF) {
        fprintf(stderr, "Error writing to file '%s': %s\n", filename, strerror(errno));
        fclose(file);
        exit(EXIT_FAILURE);
    }

    if (fclose(file) != 0) {
        fprintf(stderr, "Error closing file '%s': %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }
}

// Function to get input from the user securely.
void get_input(char *buffer, size_t size) {
    printf("Enter content to write to file: ");
    if (fgets(buffer, size, stdin) == NULL) {
        fprintf(stderr, "Error reading input: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Remove newline character if present
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    char content[MAX_FILE_CONTENT_LENGTH];

    printf("Enter the filename you want to create or read: ");
    if (fgets(filename, sizeof(filename), stdin) == NULL) {
        fprintf(stderr, "Error reading filename: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Remove newline from filename
    size_t len = strlen(filename);
    if (len > 0 && filename[len - 1] == '\n') {
        filename[len - 1] = '\0';
    }

    // Write to file
    get_input(content, sizeof(content));
    write_file(filename, content);
    printf("Content written to '%s' successfully!\n", filename);

    // Read from file
    printf("Reading content back from the file:\n");
    read_file(filename);

    return EXIT_SUCCESS;
}