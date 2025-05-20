//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_POINTS 10

// Define the struct for a point
typedef struct {
    double x;
    double y;
} Point;

// Define the struct for a cluster
typedef struct {
    Point centroid;
    Point *points;
    int num_points;
} Cluster;

// Function to calculate the distance between two points
double distance(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

// Function to initialize a new cluster with a given centroid point
Cluster *initialize_cluster(Point centroid) {
    Cluster *cluster = malloc(sizeof(Cluster));
    cluster->centroid = centroid;
    cluster->points = malloc(NUM_POINTS * sizeof(Point)); // Assume maximum points per cluster is NUM_POINTS
    cluster->num_points = 0;
    return cluster;
}

// Function to add a point to a given cluster
void add_point_to_cluster(Cluster *cluster, Point point) {
    cluster->points[cluster->num_points] = point;
    cluster->num_points++;
}

// Function to remove all points from a given cluster
void clear_cluster(Cluster *cluster) {
    cluster->num_points = 0;
}

// Function to update the centroid of a given cluster based on its current points
void update_cluster_centroid(Cluster *cluster) {
    double sum_x = 0, sum_y = 0;
    for (int i = 0; i < cluster->num_points; i++) {
        sum_x += cluster->points[i].x;
        sum_y += cluster->points[i].y;
    }
    cluster->centroid.x = sum_x / cluster->num_points;
    cluster->centroid.y = sum_y / cluster->num_points;
}

// Function to print the details of a given cluster
void print_cluster(Cluster *cluster) {
    printf("Centroid: (%f, %f)\n", cluster->centroid.x, cluster->centroid.y);
    printf("Points: ");
    for (int i = 0; i < cluster->num_points; i++) {
        printf("(%f, %f) ", cluster->points[i].x, cluster->points[i].y);
    }
    printf("\n");
}

int main() {
    // Initialize some sample points
    Point points[NUM_POINTS];
    points[0] = (Point){1, 2};
    points[1] = (Point){2, 3};
    points[2] = (Point){3, 4};
    points[3] = (Point){4, 5};
    points[4] = (Point){5, 6};
    points[5] = (Point){6, 7};
    points[6] = (Point){7, 8};
    points[7] = (Point){8, 9};
    points[8] = (Point){9, 10};
    points[9] = (Point){10, 11};

    // Initialize two clusters with the first two points as centroids
    Cluster *cluster1 = initialize_cluster(points[0]);
    Cluster *cluster2 = initialize_cluster(points[1]);

    // Assign each point to its nearest cluster
    for (int i = 2; i < NUM_POINTS; i++) {
        Point point = points[i];
        double dist1 = distance(point, cluster1->centroid);
        double dist2 = distance(point, cluster2->centroid);
        if (dist1 < dist2) {
            add_point_to_cluster(cluster1, point);
        } else {
            add_point_to_cluster(cluster2, point);
        }
    }

    // Print the initial clusters
    printf("Initial Clusters:\n");
    print_cluster(cluster1);
    print_cluster(cluster2);

    // Assign each point to its nearest cluster again, until convergence
    while (true) {
        bool has_changed = false;

        for (int i = 0; i < NUM_POINTS; i++) {
            Point point = points[i];
            double dist1 = distance(point, cluster1->centroid);
            double dist2 = distance(point, cluster2->centroid);

            // Re-assign the point if it is closer to the other cluster
            if (dist1 < dist2 && cluster1->num_points > 1) {
                clear_cluster(cluster2);
                add_point_to_cluster(cluster1, point);
                has_changed = true;
            } else if (dist2 < dist1 && cluster2->num_points > 1) {
                clear_cluster(cluster1);
                add_point_to_cluster(cluster2, point);
                has_changed = true;
            }
        }

        // If no points were re-assigned, then clustering is converged
        if (!has_changed) {
            break;
        }

        // Update the centroid of each cluster
        update_cluster_centroid(cluster1);
        update_cluster_centroid(cluster2);
    }

    // Print the final clusters
    printf("Final Clusters:\n");
    print_cluster(cluster1);
    print_cluster(cluster2);

    return 0;
}