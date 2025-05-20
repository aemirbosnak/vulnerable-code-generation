//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insertAtEnd(Node** head, int data) {
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

void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);

    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }

    newNode->next = *head;
    *head = newNode;
}

void deleteNode(Node** head, int key) {
    Node* temp = *head, *prev;

    if (temp!= NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

int search(Node* head, int key) {
    Node* current = head;

    while (current!= NULL) {
        if (current->data == key)
            return 1;
        current = current->next;
    }

    return 0;
}

void printList(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtEnd(&head, 30);
    insertAtBeginning(&head, 40);

    printf("Linked List: ");
    printList(head);

    int key;
    printf("\nEnter the key to search: ");
    scanf("%d", &key);

    if (search(head, key))
        printf("\nKey found in the list!");
    else
        printf("\nKey not found in the list.");

    return 0;
}