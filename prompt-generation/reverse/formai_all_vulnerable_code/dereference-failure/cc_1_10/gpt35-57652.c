//FormAI DATASET v1.0 Category: Linked list operations ; Style: realistic
#include<stdio.h>
#include<stdlib.h>

// Linked List Node Structure
struct Node {
    int data;
    struct Node* next;
};

// Function to traverse and print the Linked List
void printList(struct Node* n) {
    while (n != NULL) {
        printf(" %d ", n->data);
        n = n->next;
    }
    printf("\n");
}

// Function to insert a new node at the beginning of the Linked List
void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to insert a new node after a given node in the Linked List
void insertAfterNode(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Function to insert a new node at the end of the Linked List
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}

// Function to delete a node with given key from the Linked List
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref, *prev;
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

// Function to reverse the Linked List
void reverseList(struct Node** head_ref) {
    struct Node* prev_node = NULL;
    struct Node* current_node = *head_ref;
    struct Node* next_node = NULL;
    while (current_node != NULL) {
        next_node = current_node->next;
        current_node->next = prev_node;
        prev_node = current_node;
        current_node = next_node;
    }
    *head_ref = prev_node;
}

// Driver program to test above functions
int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 3);
    insertAtBeginning(&head, 1);
    insertAfterNode(head->next, 2);

    printf("\nInitial Linked List: ");
    printList(head);

    deleteNode(&head, 2);

    printf("\nLinked List after deleting node with key 2: ");
    printList(head);

    printf("\nReversed Linked List: ");
    reverseList(&head);
    printList(head);

    return 0;
}