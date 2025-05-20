//Falcon2-11B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a cluster
typedef struct {
    int id;
    int size;
    int *nodes;
} cluster;

// Function to initialize a cluster with a given ID
cluster *initCluster(int id) {
    cluster *newCluster = malloc(sizeof(cluster));
    newCluster->id = id;
    newCluster->size = 0;
    newCluster->nodes = NULL;
    return newCluster;
}

// Function to add a node to a cluster
void addToCluster(cluster *cluster, int node) {
    if (cluster->size >= 10) {
        printf("Cluster is full. Cannot add more nodes.\n");
        return;
    }
    cluster->nodes[cluster->size] = node;
    cluster->size++;
}

// Function to update the centroid of a cluster
void updateCentroid(cluster *cluster, int node) {
    for (int i = 0; i < cluster->size; i++) {
        cluster->nodes[i] -= node;
    }
    int sum = 0;
    for (int i = 0; i < cluster->size; i++) {
        sum += cluster->nodes[i];
    }
    cluster->nodes[0] = sum / cluster->size;
}

// Function to check if two clusters are the same
int areClustersEqual(cluster *cluster1, cluster *cluster2) {
    if (cluster1->size!= cluster2->size) {
        return 0;
    }
    for (int i = 0; i < cluster1->size; i++) {
        if (cluster1->nodes[i]!= cluster2->nodes[i]) {
            return 0;
        }
    }
    return 1;
}

// Function to print the cluster data
void printClusterData(cluster *cluster) {
    printf("Cluster ID: %d\n", cluster->id);
    printf("Cluster Size: %d\n", cluster->size);
    printf("Nodes in Cluster: ");
    for (int i = 0; i < cluster->size; i++) {
        printf("%d ", cluster->nodes[i]);
    }
    printf("\n");
}

int main() {
    cluster *cluster1 = initCluster(1);
    addToCluster(cluster1, 3);
    addToCluster(cluster1, 5);
    addToCluster(cluster1, 7);
    addToCluster(cluster1, 9);
    addToCluster(cluster1, 11);
    updateCentroid(cluster1, 6);
    printClusterData(cluster1);
    cluster *cluster2 = initCluster(1);
    addToCluster(cluster2, 3);
    addToCluster(cluster2, 5);
    addToCluster(cluster2, 7);
    addToCluster(cluster2, 9);
    addToCluster(cluster2, 11);
    updateCentroid(cluster2, 6);
    printClusterData(cluster2);
    if (areClustersEqual(cluster1, cluster2)) {
        printf("Clusters are the same.\n");
    } else {
        printf("Clusters are not the same.\n");
    }
    return 0;
}