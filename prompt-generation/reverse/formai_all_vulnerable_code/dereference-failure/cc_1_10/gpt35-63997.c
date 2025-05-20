//FormAI DATASET v1.0 Category: Data structures visualization ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

typedef struct node { // Define a node structure for a linked list
    int data;
    struct node* next;
} Node;

void add(Node** head, int value) { // Add a new node to the list
    Node* temp = *head;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (temp == NULL) { // If the list is empty
        *head = newNode;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(Node* head) { // Print the nodes in the list
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    add(&head, 5);
    add(&head, 10);
    add(&head, 15);
    add(&head, 20);
    add(&head, 25);

    printf("Linked List Visualization:\n");
    printf("| 5 |->| 10 |->| 15 |->| 20 |->| 25 |\n");
    printf("   ^                          |\n");
    printf("   |__________________________|\n");

    printf("\nThe nodes in the list are: ");
    printList(head);

    return 0;
}