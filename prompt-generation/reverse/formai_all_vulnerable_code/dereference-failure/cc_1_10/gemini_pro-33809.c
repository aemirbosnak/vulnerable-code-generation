//GEMINI-pro DATASET v1.0 Category: File handling ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to safely open a file for reading
FILE* open_file_for_reading(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }
    return file;
}

// Function to safely open a file for writing
FILE* open_file_for_writing(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }
    return file;
}

// Function to safely close a file
void close_file(FILE* file) {
    if (fclose(file) != 0) {
        perror("Error closing file");
        exit(EXIT_FAILURE);
    }
}

// Function to read a line from a file
char* read_line(FILE* file) {
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    if ((read = getline(&line, &len, file)) == -1) {
        perror("Error reading line from file");
        exit(EXIT_FAILURE);
    }

    return line;
}

// Function to write a line to a file
void write_line(FILE* file, const char* line) {
    if (fprintf(file, "%s", line) < 0) {
        perror("Error writing line to file");
        exit(EXIT_FAILURE);
    }
}

// Function to copy a file
void copy_file(const char* src_filename, const char* dest_filename) {
    FILE* src_file = open_file_for_reading(src_filename);
    FILE* dest_file = open_file_for_writing(dest_filename);

    char* line;
    while ((line = read_line(src_file)) != NULL) {
        write_line(dest_file, line);
        free(line);
    }

    close_file(src_file);
    close_file(dest_file);
}

int main() {
    // Copy the file "source.txt" to "destination.txt"
    copy_file("source.txt", "destination.txt");

    return 0;
}