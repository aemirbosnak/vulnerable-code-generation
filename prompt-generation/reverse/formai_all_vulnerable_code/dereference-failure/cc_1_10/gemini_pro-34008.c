//GEMINI-pro DATASET v1.0 Category: File handling ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to hold a file name and its contents
typedef struct {
    char* name;
    char* contents;
} File;

// A function to read a file into a File structure
File* read_file(char* filename) {
    // Open the file
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    // Get the size of the file
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    // Allocate memory for the file contents
    char* contents = malloc(size + 1);
    if (contents == NULL) {
        fclose(fp);
        return NULL;
    }

    // Read the file contents into memory
    fread(contents, 1, size, fp);
    fclose(fp);

    // Create a File structure and return it
    File* file = malloc(sizeof(File));
    file->name = filename;
    file->contents = contents;
    return file;
}

// A function to write a File structure to a file
int write_file(File* file) {
    // Open the file
    FILE* fp = fopen(file->name, "w");
    if (fp == NULL) {
        return -1;
    }

    // Write the file contents to the file
    fwrite(file->contents, 1, strlen(file->contents), fp);
    fclose(fp);

    return 0;
}

// A function to print a File structure
void print_file(File* file) {
    printf("File: %s\n", file->name);
    printf("Contents:\n%s\n", file->contents);
}

// A function to free the memory allocated for a File structure
void free_file(File* file) {
    free(file->name);
    free(file->contents);
    free(file);
}

// A function to main the program
int main() {
    // Read a file into a File structure
    File* file = read_file("test.txt");
    if (file == NULL) {
        printf("Error reading file\n");
        return -1;
    }

    // Print the File structure
    print_file(file);

    // Write the File structure to a file
    int result = write_file(file);
    if (result != 0) {
        printf("Error writing file\n");
        return -1;
    }

    // Free the memory allocated for the File structure
    free_file(file);

    return 0;
}