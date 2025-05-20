//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a new node at the beginning of the linked list
struct Node* addToHead(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (newNode == NULL) {
        return NULL;
    }
    newNode->next = *head;
    *head = newNode;
    return newNode;
}

// Function to add a new node at the end of the linked list
struct Node* addToTail(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (newNode == NULL) {
        return NULL;
    }
    struct Node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return newNode;
}

// Function to display the elements of the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to search for a node in the linked list
struct Node* search(struct Node* head, int data) {
    struct Node* temp = head;
    while (temp!= NULL) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to delete a node from the linked list
struct Node* deleteNode(struct Node* head, int data) {
    struct Node* temp = head;
    struct Node* prev = NULL;
    if (temp == NULL) {
        return temp;
    }
    while (temp!= NULL) {
        if (temp->data == data) {
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return temp;
    }
    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    return head;
}

int main() {
    // Create a new node
    struct Node* node1 = createNode(1);
    if (node1 == NULL) {
        return 1;
    }

    // Add node1 to the head of the linked list
    struct Node* head = addToHead(&node1, 2);
    if (head == NULL) {
        return 2;
    }

    // Add node2 to the tail of the linked list
    struct Node* node2 = createNode(2);
    if (node2 == NULL) {
        return 3;
    }
    head = addToTail(&head, node2->data);
    if (head == NULL) {
        return 4;
    }

    // Display the elements of the linked list
    displayList(head);

    // Search for node2 in the linked list
    struct Node* result = search(head, 2);
    if (result == NULL) {
        printf("Node not found\n");
        return 5;
    }

    // Delete node2 from the linked list
    head = deleteNode(head, 2);
    if (head == NULL) {
        return 6;
    }

    // Display the elements of the linked list after deleting node2
    displayList(head);

    return 0;
}