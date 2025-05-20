//FormAI DATASET v1.0 Category: Data structures visualization ; Style: complete
#include <stdio.h>
#include <stdlib.h>

/* Define a structure for each node of the linked list */
struct node {
    int data;
    struct node *next;
};

/* Define a function to create a new node */
struct node *create_node(int data) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/* Define a function to insert a node at the end of the linked list */
void insert_node(struct node **head_ref, int data) {
    if (*head_ref == NULL) {
        *head_ref = create_node(data);
        return;
    }
    struct node *last_node = *head_ref;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    last_node->next = create_node(data);
}

/* Define a function to print the linked list */
void print_list(struct node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;

    /* Insert nodes into the linked list */
    insert_node(&head, 1);
    insert_node(&head, 2);
    insert_node(&head, 3);
    insert_node(&head, 4);

    /* Print the linked list */
    printf("Linked List: ");
    print_list(head);

    return 0;
}