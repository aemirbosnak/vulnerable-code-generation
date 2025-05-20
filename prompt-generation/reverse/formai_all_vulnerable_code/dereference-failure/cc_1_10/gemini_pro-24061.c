//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// File system structure
typedef struct {
    char *name;
    int size;
    int blocks;
    int *blocks_bitmap;
} file;

// Directory structure
typedef struct {
    char *name;
    int num_files;
    file **files;
} directory;

// Create a new file
file *create_file(char *name, int size) {
    file *f = malloc(sizeof(file));
    f->name = malloc(strlen(name) + 1);
    strcpy(f->name, name);
    f->size = size;
    f->blocks = (size + 1023) / 1024;
    f->blocks_bitmap = malloc(f->blocks * sizeof(int));
    for (int i = 0; i < f->blocks; i++) {
        f->blocks_bitmap[i] = 0;
    }
    return f;
}

// Create a new directory
directory *create_directory(char *name) {
    directory *d = malloc(sizeof(directory));
    d->name = malloc(strlen(name) + 1);
    strcpy(d->name, name);
    d->num_files = 0;
    d->files = malloc(sizeof(file *));
    return d;
}

// Add a file to a directory
void add_file_to_directory(directory *d, file *f) {
    d->files = realloc(d->files, (d->num_files + 1) * sizeof(file *));
    d->files[d->num_files] = f;
    d->num_files++;
}

// Print the contents of a directory
void print_directory(directory *d) {
    printf("%s:\n", d->name);
    for (int i = 0; i < d->num_files; i++) {
        printf("\t%s (%d bytes)\n", d->files[i]->name, d->files[i]->size);
    }
}

// Simulate a file system
int main() {
    // Create a root directory
    directory *root = create_directory("/");

    // Create some files
    file *f1 = create_file("file1.txt", 1024);
    file *f2 = create_file("file2.txt", 2048);
    file *f3 = create_file("file3.txt", 4096);

    // Add the files to the root directory
    add_file_to_directory(root, f1);
    add_file_to_directory(root, f2);
    add_file_to_directory(root, f3);

    // Print the contents of the root directory
    print_directory(root);

    return 0;
}