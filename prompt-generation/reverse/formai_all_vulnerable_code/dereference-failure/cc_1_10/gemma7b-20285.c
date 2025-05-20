//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void cluster(Node* head) {
    int i, j, k, clusterSize = 0, totalDistance = 0;
    Node* current = head;
    Node* center = NULL;

    // Calculate the total number of nodes in the list
    for (i = 0; current; i++) {
        clusterSize++;
        current = current->next;
    }

    // Calculate the center of the cluster
    for (i = 0; i < clusterSize; i++) {
        totalDistance = 0;
        for (j = 0; j < clusterSize; j++) {
            if (i != j) {
                k = abs(current->data - center->data);
                totalDistance += k;
            }
        }
        center = (totalDistance) / clusterSize;
    }

    // Print the center of the cluster
    printf("The center of the cluster is: %d\n", center->data);
}

int main() {
    Node* head = NULL;
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);
    insert(head, 50);

    printList(head);
    cluster(head);

    return 0;
}