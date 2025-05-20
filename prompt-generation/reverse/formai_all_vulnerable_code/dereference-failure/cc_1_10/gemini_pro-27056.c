//GEMINI-pro DATASET v1.0 Category: File handling ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to represent a file
typedef struct File {
    char *name;
    char *contents;
    size_t size;
} File;

// A function to create a new file
File *new_file(char *name) {
    File *file = malloc(sizeof(File));
    file->name = strdup(name);
    file->contents = NULL;
    file->size = 0;
    return file;
}

// A function to open a file
File *open_file(char *name) {
    // Try to open the file
    FILE *fp = fopen(name, "r");
    if (fp == NULL) {
        return NULL;
    }

    // Get the size of the file
    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Create a new file object
    File *file = new_file(name);

    // Read the contents of the file
    file->contents = malloc(size + 1);
    fread(file->contents, 1, size, fp);
    file->contents[size] = '\0';

    // Close the file
    fclose(fp);

    return file;
}

// A function to write data to a file
void write_file(File *file, char *data, size_t size) {
    // Try to open the file
    FILE *fp = fopen(file->name, "w");
    if (fp == NULL) {
        return;
    }

    // Write the data to the file
    fwrite(data, 1, size, fp);

    // Close the file
    fclose(fp);
}

// A function to close a file
void close_file(File *file) {
    // Free the contents of the file
    free(file->contents);

    // Free the file object
    free(file);
}

// A function to print the contents of a file
void print_file(File *file) {
    printf("%s:\n%s", file->name, file->contents);
}

int main() {
    // Create a new file
    File *file = new_file("test.txt");

    // Write some data to the file
    write_file(file, "Hello, world!\n", 13);

    // Print the contents of the file
    print_file(file);

    // Close the file
    close_file(file);

    return 0;
}