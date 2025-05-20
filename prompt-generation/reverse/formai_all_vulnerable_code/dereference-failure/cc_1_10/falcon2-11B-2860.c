//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *filename;
    size_t filesize;
} File;

typedef struct {
    File files[100];
    int top;
} FileSystem;

FileSystem *create_filesystem() {
    FileSystem *fs = (FileSystem *)malloc(sizeof(FileSystem));
    fs->top = -1;
    return fs;
}

void create(FileSystem *fs, char *filename, char *content) {
    if (fs->top == -1) {
        fs->top = 0;
    }
    fs->files[fs->top].filename = strdup(filename);
    fs->files[fs->top].filesize = strlen(content);
    fs->top++;
}

void delete(FileSystem *fs, char *filename) {
    for (int i = 0; i < fs->top; i++) {
        if (strcmp(fs->files[i].filename, filename) == 0) {
            fs->top--;
            free(fs->files[i].filename);
            break;
        }
    }
}

void read(FileSystem *fs, char *filename) {
    for (int i = 0; i < fs->top; i++) {
        if (strcmp(fs->files[i].filename, filename) == 0) {
            printf("%s\n", fs->files[i].filename);
            printf("%zu bytes\n", fs->files[i].filesize);
            return;
        }
    }
}

void write(FileSystem *fs, char *filename, char *content) {
    for (int i = 0; i < fs->top; i++) {
        if (strcmp(fs->files[i].filename, filename) == 0) {
            fs->files[i].filesize = strlen(content);
            return;
        }
    }
    create(fs, filename, content);
}

int main() {
    FileSystem *fs = create_filesystem();
    create(fs, "test.txt", "Hello, world!");
    read(fs, "test.txt");
    delete(fs, "test.txt");
    return 0;
}