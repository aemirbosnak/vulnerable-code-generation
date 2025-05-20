//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* A structure to represent a point in 2D space */
typedef struct point {
    float x;
    float y;
} Point;

/* A structure to represent a cluster of points */
typedef struct cluster {
    Point center;
    Point *points;
    int size;
} Cluster;

/* Function to calculate the Euclidean distance between two points */
float distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

/* Function to randomly initialize the clusters */
void initialize_clusters(Cluster *clusters, int num_clusters, Point *points, int num_points) {
    for (int i = 0; i < num_clusters; i++) {
        // Pick a random center for the cluster
        int index = rand() % num_points;
        clusters[i].center = points[index];
        clusters[i].points = (Point *) malloc(num_points * sizeof(Point));
        clusters[i].size = 0;
    }
}

/* Function to assign each point to its nearest cluster */
void assign_points(Cluster *clusters, int num_clusters, Point *points, int num_points) {
    for (int i = 0; i < num_points; i++) {
        float min_distance = INFINITY;
        int min_cluster_index = -1;
        // Find the nearest cluster for this point
        for (int j = 0; j < num_clusters; j++) {
            float current_distance = distance(points[i], clusters[j].center);
            if (current_distance < min_distance) {
                min_distance = current_distance;
                min_cluster_index = j;
            }
        }
        // Add the point to the nearest cluster
        clusters[min_cluster_index].points[clusters[min_cluster_index].size++] = points[i];
    }
}

/* Function to update the centers of each cluster */
void update_centers(Cluster *clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        float sum_x = 0, sum_y = 0;
        for (int j = 0; j < clusters[i].size; j++) {
            sum_x += clusters[i].points[j].x;
            sum_y += clusters[i].points[j].y;
        }
        clusters[i].center.x = sum_x / clusters[i].size;
        clusters[i].center.y = sum_y / clusters[i].size;
    }
}

/* Function to print the clusters */
void print_clusters(Cluster *clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d: Center (%.2f, %.2f), Points: ", i+1, clusters[i].center.x, clusters[i].center.y);
        for (int j = 0; j < clusters[i].size; j++) {
            printf("(%.2f, %.2f) ", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }
}

int main() {
    // Initialize the points
    Point points[] = {{1, 2}, {2, 1}, {4, 3}, {5, 4}, {6, 5}, {7, 7}, {8, 8}, {9, 7}, {10, 9}, {11, 8}};
    int num_points = sizeof(points) / sizeof(points[0]);

    // Initialize the clusters
    int num_clusters = 3;
    Cluster *clusters = (Cluster *) malloc(num_clusters * sizeof(Cluster));
    initialize_clusters(clusters, num_clusters, points, num_points);

    // Perform clustering for 10 iterations
    for (int i = 0; i < 10; i++) {
        assign_points(clusters, num_clusters, points, num_points);
        update_centers(clusters, num_clusters);
    }

    // Print the final clusters
    print_clusters(clusters, num_clusters);

    // Free memory
    for (int i = 0; i < num_clusters; i++) {
        free(clusters[i].points);
    }
    free(clusters);

    return 0;
}