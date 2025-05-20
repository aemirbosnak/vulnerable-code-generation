//Falcon-180B DATASET v1.0 Category: Memory management ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *head = NULL;

void addNode(int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error: could not allocate memory for new node.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Node added successfully.\n");
}

void deleteNode(int data) {
    Node *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (temp->data == data) {
        head = temp->next;
        free(temp);
        printf("Node deleted successfully.\n");
        return;
    }
    while (temp->next!= NULL && temp->next->data!= data) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Node not found.\n");
        return;
    }
    Node *nextNode = temp->next->next;
    free(temp->next);
    temp->next = nextNode;
    printf("Node deleted successfully.\n");
}

void displayList() {
    Node *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    addNode(1);
    addNode(2);
    addNode(3);
    displayList();
    deleteNode(2);
    displayList();
    deleteNode(1);
    displayList();
    deleteNode(3);
    displayList();
    return 0;
}