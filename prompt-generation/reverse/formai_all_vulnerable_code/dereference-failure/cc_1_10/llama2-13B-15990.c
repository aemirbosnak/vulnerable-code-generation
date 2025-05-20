//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>

#define MAX_FILE_NAME 50
#define MAX_LINE_LENGTH 100

// Structure to store file information
typedef struct {
    char name[MAX_FILE_NAME];
    long int size;
} file_info_t;

// Function to read a file and return its contents as a string
char* read_file(const char* file_name) {
    file_info_t* file_info = malloc(sizeof(file_info_t));
    FILE* file = fopen(file_name, "r");

    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Get file size
    fseek(file, 0, SEEK_END);
    file_info->size = ftell(file);
    rewind(file);

    // Allocate memory for the file contents
    char* file_contents = malloc(file_info->size + 1);

    // Read the file contents
    size_t bytes_read = fread(file_contents, 1, file_info->size, file);

    // Check for errors
    if (bytes_read != file_info->size) {
        perror("Error reading file");
        free(file_contents);
        return NULL;
    }

    // Close the file
    fclose(file);

    return file_contents;
}

// Function to write a file and return its contents as a string
char* write_file(const char* file_name, const char* contents) {
    file_info_t* file_info = malloc(sizeof(file_info_t));
    FILE* file = fopen(file_name, "w");

    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Write the file contents
    size_t bytes_written = fwrite(contents, 1, strlen(contents), file);

    // Check for errors
    if (bytes_written != strlen(contents)) {
        perror("Error writing file");
        fclose(file);
        return NULL;
    }

    // Get file size
    file_info->size = ftell(file);

    // Close the file
    fclose(file);

    return contents;
}

int main() {
    // Open a file and read its contents
    char* file_contents = read_file("example.txt");

    if (file_contents == NULL) {
        printf("Error reading file\n");
        return 1;
    }

    // Print the file contents
    printf("File contents: %s\n", file_contents);

    // Write some data to the file
    char new_contents[] = "This is a new file contents!";
    write_file("example.txt", new_contents);

    // Open the file again and read its contents
    file_contents = read_file("example.txt");

    if (file_contents == NULL) {
        printf("Error reading file\n");
        return 1;
    }

    // Print the new file contents
    printf("New file contents: %s\n", file_contents);

    // Free the memory allocated for the file contents
    free(file_contents);

    return 0;
}