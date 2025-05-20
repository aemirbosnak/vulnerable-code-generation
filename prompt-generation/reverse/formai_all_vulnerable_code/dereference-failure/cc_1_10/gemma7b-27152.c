//Gemma-7B DATASET v1.0 Category: Linked list operations ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {

    // Create two linked lists for Romeo and Juliet
    struct Node* Romeo = NULL;
    struct Node* Juliet = NULL;

    // Insert data into Romeo's list
    insertAtEnd(&Romeo, 10);
    insertAtEnd(&Romeo, 20);
    insertAtEnd(&Romeo, 30);

    // Insert data into Juliet's list
    insertAtEnd(&Juliet, 40);
    insertAtEnd(&Juliet, 50);
    insertAtEnd(&Juliet, 60);

    // Print both lists
    printList(Romeo);
    printList(Juliet);

    // Check if the lists are equal
    if (Romeo == Juliet) {
        printf("Romeo and Juliet have the same list.\n");
    } else {
        printf("Romeo and Juliet have different lists.\n");
    }

    return 0;
}