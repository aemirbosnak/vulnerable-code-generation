//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX_DIR_SIZE 10
#define MAX_FILE_NAME_SIZE 25

typedef struct Directory {
    char **files;
    struct Directory **dirs;
    int size;
} Directory;

typedef struct File {
    char name[MAX_FILE_NAME_SIZE];
    int size;
    struct File *next;
} File;

Directory **createDirectory(int size) {
    Directory *dir = malloc(sizeof(Directory));
    dir->files = malloc(sizeof(char *) * size);
    dir->dirs = NULL;
    dir->size = size;
    return dir;
}

void addFile(Directory *dir, char *name, int size) {
    File *file = malloc(sizeof(File));
    strcpy(file->name, name);
    file->size = size;
    file->next = NULL;

    if (dir->files) {
        dir->files[dir->size - 1] = file;
    } else {
        dir->files = file;
    }

    dir->size++;
}

int main() {
    Directory *root = createDirectory(MAX_DIR_SIZE);
    addFile(root, "a.txt", 10);
    addFile(root, "b.txt", 20);
    addFile(root, "c/d.txt", 30);

    printf("Files in the root directory:\n");
    for (File *file = root->files; file; file = file->next) {
        printf("%s (%d bytes)\n", file->name, file->size);
    }

    printf("Files in the subdirectory 'c':\n");
    for (File *file = root->files; file; file = file->next) {
        if (strcmp(file->name, "c/d.txt") == 0) {
            printf("%s (%d bytes)\n", file->name, file->size);
        }
    }

    return 0;
}