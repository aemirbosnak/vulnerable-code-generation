//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: synchronous
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

int main() {
    insert(5);
    insert(3);
    insert(7);
    display();

    insert(2);
    insert(4);
    display();

    insert(6);
    insert(1);
    display();

    return 0;
}