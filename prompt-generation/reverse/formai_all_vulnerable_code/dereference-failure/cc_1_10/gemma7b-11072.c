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
  Node* head;
  struct Cluster* next;
} Cluster;

void insertNode(Node** head, int data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

void insertCluster(Cluster** head, int center) {
  Cluster* newCluster = malloc(sizeof(Cluster));
  newCluster->center = center;
  newCluster->head = NULL;
  newCluster->next = NULL;

  if (*head == NULL) {
    *head = newCluster;
  } else {
    (*head)->next = newCluster;
  }
}

int main() {
  // Create a list of nodes
  Node* head = NULL;
  insertNode(&head, 10);
  insertNode(&head, 20);
  insertNode(&head, 30);
  insertNode(&head, 40);
  insertNode(&head, 50);

  // Create a list of clusters
  Cluster* clusterHead = NULL;
  insertCluster(&clusterHead, 25);
  insertCluster(&clusterHead, 45);

  // Cluster the nodes
  for (Node* node = head; node; node) {
    int distance = abs(node->data - clusterHead->center);
    Cluster* closestCluster = clusterHead;
    for (Cluster* cluster = clusterHead->next; cluster; cluster) {
      if (distance < abs(node->data - cluster->center)) {
        closestCluster = cluster;
      }
    }
    insertNode(closestCluster->head, node);
  }

  // Print the clusters
  for (Cluster* cluster = clusterHead; cluster; cluster) {
    printf("Center: %d\n", cluster->center);
    for (Node* node = cluster->head; node; node) {
      printf("Node: %d\n", node->data);
    }
  }

  return 0;
}