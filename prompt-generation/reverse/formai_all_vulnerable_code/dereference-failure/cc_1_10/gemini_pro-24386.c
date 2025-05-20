//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: modular
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
    DataPoint centroid;
    int num_points;
    DataPoint* points;
} Cluster;

// Create a new data point
DataPoint* create_data_point(double x, double y) {
    DataPoint* point = malloc(sizeof(DataPoint));
    point->x = x;
    point->y = y;
    return point;
}

// Create a new cluster
Cluster* create_cluster(DataPoint* centroid) {
    Cluster* cluster = malloc(sizeof(Cluster));
    cluster->centroid = *centroid;
    cluster->num_points = 0;
    cluster->points = NULL;
    return cluster;
}

// Add a data point to a cluster
void add_data_point_to_cluster(Cluster* cluster, DataPoint* point) {
    cluster->num_points++;
    cluster->points = realloc(cluster->points, sizeof(DataPoint) * cluster->num_points);
    cluster->points[cluster->num_points - 1] = *point;
}

// Calculate the distance between two data points
double distance(DataPoint* point1, DataPoint* point2) {
    return sqrt(pow(point1->x - point2->x, 2) + pow(point1->y - point2->y, 2));
}

// Calculate the centroid of a cluster
DataPoint calculate_centroid(Cluster* cluster) {
    DataPoint centroid;
    centroid.x = 0;
    centroid.y = 0;
    for (int i = 0; i < cluster->num_points; i++) {
        centroid.x += cluster->points[i].x;
        centroid.y += cluster->points[i].y;
    }
    centroid.x /= cluster->num_points;
    centroid.y /= cluster->num_points;
    return centroid;
}

// Assign data points to clusters
void assign_data_points_to_clusters(DataPoint* data_points, int num_data_points, Cluster** clusters, int num_clusters) {
    for (int i = 0; i < num_data_points; i++) {
        double min_distance = INFINITY;
        int closest_cluster_index = -1;
        for (int j = 0; j < num_clusters; j++) {
            double distance_to_centroid = distance(&data_points[i], &clusters[j]->centroid);
            if (distance_to_centroid < min_distance) {
                min_distance = distance_to_centroid;
                closest_cluster_index = j;
            }
        }
        add_data_point_to_cluster(clusters[closest_cluster_index], &data_points[i]);
    }
}

// Update the centroids of the clusters
void update_centroids(Cluster** clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        clusters[i]->centroid = calculate_centroid(clusters[i]);
    }
}

// Perform k-means clustering
Cluster** k_means_clustering(DataPoint* data_points, int num_data_points, int num_clusters) {
    // Create the initial clusters
    Cluster** clusters = malloc(sizeof(Cluster*) * num_clusters);
    for (int i = 0; i < num_clusters; i++) {
        clusters[i] = create_cluster(&data_points[i]);
    }

    // Assign data points to clusters
    assign_data_points_to_clusters(data_points, num_data_points, clusters, num_clusters);

    // Update the centroids of the clusters
    update_centroids(clusters, num_clusters);

    // Repeat the previous two steps until the centroids no longer change
    int num_iterations = 0;
    while (num_iterations < 100) {
        // Assign data points to clusters
        assign_data_points_to_clusters(data_points, num_data_points, clusters, num_clusters);

        // Update the centroids of the clusters
        update_centroids(clusters, num_clusters);

        num_iterations++;
    }

    return clusters;
}

// Print the clusters
void print_clusters(Cluster** clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i + 1);
        printf("Centroid: (%f, %f)\n", clusters[i]->centroid.x, clusters[i]->centroid.y);
        printf("Data points:\n");
        for (int j = 0; j < clusters[i]->num_points; j++) {
            printf("(%f, %f)\n", clusters[i]->points[j].x, clusters[i]->points[j].y);
        }
        printf("\n");
    }
}

// Free the memory allocated for the clusters
void free_clusters(Cluster** clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        free(clusters[i]->points);
        free(clusters[i]);
    }
    free(clusters);
}

// Main function
int main() {
    // Create the data points
    DataPoint data_points[] = {
        {0.0, 0.0},
        {1.0, 0.0},
        {2.0, 0.0},
        {3.0, 0.0},
        {4.0, 0.0},
        {0.0, 1.0},
        {1.0, 1.0},
        {2.0, 1.0},
        {3.0, 1.0},
        {4.0, 1.0},
    };

    int num_data_points = sizeof(data_points) / sizeof(data_points[0]);

    // Perform k-means clustering
    int num_clusters = 2;
    Cluster** clusters = k_means_clustering(data_points, num_data_points, num_clusters);

    // Print the clusters
    print_clusters(clusters, num_clusters);

    // Free the memory allocated for the clusters
    free_clusters(clusters, num_clusters);

    return 0;
}