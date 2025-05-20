//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// Define node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert a node at the end of the list
void append(Node** headRef, int newData) {
    Node* newNode = createNode(newData);
    Node* last = *headRef;
    if (*headRef == NULL) {
        newNode->next = NULL;
        *headRef = newNode;
        return;
    }
    while (last->next!= NULL)
        last = last->next;
    last->next = newNode;
    return;
}

// Insert a node at the beginning of the list
void prepend(Node** headRef, int newData) {
    Node* newNode = createNode(newData);
    if (*headRef == NULL) {
        newNode->next = NULL;
        *headRef = newNode;
        return;
    }
    newNode->next = *headRef;
    *headRef = newNode;
    return;
}

// Insert a node after a given position
void insertAfter(Node* prevNode, int newData) {
    if (prevNode == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }
    Node* newNode = createNode(newData);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    return;
}

// Delete a node by key
void deleteNode(Node** headRef, int key) {
    Node* temp = *headRef, *prev;
    if (temp!= NULL && temp->data == key) {
        *headRef = temp->next;
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
    return;
}

// Display the elements in the list
void display(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Main function
int main() {
    Node* head = NULL;
    
    // Append elements
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    
    // Prepend elements
    prepend(&head, 5);
    prepend(&head, 4);
    
    // Insert element after a given position
    Node* thirdNode = head->next->next;
    insertAfter(thirdNode, 15);
    
    // Display the list
    printf("List after appending, prepending and inserting nodes: ");
    display(head);
    
    // Delete a node
    deleteNode(&head, 10);
    
    // Display the updated list
    printf("\nList after deleting a node: ");
    display(head);
    
    return 0;
}