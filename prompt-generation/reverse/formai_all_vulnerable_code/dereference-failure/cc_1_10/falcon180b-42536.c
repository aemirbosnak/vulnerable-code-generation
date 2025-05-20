//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024 // Maximum size of a line of text
#define MAX_FILE_SIZE (1024 * 1024) // Maximum size of a file in bytes

// Struct to hold information about an open file
typedef struct {
    FILE* file; // File handle
    char* filename; // Name of the file
    int lines; // Number of lines in the file
} FileInfo;

// Function to read a line of text from a file
char* read_line(FILE* file) {
    char* line = malloc(MAX_LINE_SIZE);
    if (fgets(line, MAX_LINE_SIZE, file) == NULL) {
        line[0] = '\0'; // Set the first character to null if fgets fails
    }
    return line;
}

// Function to count the number of lines in a file
int count_lines(FILE* file) {
    int lines = 0;
    char* line = read_line(file);
    while (line!= NULL) {
        lines++;
        line = read_line(file);
    }
    return lines;
}

// Function to open a file for reading
FileInfo* open_file(const char* filename) {
    FileInfo* file_info = malloc(sizeof(FileInfo));
    file_info->filename = strdup(filename);
    file_info->file = fopen(filename, "r");
    if (file_info->file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }
    file_info->lines = count_lines(file_info->file);
    return file_info;
}

// Function to close an open file
void close_file(FileInfo* file_info) {
    fclose(file_info->file);
    free(file_info->filename);
    free(file_info);
}

// Function to read a line from an open file
char* read_file_line(FileInfo* file_info, int line_num) {
    int i;
    for (i = 0; i < line_num - 1; i++) {
        char* line = read_line(file_info->file);
    }
    return read_line(file_info->file);
}

// Function to print a line of text
void print_line(const char* line) {
    printf("%s", line);
}

// Function to print a specified number of lines from an open file
void print_file_lines(FileInfo* file_info, int num_lines) {
    int i;
    for (i = 0; i < num_lines && file_info->lines > 0; i++) {
        print_line(read_file_line(file_info, i + 1));
    }
}

// Main function
int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <filename> <num_lines>\n", argv[0]);
        return 1;
    }
    const char* filename = argv[1];
    int num_lines = atoi(argv[2]);

    FileInfo* file_info = open_file(filename);
    if (num_lines > file_info->lines) {
        num_lines = file_info->lines;
    }
    print_file_lines(file_info, num_lines);

    close_file(file_info);
    return 0;
}