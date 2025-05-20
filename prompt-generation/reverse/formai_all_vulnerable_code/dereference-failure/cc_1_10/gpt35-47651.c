//FormAI DATASET v1.0 Category: File system simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 20
#define MAX_FILE_NAME 20
#define MAX_FILE_SIZE 1024

typedef struct {
    char name[MAX_FILE_NAME];
    int size;
    char data[MAX_FILE_SIZE];
} file;

typedef struct {
    char name[MAX_FILE_NAME];
    int num_files;
    file files[MAX_FILES];
} directory;

directory* create_directory(char* name) {
    directory* new_dir = (directory*) malloc(sizeof(directory));
    strcpy(new_dir->name, name);
    new_dir->num_files = 0;
    return new_dir;
}

void add_file_to_directory(directory* dir, char* name, char* data, int size) {
    if (dir->num_files < MAX_FILES) {
        file new_file;
        strcpy(new_file.name, name);
        strcpy(new_file.data, data);
        new_file.size = size;
        dir->files[dir->num_files] = new_file;
        dir->num_files++;
    } else {
        printf("Error: Directory is full.\n");
    }
}

void list_files_in_directory(directory* dir) {
    printf("Files in directory '%s':\n", dir->name);
    for (int i = 0; i < dir->num_files; i++) {
        printf("- %s (%d bytes)\n", dir->files[i].name, dir->files[i].size);
    }
}

int main() {
    directory* root = create_directory("root");
    add_file_to_directory(root, "file1.txt", "Contents of file1.txt", 21);
    add_file_to_directory(root, "file2.txt", "Contents of file2.txt", 21);
    list_files_in_directory(root);
    return 0;
}