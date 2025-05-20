//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Struct for holding data points
typedef struct point {
    double x;
    double y;
} Point;

// Function to compute Euclidean distance between two points
double dist(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Main clustering function
void cluster(Point* points, int n, double thres) {
    // Create array to store assigned cluster numbers
    int* clusters = calloc(n, sizeof(int));
    int clusterNum = 1;
    
    // Loop through each point
    for (int i = 0; i < n; i++) {
        // If point already has a cluster, skip it
        if (clusters[i] != 0) {
            continue;
        }
        
        // Point does not belong to any cluster, so assign it to a new cluster
        clusters[i] = clusterNum;
        clusterNum++;
        
        // Loop through remaining unassigned points
        for (int j = i + 1; j < n; j++) {
            if (clusters[j] != 0) {
                continue;
            }
            // Compute distance between points
            double d = dist(points[i], points[j]);
            // If distance is less than threshold, assign to same cluster
            if (d < thres) {
                clusters[j] = clusters[i];
            }
        }
    }
    
    // Print out cluster assignments
    for (int i = 0; i < n; i++) {
        printf("Point %d assigned to cluster %d\n", i+1, clusters[i]);
    }
    
    free(clusters);
}

int main() {
    // Generate random points for clustering
    srand(time(NULL));
    int n = 10;
    Point* points = calloc(n, sizeof(Point));
    for (int i = 0; i < n; i++) {
        points[i].x = (double) rand() / RAND_MAX;
        points[i].y = (double) rand() / RAND_MAX;
    }
    
    // Call clustering function with threshold of 0.5
    double thres = 0.5;
    cluster(points, n, thres);
    
    free(points);
    return 0;
}