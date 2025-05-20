//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_DIR 20
#define MAX_FILE 10

typedef struct Node {
    char name[20];
    struct Node* next;
    struct Node* dir;
} Node;

void create_node(Node* node, char* name) {
    strcpy(node->name, name);
    node->next = NULL;
    node->dir = NULL;
}

void add_file(Node* dir, char* filename) {
    Node* file = malloc(sizeof(Node));
    create_node(file, filename);
    file->dir = dir;
    dir->dir->next = file;
}

void list_files(Node* dir) {
    Node* file = dir->dir;
    while (file) {
        printf("%s\n", file->name);
        file = file->next;
    }
}

int main() {
    Node* root = NULL;

    // Create a root node
    root = malloc(sizeof(Node));
    create_node(root, "ROOT");

    // Add some directories
    Node* dir1 = malloc(sizeof(Node));
    create_node(dir1, "DIR1");
    add_file(root, dir1->name);

    Node* dir2 = malloc(sizeof(Node));
    create_node(dir2, "DIR2");
    add_file(root, dir2->name);

    // Add some files
    add_file(dir1, "file1.txt");
    add_file(dir1, "file2.txt");
    add_file(dir2, "file3.txt");

    // List the files
    list_files(root);

    return 0;
}