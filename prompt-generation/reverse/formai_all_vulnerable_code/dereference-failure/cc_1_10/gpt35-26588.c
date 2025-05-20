//FormAI DATASET v1.0 Category: Data structures visualization ; Style: complex
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node_t;

void insert(node_t** head, int data) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void delete(node_t** head, int data) {
    node_t* current = *head;
    node_t* prev = NULL;

    if(current != NULL && current->data == data) {
        *head = current->next;
        free(current);
        return;
    }

    while(current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    if(current == NULL) return;
    prev->next = current->next;
    free(current);
}

void print_list(node_t** head) {
    node_t* current = *head;

    while(current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

int main() {
    node_t* head = NULL;

    insert(&head, 5);
    insert(&head, 8);
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);

    delete(&head, 3);
    delete(&head, 8);
    delete(&head, 1);

    print_list(&head);

    return 0;
}