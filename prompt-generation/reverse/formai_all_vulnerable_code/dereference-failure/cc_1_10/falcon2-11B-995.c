//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

struct Directory {
    char name[100];
    int size;
    struct Directory *next;
};

struct Directory *root = NULL;

void add_directory(char *name, int size) {
    struct Directory *new_dir = malloc(sizeof(struct Directory));
    strcpy(new_dir->name, name);
    new_dir->size = size;
    new_dir->next = NULL;
    if (root == NULL) {
        root = new_dir;
    } else {
        struct Directory *current = root;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_dir;
    }
}

void print_directory_tree(struct Directory *current) {
    if (current == NULL) {
        return;
    }
    printf("%s\n", current->name);
    struct Directory *next = current->next;
    while (next!= NULL) {
        print_directory_tree(next);
        next = next->next;
    }
}

int main() {
    add_directory("root", 1024);
    add_directory("file1", 512);
    add_directory("file2", 1024);
    add_directory("file3", 2048);
    add_directory("subdir", 512);
    add_directory("subdir/file1", 512);
    add_directory("subdir/file2", 1024);
    add_directory("subdir/file3", 2048);
    print_directory_tree(root);
    return 0;
}