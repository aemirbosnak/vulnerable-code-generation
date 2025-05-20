//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_NAME_LEN 256
#define MAX_BUF_SIZE 1024

int main() {
    // Open a file in read-write mode
    FILE *file = fopen("example.txt", "r+");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Get the current line from the file
    char *line = NULL;
    size_t len = 0;
    if (getline(&line, &len, file) == -1) {
        perror("Error reading line");
        return 1;
    }

    // Print the current line
    printf("%s\n", line);

    // Write a new line to the file
    char *new_line = "Hello, world!";
    if (fwrite(new_line, 1, strlen(new_line), file) != strlen(new_line)) {
        perror("Error writing to file");
        return 1;
    }

    // Get the current line again
    if (getline(&line, &len, file) == -1) {
        perror("Error reading line");
        return 1;
    }

    // Print the updated line
    printf("%s\n", line);

    // Close the file
    if (fclose(file) == EOF) {
        perror("Error closing file");
        return 1;
    }

    return 0;
}

// Helper function to get a line from a file
ssize_t getline(char **line, size_t *len, FILE *file) {
    size_t bytes_read = 0;
    char buffer[MAX_BUF_SIZE];

    // Read a line from the file
    while (1) {
        // Read a chunk of data from the file
        ssize_t ret = fread(buffer, 1, MAX_BUF_SIZE, file);
        if (ret == 0) {
            // End of file
            break;
        }

        // Check if the line is too long
        if (bytes_read + ret > MAX_BUF_SIZE) {
            // Truncate the line to avoid overflow
            memmove(buffer, buffer + bytes_read, ret);
            buffer[ret] = '\0';
            break;
        }

        // Add the line to the result
        *line = buffer;
        *len = bytes_read;
        break;
    }

    return bytes_read;
}