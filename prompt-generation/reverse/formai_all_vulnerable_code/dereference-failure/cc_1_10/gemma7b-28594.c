//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int search(struct Node* head, int data) {
    while (head) {
        if (head->data == data) {
            return 1;
        } else {
            head = head->next;
        }
    }

    return 0;
}

int main() {
    struct Node* head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 50);

    if (search(head, 30) == 1) {
        printf("Data found.\n");
    } else {
        printf("Data not found.\n");
    }

    return 0;
}