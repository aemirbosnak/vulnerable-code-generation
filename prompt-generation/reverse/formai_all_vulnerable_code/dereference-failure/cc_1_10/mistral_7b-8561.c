//MISTRAL-7B DATASET v1.0 Category: File system simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_NAME_LENGTH 20
#define MAX_CONTENT_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char content[MAX_CONTENT_LENGTH];
    int size;
    struct Node *next;
} File;

typedef struct Node {
    File file;
    struct Node *next;
} Node;

Node *root = NULL;

void createFile(char *name, char *content, int size) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    File *newFile = &newNode->file;

    strcpy(newFile->name, name);
    strcpy(newFile->content, content);
    newFile->size = size;

    newNode->next = root;
    root = newNode;
}

void removeFile(char *name) {
    Node *current = root;
    Node *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->file.name, name) == 0) {
            if (previous == NULL) {
                root = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("File not found.\n");
}

void displayFiles() {
    Node *current = root;

    printf("Files in the directory:\n");
    while (current != NULL) {
        printf("%s (%d bytes)\n", current->file.name, current->file.size);
        current = current->next;
    }
}

int main() {
    createFile("file1.txt", "Hello World!", 13);
    createFile("file2.txt", "This is a test file.", 18);

    displayFiles();

    removeFile("file1.txt");

    displayFiles();

    return 0;
}