//Falcon-180B DATASET v1.0 Category: Error handling ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ERROR_MESSAGE_LENGTH 256

// Function to print error messages
void print_error(const char *message, int error_code) {
    char error_message[MAX_ERROR_MESSAGE_LENGTH];
    strerror_r(error_code, error_message, MAX_ERROR_MESSAGE_LENGTH);
    fprintf(stderr, "Error: %s - %s\n", message, error_message);
    exit(1);
}

// Function to read a line from a file
char *read_line(FILE *file) {
    char *line = NULL;
    size_t line_size = 0;
    ssize_t bytes_read;

    // Allocate memory for the line
    line = malloc(MAX_LINE_LENGTH);
    if (line == NULL) {
        print_error("Failed to allocate memory for line", ENOMEM);
    }

    // Read the line
    while ((bytes_read = getline(&line, &line_size, file))!= -1) {
        if (bytes_read >= MAX_LINE_LENGTH - 1) {
            print_error("Line is too long", EINVAL);
        }
    }

    if (bytes_read == -1) {
        print_error("Failed to read line", errno);
    }

    return line;
}

// Function to write a line to a file
void write_line(FILE *file, const char *line) {
    size_t bytes_written;

    // Write the line
    bytes_written = fprintf(file, "%s\n", line);
    if (bytes_written < 0) {
        print_error("Failed to write line", errno);
    }
}

// Function to copy a file
void copy_file(const char *source_file, const char *destination_file) {
    FILE *source, *destination;
    char *line;

    // Open the source file for reading
    source = fopen(source_file, "r");
    if (source == NULL) {
        print_error("Failed to open source file", errno);
    }

    // Open the destination file for writing
    destination = fopen(destination_file, "w");
    if (destination == NULL) {
        print_error("Failed to open destination file", errno);
    }

    // Copy the contents of the source file to the destination file
    while ((line = read_line(source))!= NULL) {
        write_line(destination, line);
    }

    // Close the files
    fclose(source);
    fclose(destination);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        print_error("Usage: copy_file <source_file> <destination_file>", 0);
    }

    copy_file(argv[1], argv[2]);

    return 0;
}