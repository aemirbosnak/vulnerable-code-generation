//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 20

struct node {
    char *data;
    struct node *next;
};

void* malloc_node(size_t size) {
    void* mem = malloc(size);
    struct node* new_node = malloc(sizeof(struct node));
    new_node->data = (char*)mem;
    new_node->next = NULL;
    return new_node;
}

void free_node(void* node) {
    free((char*)node);
}

int main() {
    struct node* head = NULL;
    struct node* current = NULL;

    // Create a linked list of strings
    char* strings[] = {"Hello", "World", "C", "Minimalist", "Programming"};
    for (int i = 0; i < sizeof(strings) / sizeof(strings[0]); i++) {
        current = malloc_node(strlen(strings[i]) + 1);
        strcpy(current->data, strings[i]);
        current->next = head;
        head = current;
    }

    // Print the linked list
    current = head;
    while (current != NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }

    // Free the linked list
    current = head;
    while (current != NULL) {
        free_node(current);
        current = current->next;
    }

    return 0;
}