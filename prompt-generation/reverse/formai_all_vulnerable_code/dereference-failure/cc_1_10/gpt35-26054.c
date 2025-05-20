//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define POINTS 100
#define CLUSTERS 5
#define MIN_FLOAT 0.0000001

typedef struct point {
    float x;
    float y;
} point;

typedef struct cluster {
    point centroid;
    point* points;
    int numOfPoints;
} cluster;

point* generateRandomPoints(int numOfPoints);
void printPoints(point* points, int numOfPoints);
void initializeClusters(point* points, int numOfPoints, cluster* clusters, int numOfClusters);
void updateCentroids(cluster* clusters, int numOfClusters);
void assignPointsToClusters(cluster* clusters, int numOfClusters, point* points, int numOfPoints);
float calculateDistance(point p1, point p2);
float calculateClusterError(cluster* clusters, int numOfClusters);
void printClusters(cluster* clusters, int numOfClusters);

int main() {
    point* points = generateRandomPoints(POINTS);
    cluster clusters[CLUSTERS];
    initializeClusters(points, POINTS, clusters, CLUSTERS);
    int numOfIterations = 0;
    float error = MIN_FLOAT + 1;

    while (error > MIN_FLOAT && numOfIterations < 20) {
        assignPointsToClusters(clusters, CLUSTERS, points, POINTS);
        updateCentroids(clusters, CLUSTERS);
        float newError = calculateClusterError(clusters, CLUSTERS);
        error = fabs(error - newError);
        numOfIterations++;
    }

    printClusters(clusters, CLUSTERS);

    free(points);
    for (int i = 0; i < CLUSTERS; i++) {
        free(clusters[i].points);
    }

    return 0;
}

point* generateRandomPoints(int numOfPoints) {
    point* points = malloc(numOfPoints * sizeof(point));
    for (int i = 0; i < numOfPoints; i++) {
        points[i].x = (float)rand() / RAND_MAX * 100;
        points[i].y = (float)rand() / RAND_MAX * 100;
    }
    return points;
}

void printPoints(point* points, int numOfPoints) {
    for (int i = 0; i < numOfPoints; i++) {
        printf("Point %d: (%f, %f)\n", i, points[i].x, points[i].y);
    }
}

void initializeClusters(point* points, int numOfPoints, cluster* clusters, int numOfClusters) {
    int pointsPerCluster = numOfPoints / numOfClusters;
    for (int i = 0; i < numOfClusters; i++) {
        int start = i * pointsPerCluster;
        clusters[i].centroid = points[start];
        clusters[i].numOfPoints = pointsPerCluster;
        clusters[i].points = malloc(pointsPerCluster * sizeof(point));
        for (int j = 0; j < pointsPerCluster; j++) {
            clusters[i].points[j] = points[start + j];
        }
    }
}

void updateCentroids(cluster* clusters, int numOfClusters) {
    for (int i = 0; i < numOfClusters; i++) {
        int numOfPoints = clusters[i].numOfPoints;
        float sumX = 0, sumY = 0;
        for (int j = 0; j < numOfPoints; j++) {
            sumX += clusters[i].points[j].x;
            sumY += clusters[i].points[j].y;
        }
        clusters[i].centroid.x = sumX / numOfPoints;
        clusters[i].centroid.y = sumY / numOfPoints;
    }
}

void assignPointsToClusters(cluster* clusters, int numOfClusters, point* points, int numOfPoints) {
    for (int i = 0; i < numOfPoints; i++) {
        float minDistance = __FLT_MAX__;
        int minDistanceCluster = -1;
        point currentPoint = points[i];
        for (int j = 0; j < numOfClusters; j++) {
            float distance = calculateDistance(currentPoint, clusters[j].centroid);
            if (distance < minDistance) {
                minDistance = distance;
                minDistanceCluster = j;
            }
        }
        clusters[minDistanceCluster].points[clusters[minDistanceCluster].numOfPoints++] = currentPoint;
    }
}

float calculateDistance(point p1, point p2) {
    float dx = p1.x - p2.x;
    float dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

float calculateClusterError(cluster* clusters, int numOfClusters) {
    float error = 0;
    for (int i = 0; i < numOfClusters; i++) {
        int numOfPoints = clusters[i].numOfPoints;
        for (int j = 0; j < numOfPoints; j++) {
            error += calculateDistance(clusters[i].points[j], clusters[i].centroid);
        }
    }
    return error;
}

void printClusters(cluster* clusters, int numOfClusters) {
    for (int i = 0; i < numOfClusters; i++) {
        printf("Cluster %d (Centroid: (%f, %f)):\n", i, clusters[i].centroid.x, clusters[i].centroid.y);
        int numOfPoints = clusters[i].numOfPoints;
        for (int j = 0; j < numOfPoints; j++) {
            printf("(%f, %f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
    }
}