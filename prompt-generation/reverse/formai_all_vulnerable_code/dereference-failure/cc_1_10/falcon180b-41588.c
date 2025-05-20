//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: energetic
#include <stdio.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to add a node at the end of the linked list
void addNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    }
    else {
        struct Node* temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to reverse the linked list
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;

    while (current!= NULL) {
        struct Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

int main() {
    struct Node* head = NULL;

    // Adding nodes to the linked list
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);

    // Printing the linked list
    printf("Original linked list:\n");
    printList(head);

    // Reversing the linked list
    reverseList(&head);

    // Printing the reversed linked list
    printf("Reversed linked list:\n");
    printList(head);

    return 0;
}