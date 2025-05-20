//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point {
    double x, y;
    int cluster;
};

double dist(struct point p1, struct point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

void k_means(struct point* points, int num_points, int num_clusters) {
    // initialize centroids randomly
    struct point* centroids = (struct point*) malloc(num_clusters * sizeof(struct point));
    for (int i = 0; i < num_clusters; i++) {
        centroids[i] = points[rand() % num_points];
    }
    
    // continue until centroids no longer change
    int num_iterations = 0;
    while (1) {
        num_iterations++;
        
        // assign each point to its closest centroid
        for (int i = 0; i < num_points; i++) {
            double min_distance = INFINITY;
            for (int j = 0; j < num_clusters; j++) {
                double distance = dist(points[i], centroids[j]);
                if (distance < min_distance) {
                    min_distance = distance;
                    points[i].cluster = j;
                }
            }
        }
        
        // reset centroids
        struct point* new_centroids = (struct point*) calloc(num_clusters, sizeof(struct point));
        int* cluster_sizes = (int*) calloc(num_clusters, sizeof(int));
        
        // calculate new centroids
        for (int i = 0; i < num_points; i++) {
            int cluster = points[i].cluster;
            new_centroids[cluster].x += points[i].x;
            new_centroids[cluster].y += points[i].y;
            cluster_sizes[cluster]++;
        }
        
        for (int i = 0; i < num_clusters; i++) {
            if (cluster_sizes[i] > 0) {
                new_centroids[i].x /= cluster_sizes[i];
                new_centroids[i].y /= cluster_sizes[i];
            }
        }
        
        // check if centroids have changed
        int centroids_changed = 0;
        for (int i = 0; i < num_clusters; i++) {
            if (fabs(new_centroids[i].x - centroids[i].x) > 0.0001 || fabs(new_centroids[i].y - centroids[i].y) > 0.0001) {
                centroids_changed = 1;
            }
            
            // update centroids
            centroids[i] = new_centroids[i];
        }
        
        free(new_centroids);
        free(cluster_sizes);
        
        if (!centroids_changed) {
            break;
        }
    }
    
    printf("Converged after %d iterations:\n", num_iterations);
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < num_points; j++) {
            if (points[j].cluster == i) {
                printf("(%f, %f)\n", points[j].x, points[j].y);
            }
        }
    }
    
    free(centroids);
}

int main() {
    // generate some random points
    const int num_points = 1000;
    struct point* points = (struct point*) malloc(num_points * sizeof(struct point));
    for (int i = 0; i < num_points; i++) {
        points[i].x = (double) rand() / RAND_MAX;
        points[i].y = (double) rand() / RAND_MAX;
    }
    
    // cluster the points
    const int num_clusters = 3;
    k_means(points, num_points, num_clusters);
    
    free(points);
    
    return 0;
}