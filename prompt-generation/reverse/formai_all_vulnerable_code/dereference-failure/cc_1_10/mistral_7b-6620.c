//MISTRAL-7B DATASET v1.0 Category: File system simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 50
#define MAX_NAME_LENGTH 20
#define MAX_CONTENT_LENGTH 100

typedef struct File {
    char name[MAX_NAME_LENGTH];
    char content[MAX_CONTENT_LENGTH];
    struct File *next;
} File;

File *root = NULL;

void createFile(char *name, char *content) {
    File *newFile = (File *) malloc(sizeof(File));
    strcpy(newFile->name, name);
    strcpy(newFile->content, content);
    newFile->next = root;
    root = newFile;
}

void removeFile(char *name) {
    File *current = root;
    File *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                root = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

void listFiles() {
    File *current = root;

    printf("Files in the system:\n");
    while (current != NULL) {
        printf("%s\n", current->name);
        current = current->next;
    }
}

int main() {
    createFile("file1.txt", "Hello, World!");
    createFile("file2.txt", "This is a test.");
    listFiles();
    removeFile("file1.txt");
    listFiles();

    return 0;
}