//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DIR 10
#define MAX_FILE 20

typedef struct Node {
    char name[256];
    struct Node* next;
    struct Node* dir;
} Node;

int main() {
    Node* root = NULL;

    // Create a root directory
    root = malloc(sizeof(Node));
    root->name[0] = '/';
    root->name[1] = '\0';
    root->dir = NULL;
    root->next = NULL;

    // Create a few files and directories
    Node* file1 = malloc(sizeof(Node));
    file1->name[0] = 'a';
    file1->name[1] = '.txt';
    file1->dir = root;
    file1->next = NULL;

    Node* dir1 = malloc(sizeof(Node));
    dir1->name[0] = 'b';
    dir1->name[1] = '/';
    dir1->dir = root;
    dir1->next = NULL;

    Node* file2 = malloc(sizeof(Node));
    file2->name[0] = 'c';
    file2->name[1] = '.txt';
    file2->dir = dir1;
    file2->next = NULL;

    // List all files and directories
    Node* current = root;
    while (current) {
        printf("%s\n", current->name);
        current = current->next;
    }

    return 0;
}