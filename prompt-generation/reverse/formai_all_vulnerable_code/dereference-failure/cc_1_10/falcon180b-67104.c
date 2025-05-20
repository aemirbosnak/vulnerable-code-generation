//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = newNode(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
    printf("%d pushed to stack\n", new_data);
}

// Function to insert a node at the end of the list
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = newNode(new_data);
    struct Node* last = *head_ref;

    if (*head_ref == NULL) {
        new_node->next = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next!= NULL)
        last = last->next;

    last->next = new_node;
    printf("%d appended to stack\n", new_data);
}

// Function to delete a node from the list
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
    printf("%d deleted from stack\n", key);
}

// Function to print the list
void printList(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Driver program to test above functions
int main() {
    struct Node* head = NULL;

    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);

    printf("Created Linked List: ");
    printList(head);

    append(&head, 50);
    printf("\nLinked List after appending 50: ");
    printList(head);

    deleteNode(&head, 10);
    printf("\nLinked List after deleting 10: ");
    printList(head);

    deleteNode(&head, 30);
    printf("\nLinked List after deleting 30: ");
    printList(head);

    return 0;
}