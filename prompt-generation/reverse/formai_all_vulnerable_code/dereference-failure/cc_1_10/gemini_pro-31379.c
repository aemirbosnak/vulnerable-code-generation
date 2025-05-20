//GEMINI-pro DATASET v1.0 Category: File handling ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the file buffer
#define BUFFER_SIZE 1024

// Define the maximum number of files to be processed
#define MAX_FILES 10

// Define the structure of a file descriptor
typedef struct {
    FILE *file;
    char *filename;
    int line_number;
    char *line_buffer;
    int line_buffer_size;
} file_descriptor;

// Declare an array of file descriptors
file_descriptor files[MAX_FILES];

// Declare a function to open a file
int open_file(file_descriptor *file, const char *filename) {
    // Allocate memory for the file descriptor
    file->file = malloc(sizeof(FILE));
    if (file->file == NULL) {
        return -1;
    }

    // Open the file
    file->file = fopen(filename, "r");
    if (file->file == NULL) {
        return -1;
    }

    // Allocate memory for the filename
    file->filename = malloc(strlen(filename) + 1);
    if (file->filename == NULL) {
        return -1;
    }

    // Copy the filename
    strcpy(file->filename, filename);

    // Initialize the line number
    file->line_number = 1;

    // Allocate memory for the line buffer
    file->line_buffer = malloc(BUFFER_SIZE);
    if (file->line_buffer == NULL) {
        return -1;
    }

    // Initialize the line buffer size
    file->line_buffer_size = BUFFER_SIZE;

    // Return 0 to indicate success
    return 0;
}

// Declare a function to close a file
int close_file(file_descriptor *file) {
    // Close the file
    fclose(file->file);

    // Free the memory allocated for the filename
    free(file->filename);

    // Free the memory allocated for the line buffer
    free(file->line_buffer);

    // Free the memory allocated for the file descriptor
    free(file);

    // Return 0 to indicate success
    return 0;
}

// Declare a function to read a line from a file
int read_line(file_descriptor *file, char *line, int line_size) {
    // Check if the end of the file has been reached
    if (feof(file->file)) {
        return -1;
    }

    // Read a line from the file
    if (fgets(line, line_size, file->file) == NULL) {
        return -1;
    }

    // Remove the newline character from the end of the line
    line[strlen(line) - 1] = '\0';

    // Increment the line number
    file->line_number++;

    // Return 0 to indicate success
    return 0;
}

// Declare a function to process a file
int process_file(file_descriptor *file) {
    // Declare a buffer for the line
    char line[BUFFER_SIZE];

    // Read the first line from the file
    if (read_line(file, line, BUFFER_SIZE) != 0) {
        return -1;
    }

    // Process the first line
    printf("%s\n", line);

    // Read the remaining lines from the file
    while (read_line(file, line, BUFFER_SIZE) == 0) {
        // Process the line
        printf("%s\n", line);
    }

    // Return 0 to indicate success
    return 0;
}

// Declare a function to process a list of files
int process_files(const char *filenames[], int num_files) {
    // Open the files
    for (int i = 0; i < num_files; i++) {
        if (open_file(&files[i], filenames[i]) != 0) {
            return -1;
        }
    }

    // Process the files
    for (int i = 0; i < num_files; i++) {
        if (process_file(&files[i]) != 0) {
            return -1;
        }
    }

    // Close the files
    for (int i = 0; i < num_files; i++) {
        if (close_file(&files[i]) != 0) {
            return -1;
        }
    }

    // Return 0 to indicate success
    return 0;
}

// Declare the main function
int main(int argc, char *argv[]) {
    // Check if the number of arguments is valid
    if (argc < 2) {
        printf("Usage: %s <filename> [<filename> ...]\n", argv[0]);
        return -1;
    }

    // Process the files
    if (process_files(&argv[1], argc - 1) != 0) {
        return -1;
    }

    // Return 0 to indicate success
    return 0;
}