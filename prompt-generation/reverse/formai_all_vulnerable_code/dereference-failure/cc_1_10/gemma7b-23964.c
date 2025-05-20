//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAtTail(Node** head, int data) {
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

int distance(Node* a, Node* b) {
    return abs(a->data - b->data);
}

void cluster(Node** head, int k) {
    int i, j, d, minDistance = MAX, clusterSize = 0;
    Node* current = *head;
    Node* centroid = NULL;

    for (i = 0; i < k; i++) {
        centroid = NULL;
        clusterSize = 0;

        for (j = 0; j < MAX; j++) {
            d = distance(current, centroid);

            if (d < minDistance) {
                minDistance = d;
                centroid = current;
                clusterSize++;
            }
        }

        printf("Centroid: %d, Size: %d\n", centroid->data, clusterSize);

        current = current->next;
    }
}

int main() {
    Node* head = NULL;
    insertAtTail(&head, 10);
    insertAtTail(&head, 20);
    insertAtTail(&head, 30);
    insertAtTail(&head, 40);
    insertAtTail(&head, 50);

    cluster(&head, 3);

    return 0;
}