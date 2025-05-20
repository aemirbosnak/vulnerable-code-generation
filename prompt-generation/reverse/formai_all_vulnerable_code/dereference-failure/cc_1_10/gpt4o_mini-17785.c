//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256
#define MAX_TRIES 3

#define FILE_PATH "data.txt"

void handle_file_error(const char *message) {
    fprintf(stderr, "File Error: %s\n", message);
    exit(EXIT_FAILURE);
}

void handle_memory_error() {
    fprintf(stderr, "Memory Allocation Error: Unable to allocate memory.\n");
    exit(EXIT_FAILURE);
}

void read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        handle_file_error("Could not open the file for reading.");
    }

    char buffer[MAX_BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("Read from file: %s", buffer);
    }

    if (ferror(file)) {
        handle_file_error("Error reading the file.");
    }
    
    fclose(file);
    printf("Successfully finished reading the file.\n");
}

void write_to_file(const char *filename, const char *data) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        handle_file_error("Could not open the file for writing.");
    }

    if (fputs(data, file) == EOF) {
        handle_file_error("Error writing to the file.");
    }

    fclose(file);
    printf("Data written to file successfully: '%s'\n", data);
}

char *get_dynamic_input() {
    char *input = (char *)malloc(MAX_BUFFER_SIZE * sizeof(char));
    if (input == NULL) {
        handle_memory_error();
    }

    printf("Please enter some data (up to %d characters): ", MAX_BUFFER_SIZE - 1);
    if (fgets(input, MAX_BUFFER_SIZE, stdin) == NULL) {
        handle_memory_error();
    }
    
    // Remove newline character
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    return input;
}

int main() {
    printf("Surprise! This is a C Error Handling Example Program!\n");

    char *inputData = get_dynamic_input();
    
    write_to_file(FILE_PATH, inputData);
    read_file(FILE_PATH);

    free(inputData);
    printf("Surprise! All actions were successfully executed!\n");

    return 0;
}