//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    int data;
    char name[50];
    struct Node* next;
} Node;

Node* createNode(int data, char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* createList() {
    Node* head = NULL;
    Node* newNode1 = createNode(1, "Apple");
    Node* newNode2 = createNode(2, "Banana");
    Node* newNode3 = createNode(3, "Cherry");

    head = newNode1;
    newNode1->next = newNode2;
    newNode2->next = newNode3;

    return head;
}

void displayList(Node* head) {
    Node* temp = head;
    printf("\nLinked List:\n");
    while (temp != NULL) {
        printf("Data: %d, Name: %s -> ", temp->data, temp->name);
        temp = temp->next;
    }
    printf("NULL\n");
}

Node* reverseList(Node* head) {
    Node* current = head;
    Node* next = NULL;
    Node* prev = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

void freeList(Node* head) {
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    Node* head = createList();
    displayList(head);

    printf("\nReversed Linked List:\n");
    head = reverseList(head);
    displayList(head);

    freeList(head);
    return 0;
}