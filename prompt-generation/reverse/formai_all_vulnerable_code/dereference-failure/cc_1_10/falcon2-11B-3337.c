//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void display() {
    struct Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void delete(int data) {
    struct Node* current = head;
    struct Node* previous = NULL;

    while (current!= NULL && current->data!= data) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Data not found in the list.\n");
    } else if (current->next == NULL) {
        free(current);
        head = NULL;
    } else {
        previous->next = current->next;
        free(current);
    }
}

void main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    display();
    delete(20);
    display();
}