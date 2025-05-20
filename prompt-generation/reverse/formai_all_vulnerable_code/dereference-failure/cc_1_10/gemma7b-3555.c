//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

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
        (*head)->next = newNode;
    }
}

int distance(Node* node1, Node* node2) {
    return abs(node1->data - node2->data);
}

void cluster(Node** head, int k) {
    int i, j, minDistance, clusterSize;
    Node* currentNode, *centroidNode;

    // Calculate the centroid of each cluster
    for (i = 0; i < k; i++) {
        centroidNode = NULL;
        clusterSize = 0;
        for (j = 0; j < MAX; j++) {
            currentNode = *head;
            while (currentNode) {
                if (distance(currentNode, centroidNode) > minDistance) {
                    insertAtTail(&centroidNode, currentNode->data);
                    clusterSize++;
                }
                currentNode = currentNode->next;
            }
        }

        // Print the centroid of each cluster
        printf("Centroid of Cluster %d: ", i + 1);
        for (j = 0; j < clusterSize; j++) {
            printf("%d ", centroidNode->data);
        }
        printf("\n");
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