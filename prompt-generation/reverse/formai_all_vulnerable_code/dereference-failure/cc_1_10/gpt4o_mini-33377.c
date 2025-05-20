//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 255
#define MAX_LINE_LENGTH 1024

void handle_error(const char *message) {
    fprintf(stderr, "An error occurred: %s\n", message);
    if (errno != 0) {
        fprintf(stderr, "Error code: %d, %s\n", errno, strerror(errno));
    }
    exit(EXIT_FAILURE);
}

FILE* open_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    
    if (file == NULL) {
        handle_error("Could not open the file for reading");
    }
    
    return file;
}

void read_file_data(FILE *file) {
    char line[MAX_LINE_LENGTH];
    int line_count = 0;

    while (fgets(line, sizeof(line), file)) {
        line_count++;
        printf("Line %d: %s", line_count, line);
    }
    
    if (ferror(file)) {
        handle_error("Error reading from the file");
    }
    
    printf("Total lines read: %d\n", line_count);
}

void close_file(FILE *file) {
    if (fclose(file) != 0) {
        handle_error("Could not close the file");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        handle_error("Usage: ./file_reader <filename>");
    }

    char filename[MAX_FILENAME_LENGTH];
    snprintf(filename, sizeof(filename), "%s", argv[1]);

    FILE *file = open_file(filename);
    read_file_data(file);
    close_file(file);

    printf("~~~ End of the reading saga ~~~\n");
    return EXIT_SUCCESS;
}