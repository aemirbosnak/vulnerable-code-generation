//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

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

void printList(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 50);

    printList(head);

    // Clustering Algorithm

    // 1. Calculate the centroid of the cluster.
    int centroid = (head->data + head->next->data + head->next->next->data) / 3;

    // 2. Move each data point to the nearest centroid.
    Node* current = head;
    while (current) {
        int distance = abs(current->data - centroid);
        if (distance > 10) {
            insert(&head, current->data - 10);
            free(current);
            current = NULL;
        } else {
            current = current->next;
        }
    }

    printList(head);

    return 0;
}