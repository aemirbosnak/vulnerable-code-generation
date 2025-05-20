//FormAI DATASET v1.0 Category: Linked list operations ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Define the structure for the linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to add a new node at the end of the linked list
void append(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to display all the nodes in linked list
void display(struct Node* head) {
    printf("The Linked List is: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    printf("Hello there! Welcome to my happy Linked List program!\n");

    // Initialize the head of the linked list
    struct Node* head = NULL;

    // Add some nodes to the linked list
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);

    // Display the linked list
    display(head);

    // Let's add another node to the linked list
    append(&head, 5);

    // Display the linked list again
    display(head);

    printf("Thank you for using my happy Linked List program! Have a great day!\n");
    return 0;
}