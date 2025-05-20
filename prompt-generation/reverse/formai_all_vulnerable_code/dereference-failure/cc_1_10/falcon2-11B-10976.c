//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: curious
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtHead(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = head;
    head = temp;
}

void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    struct Node* temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void display() {
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void deleteAtPosition(int pos) {
    if (head == NULL) {
        printf("List is empty!");
        return;
    }
    if (pos == 0) {
        head = head->next;
        free(head);
        return;
    }
    struct Node* temp = head;
    int i = 0;
    while (temp!= NULL && i!= pos - 1) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("Invalid position!");
        return;
    }
    temp->next = temp->next->next;
    free(temp);
}

int main() {
    insertAtHead(10);
    insertAtEnd(20);
    insertAtHead(30);
    insertAtEnd(40);
    display();
    deleteAtPosition(1);
    display();
    return 0;
}