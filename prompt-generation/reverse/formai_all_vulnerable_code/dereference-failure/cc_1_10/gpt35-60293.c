//FormAI DATASET v1.0 Category: File system simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct file_struct {
    char name[MAX_SIZE];
    struct file_struct* parent;
    struct file_struct* child;
} File;

void print_dir(File* parent, int indent) {
    if (parent == NULL) {
        return;
    }
    for (int i = 0; i < indent; i++) {
        printf("\t");
    }
    printf("|-> %s\n", parent->name);
    print_dir(parent->child, indent + 1);
    print_dir(parent->parent, indent - 1);
}

void create_dir(File* parent, char* name) {
    File* child = malloc(sizeof(File));
    strcpy(child->name, name);
    child->parent = parent;
    child->child = NULL;

    if (parent->child == NULL) {
        parent->child = child;
    } else {
        File* temp = parent->child;
        while (temp->child != NULL) {
            temp = temp->child;
        }
        temp->child = child;
    }
}

int main() {
    File* root = malloc(sizeof(File));
    strcpy(root->name, "root");
    root->parent = NULL;
    root->child = NULL;

    create_dir(root, "dir1");
    create_dir(root, "dir2");
    create_dir(root->child, "dir3");
    create_dir(root->child, "dir4");

    printf("\nFile system:\n");
    print_dir(root, 0);

    return 0;
}