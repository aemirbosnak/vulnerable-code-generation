//GEMINI-pro DATASET v1.0 Category: File handling ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A custom data structure to represent a file
typedef struct File {
    char* name;
    char* contents;
    size_t size;
} File;

// A function to create a new file
File* create_file(const char* name) {
    File* file = malloc(sizeof(File));
    file->name = strdup(name);
    file->contents = NULL;
    file->size = 0;
    return file;
}

// A function to open an existing file
File* open_file(const char* name) {
    FILE* fp = fopen(name, "r");
    if (fp == NULL) {
        return NULL;
    }

    // Get the file size
    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    rewind(fp);

    // Allocate memory for the file contents
    char* contents = malloc(size + 1);

    // Read the file contents into memory
    fread(contents, size, 1, fp);
    contents[size] = '\0';

    // Close the file
    fclose(fp);

    // Create a new file struct
    File* file = create_file(name);
    file->contents = contents;
    file->size = size;

    return file;
}

// A function to save a file
int save_file(File* file) {
    FILE* fp = fopen(file->name, "w");
    if (fp == NULL) {
        return -1;
    }

    // Write the file contents to the file
    fwrite(file->contents, file->size, 1, fp);

    // Close the file
    fclose(fp);

    return 0;
}

// A function to close a file
void close_file(File* file) {
    free(file->name);
    free(file->contents);
    free(file);
}

// A function to print the contents of a file
void print_file(File* file) {
    printf("Filename: %s\n", file->name);
    printf("Contents:\n%s\n", file->contents);
}

int main() {
    // Create a new file
    File* file = create_file("test.txt");

    // Open an existing file
    File* file2 = open_file("test2.txt");

    // Save a file
    save_file(file);

    // Print the contents of a file
    print_file(file);
    print_file(file2);

    // Close the files
    close_file(file);
    close_file(file2);

    return 0;
}