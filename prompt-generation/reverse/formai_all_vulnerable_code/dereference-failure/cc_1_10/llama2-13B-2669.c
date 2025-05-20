//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define MAX_FILE_SIZE 1024*1024*10

// Function to read a file into a single line
size_t read_file(const char* filename, char** line) {
    size_t len = 0;
    size_t left = 0;
    char* buffer = malloc(1024);
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return len;
    }
    while (fgets(buffer, 1024, file)) {
        len += strlen(buffer);
        left -= strlen(buffer);
        if (left < 1024) {
            break;
        }
    }
    *line = buffer;
    fclose(file);
    return len;
}

// Function to write a line to a file
size_t write_file(const char* filename, const char* line) {
    size_t len = strlen(line);
    size_t left = 0;
    char* buffer = malloc(1024);
    FILE* file = fopen(filename, "a");
    if (!file) {
        perror("Error opening file");
        return len;
    }
    while (left < len) {
        size_t write_len = 1024 - left;
        if (write_len > len - left) {
            write_len = len - left;
        }
        fwrite(line + left, 1, write_len, file);
        left += write_len;
        if (left < len) {
            break;
        }
    }
    fclose(file);
    free(buffer);
    return len;
}

// Function to truncate a file to a given size
size_t truncate_file(const char* filename, size_t size) {
    size_t left = 0;
    char* buffer = malloc(1024);
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return left;
    }
    size_t len = 0;
    while (fgets(buffer, 1024, file)) {
        len += strlen(buffer);
        left -= strlen(buffer);
        if (left < size) {
            break;
        }
    }
    fclose(file);
    free(buffer);
    return len;
}

int main() {
    char* line = NULL;
    size_t len = read_file("example.txt", &line);
    if (len == 0) {
        printf("Error reading file\n");
        return 1;
    }
    printf("File contents: %s\n", line);

    // Truncate the file to 50% of its original size
    size_t truncate_size = truncate_file("example.txt", len / 2);
    if (truncate_size == 0) {
        perror("Error truncating file");
        return 2;
    }

    // Write a new line to the file
    size_t write_len = write_file("example.txt", "New line added\n");
    if (write_len == 0) {
        perror("Error writing to file");
        return 3;
    }

    // Check if the file has been truncated successfully
    char* contents = malloc(len + 1);
    FILE* file = fopen("example.txt", "r");
    if (!file) {
        perror("Error opening file");
        return 4;
    }
    fread(contents, 1, len, file);
    fclose(file);
    contents[len] = '\0';
    if (strcmp(contents, line) != 0) {
        printf("File truncation failed\n");
        return 5;
    }

    free(line);
    free(contents);
    return 0;
}