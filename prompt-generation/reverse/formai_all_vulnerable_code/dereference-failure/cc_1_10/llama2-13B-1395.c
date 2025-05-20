//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 20
#define MAX_ARRAY_SIZE 10

typedef struct node {
    char *str;
    struct node *next;
} node_t;

node_t *create_node(char *str) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->str = str;
    new_node->next = NULL;
    return new_node;
}

void print_node(node_t *node) {
    printf("%s\n", node->str);
}

void free_node(node_t *node) {
    free(node->str);
    if (node->next != NULL) {
        free_node(node->next);
    }
    free(node);
}

int main() {
    srand(time(NULL));

    node_t *head = NULL, *current = NULL;

    for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
        char str[MAX_STR_LEN];
        snprintf(str, MAX_STR_LEN, "Item %d", i);
        head = create_node(str);
        current = head;

        for (int j = 0; j < i; j++) {
            current = current->next;
            if (current == NULL) {
                break;
            }
        }

        current->next = create_node(str);
    }

    print_node(head);

    for (node_t *node = head; node != NULL; node = node->next) {
        free_node(node);
    }

    return 0;
}