//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct node {
    int data;
    struct node* next;
} node_t;

node_t* insert(node_t* head, int data) {
    node_t* new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        head->next = new_node;
    }

    return head;
}

void find_route(node_t* head, int target) {
    node_t* current = head;
    while (current) {
        if (current->data == target) {
            printf("Route found!\n");
            return;
        } else if (current->data > target) {
            printf("Target not found.\n");
            return;
        } else {
            current = current->next;
        }
    }

    printf("Target not found.\n");
}

int main() {
    node_t* head = insert(NULL, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);

    find_route(head, 4);

    return 0;
}