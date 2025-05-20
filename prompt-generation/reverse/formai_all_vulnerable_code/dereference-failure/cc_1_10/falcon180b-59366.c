//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: ephemeral
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
        exit(1);
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
}

void deleteNode(Node** head, int key) {
    Node* temp = *head;
    Node* prev = NULL;
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

void searchElement(Node* head, int key) {
    Node* current = head;
    while (current!= NULL) {
        if (current->data == key)
            printf("%d found\n", key);
        current = current->next;
    }
    if (current == NULL)
        printf("%d not found\n", key);
}

void displayList(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    Node* head = NULL;
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    printf("List after insertion:\n");
    displayList(head);

    searchElement(head, 20);
    searchElement(head, 100);

    deleteNode(&head, 20);

    printf("\nList after deleting 20:\n");
    displayList(head);

    deleteNode(&head, 30);

    printf("\nList after deleting 30:\n");
    displayList(head);

    deleteNode(&head, 10);

    printf("\nList after deleting 10:\n");
    displayList(head);

    return 0;
}