//Falcon-180B DATASET v1.0 Category: Memory management ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

void createList(struct Node** head) {
    *head = (struct Node*)malloc(sizeof(struct Node));
    if (*head == NULL) {
        printf("Memory could not be allocated\n");
        exit(1);
    }
    (*head)->data = 1;
    (*head)->next = NULL;
}

void insertNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory could not be allocated\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteNode(struct Node** head, int data) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void printList(struct Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    createList(&head);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    printList(head);
    deleteNode(&head, 2);
    printList(head);
    deleteNode(&head, 3);
    printList(head);
    deleteNode(&head, 4);
    printList(head);
    return 0;
}