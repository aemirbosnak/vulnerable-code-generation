//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
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

void deleteNode(Node** head, int key) {
    Node* temp = *head;
    Node* prev;

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

int searchElement(Node* head, int key) {
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

    insertAtEnd(&head, 5);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 7);
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 3);

    printf("Original list: ");
    printList(head);

    int key;
    printf("\nEnter the element to search: ");
    scanf("%d", &key);

    if (searchElement(head, key))
        printf("\nElement found!\n");
    else
        printf("\nElement not found.\n");

    deleteNode(&head, 5);

    printf("\nList after deleting 5: ");
    printList(head);

    return 0;
}