//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct Cluster {
  int center;
  Node* head;
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

void createCluster(Cluster** clusterHead, int center) {
  Cluster* newCluster = (Cluster*)malloc(sizeof(Cluster));
  newCluster->center = center;
  newCluster->head = NULL;
  newCluster->next = NULL;

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

    printf("\n");
    currentCluster = currentCluster->next;
  }
}

int main() {
  int data[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49, 51, 53, 55, 57, 59, 61, 63, 65, 67, 69, 71, 73, 75, 77, 79, 81, 83, 85, 87, 89, 91, 93, 95, 97, 99, 101};

  Cluster* clusterHead = NULL;

  for (int i = 0; i < MAX_SIZE; i++) {
    insertNode(&clusterHead, data[i]);
  }

  createCluster(&clusterHead, 50);
  addNodeToCluster(clusterHead->next, 20);
  addNodeToCluster(clusterHead->next, 60);
  addNodeToCluster(clusterHead->next->next, 30);

  printClusters(clusterHead);

  return 0;
}