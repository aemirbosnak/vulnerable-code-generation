//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the data point struct
typedef struct {
    double x;
    double y;
} DataPoint;

// Define the cluster struct
typedef struct {
    DataPoint *points;
    int num_points;
} Cluster;

// Function to create a new data point
DataPoint *new_data_point(double x, double y) {
    DataPoint *point = malloc(sizeof(DataPoint));
    point->x = x;
    point->y = y;
    return point;
}

// Function to create a new cluster
Cluster *new_cluster() {
    Cluster *cluster = malloc(sizeof(Cluster));
    cluster->points = NULL;
    cluster->num_points = 0;
    return cluster;
}

// Function to add a data point to a cluster
void add_data_point_to_cluster(Cluster *cluster, DataPoint *point) {
    cluster->points = realloc(cluster->points, sizeof(DataPoint) * (cluster->num_points + 1));
    cluster->points[cluster->num_points] = *point;
    cluster->num_points++;
}

// Function to calculate the distance between two data points
double distance(DataPoint *point1, DataPoint *point2) {
    return sqrt(pow(point1->x - point2->x, 2) + pow(point1->y - point2->y, 2));
}

// Function to find the closest cluster to a data point
Cluster *find_closest_cluster(DataPoint *point, Cluster *clusters, int num_clusters) {
    double min_distance = INFINITY;
    Cluster *closest_cluster = NULL;
    for (int i = 0; i < num_clusters; i++) {
        double distance_to_cluster = distance(point, &clusters[i].points[0]);
        if (distance_to_cluster < min_distance) {
            min_distance = distance_to_cluster;
            closest_cluster = &clusters[i];
        }
    }
    return closest_cluster;
}

// Function to assign data points to clusters
void assign_data_points_to_clusters(DataPoint *data_points, int num_data_points, Cluster *clusters, int num_clusters) {
    for (int i = 0; i < num_data_points; i++) {
        Cluster *closest_cluster = find_closest_cluster(&data_points[i], clusters, num_clusters);
        add_data_point_to_cluster(closest_cluster, &data_points[i]);
    }
}

// Function to update the centroids of the clusters
void update_cluster_centroids(Cluster *clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        double sum_x = 0;
        double sum_y = 0;
        for (int j = 0; j < clusters[i].num_points; j++) {
            sum_x += clusters[i].points[j].x;
            sum_y += clusters[i].points[j].y;
        }
        clusters[i].points[0].x = sum_x / clusters[i].num_points;
        clusters[i].points[0].y = sum_y / clusters[i].num_points;
    }
}

// Function to perform the k-means clustering algorithm
void k_means(DataPoint *data_points, int num_data_points, int num_clusters) {
    // Create the clusters
    Cluster *clusters = malloc(sizeof(Cluster) * num_clusters);
    for (int i = 0; i < num_clusters; i++) {
        clusters[i] = *new_cluster();
    }

    // Initialize the clusters with random data points
    for (int i = 0; i < num_clusters; i++) {
        int random_index = rand() % num_data_points;
        add_data_point_to_cluster(&clusters[i], &data_points[random_index]);
    }

    // Assign the data points to the clusters
    assign_data_points_to_clusters(data_points, num_data_points, clusters, num_clusters);

    // Update the cluster centroids
    update_cluster_centroids(clusters, num_clusters);

    // Repeat the previous steps until the clusters no longer change
    int num_iterations = 0;
    while (1) {
        // Assign the data points to the clusters
        assign_data_points_to_clusters(data_points, num_data_points, clusters, num_clusters);

        // Update the cluster centroids
        update_cluster_centroids(clusters, num_clusters);

        num_iterations++;

        // Check if the clusters have stabilized
        int num_clusters_changed = 0;
        for (int i = 0; i < num_clusters; i++) {
            if (clusters[i].num_points == 0) {
                num_clusters_changed++;
            }
        }

        if (num_clusters_changed == 0) {
            break;
        }
    }

    // Print the final clusters
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("  (%f, %f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }

    // Free the memory allocated for the clusters
    for (int i = 0; i < num_clusters; i++) {
        free(clusters[i].points);
        free(&clusters[i]);
    }
    free(clusters);
}

int main() {
    // Create the data points
    DataPoint *data_points = malloc(sizeof(DataPoint) * 10);
    data_points[0] = *new_data_point(1, 1);
    data_points[1] = *new_data_point(2, 2);
    data_points[2] = *new_data_point(3, 3);
    data_points[3] = *new_data_point(4, 4);
    data_points[4] = *new_data_point(5, 5);
    data_points[5] = *new_data_point(6, 6);
    data_points[6] = *new_data_point(7, 7);
    data_points[7] = *new_data_point(8, 8);
    data_points[8] = *new_data_point(9, 9);
    data_points[9] = *new_data_point(10, 10);

    // Perform the k-means clustering algorithm
    k_means(data_points, 10, 3);

    // Free the memory allocated for the data points
    for (int i = 0; i < 10; i++) {
        free(&data_points[i]);
    }
    free(data_points);

    return 0;
}