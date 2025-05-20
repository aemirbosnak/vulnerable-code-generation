//LLAMA2-13B DATASET v1.0 Category: File system simulation ; Style: irregular
// Simulated File System: The Land of Confusion
// Where files are never found, and directories are always full

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Types
typedef struct file {
    char name[20];
    int size;
    int modified;
} file_t;

typedef struct directory {
    char name[20];
    int num_files;
    file_t** files;
} directory_t;

// Functions
file_t* create_file(char* name, int size) {
    file_t* file = (file_t*) malloc(sizeof(file_t));
    strcpy(file->name, name);
    file->size = size;
    file->modified = time(NULL);
    return file;
}

directory_t* create_directory(char* name) {
    directory_t* dir = (directory_t*) malloc(sizeof(directory_t));
    strcpy(dir->name, name);
    dir->num_files = 0;
    dir->files = (file_t**) malloc(sizeof(file_t*) * 10);
    return dir;
}

void add_file_to_directory(directory_t* dir, file_t* file) {
    if (dir->num_files == 10) {
        printf("Error: Directory is full. Sorry :(");
        return;
    }
    dir->files[dir->num_files] = file;
    dir->num_files++;
}

file_t* find_file(directory_t* dir, char* name) {
    for (int i = 0; i < dir->num_files; i++) {
        if (strcmp(dir->files[i]->name, name) == 0) {
            return dir->files[i];
        }
    }
    return NULL;
}

void delete_file(directory_t* dir, char* name) {
    for (int i = 0; i < dir->num_files; i++) {
        if (strcmp(dir->files[i]->name, name) == 0) {
            free(dir->files[i]);
            dir->num_files--;
            return;
        }
    }
    printf("Error: File not found. Sorry :(");
}

int main() {
    directory_t* root = create_directory("/");
    file_t* file1 = create_file("file1.txt", 100);
    file_t* file2 = create_file("file2.txt", 200);
    file_t* file3 = create_file("file3.txt", 300);

    add_file_to_directory(root, file1);
    add_file_to_directory(root, file2);
    add_file_to_directory(root, file3);

    file_t* file = find_file(root, "file1.txt");
    if (file != NULL) {
        printf("Found file1.txt\n");
    } else {
        printf("Error: File not found. Sorry :(");
    }

    file = find_file(root, "file2.txt");
    if (file != NULL) {
        printf("Found file2.txt\n");
    } else {
        printf("Error: File not found. Sorry :(");
    }

    delete_file(root, "file1.txt");

    return 0;
}