//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point *points;
    int num_points;
} Cluster;

double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void initialize_clusters(Cluster *clusters, Point *data_points, int num_clusters, int num_points) {
    srand(time(NULL));
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].points = (Point *)malloc(num_points * sizeof(Point));
        clusters[i].num_points = 0;

        // Randomly select initial centroids from data points
        clusters[i].points[0] = data_points[rand() % num_points];
    }
}

void assign_points_to_clusters(Point *data_points, Cluster *clusters, int num_clusters, int num_points) {
    for (int i = 0; i < num_points; i++) {
        double min_dist = INFINITY;
        int cluster_index = -1;

        // Find the closest cluster centroid
        for (int j = 0; j < num_clusters; j++) {
            double dist = distance(data_points[i], clusters[j].points[0]); // centroids are points[0]
            if (dist < min_dist) {
                min_dist = dist;
                cluster_index = j;
            }
        }

        clusters[cluster_index].points[clusters[cluster_index].num_points] = data_points[i];
        clusters[cluster_index].num_points++;
    }
}

void update_centroids(Cluster *clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        double sum_x = 0;
        double sum_y = 0;

        for (int j = 0; j < clusters[i].num_points; j++) {
            sum_x += clusters[i].points[j].x;
            sum_y += clusters[i].points[j].y;
        }

        if (clusters[i].num_points > 0) {
            clusters[i].points[0].x = sum_x / clusters[i].num_points;
            clusters[i].points[0].y = sum_y / clusters[i].num_points;
        }
    }
}

void print_clusters(Cluster *clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i + 1);
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("  Point(%lf, %lf)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("  Centroid(%lf, %lf)\n", clusters[i].points[0].x, clusters[i].points[0].y);
    }
}

void free_clusters(Cluster *clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        free(clusters[i].points);
    }
}

int main() {
    int num_points = 100;
    int num_clusters = 3;

    // Generate random data points
    Point *data_points = (Point *)malloc(num_points * sizeof(Point));
    for (int i = 0; i < num_points; i++) {
        data_points[i].x = ((double)rand() / RAND_MAX) * 100;
        data_points[i].y = ((double)rand() / RAND_MAX) * 100;
    }

    // Initialize clusters
    Cluster *clusters = (Cluster *)malloc(num_clusters * sizeof(Cluster));
    initialize_clusters(clusters, data_points, num_clusters, num_points);

    // K-Means Clustering
    int iterations = 10;
    for (int iter = 0; iter < iterations; iter++) {
        // Reset cluster points count
        for (int i = 0; i < num_clusters; i++) {
            clusters[i].num_points = 0;
        }

        // Assign points to clusters
        assign_points_to_clusters(data_points, clusters, num_clusters, num_points);
        
        // Update centroids
        update_centroids(clusters, num_clusters);
    }

    // Print results
    print_clusters(clusters, num_clusters);

    // Clean up
    free(data_points);
    free(clusters);
    return 0;
}