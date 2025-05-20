//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

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

void cluster(Node** head) {
    int i, j, k, count = 0, clusterSize = 0, minDistance = MAX, currentDistance = MAX;

    for (i = 0; i < MAX; i++) {
        insertAtTail(head, i);
    }

    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            currentDistance = abs(i - j);
            if (currentDistance < minDistance) {
                minDistance = currentDistance;
                clusterSize = 1;
            } else if (currentDistance == minDistance) {
                clusterSize++;
            }
        }
        printf("Cluster size: %d, Min distance: %d\n", clusterSize, minDistance);
        clusterSize = 0;
        minDistance = MAX;
    }
}

int main() {
    Node* head = NULL;
    cluster(&head);
    return 0;
}