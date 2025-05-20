//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// Function to read an integer from a file
int read_integer_from_file(FILE *file) {
    int value;
    if (fscanf(file, "%d", &value) != 1) {
        if (feof(file)) {
            printf("Reached the end of the file gracefully.\n");
        } else {
            printf("Error reading integer from file: %s\n", strerror(errno));
        }
        return -1; // Return an invalid value on error
    }
    return value;
}

// Function to write to a file
void write_integer_to_file(FILE *file, int value) {
    if (fprintf(file, "%d\n", value) < 0) {
        printf("Error writing integer to file: %s\n", strerror(errno));
    } else {
        printf("Successfully wrote %d to file.\n", value);
    }
}

// Function to handle file operations
void handle_file_operations(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Failed to open file for reading: %s\n", strerror(errno));
        return;
    }

    printf("File '%s' opened successfully for reading!\n", filename);
    int number;
    while ((number = read_integer_from_file(file)) != -1) {
        printf("Read integer: %d from file.\n", number);
    }

    fclose(file);
    printf("File '%s' closed successfully after reading.\n", filename);
}

// Function to create and write to a new file
void create_and_write_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Failed to open file for writing: %s\n", strerror(errno));
        return;
    }

    printf("File '%s' opened successfully for writing!\n", filename);
    for (int i = 1; i <= 10; i++) {
        write_integer_to_file(file, i);
    }

    fclose(file);
    printf("File '%s' closed successfully after writing.\n", filename);
}

int main() {
    const char *filename = "numbers.txt";

    create_and_write_file(filename);
    
    handle_file_operations(filename);
    
    printf("Thank you for using the file operations program!\n");
    return 0;
}