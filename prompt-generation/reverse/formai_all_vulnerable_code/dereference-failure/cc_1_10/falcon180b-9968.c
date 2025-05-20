//Falcon-180B DATASET v1.0 Category: Memory management ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct node {
    char *data;
    struct node *next;
} node_t;

node_t *head = NULL;

void add_node(char *data) {
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    if (new_node == NULL) {
        printf("Error: Out of memory.\n");
        exit(1);
    }
    new_node->data = strdup(data);
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        node_t *current_node = head;
        while (current_node->next!= NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

void delete_node(char *data) {
    node_t *current_node = head;
    while (current_node!= NULL) {
        if (strcmp(current_node->data, data) == 0) {
            node_t *next_node = current_node->next;
            free(current_node->data);
            free(current_node);
            if (next_node == NULL) {
                head = NULL;
            } else {
                head = next_node;
            }
            return;
        }
        current_node = current_node->next;
    }
}

void print_list() {
    node_t *current_node = head;
    while (current_node!= NULL) {
        printf("%s\n", current_node->data);
        current_node = current_node->next;
    }
}

int main() {
    add_node("Hello");
    add_node("World");
    print_list();
    delete_node("Hello");
    print_list();
    return 0;
}