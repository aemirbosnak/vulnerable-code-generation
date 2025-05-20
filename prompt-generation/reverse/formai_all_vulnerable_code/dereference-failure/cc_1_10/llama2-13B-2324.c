//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_SIZE 10000
#define MAX_LINE_SIZE 200

// Structure to store information about a file
typedef struct {
    char *name;    // File name
    size_t size;   // File size
    size_t lines;  // Number of lines
} file_info_t;

// Function to read a file and store its information
file_info_t read_file(const char *file_path) {
    file_info_t info;
    info.name = strdup(file_path);
    info.size = 0;
    info.lines = 0;

    // Open the file in read mode
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Failed to open file");
        return info;
    }

    // Read the file and count its lines
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file) != NULL) {
        info.lines++;
        info.size += strlen(line) + 1; // Include the newline char
    }

    // Close the file and return the information
    fclose(file);
    return info;
}

// Function to write a file and store its information
void write_file(const char *file_path, const file_info_t *info) {
    // Open the file in write mode
    FILE *file = fopen(file_path, "w");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    // Write the file's name and size to the file
    fprintf(file, "Name: %s\nSize: %zu\n", info->name, info->size);

    // Write each line of the file
    char line[MAX_LINE_SIZE];
    for (size_t i = 0; i < info->lines; i++) {
        fprintf(file, "%s\n", line);
    }

    // Close the file
    fclose(file);
}

// Example usage of the file handler functions
int main() {
    // Read a file and store its information
    file_info_t info = read_file("example.txt");
    printf("File name: %s\nSize: %zu\nLines: %zu\n", info.name, info.size, info.lines);

    // Write the file's information to a new file
    write_file("output.txt", &info);

    return 0;
}