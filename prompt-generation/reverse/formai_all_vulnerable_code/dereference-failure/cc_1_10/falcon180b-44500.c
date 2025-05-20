//Falcon-180B DATASET v1.0 Category: Memory management ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *data;
    struct node *next;
} node_t;

node_t *create_node(char *data) {
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void add_node(node_t **head, char *data) {
    node_t *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    node_t *temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void print_list(node_t *head) {
    node_t *temp = head;
    while (temp!= NULL) {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void free_list(node_t *head) {
    node_t *temp = head;
    while (temp!= NULL) {
        free(temp->data);
        temp = temp->next;
    }
    free(head);
}

int main() {
    node_t *head = NULL;
    char *data = "hello";
    add_node(&head, data);
    print_list(head);
    return 0;
}