//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int size;
    char* data;
} File;

typedef struct {
    File* files;
    int numFiles;
} Directory;

void addFile(Directory* dir, char* name, int size, char* data) {
    if (dir->numFiles == 0) {
        dir->files = (File*)malloc(sizeof(File));
        strcpy(dir->files->name, name);
        dir->files->size = size;
        dir->files->data = (char*)malloc(size);
        strcpy(dir->files->data, data);
        dir->numFiles++;
    } else {
        File* newFile = (File*)malloc(sizeof(File));
        strcpy(newFile->name, name);
        newFile->size = size;
        newFile->data = (char*)malloc(size);
        strcpy(newFile->data, data);
        dir->files = (File*)realloc(dir->files, (dir->numFiles + 1) * sizeof(File));
        dir->files[dir->numFiles - 1] = *newFile;
        dir->numFiles++;
    }
}

void listFiles(Directory* dir) {
    if (dir->numFiles == 0) {
        printf("Directory is empty\n");
    } else {
        printf("Files in directory:\n");
        for (int i = 0; i < dir->numFiles; i++) {
            printf("%s - %d bytes\n", dir->files[i].name, dir->files[i].size);
        }
    }
}

int main() {
    Directory dir;
    addFile(&dir, "file1.txt", 100, "This is file 1");
    addFile(&dir, "file2.txt", 200, "This is file 2");
    listFiles(&dir);
    return 0;
}