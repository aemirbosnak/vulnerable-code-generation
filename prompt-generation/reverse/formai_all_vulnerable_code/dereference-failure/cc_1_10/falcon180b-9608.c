//Falcon-180B DATASET v1.0 Category: Memory management ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure definition
struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
int size = 0;

void addNode(int data) {
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        struct node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    size++;
}

void deleteNode(int data) {
    struct node *temp = head;
    struct node *prev = NULL;
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }
    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    size--;
}

void printList() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    addNode(1);
    addNode(2);
    addNode(3);
    printList();

    deleteNode(2);
    printList();

    deleteNode(1);
    printList();

    deleteNode(3);
    printList();

    return 0;
}