//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[20];
    struct Node* next;
} Node;

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%s -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

Node* createNode(char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

void insertAtHead(Node** head, char* data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtTail(Node** head, char* data) {
    Node* newNode = createNode(data);
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

void deleteNode(Node** head, char* data) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (strcmp((*head)->data, data) == 0) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    Node* current = *head;
    while (current->next != NULL && strcmp(current->next->data, data) != 0) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("Element not found!\n");
        return;
    }

    Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
}

int main() {
    Node* head = NULL;

    insertAtHead(&head, "Apple");
    insertAtTail(&head, "Banana");
    insertAtTail(&head, "Cherry");
    insertAtTail(&head, "Date");
    insertAtHead(&head, "Elderberry");

    printList(head);

    deleteNode(&head, "Banana");

    printList(head);

    deleteNode(&head, "Apple");

    printList(head);

    deleteNode(&head, "Date");

    printList(head);

    deleteNode(&head, "Cherry");

    printList(head);

    deleteNode(&head, "Elderberry");

    printList(head);

    free(head);

    return 0;
}