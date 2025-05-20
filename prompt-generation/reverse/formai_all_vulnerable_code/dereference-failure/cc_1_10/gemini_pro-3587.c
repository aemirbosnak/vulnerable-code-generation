//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: happy
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *head = NULL;

void insertFirst(int data) {
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertLast(int data) {
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAfter(int data, int after) {
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    node *temp = head;
    while (temp->data != after) {
        temp = temp->next;
        if (temp == NULL) {
            printf("Element not found.\n");
            return;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFirst() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    node *temp = head;
    head = head->next;
    free(temp);
}

void deleteLast() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == NULL) {
        head = NULL;
        return;
    }
    node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteElement(int data) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->data == data) {
        deleteFirst();
        return;
    }
    node *temp = head;
    while (temp->next->data != data) {
        temp = temp->next;
        if (temp->next == NULL) {
            printf("Element not found.\n");
            return;
        }
    }
    node *toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

void printList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    printf("Welcome to the happy linked list program!\n");
    printf("Let's start by creating a list.\n");
    insertFirst(10);
    insertFirst(20);
    insertFirst(30);
    printf("We have a list now: ");
    printList();
    printf("Let's insert 40 after 20.\n");
    insertAfter(40, 20);
    printf("The updated list is: ");
    printList();
    printf("Let's delete the first element.\n");
    deleteFirst();
    printf("The updated list is: ");
    printList();
    printf("Let's delete the last element.\n");
    deleteLast();
    printf("The updated list is: ");
    printList();
    printf("Let's delete the element 40.\n");
    deleteElement(40);
    printf("The updated list is: ");
    printList();
    printf("Thank you for using the happy linked list program!\n");
    return 0;
}