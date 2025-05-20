//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DIM 3

typedef struct Node {
    int x, y, z;
    struct Node* next;
} Node;

typedef struct Cluster {
    Node* head;
    struct Cluster* next;
} Cluster;

void insertNode(Cluster* cluster, int x, int y, int z) {
    Node* newNode = malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->z = z;
    newNode->next = NULL;

    if (cluster->head == NULL) {
        cluster->head = newNode;
    } else {
        cluster->head->next = newNode;
    }
}

void distance(Node* node1, Node* node2) {
    int dx = node1->x - node2->x;
    int dy = node1->y - node2->y;
    int dz = node1->z - node2->z;

    int distance = sqrt(dx * dx + dy * dy + dz * dz);

    printf("Distance between nodes %p and %p is %d.\n", node1, node2, distance);
}

int main() {
    Cluster* cluster = malloc(sizeof(Cluster));
    cluster->head = NULL;
    cluster->next = NULL;

    insertNode(cluster, 1, 2, 3);
    insertNode(cluster, 4, 5, 6);
    insertNode(cluster, 7, 8, 9);
    insertNode(cluster, 10, 11, 12);

    distance(cluster->head, cluster->head->next);

    return 0;
}