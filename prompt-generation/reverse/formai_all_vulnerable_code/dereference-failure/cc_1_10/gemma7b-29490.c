//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the number of clusters
int numClusters = 3;

// Define the distance metric
double distance(int, int);

// Create a cluster structure
typedef struct Cluster {
    int members[100];
    double center[2];
} Cluster;

// Function to initialize a cluster
void initializeCluster(Cluster *c) {
    c->members[0] = -1;
    c->center[0] = 0.0;
    c->center[1] = 0.0;
}

// Function to assign a member to a cluster
void assignMember(Cluster *c, int m) {
    c->members[++c->members[0]] = m;
}

// Function to calculate the center of a cluster
void calculateCenter(Cluster *c) {
    double sumX = 0.0, sumY = 0.0, numMembers = 0.0;
    for (int i = 0; i < c->members[0]; i++) {
        sumX += c->members[i] * c->center[0];
        sumY += c->members[i] * c->center[1];
        numMembers += c->members[i];
    }
    c->center[0] = sumX / numMembers;
    c->center[1] = sumY / numMembers;
}

int main() {
    // Create an array of cluster structures
    Cluster *clusters = malloc(numClusters * sizeof(Cluster));
    for (int i = 0; i < numClusters; i++) {
        initializeCluster(&clusters[i]);
    }

    // Assign members to clusters
    assignMember(&clusters[0], 1);
    assignMember(&clusters[0], 3);
    assignMember(&clusters[1], 2);
    assignMember(&clusters[1], 4);
    assignMember(&clusters[2], 5);

    // Calculate the center of each cluster
    for (int i = 0; i < numClusters; i++) {
        calculateCenter(&clusters[i]);
    }

    // Print the center of each cluster
    for (int i = 0; i < numClusters; i++) {
        printf("Cluster %d: Center = (%f, %f)\n", i + 1, clusters[i].center[0], clusters[i].center[1]);
    }

    return 0;
}