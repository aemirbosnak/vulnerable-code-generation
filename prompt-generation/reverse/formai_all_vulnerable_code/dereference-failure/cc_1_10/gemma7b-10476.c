//Gemma-7B DATASET v1.0 Category: Database querying ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void query(Node* head, int target) {
    while (head) {
        if (head->data == target) {
            printf("Data found: %d\n", head->data);
            return;
        } else if (head->data < target) {
            head = head->next;
        } else {
            return;
        }
    }

    printf("Data not found\n");
}

int main() {
    Node* head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 50);

    query(head, 30);
    query(head, 60);

    return 0;
}