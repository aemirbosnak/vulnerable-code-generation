//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *name;
    int size;
    struct node *next;
} node;

node *head = NULL;

void add_file(char *name, int size) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->name = name;
    new_node->size = size;
    new_node->next = head;
    head = new_node;
}

void remove_file(char *name) {
    node *current = head;
    node *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->name);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

int get_file_size(char *name) {
    node *current = head;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current->size;
        }
        current = current->next;
    }

    return -1;
}

void print_files() {
    node *current = head;

    while (current != NULL) {
        printf("%s (%d bytes)\n", current->name, current->size);
        current = current->next;
    }
}

int main() {
    add_file("file1.txt", 100);
    add_file("file2.txt", 200);
    add_file("file3.txt", 300);

    print_files();

    remove_file("file2.txt");

    print_files();

    printf("File size of file1.txt: %d bytes\n", get_file_size("file1.txt"));

    return 0;
}