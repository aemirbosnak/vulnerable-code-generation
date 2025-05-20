//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* head = NULL;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteNode(int data) {
    Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
    } else if (temp->data == data) {
        head = temp->next;
        free(temp);
    } else {
        while (temp->next!= NULL) {
            if (temp->next->data == data) {
                temp->next = temp->next->next;
                free(temp->next);
            } else {
                temp = temp->next;
            }
        }
    }
}

void displayList() {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insertNode(1);
    insertNode(2);
    insertNode(3);
    insertNode(4);
    insertNode(5);
    displayList();
    deleteNode(3);
    displayList();
    deleteNode(2);
    displayList();
    return 0;
}