//FormAI DATASET v1.0 Category: Linked list operations ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head;

void insert(int x);
void delete(int x);
void print();

int main() {
    head = NULL;

    insert(5);
    insert(10);
    insert(15);
    insert(20);
    print();

    delete(10);
    print();

    delete(5);
    print();

    return 0;
}

void insert(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;

    if(head == NULL) {
        head = newNode;
        newNode->next = NULL;
    }
    else {
        struct Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
    }
}

void delete(int x) {
    if(head == NULL) {
        printf("Linked list is empty!\n");
        return;
    }

    if(head->data == x) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }

    struct Node* temp = head;
    while(temp->next != NULL && temp->next->data != x) {
        temp = temp->next;
    }

    if(temp->next == NULL) {
        printf("Element not found in linked list!\n");
        return;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
}

void print() {
    struct Node* temp = head;
    printf("Linked List Elements: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}