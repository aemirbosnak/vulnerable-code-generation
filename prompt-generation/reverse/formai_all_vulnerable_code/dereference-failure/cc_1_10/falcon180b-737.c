//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data;
    struct node* next;
} Node;

Node* createNode(char data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addNodeAtBeginning(Node** headRef, char data) {
    Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    newNode->next = *headRef;
    *headRef = newNode;
}

void addNodeAtEnd(Node** headRef, char data) {
    Node* newNode = createNode(data);
    Node* last = *headRef;
    if (*headRef == NULL) {
        newNode->next = NULL;
        *headRef = newNode;
        return;
    }
    while (last->next!= NULL)
        last = last->next;
    last->next = newNode;
}

void addNodeAtPosition(Node** headRef, int pos, char data) {
    Node* newNode = createNode(data);
    Node* temp = *headRef;
    if (pos == 1) {
        newNode->next = *headRef;
        *headRef = newNode;
        return;
    }
    for (int i = 0; i < pos - 2; i++) {
        if (temp == NULL) {
            printf("Invalid position\n");
            return;
        }
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNodeByValue(Node** headRef, char data) {
    Node* temp = *headRef;
    Node* prev;
    if (temp!= NULL && temp->data == data) {
        *headRef = temp->next;
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

void deleteNodeByPosition(Node** headRef, int pos) {
    Node* temp = *headRef;
    Node* prev;
    if (pos == 1) {
        *headRef = temp->next;
        free(temp);
        return;
    }
    for (int i = 1; i < pos - 1; i++) {
        if (temp == NULL) {
            printf("Invalid position\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
}

void displayList(Node* node) {
    while (node!= NULL) {
        printf("%c ", node->data);
        node = node->next;
    }
}

int main() {
    Node* head = NULL;
    addNodeAtBeginning(&head, 'a');
    addNodeAtEnd(&head, 'b');
    addNodeAtPosition(&head, 2, 'c');
    displayList(head);
    deleteNodeByValue(&head, 'b');
    displayList(head);
    deleteNodeByPosition(&head, 1);
    displayList(head);
    return 0;
}