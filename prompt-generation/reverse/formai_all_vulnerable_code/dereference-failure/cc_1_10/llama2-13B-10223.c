//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRLEN 1024

struct node {
    char *str;
    size_t len;
    struct node *next;
};

void *malloc_node(size_t size) {
    struct node *node = malloc(sizeof(struct node));
    node->str = malloc(size);
    node->len = size;
    node->next = NULL;
    return node;
}

void free_node(void *ptr) {
    struct node *node = ptr;
    free(node->str);
    free(node);
}

int main() {
    struct node *head = NULL, *current = NULL;
    char str[MAX_STRLEN];

    // Create a list of strings
    while (1) {
        printf("Enter a string: ");
        fgets(str, MAX_STRLEN, stdin);
        if (strcmp(str, "") == 0) break;
        current = malloc_node(strlen(str) + 1);
        current->str = strdup(str);
        current->len = strlen(str) + 1;
        current->next = head;
        head = current;
    }

    // Traverse the list and print each string
    current = head;
    while (current != NULL) {
        printf("%s\n", current->str);
        current = current->next;
    }

    // Free the list
    current = head;
    while (current != NULL) {
        free_node(current);
        current = current->next;
    }

    return 0;
}