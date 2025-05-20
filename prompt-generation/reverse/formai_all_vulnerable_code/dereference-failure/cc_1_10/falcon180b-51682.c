//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10) // 10 MB

typedef struct {
    char *filename;
    char *hash;
} FileInfo;

typedef struct {
    FileInfo *files;
    int num_files;
    int capacity;
} FileSynchronizer;

void init_filesync(FileSynchronizer *fs, int capacity) {
    fs->files = malloc(capacity * sizeof(FileInfo));
    fs->num_files = 0;
    fs->capacity = capacity;
}

void add_file(FileSynchronizer *fs, const char *filename, const char *hash) {
    if (fs->num_files >= fs->capacity) {
        printf("Error: file synchronizer is full\n");
        return;
    }

    FileInfo *fi = &fs->files[fs->num_files];
    fi->filename = strdup(filename);
    fi->hash = strdup(hash);

    fs->num_files++;
}

void print_files(FileSynchronizer *fs) {
    for (int i = 0; i < fs->num_files; i++) {
        printf("%s -> %s\n", fs->files[i].filename, fs->files[i].hash);
    }
}

void free_filesync(FileSynchronizer *fs) {
    for (int i = 0; i < fs->num_files; i++) {
        free(fs->files[i].filename);
        free(fs->files[i].hash);
    }
    free(fs->files);
}

int main() {
    FileSynchronizer fs;
    init_filesync(&fs, 10);

    add_file(&fs, "file1.txt", "abcdefg");
    add_file(&fs, "file2.txt", "hijklmn");
    add_file(&fs, "file3.txt", "opqrstu");

    print_files(&fs);

    free_filesync(&fs);

    return 0;
}