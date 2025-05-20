//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DATA 1000
#define MAX_CLUSTERS 10
#define MAX_ITERATIONS 100

typedef struct {
    double x;
    double y;
} point;

typedef struct {
    point centroid;
    int num_points;
    point *points;
} cluster;

cluster *clusters;
int num_clusters;
int num_data;
point *data;

void initialize_data() {
    // Generate some random data
    data = malloc(sizeof(point) * MAX_DATA);
    for (int i = 0; i < MAX_DATA; i++) {
        data[i].x = rand() % 100;
        data[i].y = rand() % 100;
    }
}

void initialize_clusters() {
    // Initialize the clusters randomly
    clusters = malloc(sizeof(cluster) * MAX_CLUSTERS);
    for (int i = 0; i < MAX_CLUSTERS; i++) {
        clusters[i].centroid.x = rand() % 100;
        clusters[i].centroid.y = rand() % 100;
        clusters[i].num_points = 0;
        clusters[i].points = NULL;
    }
}

void assign_points_to_clusters() {
    // Assign each point to the closest cluster
    for (int i = 0; i < MAX_DATA; i++) {
        double min_distance = INFINITY;
        int closest_cluster = -1;
        for (int j = 0; j < MAX_CLUSTERS; j++) {
            double distance = sqrt(pow(data[i].x - clusters[j].centroid.x, 2) + pow(data[i].y - clusters[j].centroid.y, 2));
            if (distance < min_distance) {
                min_distance = distance;
                closest_cluster = j;
            }
        }
        clusters[closest_cluster].num_points++;
        clusters[closest_cluster].points = realloc(clusters[closest_cluster].points, sizeof(point) * clusters[closest_cluster].num_points);
        clusters[closest_cluster].points[clusters[closest_cluster].num_points - 1] = data[i];
    }
}

void update_centroids() {
    // Update the centroids of each cluster
    for (int i = 0; i < MAX_CLUSTERS; i++) {
        clusters[i].centroid.x = 0;
        clusters[i].centroid.y = 0;
        for (int j = 0; j < clusters[i].num_points; j++) {
            clusters[i].centroid.x += clusters[i].points[j].x;
            clusters[i].centroid.y += clusters[i].points[j].y;
        }
        clusters[i].centroid.x /= clusters[i].num_points;
        clusters[i].centroid.y /= clusters[i].num_points;
    }
}

void print_clusters() {
    // Print the clusters
    for (int i = 0; i < MAX_CLUSTERS; i++) {
        printf("Cluster %d:\n", i);
        printf("Centroid: (%f, %f)\n", clusters[i].centroid.x, clusters[i].centroid.y);
        printf("Number of points: %d\n", clusters[i].num_points);
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("Point %d: (%f, %f)\n", j, clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }
}

int main() {
    initialize_data();
    initialize_clusters();

    for (int i = 0; i < MAX_ITERATIONS; i++) {
        assign_points_to_clusters();
        update_centroids();
    }

    print_clusters();

    return 0;
}