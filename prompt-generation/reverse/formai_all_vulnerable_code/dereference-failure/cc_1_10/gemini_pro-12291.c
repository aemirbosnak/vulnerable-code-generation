//GEMINI-pro DATASET v1.0 Category: File handling ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a new file
FILE *create_file(char *filename) {
    FILE *fp;
    fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }
    return fp;
}

// Function to write to a file
void write_to_file(FILE *fp, char *data) {
    fprintf(fp, "%s\n", data);
}

// Function to close a file
void close_file(FILE *fp) {
    fclose(fp);
}

// Function to read from a file
char *read_from_file(char *filename) {
    FILE *fp;
    char *data;
    long length;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Get the length of the file
    fseek(fp, 0, SEEK_END);
    length = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Allocate memory for the data
    data = malloc(length + 1);
    if (data == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    // Read the data from the file
    fread(data, 1, length, fp);
    data[length] = '\0';

    // Close the file
    fclose(fp);

    return data;
}

// Function to append to a file
void append_to_file(char *filename, char *data) {
    FILE *fp;

    fp = fopen(filename, "a");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    fprintf(fp, "%s\n", data);

    // Close the file
    fclose(fp);
}

// Function to delete a file
void delete_file(char *filename) {
    if (remove(filename) == 0) {
        printf("File deleted successfully\n");
    } else {
        perror("Error deleting file");
    }
}

int main() {
    FILE *fp;
    char *data;

    // Create a new file
    fp = create_file("test.txt");

    // Write to the file
    write_to_file(fp, "This is a test");

    // Close the file
    close_file(fp);

    // Read from the file
    data = read_from_file("test.txt");

    // Print the data
    printf("%s\n", data);

    // Append to the file
    append_to_file("test.txt", "This is an append");

    // Read from the file again
    data = read_from_file("test.txt");

    // Print the data
    printf("%s\n", data);

    // Delete the file
    delete_file("test.txt");

    return 0;
}