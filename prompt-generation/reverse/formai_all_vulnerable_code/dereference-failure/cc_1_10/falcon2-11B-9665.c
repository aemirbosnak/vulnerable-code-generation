//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertNodeAtBeg(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertNodeAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while(temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteNode(int data) {
    if(head == NULL) {
        printf("List is empty");
        return;
    }

    if(head->data == data) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }

    struct Node* temp = head;
    while(temp->next!= NULL && temp->next->data!= data) {
        temp = temp->next;
    }

    if(temp->next == NULL) {
        printf("Element not found in the list");
        return;
    }

    struct Node* next = temp->next->next;
    temp->next = next;
    free(temp->next);
}

void displayList() {
    if(head == NULL) {
        printf("List is empty");
        return;
    }

    struct Node* temp = head;
    while(temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insertNodeAtBeg(10);
    insertNodeAtBeg(20);
    insertNodeAtBeg(30);
    insertNodeAtBeg(40);

    displayList();

    deleteNode(20);

    displayList();

    return 0;
}