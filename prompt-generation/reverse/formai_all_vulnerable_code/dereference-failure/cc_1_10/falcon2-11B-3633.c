//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: relaxed
#include <stdio.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new Node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the Linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while(temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to insert a node at the beginning of the Linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = (*head);
    *head = newNode;
}

// Function to insert a node at the end of the Linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while(temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node from the Linked list
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if ((*head)->data == key) {
        *head = (*head)->next;
        free((*head));
        return;
    }
    struct Node* temp = *head;
    while(temp->next!= NULL && temp->next->data!= key) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Key not found\n");
        return;
    }
    temp->next = temp->next->next;
    free(temp->next);
}

// Function to search for a node in the Linked list
int searchNode(struct Node* head, int key) {
    if (head == NULL) {
        return 0;
    }
    while(head!= NULL && head->data!= key) {
        head = head->next;
    }
    return head!= NULL;
}

int main() {
    struct Node* head = NULL;

    // Inserting nodes at the beginning and end of the Linked list
    insertAtBeginning(&head, 1);
    insertAtEnd(&head, 2);
    insertAtBeginning(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);

    // Printing the Linked list
    printf("Linked list before deletion: ");
    printList(head);

    // Deleting a node from the Linked list
    deleteNode(&head, 4);

    // Printing the Linked list after deletion
    printf("Linked list after deletion: ");
    printList(head);

    return 0;
}