//FormAI DATASET v1.0 Category: Linked list operations ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node node;

void insertAtEnd(node** head, int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void deleteAtEnd(node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    node* current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

void display(node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    node* head = NULL;

    insertAtEnd(&head, 5);
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 15);
    insertAtEnd(&head, 20);

    printf("Initial list: ");
    display(head);
    
    deleteAtEnd(&head);
    printf("List after deleting last element: ");
    display(head);

    deleteAtEnd(&head);
    printf("List after deleting last element: ");
    display(head);

    insertAtEnd(&head, 25);
    printf("List after inserting new element: ");
    display(head);

    return 0;
}