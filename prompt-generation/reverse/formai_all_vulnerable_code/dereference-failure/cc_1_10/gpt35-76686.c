//FormAI DATASET v1.0 Category: Linked list operations ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

/* Define the Node structure */
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/* Function to insert a new node at the beginning of the linked list */
void insertAtBeginning(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

/* Function to insert a new node at the end of the linked list */
void insertAtEnd(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

/* Function to delete the first occurrence of a given value in the linked list */
void deleteNode(Node** head, int data) {
    Node* temp = *head;
    Node* prev = NULL;

    if (temp == NULL) {
        printf("Empty list\n");
        return;
    }

    if (temp != NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

/* Function to display the contents of the linked list */
void display(Node* head) {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }

    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

/* Main function to test the linked list operations */
int main() {
    Node* head = NULL;

    /* Insert some nodes */
    insertAtEnd(&head, 5);
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 8);
    insertAtBeginning(&head, 2);

    /* Display the contents */
    printf("\nLinked list contents: ");
    display(head);

    /* Delete some nodes */
    deleteNode(&head, 10);
    deleteNode(&head, 5);
    deleteNode(&head, 100);

    /* Display the contents again */
    printf("\nLinked list contents after deletion: ");
    display(head);

    return 0;
}