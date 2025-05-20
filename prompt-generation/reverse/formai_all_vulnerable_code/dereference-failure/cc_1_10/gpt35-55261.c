//FormAI DATASET v1.0 Category: Linked list operations ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

/* Define the node structure */
typedef struct node {
    int data;
    struct node* next;
} Node;

/* Insert a node at the end of the list */
void insert(Node** head, int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

/* Delete a node with the given value */
void delete(Node** head, int value) {
    Node* current = *head;
    Node* prev = NULL;

    while (current != NULL) {
        if (current->data == value) {
            if (prev == NULL) {
                /* The node to be deleted is the head node */
                *head = current->next;
            } else {
                prev->next = current->next;
            }

            free(current);
            return;
        }

        prev = current;
        current = current->next;
    }

    printf("Node with value %d not found\n", value);
}

/* Print all the nodes in the list */
void printList(Node* head) {
    Node* current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    Node* head = NULL;

    /* Insert some nodes */
    insert(&head, 5);
    insert(&head, 10);
    insert(&head, 15);
    insert(&head, 20);

    /* Delete a node */
    delete(&head, 15);

    /* Print the resulting list */
    printList(head);

    return 0;
}