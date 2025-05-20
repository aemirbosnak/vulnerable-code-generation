//MISTRAL-7B DATASET v1.0 Category: File system simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_NUM_FILES 50

typedef struct File {
    char name[MAX_FILE_NAME_LENGTH];
    int size;
    struct File *next;
} File;

File *root = NULL;

void createFile(const char *fileName, int fileSize) {
    File *newFile = (File *) malloc(sizeof(File));
    strcpy(newFile->name, fileName);
    newFile->size = fileSize;
    newFile->next = root;
    root = newFile;
}

void deleteFile(const char *fileName) {
    File *current = root;
    File *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, fileName) == 0) {
            if (prev == NULL) {
                root = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("File not found.\n");
}

void listFiles() {
    File *current = root;

    printf("Files in the directory:\n");
    while (current != NULL) {
        printf("%s (size: %d)\n", current->name, current->size);
        current = current->next;
    }
}

int main() {
    createFile("file1.txt", 10);
    createFile("file2.txt", 20);
    createFile("file3.txt", 30);

    listFiles();

    deleteFile("file2.txt");

    listFiles();

    return 0;
}