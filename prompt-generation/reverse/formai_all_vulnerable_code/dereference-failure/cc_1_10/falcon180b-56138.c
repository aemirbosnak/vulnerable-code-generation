//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LEN 100
#define MAX_FILE_DATA_LEN 1000

typedef struct {
    char name[MAX_FILE_NAME_LEN];
    char data[MAX_FILE_DATA_LEN];
} File;

typedef struct {
    File *files[MAX_FILES];
    int numFiles;
} FileSystem;

void initFileSystem(FileSystem *fs) {
    fs->numFiles = 0;
}

int addFile(FileSystem *fs, char *name, char *data) {
    if (fs->numFiles >= MAX_FILES) {
        printf("Error: File system is full.\n");
        return -1;
    }

    File *newFile = (File *)malloc(sizeof(File));
    strcpy(newFile->name, name);
    strcpy(newFile->data, data);

    fs->files[fs->numFiles++] = newFile;
    return 0;
}

int removeFile(FileSystem *fs, char *name) {
    int i;
    for (i = 0; i < fs->numFiles; i++) {
        if (strcmp(fs->files[i]->name, name) == 0) {
            free(fs->files[i]);
            fs->files[i] = NULL;
            fs->numFiles--;
            return 0;
        }
    }

    printf("Error: File not found.\n");
    return -1;
}

int editFile(FileSystem *fs, char *name, char *data) {
    int i;
    for (i = 0; i < fs->numFiles; i++) {
        if (strcmp(fs->files[i]->name, name) == 0) {
            strcpy(fs->files[i]->data, data);
            return 0;
        }
    }

    printf("Error: File not found.\n");
    return -1;
}

int listFiles(FileSystem *fs) {
    int i;
    for (i = 0; i < fs->numFiles; i++) {
        printf("%s\n", fs->files[i]->name);
    }
}

int main() {
    FileSystem fs;
    initFileSystem(&fs);

    addFile(&fs, "test.txt", "This is a test file. ");
    addFile(&fs, "example.txt", "This is an example file. ");
    listFiles(&fs);

    editFile(&fs, "test.txt", "This is an updated test file. ");
    listFiles(&fs);

    removeFile(&fs, "test.txt");
    listFiles(&fs);

    return 0;
}