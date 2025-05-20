//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_DIR 5

typedef struct Node {
    char name[256];
    struct Node* next;
    struct Node* dir;
    FILE* file;
} Node;

Node* head = NULL;

void createNode(char* name, FILE* file) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->file = file;
    newNode->next = NULL;
    newNode->dir = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void listFiles(char* dir) {
    Node* current = head;
    while (current) {
        if (strcmp(current->name, dir) == 0) {
            if (current->file) {
                printf("%s\n", current->name);
            } else if (current->dir) {
                listFiles(current->name);
            }
        }
        current = current->next;
    }
}

int main() {
    FILE* file = fopen("test.txt", "w");
    createNode("test.txt", file);
    fclose(file);

    listFiles("test");

    return 0;
}