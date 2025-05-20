//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: systematic
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void insertAtHead(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;
    head = temp;
}

void display() {
    struct node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void deleteAtHead() {
    struct node* temp = head;
    head = head->next;
    free(temp);
}

void insertAtTail(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    struct node* temp = head;

    if (head == NULL) {
        head = newNode;
        return;
    }

    while (temp->next!= NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void deleteAtTail() {
    struct node* temp = head;

    if (temp->next == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp->next->next!= NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

void reverse() {
    struct node* prev = NULL;
    struct node* current = head;
    struct node* next = NULL;

    while (current!= NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main() {
    insertAtHead(10);
    insertAtHead(20);
    insertAtHead(30);
    insertAtHead(40);

    display();

    insertAtTail(50);

    display();

    deleteAtHead();

    display();

    deleteAtTail();

    display();

    reverse();

    display();

    return 0;
}