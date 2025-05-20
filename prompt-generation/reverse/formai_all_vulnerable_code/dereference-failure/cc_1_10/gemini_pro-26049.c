//GEMINI-pro DATASET v1.0 Category: File handling ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of a line in the file
#define MAX_LINE_SIZE 1024

// Function to read a file line by line and print it to the console
void readFileLineByLine(char *filename) {
    // Open the file in read mode
    FILE *file = fopen(filename, "r");

    // Check if the file was opened successfully
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // Read the file line by line
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)) {
        // Print the line to the console
        printf("%s", line);
    }

    // Close the file
    fclose(file);
}

// Function to write a string to a file
void writeStringToFile(char *filename, char *string) {
    // Open the file in write mode
    FILE *file = fopen(filename, "w");

    // Check if the file was opened successfully
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // Write the string to the file
    fputs(string, file);

    // Close the file
    fclose(file);
}

// Function to append a string to a file
void appendStringToFile(char *filename, char *string) {
    // Open the file in append mode
    FILE *file = fopen(filename, "a");

    // Check if the file was opened successfully
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // Append the string to the file
    fputs(string, file);

    // Close the file
    fclose(file);
}

// Function to read a file into a buffer
char *readFileIntoBuffer(char *filename) {
    // Open the file in read mode
    FILE *file = fopen(filename, "r");

    // Check if the file was opened successfully
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Get the size of the file
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    // Allocate a buffer to store the file contents
    char *buffer = malloc(size + 1);

    // Read the file contents into the buffer
    fread(buffer, 1, size, file);

    // Close the file
    fclose(file);

    // Add a null terminator to the end of the buffer
    buffer[size] = '\0';

    // Return the buffer
    return buffer;
}

// Function to write a buffer to a file
void writeBufferToFile(char *filename, char *buffer) {
    // Open the file in write mode
    FILE *file = fopen(filename, "w");

    // Check if the file was opened successfully
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // Write the buffer to the file
    fwrite(buffer, 1, strlen(buffer), file);

    // Close the file
    fclose(file);
}

// Function to append a buffer to a file
void appendBufferToFile(char *filename, char *buffer) {
    // Open the file in append mode
    FILE *file = fopen(filename, "a");

    // Check if the file was opened successfully
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // Append the buffer to the file
    fwrite(buffer, 1, strlen(buffer), file);

    // Close the file
    fclose(file);
}

// Function to copy a file
void copyFile(char *source_filename, char *destination_filename) {
    // Open the source file in read mode
    FILE *source_file = fopen(source_filename, "r");

    // Check if the source file was opened successfully
    if (source_file == NULL) {
        perror("Error opening source file");
        return;
    }

    // Open the destination file in write mode
    FILE *destination_file = fopen(destination_filename, "w");

    // Check if the destination file was opened successfully
    if (destination_file == NULL) {
        perror("Error opening destination file");
        return;
    }

    // Copy the contents of the source file to the destination file
    char buffer[MAX_LINE_SIZE];
    while (fgets(buffer, MAX_LINE_SIZE, source_file)) {
        fputs(buffer, destination_file);
    }

    // Close the source file
    fclose(source_file);

    // Close the destination file
    fclose(destination_file);
}

// Function to move a file
void moveFile(char *source_filename, char *destination_filename) {
    // Rename the source file to the destination file
    if (rename(source_filename, destination_filename) != 0) {
        perror("Error moving file");
        return;
    }
}

// Function to delete a file
void deleteFile(char *filename) {
    // Delete the file
    if (remove(filename) != 0) {
        perror("Error deleting file");
        return;
    }
}

int main() {
    // Read a file line by line
    readFileLineByLine("input.txt");

    // Write a string to a file
    writeStringToFile("output.txt", "Hello, world!");

    // Append a string to a file
    appendStringToFile("output.txt", "\nThis is a new line.");

    // Read a file into a buffer
    char *buffer = readFileIntoBuffer("input.txt");

    // Write a buffer to a file
    writeBufferToFile("output.txt", buffer);

    // Append a buffer to a file
    appendBufferToFile("output.txt", buffer);

    // Copy a file
    copyFile("input.txt", "copy.txt");

    // Move a file
    moveFile("copy.txt", "moved.txt");

    // Delete a file
    deleteFile("moved.txt");

    // Free the buffer
    free(buffer);

    return 0;
}