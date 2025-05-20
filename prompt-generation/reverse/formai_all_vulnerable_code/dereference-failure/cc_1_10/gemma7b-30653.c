//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Cluster {
    int center;
    struct Cluster* next;
} Cluster;

void insertNode(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void insertCluster(Cluster** head, int center) {
    Cluster* newCluster = (Cluster*)malloc(sizeof(Cluster));
    newCluster->center = center;
    newCluster->next = NULL;

    if (*head == NULL) {
        *head = newCluster;
    } else {
        (*head)->next = newCluster;
    }
}

void calculateDistance(Node* node, Cluster* cluster) {
    int distance = abs(node->data - cluster->center);
    printf("Distance of node %d from cluster %d is %d\n", node->data, cluster->center, distance);
}

int main() {
    Node* head = NULL;
    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);
    insertNode(&head, 40);

    Cluster* clusterHead = NULL;
    insertCluster(&clusterHead, 25);
    insertCluster(&clusterHead, 35);

    calculateDistance(head, clusterHead);

    return 0;
}