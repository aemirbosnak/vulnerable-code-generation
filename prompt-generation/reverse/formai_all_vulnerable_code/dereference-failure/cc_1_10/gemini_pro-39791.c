//GEMINI-pro DATASET v1.0 Category: File handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 1024

// A simple text editor in C!

// Function to open a file
FILE *open_file(char *filename, char *mode) {
    FILE *fp = fopen(filename, mode);
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    return fp;
}

// Function to read a file
char *read_file(FILE *fp) {
    char *buffer = malloc(MAX_LEN);
    int len = fread(buffer, 1, MAX_LEN, fp);
    buffer[len] = '\0';
    return buffer;
}

// Function to write to a file
void write_file(FILE *fp, char *buffer) {
    int len = strlen(buffer);
    fwrite(buffer, 1, len, fp);
}

// Main function
int main() {
    // Open the file in read mode
    FILE *fp = open_file("text.txt", "r");

    // Read the file into a buffer
    char *buffer = read_file(fp);

    // Close the file
    fclose(fp);

    // Modify the buffer
    strcat(buffer, "\nThis is the new text.");

    // Open the file in write mode
    fp = open_file("text.txt", "w");

    // Write the buffer to the file
    write_file(fp, buffer);

    // Close the file
    fclose(fp);

    // Free the buffer
    free(buffer);

    return 0;
}