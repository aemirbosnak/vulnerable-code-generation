//FormAI DATASET v1.0 Category: Linked list operations ; Style: funny
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head;

void insertAtBeginning(int x) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = head;
    head = temp;
    printf("Data inserted at the beginning, I'm beginning to feel like a linked list rapper!\n");
}

void insertAtEnd(int x) {
    Node* temp = (Node*)malloc(sizeof(Node));
    Node* trav = head;
    temp->data = x;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
    }
    else {
        while (trav->next != NULL) {
            trav = trav->next;
        }
        trav->next = temp;
    }
    printf("Data inserted at the end, let's link it up!\n");
}

void insertAtPosition(int x, int n) {
    Node* temp = (Node*)malloc(sizeof(Node));
    Node* trav = head;
    temp->data = x;
    if (n == 1) {
        temp->next = head;
        head = temp;
    }
    else {
        for (int i = 1; i < n-1; i++) {
            trav = trav->next;
        }
        temp->next = trav->next;
        trav->next = temp;
    }
    printf("Data inserted at position %d, I'm feeling pretty positioned myself!\n", n);
}

void deleteAtPosition(int n) {
    Node* temp = head;
    if (n == 1) {
        head = temp->next;
        free(temp);
    }
    else {
        for (int i = 1; i < n-1; i++) {
            temp = temp->next;
        }
        Node* temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
    }
    printf("Data deleted from position %d, let's not link with that data anymore!\n", n);
}

void display() {
    printf("Current linked list: ");
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    head = NULL;
    insertAtBeginning(5);
    insertAtEnd(10);
    insertAtPosition(7, 2);
    insertAtPosition(15, 4);
    display();
    deleteAtPosition(3);
    display();
    return 0;
}