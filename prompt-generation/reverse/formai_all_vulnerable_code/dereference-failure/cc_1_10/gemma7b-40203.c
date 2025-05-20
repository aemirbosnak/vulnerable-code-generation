//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIR 10
#define MAX_FILE 20

typedef struct FileSystem {
    char **dirs;
    char **files;
    int currentDir;
} FileSystem;

FileSystem fs;

void initFileSystem() {
    fs.dirs = malloc(MAX_DIR * sizeof(char *));
    fs.files = malloc(MAX_FILE * sizeof(char *));
    fs.currentDir = 0;
}

void cd(char *dir) {
    int i = 0;
    for (i = 0; fs.dirs[i] != NULL && strcmp(fs.dirs[i], dir) != 0; i++) {}

    if (fs.dirs[i] == NULL) {
        printf("Error: Directory not found.\n");
        return;
    }

    fs.currentDir = i;
}

void ls() {
    int i = 0;
    for (i = 0; fs.files[i] != NULL && strcmp(fs.files[i], "") != 0; i++) {
        printf("%s\n", fs.files[i]);
    }

    printf("Current Directory: %s\n", fs.dirs[fs.currentDir]);
}

void mkdir(char *dir) {
    int i = 0;
    for (i = 0; fs.dirs[i] != NULL && strcmp(fs.dirs[i], dir) != 0; i++) {}

    if (fs.dirs[i] != NULL) {
        printf("Error: Directory already exists.\n");
        return;
    }

    fs.dirs[i] = malloc(20);
    strcpy(fs.dirs[i], dir);

    printf("Directory created: %s\n", dir);
}

void touch(char *file) {
    int i = 0;
    for (i = 0; fs.files[i] != NULL && strcmp(fs.files[i], file) != 0; i++) {}

    if (fs.files[i] != NULL) {
        printf("Error: File already exists.\n");
        return;
    }

    fs.files[i] = malloc(20);
    strcpy(fs.files[i], file);

    printf("File created: %s\n", file);
}

int main() {
    initFileSystem();

    cd("Test");
    ls();
    mkdir("Sub");
    touch("test.txt");
    ls();

    return 0;
}