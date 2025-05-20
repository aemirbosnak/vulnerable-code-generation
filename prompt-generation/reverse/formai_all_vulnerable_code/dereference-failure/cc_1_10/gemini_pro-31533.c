//GEMINI-pro DATASET v1.0 Category: File handling ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a new file
FILE *create_file(char *filename) {
    FILE *fp;

    // Open the file in write mode
    fp = fopen(filename, "w");

    // Check if the file was successfully opened
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Return the file pointer
    return fp;
}

// Function to write data to a file
void write_data(FILE *fp, char *data) {
    // Write the data to the file
    fwrite(data, strlen(data), 1, fp);

    // Flush the file buffer
    fflush(fp);
}

// Function to read data from a file
char *read_data(FILE *fp) {
    // Read the data from the file
    char *data = malloc(1024);
    fread(data, 1024, 1, fp);

    // Return the data
    return data;
}

// Function to close a file
void close_file(FILE *fp) {
    // Close the file
    fclose(fp);
}

int main() {
    // Create a new file
    FILE *fp = create_file("test.txt");

    // Write data to the file
    write_data(fp, "Hello, world!\n");

    // Read data from the file
    char *data = read_data(fp);

    // Print the data
    printf("%s", data);

    // Close the file
    close_file(fp);

    // Free the allocated memory
    free(data);

    return 0;
}