//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_BUFFER 256
#define FILE_PATH "example.txt"

/* Function to read data from a file */
void read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s: %s\n", filename, strerror(errno));
        return;
    }

    char buffer[MAX_BUFFER];
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }

    if (ferror(file)) {
        fprintf(stderr, "Error reading from file %s: %s\n", filename, strerror(errno));
    }

    if (fclose(file) != 0) {
        fprintf(stderr, "Error closing file %s: %s\n", filename, strerror(errno));
    }
}

/* Function to write data to a file */
void write_file(const char *filename, const char *data) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s: %s\n", filename, strerror(errno));
        return;
    }

    if (fputs(data, file) == EOF) {
        fprintf(stderr, "Error writing to file %s: %s\n", filename, strerror(errno));
    }

    if (fclose(file) != 0) {
        fprintf(stderr, "Error closing file %s: %s\n", filename, strerror(errno));
    }
}

/* Function to get user input safely */
void get_user_input(char *buffer, size_t size) {
    if (fgets(buffer, size, stdin) == NULL) {
        fprintf(stderr, "Error reading input: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    // Remove newline character if present
    buffer[strcspn(buffer, "\n")] = '\0';
}

int main() {
    char input[MAX_BUFFER];
    printf("Welcome to the File Example Program!\n");
    
    // Writing data to file
    printf("Please enter data to write to the file (max %d characters):\n", MAX_BUFFER - 1);
    get_user_input(input, sizeof(input));
    write_file(FILE_PATH, input);

    // Reading data back from file
    printf("Data read from the file:\n");
    read_file(FILE_PATH);

    // Check if the file is readable after modifications
    printf("Checking if the file can still be read...\n");
    read_file(FILE_PATH);

    // Analyzing file size
    FILE *file = fopen(FILE_PATH, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file for size check: %s\n", strerror(errno));
    } else {
        fseek(file, 0, SEEK_END);
        long filesize = ftell(file);
        if (filesize == -1) {
            fprintf(stderr, "Error determining file size: %s\n", strerror(errno));
        } else {
            printf("File size: %ld bytes\n", filesize);
        }
        fclose(file);
    }

    // Cleanup
    if (remove(FILE_PATH) == 0) {
        printf("Temporary file '%s' deleted successfully.\n", FILE_PATH);
    } else {
        fprintf(stderr, "Error deleting file %s: %s\n", FILE_PATH, strerror(errno));
    }

    printf("Program completed successfully!\n");
    return 0;
}