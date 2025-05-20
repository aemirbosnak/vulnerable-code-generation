//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure definition
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a node at the end of the list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = newNode(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Function to search for an element in the linked list
bool search(struct Node* head, int x) {
    struct Node* current = head;
    while (current!= NULL) {
        if (current->data == x)
            return true;
        current = current->next;
    }
    return false;
}

// Driver code to test above functions
int main() {
    struct Node* head = NULL;
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    push(&head, 6);
    push(&head, 8);

    printf("Created Linked List: ");
    printList(head);

    int searchElement = 6;
    if (search(head, searchElement))
        printf("\n%d found in the linked list", searchElement);
    else
        printf("\n%d not found in the linked list", searchElement);

    return 0;
}