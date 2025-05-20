//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// A struct to represent a data point
typedef struct point {
    float x, y, z;
} Point;

// Function to calculate Euclidean distance between two data points
float euclideanDistance(Point p1, Point p2) {
    float dist = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));
    return dist;
}

// Function to initialize k cluster centers randomly
Point* initCenters(Point* data, int numPoints, int k) {
    Point* centers = (Point*)malloc(sizeof(Point) * k);
    for (int i = 0; i < k; i++) {
        int randIndex = rand() % numPoints;
        centers[i] = data[randIndex];
    }
    return centers;
}

// Function to assign each point to a cluster based on the distance between the point and the cluster centers
int* assignClusters(Point* data, int numPoints, Point* centers, int k) {
    int* assignments = (int*)malloc(sizeof(int) * numPoints);
    for (int i = 0; i < numPoints; i++) {
        float minDist = INFINITY;
        int assignedCluster = 0;
        for (int j = 0; j < k; j++) {
            float dist = euclideanDistance(data[i], centers[j]);
            if (dist < minDist) {
                minDist = dist;
                assignedCluster = j;
            }
        }
        assignments[i] = assignedCluster;
    }
    return assignments;
}

// Function to update the cluster centers based on the points in the cluster
Point* updateCenters(Point* data, int numPoints, int* assignments, int k) {
    Point* newCenters = (Point*)malloc(sizeof(Point) * k);
    int* clusterSizes = (int*)calloc(k, sizeof(int));
    for (int i = 0; i < numPoints; i++) {
        int currCluster = assignments[i];
        newCenters[currCluster].x += data[i].x;
        newCenters[currCluster].y += data[i].y;
        newCenters[currCluster].z += data[i].z;
        clusterSizes[currCluster]++;
    }
    for (int i = 0; i < k; i++) {
        newCenters[i].x /= clusterSizes[i];
        newCenters[i].y /= clusterSizes[i];
        newCenters[i].z /= clusterSizes[i];
    }
    free(clusterSizes);
    return newCenters;
}

// Function to check if two sets of cluster centers are the same
int centersEqual(Point* oldCenters, Point* newCenters, int k) {
    for (int i = 0; i < k; i++) {
        if (oldCenters[i].x != newCenters[i].x || oldCenters[i].y != newCenters[i].y || oldCenters[i].z != newCenters[i].z) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int numPoints = 1000;
    Point* data = (Point*)malloc(sizeof(Point) * numPoints);
    for (int i = 0; i < numPoints; i++) {
        data[i].x = (float)rand() / RAND_MAX * 10;
        data[i].y = (float)rand() / RAND_MAX * 10;
        data[i].z = (float)rand() / RAND_MAX * 10;
    }

    int k = 3; // number of clusters
    Point* centers = initCenters(data, numPoints, k);

    int maxIter = 100; // maximum number of iterations
    int currIter = 0;
    while (currIter < maxIter) {
        int* assignments = assignClusters(data, numPoints, centers, k);
        Point* newCenters = updateCenters(data, numPoints, assignments, k);
        if (centersEqual(centers, newCenters, k)) {
            break;
        }
        free(centers);
        free(assignments);
        centers = newCenters;
        currIter++;
    }

    for (int i = 0; i < k; i++) {
        printf("Cluster %d center: (%.2f, %.2f, %.2f)\n", i+1, centers[i].x, centers[i].y, centers[i].z);
    }

    free(data);
    free(centers);

    return 0;
}