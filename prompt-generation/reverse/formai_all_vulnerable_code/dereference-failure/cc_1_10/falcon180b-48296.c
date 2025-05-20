//Falcon-180B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000

typedef struct {
    int id;
    double x, y;
} Point;

typedef struct {
    int count;
    Point *points;
} Cluster;

void initialize(Cluster *cluster, int k) {
    cluster->count = 0;
    cluster->points = (Point *)malloc(k * sizeof(Point));
}

void addPoint(Cluster *cluster, Point point) {
    cluster->points[cluster->count] = point;
    cluster->count++;
}

double euclideanDistance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

void kMeans(Point points[], int n, int k, Cluster clusters[]) {
    int i, j;
    double minDistance;
    Point centroid;

    // Initialize centroids randomly
    for (i = 0; i < k; i++) {
        clusters[i].count = 0;
        clusters[i].points = (Point *)malloc(MAX_POINTS * sizeof(Point));
        centroid = points[rand() % n];
        clusters[i].points[0] = centroid;
    }

    // Perform k-means clustering
    for (i = 0; i < 100; i++) {
        // Assign each point to the closest centroid
        for (j = 0; j < n; j++) {
            minDistance = euclideanDistance(points[j], clusters[0].points[0]);
            int closestCluster = 0;

            for (int c = 1; c < k; c++) {
                double distance = euclideanDistance(points[j], clusters[c].points[0]);
                if (distance < minDistance) {
                    minDistance = distance;
                    closestCluster = c;
                }
            }

            clusters[closestCluster].count++;
            addPoint(&clusters[closestCluster], points[j]);
        }

        // Update centroids
        for (j = 0; j < k; j++) {
            if (clusters[j].count > 0) {
                double xSum = 0, ySum = 0;

                for (int c = 0; c < clusters[j].count; c++) {
                    xSum += clusters[j].points[c].x;
                    ySum += clusters[j].points[c].y;
                }

                Point centroid = {0, 0};
                centroid.x = xSum / clusters[j].count;
                centroid.y = ySum / clusters[j].count;
                clusters[j].points[0] = centroid;
            }
        }
    }
}

void printClusters(Cluster clusters[], int k) {
    int i, j;

    for (i = 0; i < k; i++) {
        printf("Cluster %d:\n", i);
        for (j = 0; j < clusters[i].count; j++) {
            printf("(%d, %lf, %lf)\n", clusters[i].points[j].id, clusters[i].points[j].x, clusters[i].points[j].y);
        }
    }
}

int main() {
    Point points[] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};
    int n = sizeof(points) / sizeof(points[0]);
    int k = 2;

    Cluster clusters[k];

    kMeans(points, n, k, clusters);
    printClusters(clusters, k);

    return 0;
}