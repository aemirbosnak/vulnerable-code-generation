//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIR_NAME_LEN 255
#define MAX_FILE_NAME_LEN 255
#define MAX_FILE_SIZE 1024

typedef struct Node {
    char name[MAX_DIR_NAME_LEN];
    struct Node* next;
    struct Node* child;
} Node;

typedef struct File {
    char name[MAX_FILE_NAME_LEN];
    int size;
    struct File* next;
    struct File* prev;
    struct Node* node;
} File;

Node* newNode(char* name) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->name, name);
    node->next = NULL;
    node->child = NULL;
    return node;
}

File* newFile(char* name, int size) {
    File* file = (File*)malloc(sizeof(File));
    strcpy(file->name, name);
    file->size = size;
    file->next = NULL;
    file->prev = NULL;
    file->node = NULL;
    return file;
}

void traverseDirectory(Node* node) {
    printf("%s\n", node->name);
    if (node->child) {
        traverseDirectory(node->child);
    }
}

int main() {
    Node* root = newNode("root");
    File* file = newFile("my_file.txt", 1024);
    file->node = root;
    root->child = file;

    traverseDirectory(root);

    return 0;
}