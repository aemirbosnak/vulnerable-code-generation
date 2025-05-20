//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 10
#define DIMENSIONS 2
#define MAX_ITERATIONS 100

typedef struct {
    double coordinates[DIMENSIONS];
} Point;

typedef struct {
    Point centroid;
    Point points[MAX_POINTS];
    int point_count;
} Cluster;

// Function to calculate the distance between two points
double calculate_distance(Point* a, Point* b) {
    double sum = 0.0;
    for (int i = 0; i < DIMENSIONS; i++) {
        sum += pow(a->coordinates[i] - b->coordinates[i], 2);
    }
    return sqrt(sum);
}

// Function to initialize clusters with random centroids
void initialize_clusters(Cluster* clusters, int cluster_count, Point* points, int point_count) {
    srand(time(NULL));
    for (int i = 0; i < cluster_count; i++) {
        int random_index = rand() % point_count;
        clusters[i].centroid = points[random_index];
        clusters[i].point_count = 0; // Initialize count to zero
    }
}

// Function to assign points to the nearest cluster
void assign_points_to_clusters(Cluster* clusters, int cluster_count, Point* points, int point_count) {
    for (int i = 0; i < point_count; i++) {
        double min_distance = INFINITY;
        int cluster_index = -1;
        for (int j = 0; j < cluster_count; j++) {
            double distance = calculate_distance(&points[i], &clusters[j].centroid);
            if (distance < min_distance) {
                min_distance = distance;
                cluster_index = j;
            }
        }
        clusters[cluster_index].points[clusters[cluster_index].point_count] = points[i];
        clusters[cluster_index].point_count++;
    }
}

// Function to update the centroid of each cluster
void update_centroids(Cluster* clusters, int cluster_count) {
    for (int i = 0; i < cluster_count; i++) {
        for (int j = 0; j < DIMENSIONS; j++) {
            clusters[i].centroid.coordinates[j] = 0.0;
        }
        for (int j = 0; j < clusters[i].point_count; j++) {
            for (int d = 0; d < DIMENSIONS; d++) {
                clusters[i].centroid.coordinates[d] += clusters[i].points[j].coordinates[d];
            }
        }
        if (clusters[i].point_count > 0) {
            for (int d = 0; d < DIMENSIONS; d++) {
                clusters[i].centroid.coordinates[d] /= clusters[i].point_count;
            }
        }
    }
}

// Function to clear clusters for the next iteration
void clear_clusters(Cluster* clusters, int cluster_count) {
    for (int i = 0; i < cluster_count; i++) {
        clusters[i].point_count = 0; // Reset count to zero
    }
}

// Main function to execute the clustering algorithm
int main() {
    int point_count, cluster_count;

    // Input for number of points
    printf("Enter the number of points (max %d): ", MAX_POINTS);
    scanf("%d", &point_count);
    if (point_count > MAX_POINTS) {
        printf("Too many points, using max %d instead.\n", MAX_POINTS);
        point_count = MAX_POINTS;
    }

    Point points[MAX_POINTS];

    // Input for point coordinates
    for (int i = 0; i < point_count; i++) {
        printf("Enter coordinates of point %d (x y): ", i + 1);
        scanf("%lf %lf", &points[i].coordinates[0], &points[i].coordinates[1]);
    }

    // Input for number of clusters
    printf("Enter number of clusters (max %d): ", MAX_CLUSTERS);
    scanf("%d", &cluster_count);
    if (cluster_count > MAX_CLUSTERS) {
        printf("Too many clusters, using max %d instead.\n", MAX_CLUSTERS);
        cluster_count = MAX_CLUSTERS;
    }

    Cluster clusters[MAX_CLUSTERS];

    initialize_clusters(clusters, cluster_count, points, point_count);

    for (int iter = 0; iter < MAX_ITERATIONS; iter++) {
        clear_clusters(clusters, cluster_count);
        assign_points_to_clusters(clusters, cluster_count, points, point_count);
        update_centroids(clusters, cluster_count);
    }

    // Output results
    for (int i = 0; i < cluster_count; i++) {
        printf("Cluster %d:\n", i + 1);
        printf(" Centroid: (%.2f, %.2f)\n", clusters[i].centroid.coordinates[0], clusters[i].centroid.coordinates[1]);
        printf(" Points: ");
        for (int j = 0; j < clusters[i].point_count; j++) {
            printf("(%.2f, %.2f) ", clusters[i].points[j].coordinates[0], clusters[i].points[j].coordinates[1]);
        }
        printf("\n");
    }

    return 0;
}