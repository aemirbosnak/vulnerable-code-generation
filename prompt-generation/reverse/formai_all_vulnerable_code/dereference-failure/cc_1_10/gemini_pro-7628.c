//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// File system structure
typedef struct FS {
    char **files;
    int num_files;
    int max_files;
} FS;

// Initialize the file system
FS *init_fs(int max_files) {
    FS *fs = malloc(sizeof(FS));
    fs->files = malloc(max_files * sizeof(char *));
    fs->num_files = 0;
    fs->max_files = max_files;
    return fs;
}

// Create a new file in the file system
void create_file(FS *fs, char *filename) {
    if (fs->num_files == fs->max_files) {
        printf("Error: File system is full\n");
        return;
    }
    fs->files[fs->num_files] = malloc(strlen(filename) + 1);
    strcpy(fs->files[fs->num_files], filename);
    fs->num_files++;
}

// Delete a file from the file system
void delete_file(FS *fs, char *filename) {
    int i;
    for (i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i], filename) == 0) {
            free(fs->files[i]);
            fs->files[i] = fs->files[fs->num_files - 1];
            fs->num_files--;
            return;
        }
    }
    printf("Error: File not found\n");
}

// List the files in the file system
void list_files(FS *fs) {
    int i;
    for (i = 0; i < fs->num_files; i++) {
        printf("%s\n", fs->files[i]);
    }
}

// Main function
int main() {
    FS *fs = init_fs(10);
    create_file(fs, "file1.txt");
    create_file(fs, "file2.txt");
    create_file(fs, "file3.txt");
    list_files(fs);
    delete_file(fs, "file2.txt");
    list_files(fs);
    free(fs);
    return 0;
}