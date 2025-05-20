//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: rigorous
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
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* addNode(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    Node* temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node* deleteNode(Node* head, int data) {
    Node* temp = head;
    if (temp == NULL) {
        return head;
    }
    if (temp->data == data) {
        Node* newHead = temp->next;
        free(temp);
        return newHead;
    }
    while (temp->next!= NULL) {
        if (temp->next->data == data) {
            Node* prev = temp;
            temp = temp->next;
            prev->next = temp->next;
            free(temp);
            return head;
        }
        temp = temp->next;
    }
    return head;
}

Node* searchNode(Node* head, int data) {
    Node* temp = head;
    while (temp!= NULL) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
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
    head = addNode(head, 1);
    head = addNode(head, 2);
    head = addNode(head, 3);
    head = addNode(head, 4);
    head = addNode(head, 5);
    printList(head);
    head = deleteNode(head, 2);
    printList(head);
    Node* node = searchNode(head, 4);
    if (node!= NULL) {
        printf("Node found\n");
    } else {
        printf("Node not found\n");
    }
    return 0;
}