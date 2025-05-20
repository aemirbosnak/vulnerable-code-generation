//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Cluster {
    int center;
    struct Cluster* next;
    Node* head;
} Cluster;

void insertNode(Node** head, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
        *head = newNode;
    }
}

void createCluster(Cluster** clusterHead, int center) {
    Cluster* newCluster = malloc(sizeof(Cluster));
    newCluster->center = center;
    newCluster->next = NULL;
    newCluster->head = NULL;

    *clusterHead = newCluster;
}

void addNodeToCluster(Cluster* cluster, int data) {
    insertNode(&cluster->head, data);
}

void printClusters(Cluster* clusterHead) {
    Cluster* currentCluster = clusterHead;

    while (currentCluster) {
        printf("Center: %d\n", currentCluster->center);
        Node* currentNode = currentCluster->head;

        while (currentNode) {
            printf("Node: %d\n", currentNode->data);
            currentNode = currentNode->next;
        }

        currentCluster = currentCluster->next;
    }
}

int main() {
    Cluster* clusterHead = NULL;

    createCluster(&clusterHead, 10);
    addNodeToCluster(clusterHead, 5);
    addNodeToCluster(clusterHead, 15);
    addNodeToCluster(clusterHead, 20);

    createCluster(&clusterHead, 25);
    addNodeToCluster(clusterHead, 22);
    addNodeToCluster(clusterHead, 30);

    printClusters(clusterHead);

    return 0;
}