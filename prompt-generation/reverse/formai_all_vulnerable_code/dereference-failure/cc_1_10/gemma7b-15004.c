//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the Euclidean distance function
double euclidean_distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Define the cluster centroid function
double calculate_centroid(int cluster_num, double **data, int num_points) {
    double sum_x = 0.0, sum_y = 0.0, total_points = 0.0;
    for (int i = 0; i < num_points; i++) {
        if (data[i][0] == cluster_num) {
            sum_x += data[i][1];
            sum_y += data[i][2];
            total_points++;
        }
    }
    return (sum_x / total_points) + (sum_y / total_points);
}

// Main function
int main() {
    // Create a sample data set
    double **data = malloc(10 * sizeof(double *));
    for (int i = 0; i < 10; i++) {
        data[i] = malloc(3 * sizeof(double));
        data[i][0] = i + 1;
        data[i][1] = rand() % 100;
        data[i][2] = rand() % 100;
    }

    // Calculate the Euclidean distances between each point and the cluster centroids
    int num_clusters = 3;
    double **centroids = malloc(num_clusters * sizeof(double *));
    for (int i = 0; i < num_clusters; i++) {
        centroids[i] = malloc(2 * sizeof(double));
    }
    centroids[0][0] = calculate_centroid(0, data, 10);
    centroids[0][1] = calculate_centroid(0, data, 10);
    centroids[1][0] = calculate_centroid(1, data, 10);
    centroids[1][1] = calculate_centroid(1, data, 10);
    centroids[2][0] = calculate_centroid(2, data, 10);
    centroids[2][1] = calculate_centroid(2, data, 10);

    // Assign each point to its closest cluster centroid
    for (int i = 0; i < 10; i++) {
        double min_distance = 100.0;
        int cluster_num = -1;
        for (int j = 0; j < num_clusters; j++) {
            double distance = euclidean_distance(data[i][1], data[i][2], centroids[j][0], centroids[j][1]);
            if (distance < min_distance) {
                min_distance = distance;
                cluster_num = j;
            }
        }
        data[i][0] = cluster_num;
    }

    // Print the cluster memberships
    for (int i = 0; i < 10; i++) {
        printf("Point %d belongs to Cluster %d\n", data[i][0], data[i][0]);
    }

    // Free the memory
    for (int i = 0; i < 10; i++) {
        free(data[i]);
    }
    free(data);
    for (int i = 0; i < num_clusters; i++) {
        free(centroids[i]);
    }
    free(centroids);

    return 0;
}