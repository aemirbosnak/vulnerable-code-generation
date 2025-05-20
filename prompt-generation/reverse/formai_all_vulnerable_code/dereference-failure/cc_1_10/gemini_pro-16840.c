//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_CLUSTERS 3
#define NUM_DIMENSIONS 2

// Data point
typedef struct {
    double dimensions[NUM_DIMENSIONS];
} DataPoint;

// Cluster
typedef struct {
    DataPoint centroid;
    int num_points;
    DataPoint *points;
} Cluster;

// Global variables
DataPoint *data_points;
int num_data_points;
Cluster *clusters;

// Function prototypes
void initialize_data_points();
void initialize_clusters();
void assign_points_to_clusters();
void update_centroids();
double calculate_distance(DataPoint a, DataPoint b);
int main() {
    // Initialize data points
    initialize_data_points();

    // Initialize clusters
    initialize_clusters();

    // Assign points to clusters
    assign_points_to_clusters();

    // Update centroids
    update_centroids();

    // Print cluster centroids
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        printf("Cluster %d centroid: ", i);
        for (int j = 0; j < NUM_DIMENSIONS; j++) {
            printf("%f ", clusters[i].centroid.dimensions[j]);
        }
        printf("\n");
    }

    return 0;
}

void initialize_data_points() {
    // Generate random data points
    data_points = malloc(sizeof(DataPoint) * num_data_points);
    for (int i = 0; i < num_data_points; i++) {
        for (int j = 0; j < NUM_DIMENSIONS; j++) {
            data_points[i].dimensions[j] = rand() / (double)RAND_MAX;
        }
    }
}

void initialize_clusters() {
    // Randomly select cluster centroids
    clusters = malloc(sizeof(Cluster) * NUM_CLUSTERS);
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        for (int j = 0; j < NUM_DIMENSIONS; j++) {
            clusters[i].centroid.dimensions[j] = rand() / (double)RAND_MAX;
        }
        clusters[i].num_points = 0;
        clusters[i].points = NULL;
    }
}

void assign_points_to_clusters() {
    // Assign each data point to the closest cluster
    for (int i = 0; i < num_data_points; i++) {
        double min_distance = INFINITY;
        int closest_cluster = -1;
        for (int j = 0; j < NUM_CLUSTERS; j++) {
            double distance = calculate_distance(data_points[i], clusters[j].centroid);
            if (distance < min_distance) {
                min_distance = distance;
                closest_cluster = j;
            }
        }
        clusters[closest_cluster].points = realloc(clusters[closest_cluster].points, sizeof(DataPoint) * (clusters[closest_cluster].num_points + 1));
        clusters[closest_cluster].points[clusters[closest_cluster].num_points] = data_points[i];
        clusters[closest_cluster].num_points++;
    }
}

void update_centroids() {
    // Update the centroid of each cluster
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        for (int j = 0; j < NUM_DIMENSIONS; j++) {
            clusters[i].centroid.dimensions[j] = 0;
        }
        for (int k = 0; k < clusters[i].num_points; k++) {
            for (int j = 0; j < NUM_DIMENSIONS; j++) {
                clusters[i].centroid.dimensions[j] += clusters[i].points[k].dimensions[j];
            }
        }
        for (int j = 0; j < NUM_DIMENSIONS; j++) {
            clusters[i].centroid.dimensions[j] /= clusters[i].num_points;
        }
    }
}

double calculate_distance(DataPoint a, DataPoint b) {
    // Calculate the Euclidean distance between two data points
    double distance = 0;
    for (int i = 0; i < NUM_DIMENSIONS; i++) {
        distance += pow(a.dimensions[i] - b.dimensions[i], 2);
    }
    return sqrt(distance);
}