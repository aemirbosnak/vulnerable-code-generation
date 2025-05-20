//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: romantic
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList {
    int data;
    struct LinkedList *next;
} LinkedList;

void insertAtBeginning(LinkedList **head, int data) {
    LinkedList *newNode = (LinkedList *)malloc(sizeof(LinkedList));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(LinkedList **head, int data) {
    LinkedList *newNode = (LinkedList *)malloc(sizeof(LinkedList));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        LinkedList *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void insertAtIndex(LinkedList **head, int data, int index) {
    if (index == 0) {
        insertAtBeginning(head, data);
    } else {
        LinkedList *newNode = (LinkedList *)malloc(sizeof(LinkedList));
        newNode->data = data;
        LinkedList *current = *head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void deleteAtBeginning(LinkedList **head) {
    if (*head == NULL) {
        return;
    }
    LinkedList *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteAtEnd(LinkedList **head) {
    if (*head == NULL) {
        return;
    }
    LinkedList *current = *head;
    LinkedList *previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    if (previous == NULL) {
        *head = NULL;
    } else {
        previous->next = NULL;
    }
    free(current);
}

void deleteAtIndex(LinkedList **head, int index) {
    if (*head == NULL) {
        return;
    }
    LinkedList *current = *head;
    LinkedList *previous = NULL;
    for (int i = 0; i < index; i++) {
        previous = current;
        current = current->next;
    }
    if (previous == NULL) {
        *head = (*head)->next;
    } else {
        previous->next = current->next;
    }
    free(current);
}

void printLinkedList(LinkedList *head) {
    LinkedList *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    LinkedList *head = NULL;
    // Insert some hearts into the linked list
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 1);
    insertAtBeginning(&head, 5);
    insertAtEnd(&head, 10);
    insertAtIndex(&head, 7, 3);
    // The moon and the stars: a background for our hearts
    printf("The moon and the stars:\n");
    printLinkedList(head);
    // Delete a few hearts to symbolize the ups and downs in love
    deleteAtBeginning(&head);
    deleteAtEnd(&head);
    deleteAtIndex(&head, 2);
    // The remaining hearts: stronger and more resilient
    printf("The remaining hearts:\n");
    printLinkedList(head);
    return 0;
}