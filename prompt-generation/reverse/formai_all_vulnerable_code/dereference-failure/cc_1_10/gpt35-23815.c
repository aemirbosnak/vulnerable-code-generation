//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

typedef struct ClusterNode ClusterNode;
struct ClusterNode {
    Point centroid;
    int size;
    ClusterNode *left;
    ClusterNode *right;
};

ClusterNode *createCluster(Point p) {
    ClusterNode *node = malloc(sizeof(ClusterNode));
    node->centroid = p;
    node->size = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

ClusterNode *mergeClusters(ClusterNode *a, ClusterNode *b) {
    ClusterNode *node = malloc(sizeof(ClusterNode));
    node->centroid.x = (a->centroid.x * a->size + b->centroid.x * b->size)
                        / (a->size + b->size);
    node->centroid.y = (a->centroid.y * a->size + b->centroid.y * b->size)
                        / (a->size + b->size);
    node->size = a->size + b->size;
    node->left = a;
    node->right = b;
    return node;
}

ClusterNode *findClosestCluster(ClusterNode **clusters, int numClusters) {
    double minDist = INFINITY;
    ClusterNode *closest = NULL;
    for (int i = 0; i < numClusters; i++) {
        for (int j = i+1; j < numClusters; j++) {
            double dist = distance(clusters[i]->centroid, clusters[j]->centroid);
            if (dist < minDist) {
                minDist = dist;
                closest = mergeClusters(clusters[i], clusters[j]);
            }
        }
    }
    return closest;
}

void printCluster(ClusterNode *cluster) {
    printf("(");
    if (cluster->left) {
        printCluster(cluster->left);
    } else {
        printf("(%lf, %lf)", cluster->centroid.x, cluster->centroid.y);
    }
    printf(", ");
    if (cluster->right) {
        printCluster(cluster->right);
    } else {
        printf("(%lf, %lf)", cluster->centroid.x, cluster->centroid.y);
    }
    printf(")");
}

int main() {
    Point points[] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};
    int numPoints = sizeof(points) / sizeof(Point);
    ClusterNode *clusters[numPoints];
    for (int i = 0; i < numPoints; i++) {
        clusters[i] = createCluster(points[i]);
    }
    int numClusters = numPoints;
    while (numClusters > 1) {
        ClusterNode *closest = findClosestCluster(clusters, numClusters);
        for (int i = 0; i < numClusters; i++) {
            if (clusters[i] == closest->left || clusters[i] == closest->right) {
                clusters[i] = closest;
                break;
            }
        }
        numClusters--;
    }
    printCluster(clusters[0]);
    return 0;
}