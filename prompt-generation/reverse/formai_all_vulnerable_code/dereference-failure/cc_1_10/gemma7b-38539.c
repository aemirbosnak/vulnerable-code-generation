//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_DIR 5

typedef struct Node {
    char name[20];
    struct Node* next;
    struct Node* dir;
} Node;

Node* head = NULL;
Node* dirHead = NULL;

void createNode(char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    newNode->dir = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void createDir(char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    newNode->dir = NULL;

    if (dirHead == NULL) {
        dirHead = newNode;
    } else {
        Node* temp = dirHead;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void listFiles() {
    Node* current = head;
    while (current) {
        if (current->dir == NULL) {
            printf("%s\n", current->name);
        }
        current = current->next;
    }
}

void listDirectories() {
    Node* current = dirHead;
    while (current) {
        printf("%s\n", current->name);
        current = current->next;
    }
}

int main() {
    createNode("file1.txt");
    createNode("file2.txt");
    createDir("dir1");
    createDir("dir2");
    createDir("dir3");

    listFiles();
    listDirectories();

    return 0;
}