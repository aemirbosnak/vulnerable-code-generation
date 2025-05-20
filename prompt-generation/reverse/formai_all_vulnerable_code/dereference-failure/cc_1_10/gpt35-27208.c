//FormAI DATASET v1.0 Category: Linked list operations ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = (*head);
    (*head) = newNode;
}

void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    newNode->value = value;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteNode(struct Node** head, int value) {
    struct Node* temp = *head, *prev;
    if (temp != NULL && temp->value == value) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->value != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Value not found!\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    insertAtEnd(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtEnd(&head, 3);
    insertAtBeginning(&head, 4);
    printf("Original List: ");
    display(head);
    deleteNode(&head, 2);
    printf("After deleting node with value 2: ");
    display(head);
    insertAtEnd(&head, 5);
    printf("After inserting value 5 at end: ");
    display(head);
    deleteNode(&head, 6);
    printf("After deleting value 6: ");
    display(head);

    return 0;
}