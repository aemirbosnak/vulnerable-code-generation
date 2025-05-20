//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of files and directories that can be created
#define MAX_FILES 100
#define MAX_DIRECTORIES 100

// Define the maximum size of a file or directory name
#define MAX_NAME_SIZE 32

// Define the maximum number of levels in the directory tree
#define MAX_DEPTH 10

// Define the file system structure
typedef struct {
    char name[MAX_NAME_SIZE];
    int size;
    time_t timestamp;
    struct directory *parent;
} file;

typedef struct {
    char name[MAX_NAME_SIZE];
    int num_files;
    int num_directories;
    file *files[MAX_FILES];
    struct directory *directories[MAX_DIRECTORIES];
    struct directory *parent;
} directory;

// Create a new file
file *create_file(char *name, int size) {
    file *f = malloc(sizeof(file));
    strcpy(f->name, name);
    f->size = size;
    f->timestamp = time(NULL);
    f->parent = NULL;
    return f;
}

// Create a new directory
directory *create_directory(char *name) {
    directory *d = malloc(sizeof(directory));
    strcpy(d->name, name);
    d->num_files = 0;
    d->num_directories = 0;
    d->parent = NULL;
    return d;
}

// Add a file to a directory
void add_file_to_directory(directory *d, file *f) {
    d->files[d->num_files++] = f;
    f->parent = d;
}

// Add a directory to a directory
void add_directory_to_directory(directory *d, directory *d2) {
    d->directories[d->num_directories++] = d2;
    d2->parent = d;
}

// Print the file system tree
void print_file_system(directory *d, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("%s\n", d->name);

    for (int i = 0; i < d->num_files; i++) {
        for (int j = 0; j < depth + 1; j++) {
            printf("  ");
        }
        printf("%s (%d bytes)\n", d->files[i]->name, d->files[i]->size);
    }

    for (int i = 0; i < d->num_directories; i++) {
        print_file_system(d->directories[i], depth + 1);
    }
}

// Main function
int main() {
    // Create the root directory
    directory *root = create_directory("/");

    // Create some files and directories
    file *f1 = create_file("file1.txt", 100);
    file *f2 = create_file("file2.txt", 200);
    directory *d1 = create_directory("dir1");
    directory *d2 = create_directory("dir2");

    // Add the files and directories to the root directory
    add_file_to_directory(root, f1);
    add_file_to_directory(root, f2);
    add_directory_to_directory(root, d1);
    add_directory_to_directory(root, d2);

    // Create some files and directories in the subdirectories
    file *f3 = create_file("file3.txt", 300);
    file *f4 = create_file("file4.txt", 400);
    directory *d3 = create_directory("dir3");
    directory *d4 = create_directory("dir4");

    // Add the files and directories to the subdirectories
    add_file_to_directory(d1, f3);
    add_file_to_directory(d1, f4);
    add_directory_to_directory(d1, d3);
    add_directory_to_directory(d1, d4);

    // Print the file system tree
    print_file_system(root, 0);

    return 0;
}