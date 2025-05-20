//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *data;
    struct node *next;
} node;

node *head = NULL;

void insert_node(char *data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = strdup(data);
    new_node->next = head;
    head = new_node;
}

void print_list() {
    node *current = head;
    while (current != NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }
}

void free_list() {
    node *current = head;
    while (current != NULL) {
        node *next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
}

int main() {
    char *data[] = {
        "The", "quick", "brown", "fox", "jumps",
        "over", "the", "lazy", "dog"
    };

    for (int i = 0; i < 9; i++) {
        insert_node(data[i]);
    }

    print_list();
    free_list();

    return 0;
}