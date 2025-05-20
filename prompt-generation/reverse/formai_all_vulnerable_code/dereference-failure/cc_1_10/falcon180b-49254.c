//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: retro
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

Node* addNode(Node* head, int data) {
    Node* newNode = createNode(data);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

Node* deleteNode(Node* head, int data) {
    Node* temp = head;
    if (temp && temp->data == data) {
        head = temp->next;
        free(temp);
        return head;
    }
    while (temp && temp->data!= data) {
        temp = temp->next;
    }
    if (!temp) {
        return head;
    }
    Node* next = temp->next;
    free(temp);
    temp = next;
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    head = addNode(head, 1);
    head = addNode(head, 2);
    head = addNode(head, 3);
    head = addNode(head, 4);
    head = addNode(head, 5);
    printList(head);
    head = deleteNode(head, 3);
    printList(head);
    head = deleteNode(head, 1);
    printList(head);
    head = deleteNode(head, 5);
    printList(head);
    return 0;
}