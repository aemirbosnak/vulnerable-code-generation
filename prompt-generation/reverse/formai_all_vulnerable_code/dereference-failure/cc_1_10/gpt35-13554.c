//FormAI DATASET v1.0 Category: Linked list operations ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Define the structure of the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to check whether the linked list is empty or not
int isEmpty(Node* head) {
    return head == NULL;
}

// Function to get the length of the linked list
int length(Node* head) {
    Node* current = head;
    int count = 0;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

// Function to print the elements of the linked list
void printList(Node* head) {
    Node* current = head;

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

// Function to insert an element at the beginning of the linked list
void insertFirst(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to insert an element at the end of the linked list
void insertLast(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(*head)) {
        *head = newNode;
    } else {
        Node* current = *head;
        
        while (current->next != NULL) {
            current = current->next;
        }
        
        current->next = newNode;
    }
}

// Function to delete an element from the linked list
void delete(Node** head, int data) {
    if (isEmpty(*head)) {
        printf("Linked list is empty.\n");
        return;
    }

    Node* current = *head;
    Node* prev = NULL;

    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Could not find the element %d.\n", data);
        return;
    }

    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

// Main function
int main() {
    Node* head = NULL;

    insertFirst(&head, 10);
    insertFirst(&head, 20);
    insertFirst(&head, 30);
    insertFirst(&head, 40);

    printf("Linked list after inserting elements at the beginning:\n");
    printList(head);

    insertLast(&head, 50);
    insertLast(&head, 60);
    insertLast(&head, 70);

    printf("\nLinked list after inserting elements at the end:\n");
    printList(head);

    delete(&head, 30);

    printf("\nLinked list after deleting an element:\n");
    printList(head);

    printf("\nThe length of the linked list is %d.\n", length(head));

    return 0;
}