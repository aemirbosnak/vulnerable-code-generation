//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createLinkedList(int size) {
    Node* head = NULL;
    Node* tail = NULL;
    for (int i = 0; i < size; i++) {
        Node* node = (Node*)malloc(sizeof(Node));
        node->data = i;
        node->next = NULL;
        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

void printLinkedList(Node* head) {
    while (head!= NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void addNode(Node** headRef, int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if (*headRef == NULL) {
        node->next = NULL;
        *headRef = node;
    } else {
        Node* temp = *headRef;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = node;
        node->next = NULL;
    }
}

void deleteNode(Node** headRef, int key) {
    Node* temp = *headRef;
    Node* prev = NULL;
    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Key not found in the list\n");
        return;
    }
    if (prev == NULL) {
        *headRef = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

int searchNode(Node* head, int key) {
    Node* temp = head;
    while (temp!= NULL) {
        if (temp->data == key) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    Node* head = createLinkedList(5);
    printLinkedList(head);

    addNode(&head, 6);
    printLinkedList(head);

    deleteNode(&head, 3);
    printLinkedList(head);

    int key = 6;
    if (searchNode(head, key)) {
        printf("%d found in the list\n", key);
    } else {
        printf("%d not found in the list\n", key);
    }

    return 0;
}