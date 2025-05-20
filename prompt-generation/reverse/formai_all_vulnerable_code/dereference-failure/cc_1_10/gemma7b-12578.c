//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: scientific
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

void create_node(char* name) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    newNode->dir = NULL;
}

void add_to_dir(Node* dir, Node* newNode) {
    if (dir == NULL) {
        dir = newNode;
    } else {
        dir->next = newNode;
        dir = newNode;
    }
}

void list_dir(Node* dir) {
    while (dir) {
        printf("%s ", dir->name);
        dir = dir->next;
    }
    printf("\n");
}

void search_dir(Node* dir, char* query) {
    while (dir) {
        if (strcmp(dir->name, query) == 0) {
            printf("%s\n", dir->name);
        } else if (dir->dir) {
            search_dir(dir->dir, query);
        }
        dir = dir->next;
    }
}

int main() {
    Node* root = NULL;
    create_node("Root");
    root = root->next;

    // Create some directories
    create_node("Dir1");
    add_to_dir(root, root->next);
    create_node("Dir2");
    add_to_dir(root, root->next->next);

    // Create some files
    create_node("File1");
    add_to_dir(root->next, root->next->next->next);
    create_node("File2");
    add_to_dir(root->next, root->next->next->next->next);

    // List the directory
    list_dir(root);

    // Search for a file
    search_dir(root, "File2");

    return 0;
}