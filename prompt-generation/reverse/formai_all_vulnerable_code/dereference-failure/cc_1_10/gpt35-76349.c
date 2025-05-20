//FormAI DATASET v1.0 Category: Linked list operations ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *next;
};

typedef struct node Node;

void printList(Node *n) {
    while (n != NULL) {
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
}

void addNode(Node **head_ref, int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void deleteNode(Node **head_ref, int key) {
    Node *temp = *head_ref, *prev;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }
    prev->next = temp->next;
    free(temp);
}

int main() {
    Node *head = NULL;

    addNode(&head, 3);
    addNode(&head, 5);
    addNode(&head, 7);
    
    printf("Linked List: ");
    printList(head);

    printf("Deleting node with data 5\n");
    deleteNode(&head, 5);

    printf("Linked List after deletion: ");
    printList(head);

    return 0;
}