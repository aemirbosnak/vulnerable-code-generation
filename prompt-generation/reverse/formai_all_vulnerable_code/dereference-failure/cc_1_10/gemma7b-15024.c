//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_CLUSTER_SIZE 10

typedef struct Cluster {
  int id;
  double centroid[2];
  struct Cluster* next;
} Cluster;

Cluster* createCluster(int id) {
  Cluster* cluster = (Cluster*)malloc(sizeof(Cluster));
  cluster->id = id;
  cluster->centroid[0] = 0.0;
  cluster->centroid[1] = 0.0;
  cluster->next = NULL;
  return cluster;
}

void addPointToCluster(Cluster* cluster, double x, double y) {
  cluster->centroid[0] += x;
  cluster->centroid[1] += y;
  cluster->next = createCluster(cluster->id + 1);
  cluster = cluster->next;
}

void calculateCentroid(Cluster* cluster) {
  int points = 0;
  double total_x = 0.0;
  double total_y = 0.0;
  for (Cluster* current = cluster; current; current = current->next) {
    points++;
    total_x += current->centroid[0];
    total_y += current->centroid[1];
  }
  cluster->centroid[0] = total_x / points;
  cluster->centroid[1] = total_y / points;
}

int main() {
  Cluster* head = createCluster(0);
  addPointToCluster(head, 1.0, 2.0);
  addPointToCluster(head, 3.0, 4.0);
  addPointToCluster(head, 5.0, 6.0);
  addPointToCluster(head, 7.0, 8.0);

  calculateCentroid(head);

  for (Cluster* current = head; current; current = current->next) {
    printf("Cluster ID: %d, Centroid: (%f, %f)\n", current->id, current->centroid[0], current->centroid[1]);
  }

  return 0;
}