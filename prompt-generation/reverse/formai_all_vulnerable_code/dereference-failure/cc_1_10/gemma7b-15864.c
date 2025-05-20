//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Cluster {
    int members[MAX_SIZE];
    struct Cluster* next;
} Cluster;

Cluster* createCluster(int numMembers) {
    Cluster* cluster = (Cluster*)malloc(sizeof(Cluster));
    cluster->members[0] = numMembers;
    cluster->next = NULL;
    return cluster;
}

void addToCluster(Cluster* cluster, int member) {
    for (int i = 0; i < cluster->members[0]; i++) {
        if (cluster->members[i] == member) {
            return;
        }
    }
    cluster->members[cluster->members[0]] = member;
    cluster->members[0]++;
}

void printCluster(Cluster* cluster) {
    printf("Members of Cluster:");
    for (int i = 0; i < cluster->members[0]; i++) {
        printf(" %d ", cluster->members[i]);
    }
    printf("\n");
}

int main() {
    Cluster* cluster = createCluster(3);
    addToCluster(cluster, 1);
    addToCluster(cluster, 2);
    addToCluster(cluster, 3);

    printCluster(cluster);

    addToCluster(cluster, 4);
    addToCluster(cluster, 5);

    printCluster(cluster);

    return 0;
}