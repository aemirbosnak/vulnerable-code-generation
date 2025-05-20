//FormAI DATASET v1.0 Category: Linked list operations ; Style: genious
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node node_t;

void print_list(node_t* head) {
    node_t* current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void push(node_t** head_ref, int new_data) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));

    new_node->data = new_data;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

void delete_node(node_t** head_ref, int key) {
    node_t* temp = *head_ref,
        * prev;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;

    free(temp);
}

int main() {
    node_t* head = NULL;

    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);

    printf("Linked List: ");
    print_list(head);

    delete_node(&head, 3);

    printf("Linked List after Deletion of 3: ");
    print_list(head);

    delete_node(&head, 5);
    printf("Linked List after Deletion of 5: ");
    print_list(head);

    return 0;
}