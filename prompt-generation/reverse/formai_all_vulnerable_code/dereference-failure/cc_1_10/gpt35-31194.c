//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the data structure for each point
typedef struct {
    double x;
    double y;
} point;

// Define the data structure for each cluster
typedef struct {
    point centroid;
    point *points;
    int num_points;
} cluster;

// Function to calculate the Euclidean distance between two points
double distance(point p1, point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Function to randomly initialize the centroids of the clusters
void initialize_clusters(point *points, int num_points, cluster *clusters, int num_clusters) {
    int i, j;
    for (i = 0; i < num_clusters; i++) {
        clusters[i].centroid = points[rand() % num_points];
        clusters[i].points = malloc(num_points * sizeof(point));
        clusters[i].num_points = 0;
    }
    for (j = 0; j < num_points; j++) {
        int closest_cluster = 0;
        double min_distance = distance(points[j], clusters[0].centroid);
        for (i = 1; i < num_clusters; i++) {
            double d = distance(points[j], clusters[i].centroid);
            if (d < min_distance) {
                min_distance = d;
                closest_cluster = i;
            }
        }
        clusters[closest_cluster].points[clusters[closest_cluster].num_points] = points[j];
        clusters[closest_cluster].num_points++;
    }
}

// Function to calculate the new centroids for each cluster
void calculate_centroids(cluster *clusters, int num_clusters) {
    int i, j;
    for (i = 0; i < num_clusters; i++) {
        double sum_x = 0, sum_y = 0;
        for (j = 0; j < clusters[i].num_points; j++) {
            sum_x += clusters[i].points[j].x;
            sum_y += clusters[i].points[j].y;
        }
        clusters[i].centroid.x = sum_x / clusters[i].num_points;
        clusters[i].centroid.y = sum_y / clusters[i].num_points;
    }
}

// Function to perform the clustering
void cluster_points(point *points, int num_points, cluster *clusters, int num_clusters) {
    while (1) {
        int i, j;
        
        // Assign each point to its closest cluster
        for (j = 0; j < num_points; j++) {
            int closest_cluster = 0;
            double min_distance = distance(points[j], clusters[0].centroid);
            for (i = 1; i < num_clusters; i++) {
                double d = distance(points[j], clusters[i].centroid);
                if (d < min_distance) {
                    min_distance = d;
                    closest_cluster = i;
                }
            }
            clusters[closest_cluster].points[clusters[closest_cluster].num_points] = points[j];
            clusters[closest_cluster].num_points++;
        }
        
        // Save the previous centroids
        point *previous_centroids = malloc(num_clusters * sizeof(point));
        for (i = 0; i < num_clusters; i++) {
            previous_centroids[i] = clusters[i].centroid;
        }
        
        // Calculate the new centroids
        calculate_centroids(clusters, num_clusters);
        
        // Check if the centroids have converged
        int converged = 1;
        for (i = 0; i < num_clusters; i++) {
            if (distance(previous_centroids[i], clusters[i].centroid) > 0.001) {
                converged = 0;
                break;
            }
        }
        free(previous_centroids);
        
        // If the centroids have converged, exit the loop
        if (converged) {
            break;
        }
        
        // Otherwise, reset the clusters
        for (i = 0; i < num_clusters; i++) {
            clusters[i].num_points = 0;
        }
    }
}

// Sample main function
int main() {
    int i;
    int num_points = 20;
    int num_clusters = 3;
    point *points = malloc(num_points * sizeof(point));
    cluster *clusters = malloc(num_clusters * sizeof(cluster));
    srand(12345);
    for (i = 0; i < num_points; i++) {
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;
    }
    initialize_clusters(points, num_points, clusters, num_clusters);
    cluster_points(points, num_points, clusters, num_clusters);
    for (i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i + 1);
        int j;
        for (j = 0; j < clusters[i].num_points; j++) {
            printf("(%lf, %lf)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
    }
    free(points);
    for (i = 0; i < num_clusters; i++) {
        free(clusters[i].points);
    }
    free(clusters);
    return 0;
}