//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

typedef struct file_node {
    char name[256];
    struct file_node* next;
    struct file_node* parent;
    int size;
    char data[1024];
} file_node;

file_node* create_file(char* name, int size) {
    file_node* new_file = malloc(sizeof(file_node));
    strcpy(new_file->name, name);
    new_file->size = size;
    new_file->next = NULL;
    new_file->parent = NULL;
    return new_file;
}

void add_file(file_node* parent, char* name, int size) {
    file_node* new_file = create_file(name, size);
    if (parent) {
        new_file->parent = parent;
    }
    if (parent->next) {
        parent->next->next = new_file;
    } else {
        parent->next = new_file;
    }
}

void list_files(file_node* current) {
    printf("%s ", current->name);
    if (current->next) {
        list_files(current->next);
    }
}

int main() {
    file_node* root = NULL;
    add_file(root, "a.txt", 10);
    add_file(root, "b.txt", 20);
    add_file(root, "c.txt", 30);
    list_files(root);
    return 0;
}