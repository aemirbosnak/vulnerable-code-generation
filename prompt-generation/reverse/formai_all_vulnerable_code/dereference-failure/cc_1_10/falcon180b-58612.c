//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node* node) {
    while (node!= NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}

int search(struct Node* head, int x) {
    struct Node* current = head;
    while (current!= NULL) {
        if (current->data == x)
            return 1;
        current = current->next;
    }
    return 0;
}

void deleteNode(struct Node **head_ref, int key) {
    struct Node* temp = *head_ref, *prev;

    if (temp!= NULL && temp->data == key) {
        *head_ref = temp->next; 
        free(temp);            
        return;
    }

    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

void reverseList(struct Node **head_ref) {
    struct Node* prev = NULL;
    struct Node* current = *head_ref;

    while (current!= NULL) {
        struct Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head_ref = prev;
}

int main() {
    struct Node* head = NULL;

    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    push(&head, 6);
    push(&head, 5);

    printf("Created Linked List: ");
    printList(head);

    int find = 5;
    int position = search(head, find);

    if (position == 0)
        printf("\nElement not present in the list");
    else
        printf("\nElement found at position %d", position + 1);

    deleteNode(&head, 1);
    printf("\nList after deleting 1: ");
    printList(head);

    reverseList(&head);
    printf("\nReversed List: ");
    printList(head);

    return 0;
}