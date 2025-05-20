//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAtTail(Node** head, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        ((*head)->next = newNode);
        *head = newNode;
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

    insertAtTail(&head, 10);
    insertAtTail(&head, 20);
    insertAtTail(&head, 30);
    insertAtTail(&head, 40);
    insertAtTail(&head, 50);

    printList(head);

    // Cluster the nodes based on their data values
    int clusters[5] = {
        0,
        2,
        2,
        2,
        1
    };

    for (int i = 0; i < MAX_SIZE; i++) {
        if (clusters[i] != 0) {
            printf("Node with data %d belongs to cluster %d\n", i, clusters[i]);
        }
    }

    return 0;
}