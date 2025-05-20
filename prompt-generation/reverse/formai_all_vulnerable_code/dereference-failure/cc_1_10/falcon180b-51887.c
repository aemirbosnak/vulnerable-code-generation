//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node with given data
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node) {
        printf("Memory error\n");
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the list
void push(Node** head_ref, int new_data) {
    Node* new_node = newNode(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
    printf("%d pushed to stack\n", new_data);
}

// Function to insert a node at the end of the list
void append(Node** head_ref, int new_data) {
    Node* new_node = newNode(new_data);
    Node* last = *head_ref;
    if (*head_ref == NULL) {
        new_node->next = NULL;
        *head_ref = new_node;
        return;
    }
    while (last->next!= NULL) {
        last = last->next;
    }
    last->next = new_node;
    printf("%d appended to stack\n", new_data);
}

// Function to delete a node from the list
void deleteNode(Node **head_ref, int key) {
    Node* temp = *head_ref;
    Node* prev;
    
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

// Function to search for a node in the list
Node* search(Node* head, int x) {
    Node* current = head;
    while (current!= NULL) {
        if (current->data == x)
            return current;
        current = current->next;
    }
    return NULL;
}

// Function to print the list
void printList(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    // Test push operation
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    printList(head);

    // Test append operation
    append(&head, 40);
    append(&head, 50);
    printList(head);

    // Test delete operation
    deleteNode(&head, 20);
    printList(head);

    // Test search operation
    Node* result = search(head, 30);
    if (result!= NULL)
        printf("Found %d in the list\n", result->data);
    else
        printf("Did not find %d in the list\n", 30);

    return 0;
}