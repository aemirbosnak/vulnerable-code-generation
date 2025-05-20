//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 100
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

void print_nodes(node_t *head) {
    while (head != NULL) {
        printf("%s\n", head->str);
        head = head->next;
    }
}

int main() {
    node_t *head = NULL;
    char str[MAX_STR_LEN];
    int i;

    // Create some nodes
    for (i = 0; i < MAX_ARRAY_SIZE; i++) {
        sprintf(str, "Node %d", i);
        head = create_node(str);
        if (head == NULL) {
            printf("Failed to create node\n");
            return 1;
        }
    }

    // Print the nodes
    print_nodes(head);

    // Free the nodes
    while (head != NULL) {
        node_t *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}