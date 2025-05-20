//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_FILE_SIZE 100000
#define MAX_LINE_LENGTH 255

// Structure to hold information about the file
typedef struct {
    char *filename;
    size_t filesize;
    size_t linelen;
} file_info_t;

// Function to open a file and retrieve its information
file_info_t *get_file_info(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    file_info_t *file_info = malloc(sizeof(file_info_t));
    file_info->filename = strdup(filename);
    file_info->filesize = ftell(file);
    file_info->linelen = 0;

    // Get the line count and line length
    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, file)) {
        file_info->linelen += strlen(buffer);
    }

    fclose(file);
    return file_info;
}

// Function to print the file information
void print_file_info(file_info_t *file_info) {
    printf("File: %s\n", file_info->filename);
    printf("Size: %zu bytes\n", file_info->filesize);
    printf("Line count: %zu\n", file_info->linelen);
}

int main() {
    // Open the file and retrieve its information
    file_info_t *file_info = get_file_info("example.txt");
    if (!file_info) {
        return 1;
    }

    // Print the file information
    print_file_info(file_info);

    // Calculate the average line length
    double average_line_length = file_info->linelen / (double)file_info->filesize;
    printf("Average line length: %f\n", average_line_length);

    // Calculate the entropy of the file
    int entropy = calculate_entropy(file_info->filename, file_info->filesize);
    printf("Entropy: %d\n", entropy);

    // Free the memory allocated for the file information
    free(file_info);

    return 0;
}

// Function to calculate the entropy of a file
int calculate_entropy(const char *filename, size_t filesize) {
    // Initialize the entropy value
    int entropy = 0;

    // Read the file and calculate the entropy
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return -1;
    }

    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, file)) {
        entropy += calculate_entropy_for_line(buffer);
    }

    fclose(file);
    return entropy;
}

// Function to calculate the entropy of a line
int calculate_entropy_for_line(const char *line) {
    // Initialize the entropy value
    int entropy = 0;

    // Calculate the number of unique characters in the line
    int unique_chars = 0;
    for (int i = 0; i < strlen(line); i++) {
        if (isalpha(line[i]) || isdigit(line[i]) || ispunct(line[i])) {
            unique_chars++;
        }
    }

    // Calculate the entropy
    entropy += (-unique_chars * log(unique_chars)) / log(256);

    return entropy;
}