//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: Donald Knuth
// A quaint and curious C file system simulation, inspired by the venerable Donald Knuth

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define our rudimentary file system structures
typedef struct file {
    char *name;
    int size;
    char *data;
} file_t;

typedef struct directory {
    char *name;
    int num_files;
    file_t **files;
} directory_t;

// Create a new file system
directory_t *create_file_system() {
    directory_t *fs = malloc(sizeof(directory_t));
    fs->name = malloc(sizeof("File System"));
    strcpy(fs->name, "File System");
    fs->num_files = 0;
    fs->files = NULL;
    return fs;
}

// Create a new directory within the file system
directory_t *create_directory(directory_t *fs, char *name) {
    directory_t *dir = malloc(sizeof(directory_t));
    dir->name = malloc(strlen(name) + 1);
    strcpy(dir->name, name);
    dir->num_files = 0;
    dir->files = NULL;
    fs->files = realloc(fs->files, (fs->num_files + 1) * sizeof(file_t *));
    fs->files[fs->num_files++] = (file_t *) dir;
    return dir;
}

// Create a new file within the file system
file_t *create_file(directory_t *dir, char *name, int size) {
    file_t *file = malloc(sizeof(file_t));
    file->name = malloc(strlen(name) + 1);
    strcpy(file->name, name);
    file->size = size;
    file->data = malloc(size);
    dir->files = realloc(dir->files, (dir->num_files + 1) * sizeof(file_t *));
    dir->files[dir->num_files++] = file;
    return file;
}

// Open a file within the file system
file_t *open_file(directory_t *dir, char *name) {
    for (int i = 0; i < dir->num_files; i++) {
        if (strcmp(dir->files[i]->name, name) == 0) {
            return dir->files[i];
        }
    }
    return NULL;
}

// Write data to a file within the file system
void write_file(file_t *file, char *data, int size) {
    if (file->size < size) {
        file->data = realloc(file->data, size);
        file->size = size;
    }
    memcpy(file->data, data, size);
}

// Read data from a file within the file system
void read_file(file_t *file) {
    printf("%s: %s\n", file->name, file->data);
}

// Close a file within the file system
void close_file(file_t *file) {
    free(file->name);
    free(file->data);
    free(file);
}

// Delete a file from the file system
void delete_file(directory_t *dir, char *name) {
    for (int i = 0; i < dir->num_files; i++) {
        if (strcmp(dir->files[i]->name, name) == 0) {
            free(dir->files[i]->name);
            free(dir->files[i]->data);
            free(dir->files[i]);
            for (int j = i + 1; j < dir->num_files; j++) {
                dir->files[j - 1] = dir->files[j];
            }
            dir->num_files--;
            break;
        }
    }
}

// Print the contents of a directory within the file system
void print_directory(directory_t *dir) {
    printf("%s\n", dir->name);
    for (int i = 0; i < dir->num_files; i++) {
        printf("  %s (%d bytes)\n", dir->files[i]->name, dir->files[i]->size);
    }
}

// Destroy the file system
void destroy_file_system(directory_t *fs) {
    for (int i = 0; i < fs->num_files; i++) {
        close_file(fs->files[i]);
    }
    free(fs->name);
    free(fs->files);
    free(fs);
}

// Main function
int main() {
    // Create our file system
    directory_t *fs = create_file_system();

    // Create a directory within the file system
    directory_t *dir = create_directory(fs, "My Directory");

    // Create a file within the directory
    file_t *file = create_file(dir, "My File.txt", 100);

    // Write some data to the file
    write_file(file, "Hello, world!", 13);

    // Read the data from the file
    read_file(file);

    // Close the file
    close_file(file);

    // Delete the file from the directory
    delete_file(dir, "My File.txt");

    // Print the contents of the directory
    print_directory(dir);

    // Destroy the file system
    destroy_file_system(fs);

    return 0;
}