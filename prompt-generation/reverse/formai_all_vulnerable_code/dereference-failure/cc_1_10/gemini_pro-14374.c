//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the data point structure
typedef struct {
    double x;
    double y;
} Point;

// Define the cluster structure
typedef struct {
    Point centroid;
    int num_points;
    Point* points;
} Cluster;

// Create a new point
Point* create_point(double x, double y) {
    Point* point = malloc(sizeof(Point));
    point->x = x;
    point->y = y;
    return point;
}

// Create a new cluster
Cluster* create_cluster(Point centroid) {
    Cluster* cluster = malloc(sizeof(Cluster));
    cluster->centroid = centroid;
    cluster->num_points = 0;
    cluster->points = NULL;
    return cluster;
}

// Add a point to a cluster
void add_point_to_cluster(Cluster* cluster, Point* point) {
    // Reallocate the points array if necessary
    if (cluster->num_points == 0) {
        cluster->points = malloc(sizeof(Point));
    } else {
        cluster->points = realloc(cluster->points, (cluster->num_points + 1) * sizeof(Point));
    }
    
    // Add the point to the array
    cluster->points[cluster->num_points] = *point;
    
    // Increment the number of points in the cluster
    cluster->num_points++;
}

// Calculate the centroid of a cluster
Point calculate_centroid(Cluster* cluster) {
    Point centroid = {0, 0};
    
    // Calculate the sum of the x and y coordinates of all the points in the cluster
    for (int i = 0; i < cluster->num_points; i++) {
        centroid.x += cluster->points[i].x;
        centroid.y += cluster->points[i].y;
    }
    
    // Calculate the average x and y coordinates of the points in the cluster
    centroid.x /= cluster->num_points;
    centroid.y /= cluster->num_points;
    
    return centroid;
}

// Assign a point to the closest cluster
Cluster* assign_point_to_cluster(Point* point, Cluster* clusters, int num_clusters) {
    Cluster* closest_cluster = NULL;
    double closest_distance = INFINITY;
    
    // Calculate the distance from the point to each cluster centroid
    for (int i = 0; i < num_clusters; i++) {
        double distance = sqrt(pow(point->x - clusters[i].centroid.x, 2) + pow(point->y - clusters[i].centroid.y, 2));
        if (distance < closest_distance) {
            closest_distance = distance;
            closest_cluster = &clusters[i];
        }
    }
    
    // Return the closest cluster
    return closest_cluster;
}

// Perform k-means clustering
void k_means_clustering(Point* points, int num_points, int num_clusters) {
    // Create the clusters
    Cluster* clusters = malloc(num_clusters * sizeof(Cluster));
    for (int i = 0; i < num_clusters; i++) {
        clusters[i] = *create_cluster((Point) {rand() % 100, rand() % 100});
    }
    
    // Assign each point to the closest cluster
    for (int i = 0; i < num_points; i++) {
        Cluster* closest_cluster = assign_point_to_cluster(&points[i], clusters, num_clusters);
        add_point_to_cluster(closest_cluster, &points[i]);
    }
    
    // Calculate the new centroids of the clusters
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].centroid = calculate_centroid(&clusters[i]);
    }
    
    // Repeat the previous two steps until the centroids no longer change
    int iterations = 0;
    while (1) {
        int num_changes = 0;
        
        // Assign each point to the closest cluster
        for (int i = 0; i < num_points; i++) {
            Cluster* closest_cluster = assign_point_to_cluster(&points[i], clusters, num_clusters);
            if (closest_cluster != assign_point_to_cluster(&points[i], clusters, num_clusters)) {
                num_changes++;
            }
            add_point_to_cluster(closest_cluster, &points[i]);
        }
        
        // Calculate the new centroids of the clusters
        for (int i = 0; i < num_clusters; i++) {
            clusters[i].centroid = calculate_centroid(&clusters[i]);
        }
        
        iterations++;
        
        // Break out of the loop if there are no more changes
        if (num_changes == 0) {
            break;
        }
    }
    
    // Print the final clusters
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("  (%f, %f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
    }
}

int main() {
    // Create the data points
    Point points[] = {
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8},
        {9, 10},
        {11, 12},
        {13, 14},
        {15, 16},
        {17, 18},
        {19, 20}
    };
    
    // Perform k-means clustering
    k_means_clustering(points, 10, 3);
    
    return 0;
}