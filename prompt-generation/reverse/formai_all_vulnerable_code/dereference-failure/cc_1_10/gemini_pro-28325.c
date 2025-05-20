//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the data point structure
typedef struct {
    double x;
    double y;
} point;

// Define the cluster structure
typedef struct {
    point center;
    int num_points;
} cluster;

// Define the function to initialize a cluster
cluster *init_cluster(point center) {
    cluster *c = malloc(sizeof(cluster));
    c->center = center;
    c->num_points = 0;
    return c;
}

// Define the function to assign a point to a cluster
void assign_point(point *p, cluster *c) {
    c->num_points++;
    c->center.x += (p->x - c->center.x) / c->num_points;
    c->center.y += (p->y - c->center.y) / c->num_points;
}

// Define the function to calculate the distance between two points
double distance(point p1, point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Define the function to perform k-means clustering
cluster *kmeans(point *points, int num_points, int num_clusters) {
    // Initialize the clusters
    cluster *clusters = malloc(sizeof(cluster) * num_clusters);
    for (int i = 0; i < num_clusters; i++) {
        clusters[i] = *init_cluster(points[rand() % num_points]);
    }

    // Assign the points to the clusters
    for (int i = 0; i < num_points; i++) {
        double min_distance = INFINITY;
        cluster *closest_cluster = NULL;
        for (int j = 0; j < num_clusters; j++) {
            double distance_to_cluster = distance(points[i], clusters[j].center);
            if (distance_to_cluster < min_distance) {
                min_distance = distance_to_cluster;
                closest_cluster = &clusters[j];
            }
        }
        assign_point(&points[i], closest_cluster);
    }

    // Update the cluster centers
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].center.x /= clusters[i].num_points;
        clusters[i].center.y /= clusters[i].num_points;
    }

    return clusters;
}

// Define the function to print the clusters
void print_clusters(cluster *clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i);
        printf("Center: (%f, %f)\n", clusters[i].center.x, clusters[i].center.y);
        printf("Num points: %d\n", clusters[i].num_points);
        printf("\n");
    }
}

// Define the main function
int main() {
    // Initialize the data points
    point points[] = {
        {0.0, 0.0},
        {1.0, 1.0},
        {2.0, 2.0},
        {3.0, 3.0},
        {4.0, 4.0},
        {5.0, 5.0},
        {6.0, 6.0},
        {7.0, 7.0},
        {8.0, 8.0},
        {9.0, 9.0}
    };

    // Perform k-means clustering
    cluster *clusters = kmeans(points, sizeof(points) / sizeof(point), 3);

    // Print the clusters
    print_clusters(clusters, 3);

    // Free the clusters
    for (int i = 0; i < 3; i++) {
        free(&clusters[i]);
    }
    free(clusters);

    return 0;
}