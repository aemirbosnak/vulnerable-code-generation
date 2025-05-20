//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

/* Define a structure for the node in the linked list */
struct Node {
    int data;
    struct Node* next;
};

/* Function to insert a new node at the beginning of the linked list */
void insert(struct Node** head_ref, int new_data) {
    /* Allocate memory for the new node */
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    /* Initialize the new node */
    new_node->data = new_data;
    new_node->next = (*head_ref);

    /* Update the head pointer */
    (*head_ref) = new_node;
}

/* Function to search for a given value in the linked list */
int search(struct Node* head, int value) {
    struct Node* current = head;

    while (current!= NULL && current->data!= value) {
        current = current->next;
    }

    return (current == NULL)? -1 : 1;
}

/* Function to delete a node from the linked list */
void delete(struct Node** head_ref, int value) {
    struct Node* current = *head_ref;
    struct Node* prev;

    while (current!= NULL && current->data!= value) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        return;
    }

    if (current == *head_ref) {
        *head_ref = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

/* Function to print the contents of the linked list */
void print(struct Node* head) {
    struct Node* current = head;

    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    struct Node* head = NULL;

    /* Insert some values into the linked list */
    insert(&head, 5);
    insert(&head, 10);
    insert(&head, 15);
    insert(&head, 20);
    insert(&head, 25);

    /* Search for a value in the linked list */
    int search_value = search(head, 15);

    if (search_value == 1) {
        printf("Value found: %d\n", 15);
    } else {
        printf("Value not found\n");
    }

    /* Delete a node from the linked list */
    delete(&head, 10);

    /* Print the contents of the linked list */
    print(head);

    return 0;
}