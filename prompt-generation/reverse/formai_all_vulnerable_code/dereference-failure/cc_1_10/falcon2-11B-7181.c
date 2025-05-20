//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = (*head);
    *head = newNode;
}

void deleteNode(struct Node** head, int data) {
    struct Node* temp = *head;
    if (temp == NULL) {
        return;
    }
    if (temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp->next!= NULL && temp->next->data!= data) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        return;
    }
    struct Node* temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
}

void deleteList(struct Node** head) {
    struct Node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    free(temp);
    *head = NULL;
}

int main() {
    struct Node* head = NULL;

    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);
    printList(head);

    printf("After deleting 30: ");
    deleteNode(&head, 30);
    printList(head);

    deleteList(&head);
    return 0;
}