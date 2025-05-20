//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIR 10
#define MAX_FILE 20

typedef struct Node {
    char name[20];
    struct Node* next;
    struct Node* dir;
} Node;

void createDir(Node** head, char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    newNode->dir = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void createFile(Node* dir, char* name, char* content) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    newNode->dir = dir;

    dir->dir = newNode;
}

void listDir(Node* dir) {
    Node* current = dir->dir;
    while (current) {
        printf("%s\n", current->name);
        current = current->next;
    }
}

int main() {
    Node* head = NULL;
    createDir(&head, "mydir");
    createDir(&head, "anotherdir");
    createFile(head->dir->dir, "myfile.txt", "This is my file content.");

    listDir(head->dir);

    return 0;
}