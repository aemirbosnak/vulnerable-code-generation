//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
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

Node* insertNode(Node* head, int data) {
    Node* newNode = createNode(data);
    Node* temp = head;
    if (head == NULL) {
        newNode->next = NULL;
        head = newNode;
    }
    else {
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
    }
    return head;
}

Node* deleteNode(Node* head, int key) {
    Node* temp = head;
    Node* prev = NULL;
    if (temp!= NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }
    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element not found\n");
        return head;
    }
    prev->next = temp->next;
    free(temp);
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    head = insertNode(head, 5);
    head = insertNode(head, 10);
    head = insertNode(head, 15);
    head = insertNode(head, 20);
    head = insertNode(head, 25);
    printList(head);
    head = deleteNode(head, 15);
    printList(head);
    head = deleteNode(head, 10);
    printList(head);
    head = deleteNode(head, 5);
    printList(head);
    head = deleteNode(head, 20);
    printList(head);
    head = deleteNode(head, 25);
    printList(head);
    return 0;
}