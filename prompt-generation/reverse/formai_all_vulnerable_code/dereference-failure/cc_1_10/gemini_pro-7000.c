//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// File system simulation parameters
#define MAX_FILES 100
#define MAX_FILE_SIZE 1000000
#define MAX_DIRECTORY_SIZE 1000000

// File system data structures
typedef struct file {
    char name[256];
    int size;
    time_t created;
    time_t modified;
} file;

typedef struct directory {
    char name[256];
    int size;
    time_t created;
    time_t modified;
    struct file *files[MAX_FILES];
    int num_files;
    struct directory *subdirectories[MAX_FILES];
    int num_subdirectories;
} directory;

// File system functions
file *create_file(char *name, int size) {
    file *f = malloc(sizeof(file));
    strcpy(f->name, name);
    f->size = size;
    f->created = time(NULL);
    f->modified = time(NULL);
    return f;
}

directory *create_directory(char *name) {
    directory *d = malloc(sizeof(directory));
    strcpy(d->name, name);
    d->size = 0;
    d->created = time(NULL);
    d->modified = time(NULL);
    d->num_files = 0;
    d->num_subdirectories = 0;
    return d;
}

void add_file_to_directory(directory *d, file *f) {
    d->files[d->num_files++] = f;
    d->size += f->size;
    d->modified = time(NULL);
}

void add_subdirectory_to_directory(directory *d, directory *subd) {
    d->subdirectories[d->num_subdirectories++] = subd;
    d->size += subd->size;
    d->modified = time(NULL);
}

void print_file(file *f) {
    printf("File: %s, Size: %d, Created: %s, Modified: %s\n", f->name, f->size, ctime(&f->created), ctime(&f->modified));
}

void print_directory(directory *d) {
    printf("Directory: %s, Size: %d, Created: %s, Modified: %s\n", d->name, d->size, ctime(&d->created), ctime(&d->modified));
    for (int i = 0; i < d->num_files; i++) {
        print_file(d->files[i]);
    }
    for (int i = 0; i < d->num_subdirectories; i++) {
        print_directory(d->subdirectories[i]);
    }
}

// Main function
int main() {
    // Create the root directory
    directory *root = create_directory("/");

    // Create some files and subdirectories
    file *f1 = create_file("file1.txt", 1000);
    file *f2 = create_file("file2.txt", 2000);
    directory *subd1 = create_directory("subdirectory1");
    directory *subd2 = create_directory("subdirectory2");

    // Add the files and subdirectories to the root directory
    add_file_to_directory(root, f1);
    add_file_to_directory(root, f2);
    add_subdirectory_to_directory(root, subd1);
    add_subdirectory_to_directory(root, subd2);

    // Print the file system
    print_directory(root);

    return 0;
}