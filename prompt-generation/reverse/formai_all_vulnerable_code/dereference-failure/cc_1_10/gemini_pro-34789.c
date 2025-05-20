//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *name;
    int size;
    struct node *next;
} node_t;

typedef struct dir {
    char *name;
    node_t *head;
    node_t *tail;
    struct dir *next;
} dir_t;

dir_t *root_dir;

void add_file(char *name, int size) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->name = malloc(strlen(name) + 1);
    strcpy(new_node->name, name);
    new_node->size = size;
    new_node->next = NULL;

    if (root_dir->head == NULL) {
        root_dir->head = new_node;
        root_dir->tail = new_node;
    } else {
        root_dir->tail->next = new_node;
        root_dir->tail = new_node;
    }
}

void add_dir(char *name) {
    dir_t *new_dir = malloc(sizeof(dir_t));
    new_dir->name = malloc(strlen(name) + 1);
    strcpy(new_dir->name, name);
    new_dir->head = NULL;
    new_dir->tail = NULL;
    new_dir->next = NULL;

    if (root_dir->next == NULL) {
        root_dir->next = new_dir;
    } else {
        dir_t *current_dir = root_dir->next;
        while (current_dir->next != NULL) {
            current_dir = current_dir->next;
        }
        current_dir->next = new_dir;
    }
}

void print_file(node_t *file) {
    printf("%s (%d bytes)\n", file->name, file->size);
}

void print_dir(dir_t *dir) {
    printf("%s\n", dir->name);
    node_t *current_file = dir->head;
    while (current_file != NULL) {
        print_file(current_file);
        current_file = current_file->next;
    }
    dir_t *current_dir = dir->next;
    while (current_dir != NULL) {
        print_dir(current_dir);
        current_dir = current_dir->next;
    }
}

int main() {
    root_dir = malloc(sizeof(dir_t));
    root_dir->name = "/";
    root_dir->head = NULL;
    root_dir->tail = NULL;
    root_dir->next = NULL;

    add_file("file1.txt", 100);
    add_file("file2.txt", 200);
    add_dir("dir1");
    add_file("dir1/file3.txt", 300);
    add_dir("dir1/subdir1");
    add_file("dir1/subdir1/file4.txt", 400);

    print_dir(root_dir);

    return 0;
}