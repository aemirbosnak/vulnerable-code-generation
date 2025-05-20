//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;
int size = 0;

void InsertAtBeginning(int newData) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
    size++;
}

void InsertAtEnd(int newData) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    Node* temp = head;
    newNode->data = newData;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        tail = newNode;
    }
    size++;
}

void DeleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
    size--;
}

void DeleteAtEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        tail = NULL;
    } else {
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        tail = temp;
    }
    size--;
}

void Display() {
    Node* temp = head;
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("List elements are: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    InsertAtBeginning(5);
    InsertAtBeginning(3);
    InsertAtEnd(7);
    InsertAtEnd(11);

    Display();

    DeleteAtBeginning();
    DeleteAtEnd();

    Display();

    return 0;
}