//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DIM 2

typedef struct Cluster {
  int idx;
  double distance;
  struct Cluster* next;
} Cluster;

Cluster* createCluster(int idx, double distance) {
  Cluster* cluster = (Cluster*)malloc(sizeof(Cluster));
  cluster->idx = idx;
  cluster->distance = distance;
  cluster->next = NULL;
  return cluster;
}

void addCluster(Cluster* cluster, int idx, double distance) {
  Cluster* newCluster = createCluster(idx, distance);
  if (cluster == NULL) {
    cluster = newCluster;
  } else {
    cluster->next = newCluster;
    cluster = newCluster;
  }
}

double calculateDistance(double x1, double y1, double x2, double y2) {
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void cluster(Cluster* cluster) {
  int i = 0;
  for (Cluster* current = cluster; current; current = current->next) {
    printf("Cluster member: %d, Distance: %.2lf\n", current->idx, current->distance);
  }
}

int main() {
  double data[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
  int numData = 10;

  Cluster* root = NULL;
  for (int i = 0; i < numData; i++) {
    addCluster(root, data[i], calculateDistance(data[i], data[i], data[i], data[i]));
  }

  cluster(root);

  return 0;
}