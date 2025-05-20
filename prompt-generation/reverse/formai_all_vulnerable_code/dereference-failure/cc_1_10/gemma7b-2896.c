//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIR 10
#define MAX_FILE 20

struct Dir {
    char name[20];
    struct Dir* next;
    struct File** files;
};

struct File {
    char name[20];
    int size;
    struct File* next;
    struct Dir* dir;
};

void mkdir(struct Dir** head, char* name) {
    struct Dir* newNode = (struct Dir*)malloc(sizeof(struct Dir));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    newNode->files = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void createFile(struct File** head, char* name, int size) {
    struct File* newNode = (struct File*)malloc(sizeof(struct File));
    strcpy(newNode->name, name);
    newNode->size = size;
    newNode->next = NULL;
    newNode->dir = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int main() {
    struct Dir* head = NULL;
    struct File* fileHead = NULL;

    mkdir(&head, "home");
    mkdir(&head, "home/user");
    mkdir(&head, "home/user/documents");

    createFile(&fileHead, "home/user/documents/test.txt", 10);
    createFile(&fileHead, "home/user/documents/another.txt", 20);

    printf("Files in home/user/documents:\n");
    for (struct File* file = fileHead; file; file = file->next) {
        if (file->dir->name == "home/user/documents") {
            printf("%s\n", file->name);
        }
    }

    return 0;
}