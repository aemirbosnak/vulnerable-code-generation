//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addToEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* temp = *head;

    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }

    while (temp->next!= NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = NULL;
}

void deleteNode(Node** head, int data) {
    Node* temp = *head;
    Node* prev = NULL;

    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

int search(Node* head, int data) {
    Node* temp = head;

    while (temp!= NULL) {
        if (temp->data == data)
            return 1;
        temp = temp->next;
    }

    return 0;
}

void printList(Node* head) {
    Node* temp = head;

    if (head == NULL)
        return;

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;

    addToEnd(&head, 1);
    addToEnd(&head, 2);
    addToEnd(&head, 3);
    addToEnd(&head, 4);
    addToEnd(&head, 5);

    printf("Initial list:\n");
    printList(head);

    deleteNode(&head, 3);

    printf("\nList after deleting 3:\n");
    printList(head);

    int searchData = 4;
    int result = search(head, searchData);

    if (result)
        printf("\n%d found in the list", searchData);
    else
        printf("\n%d not found in the list", searchData);

    return 0;
}