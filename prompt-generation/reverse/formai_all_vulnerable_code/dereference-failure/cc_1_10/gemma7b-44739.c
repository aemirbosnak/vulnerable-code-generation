//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: safe
#include <stdio.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_DIR 5

typedef struct Node {
    char name[256];
    struct Node* next;
    struct Node* dir;
} Node;

Node* fileSystem = NULL;

void createNode(char* name) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    newNode->dir = NULL;

    if (fileSystem == NULL) {
        fileSystem = newNode;
    } else {
        fileSystem->next = newNode;
        fileSystem = newNode;
    }
}

void listDirectory(char* dir) {
    Node* currentDir = fileSystem;
    while (currentDir) {
        if (strcmp(currentDir->name, dir) == 0) {
            printf("%s\n", currentDir->name);
            if (currentDir->dir) {
                listDirectory(currentDir->name);
            }
        }
        currentDir = currentDir->next;
    }
}

int main() {
    createNode("home");
    createNode("home/documents");
    createNode("home/pictures");
    createNode("home/documents/my_document.txt");
    createNode("home/pictures/my_picture.jpg");

    listDirectory("home");
    listDirectory("home/documents");

    return 0;
}