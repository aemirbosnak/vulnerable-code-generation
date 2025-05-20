//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_PATH_LENGTH 200
#define MAX_FILE_SIZE 1000000

struct file_info {
    char filename[MAX_FILENAME_LENGTH];
    int file_size;
    int num_references;
};

struct directory_info {
    char path[MAX_PATH_LENGTH];
    struct file_info* files[MAX_FILE_SIZE];
    int num_files;
};

struct directory_info* create_directory(char* path) {
    struct directory_info* dir = malloc(sizeof(struct directory_info));
    strcpy(dir->path, path);
    dir->num_files = 0;
    return dir;
}

int add_file(struct directory_info* dir, char* filename, int file_size) {
    struct file_info* file = malloc(sizeof(struct file_info));
    strcpy(file->filename, filename);
    file->file_size = file_size;
    file->num_references = 1;
    dir->files[dir->num_files] = file;
    dir->num_files++;
    return dir->num_files - 1;
}

void remove_file(struct directory_info* dir, int index) {
    free(dir->files[index]);
    dir->num_files--;
}

int open_file(struct directory_info* dir, char* filename) {
    for (int i = 0; i < dir->num_files; i++) {
        if (strcmp(dir->files[i]->filename, filename) == 0) {
            return i;
        }
    }
    return -1;
}

void close_file(struct directory_info* dir, int index) {
    dir->files[index]->num_references--;
    if (dir->files[index]->num_references == 0) {
        remove_file(dir, index);
    }
}

int read_file(struct directory_info* dir, int index, char* buffer, int size) {
    if (dir->files[index]->num_references == 0) {
        return -1;
    }
    memcpy(buffer, dir->files[index]->filename, MAX_FILENAME_LENGTH);
    return dir->files[index]->file_size;
}

int write_file(struct directory_info* dir, int index, char* buffer, int size) {
    if (dir->files[index]->num_references == 0) {
        return -1;
    }
    return dir->files[index]->file_size;
}

int main() {
    struct directory_info* root = create_directory(".");

    add_file(root, "file1.txt", 100);
    add_file(root, "file2.txt", 200);

    printf("Opened file: %s\n", read_file(root, open_file(root, "file1.txt"), "buffer", 100));

    close_file(root, open_file(root, "file1.txt"));

    printf("Opened file: %s\n", read_file(root, open_file(root, "file2.txt"), "buffer", 100));

    return 0;
}