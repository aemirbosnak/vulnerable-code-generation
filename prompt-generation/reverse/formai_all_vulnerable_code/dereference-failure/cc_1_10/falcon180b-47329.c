//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    char data[MAX_SIZE];
    struct node* next;
} Node;

Node* createNode(char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

void addNode(Node** head, char* data) {
    Node* newNode = createNode(data);
    Node* temp = *head;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteNode(Node** head, char* data) {
    Node* temp = *head;
    Node* prev = NULL;
    if (temp!= NULL && strcmp(temp->data, data) == 0) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && strcmp(temp->data, data)!= 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void reverseList(Node** head) {
    Node* prev = NULL;
    Node* current = *head;
    while (current!= NULL) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int main() {
    Node* head = NULL;
    addNode(&head, "apple");
    addNode(&head, "banana");
    addNode(&head, "cherry");
    printList(head);
    deleteNode(&head, "banana");
    printList(head);
    reverseList(&head);
    printList(head);
    return 0;
}