//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char* name;
    struct node* next;
} Node;

typedef struct filesystem {
    Node* root;
} Filesystem;

void create_node(Node* node, char* name) {
    node->name = (char*)malloc(strlen(name) + 1);
    strcpy(node->name, name);
    node->next = NULL;
}

void create_filesystem(Filesystem* fs) {
    fs->root = (Node*)malloc(sizeof(Node));
    create_node(fs->root, "root");
}

void print_filesystem(Filesystem* fs) {
    Node* current = fs->root;
    while (current!= NULL) {
        printf("%s\n", current->name);
        current = current->next;
    }
}

void add_file(Filesystem* fs, char* filename) {
    Node* current = fs->root;
    while (current!= NULL) {
        if (strcmp(current->name, filename) == 0) {
            printf("File %s already exists in the filesystem.\n", filename);
            return;
        }
        current = current->next;
    }
    Node* new_node = (Node*)malloc(sizeof(Node));
    create_node(new_node, filename);
    new_node->next = current;
    fs->root = new_node;
}

void remove_file(Filesystem* fs, char* filename) {
    Node* current = fs->root;
    while (current!= NULL) {
        if (strcmp(current->name, filename) == 0) {
            if (current->next == NULL) {
                fs->root = NULL;
            } else {
                Node* temp = current->next;
                free(current);
                current = temp;
            }
            return;
        }
        current = current->next;
    }
    printf("File %s does not exist in the filesystem.\n", filename);
}

void search_file(Filesystem* fs, char* filename) {
    Node* current = fs->root;
    while (current!= NULL) {
        if (strcmp(current->name, filename) == 0) {
            printf("File %s found in the filesystem.\n", filename);
            return;
        }
        current = current->next;
    }
    printf("File %s does not exist in the filesystem.\n", filename);
}

void main() {
    Filesystem* fs = (Filesystem*)malloc(sizeof(Filesystem));
    create_filesystem(fs);
    add_file(fs, "file1.txt");
    add_file(fs, "file2.txt");
    print_filesystem(fs);
    remove_file(fs, "file1.txt");
    print_filesystem(fs);
    search_file(fs, "file1.txt");
}