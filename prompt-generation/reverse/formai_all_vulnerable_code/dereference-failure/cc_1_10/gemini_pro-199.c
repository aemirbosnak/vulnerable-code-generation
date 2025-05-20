//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: invasive
#include <stdlib.h>
#include <stdio.h>

// Define a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create a new node with the given data and next pointer
Node* createNode(int data, Node* next) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = next;
    return newNode;
}

// Insert a new node at the beginning of the linked list
Node* insertAtBeginning(Node* head, int data) {
    return createNode(data, head);
}

// Insert a new node at the end of the linked list
Node* insertAtEnd(Node* head, int data) {
    if (head == NULL) {
        return createNode(data, NULL);
    }

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = createNode(data, NULL);
    return head;
}

// Insert a new node after a given node in the linked list
Node* insertAfter(Node* head, Node* prev, int data) {
    if (prev == NULL) {
        return createNode(data, head);
    }

    Node* newNode = createNode(data, prev->next);
    prev->next = newNode;
    return head;
}

// Delete a node from the linked list
Node* deleteNode(Node* head, int data) {
    if (head == NULL) {
        return NULL;
    }

    if (head->data == data) {
        Node* newHead = head->next;
        free(head);
        return newHead;
    }

    Node* current = head;
    while (current->next != NULL) {
        if (current->next->data == data) {
            Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
            return head;
        }

        current = current->next;
    }

    return head;
}

// Print the linked list
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}


int main() {
    // **Example 1:  Create a linked list and insert a new node at the beginning**
    Node* list = NULL;
    list = insertAtBeginning(list, 1);
    list = insertAtBeginning(list, 2);
    list = insertAtBeginning(list, 3);
    printLinkedList(list); // Output: 3 2 1
    
    
    
    
    // **Example 2:  Create a linked list and insert a new node at the end**
    list = NULL;
    list = insertAtEnd(list, 1);
    list = insertAtEnd(list, 2);
    list = insertAtEnd(list, 3);
    printLinkedList(list); // Output: 1 2 3
    
    
    
    
    // **Example 3:  Create a linked list and insert a new node after a given node**
    list = NULL;
    list = insertAtBeginning(list, 1);
    list = insertAtBeginning(list, 2);
    list = insertAtBeginning(list, 3);
    list = insertAfter(list, list->next, 4);
    printLinkedList(list); // Output: 3 2 4 1
    
    
    
    
    // **Example 4:  Create a linked list and delete a node from it**
    list = NULL;
    list = insertAtBeginning(list, 1);
    list = insertAtBeginning(list, 2);
    list = insertAtBeginning(list, 3);
    list = deleteNode(list, 2);
    printLinkedList(list); // Output: 3 1
    
    return 0;
}