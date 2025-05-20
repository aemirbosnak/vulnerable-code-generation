//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertNodeAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertNodeAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteNode(Node** head, int data) {
    Node* temp = *head;
    if (temp == NULL) {
        return;
    }
    if (temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp->next!= NULL) {
        if (temp->next->data == data) {
            Node* temp2 = temp->next;
            temp->next = temp2->next;
            free(temp2);
            return;
        }
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;
    insertNodeAtBeginning(&head, 1);
    insertNodeAtBeginning(&head, 2);
    insertNodeAtBeginning(&head, 3);
    insertNodeAtEnd(&head, 4);
    insertNodeAtEnd(&head, 5);
    printf("Graph Representation:\n");
    printList(head);
    printf("\n");
    deleteNode(&head, 2);
    printf("After Deleting Node with data 2:\n");
    printList(head);
    printf("\n");
    return 0;
}