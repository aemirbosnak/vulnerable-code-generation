//FormAI DATASET v1.0 Category: Data mining ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define K 3 // number of clusters
#define MAX_ITERATIONS 1000

typedef struct {
    float x;
    float y;
} point;

float euclidean_distance(point p1, point p2) {
    float dx = p1.x - p2.x;
    float dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

void kmeans(point *data, int n, point *centroids) {
    // allocate memory for the cluster assignments
    int *assignments = (int *)malloc(n * sizeof(int));
    
    // initialize the centroids randomly
    for (int i = 0; i < K; i++) {
        centroids[i].x = data[rand() % n].x;
        centroids[i].y = data[rand() % n].y;
    }
    
    int iteration = 0;
    while (iteration < MAX_ITERATIONS) {
        // for each data point, assign it to the closest centroid
        for (int i = 0; i < n; i++) {
            int closest_centroid = -1;
            float min_distance = HUGE_VALF;
            for (int j = 0; j < K; j++) {
                float distance = euclidean_distance(data[i], centroids[j]);
                if (distance < min_distance) {
                    closest_centroid = j;
                    min_distance = distance;
                }
            }
            assignments[i] = closest_centroid;
        }
        
        // compute the new centroids
        point *sums = (point *)calloc(K, sizeof(point));
        int *counts = (int *)calloc(K, sizeof(int));
        for (int i = 0; i < n; i++) {
            int cluster = assignments[i];
            sums[cluster].x += data[i].x;
            sums[cluster].y += data[i].y;
            counts[cluster]++;
        }
        for (int i = 0; i < K; i++) {
            centroids[i].x = sums[i].x / counts[i];
            centroids[i].y = sums[i].y / counts[i];
        }
        free(sums);
        free(counts);
        
        iteration++;
    }
    
    free(assignments);
}

int main() {
    // generate some random data
    point data[] = {
        {1.0, 2.0},
        {2.0, 2.0},
        {1.0, 3.0},
        {2.0, 3.0},
        {4.0, 4.0},
        {5.0, 5.0},
        {4.0, 6.0},
        {5.0, 6.0},
        {8.0, 1.0},
        {9.0, 1.0},
        {8.0, 2.0},
        {9.0, 2.0},
        {10.0, 4.0},
        {10.0, 5.0},
        {11.0, 4.0},
        {11.0, 5.0}
    };
    int n = sizeof(data) / sizeof(point);
    
    // run k-means clustering
    point centroids[K];
    kmeans(data, n, centroids);
    
    // print the results
    for (int i = 0; i < K; i++) {
        printf("Centroid %d: (%.1f, %.1f)\n", i+1, centroids[i].x, centroids[i].y);
    }
    
    return 0;
}