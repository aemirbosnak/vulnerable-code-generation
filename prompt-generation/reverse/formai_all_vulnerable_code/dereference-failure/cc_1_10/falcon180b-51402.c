//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: lively
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
    }
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
    if (temp == NULL) {
        printf("Element not found\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void searchNode(Node* head, int data) {
    Node* temp = head;
    while (temp!= NULL) {
        if (temp->data == data) {
            printf("Element found\n");
            return;
        }
        temp = temp->next;
    }
    printf("Element not found\n");
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    insertNode(&head, 5);
    insertNode(&head, 10);
    insertNode(&head, 15);
    displayList(head);
    searchNode(head, 10);
    deleteNode(&head, 10);
    displayList(head);
    return 0;
}