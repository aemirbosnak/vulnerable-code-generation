//MISTRAL-7B DATASET v1.0 Category: File system simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 20
#define MAX_NAME_LENGTH 20

typedef struct File {
    char name[MAX_NAME_LENGTH + 1];
    char content[1024];
    struct File *next;
} File;

File *root = NULL;

void createFile(const char *fileName, const char *content) {
    File *newFile = (File *)malloc(sizeof(File));
    strcpy(newFile->name, fileName);
    strcpy(newFile->content, content);
    newFile->next = root;
    root = newFile;
}

void deleteFile(const char *fileName) {
    File *current = root;
    File *previous = NULL;

    while (current != NULL && strcmp(current->name, fileName) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("File not found.\n");
        return;
    }

    if (previous == NULL) {
        root = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
}

void readFile(const char *fileName) {
    File *current = root;

    while (current != NULL && strcmp(current->name, fileName) != 0) {
        current = current->next;
    }

    if (current == NULL) {
        printf("File not found.\n");
        return;
    }

    printf("%s\n", current->content);
}

int main() {
    createFile("Blessings.txt", "May you be blessed with happiness and success.\n");
    createFile("Grace.txt", "May you be graced with peace and love.\n");

    readFile("Blessings.txt");

    deleteFile("Grace.txt");

    return 0;
}