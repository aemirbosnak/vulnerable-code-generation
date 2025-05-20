//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Linked list
struct Node* head = NULL;

void insert(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void delete(int data) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp!= NULL) {
        if (temp->data == data) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
}

int search(int data) {
    struct Node* temp = head;

    while (temp!= NULL) {
        if (temp->data == data) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    insert(10);
    insert(20);
    insert(30);

    printf("Linked list: ");
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    delete(10);

    printf("Linked list after deletion: ");
    temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    int searchData = 20;
    if (search(searchData)) {
        printf("Element %d found in the linked list\n", searchData);
    } else {
        printf("Element %d not found in the linked list\n", searchData);
    }

    return 0;
}