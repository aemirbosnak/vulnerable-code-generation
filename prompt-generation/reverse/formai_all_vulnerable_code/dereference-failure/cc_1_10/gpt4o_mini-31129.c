//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define FILE_NAME "data.txt"

void handle_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void read_file() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        handle_error("Failed to open file");
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        printf("Read line: %s", line);
    }

    if (ferror(file)) {
        handle_error("Error reading the file");
    }

    if (fclose(file) != 0) {
        handle_error("Failed to close the file");
    }
}

void write_to_file(const char *content) {
    FILE *file = fopen(FILE_NAME, "w");
    if (!file) {
        handle_error("Failed to open file for writing");
    }

    if (fputs(content, file) == EOF) {
        handle_error("Error writing to file");
    }

    if (fclose(file) != 0) {
        handle_error("Failed to close the file after writing");
    }
}

void append_to_file(const char *content) {
    FILE *file = fopen(FILE_NAME, "a");
    if (!file) {
        handle_error("Failed to open file for appending");
    }

    if (fputs(content, file) == EOF) {
        handle_error("Error appending to file");
    }

    if (fclose(file) != 0) {
        handle_error("Failed to close the file after appending");
    }
}

int main() {
    const char *message = "This is a test.\n";

    write_to_file(message);
    printf("Content written to '%s'.\n", FILE_NAME);

    append_to_file("Appending some more text.\n");
    printf("Content appended to '%s'.\n", FILE_NAME);

    printf("Reading the entire file:\n");
    read_file();

    printf("Operations completed successfully.\n");
    return 0;
}