//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_X 20
#define MAX_Y 20
#define MAX_CLUSTERS 3
#define MAX_ITERATIONS 500

// Generate random points
void generate_points(int num_points, int points[MAX_X][MAX_Y]) {
    for (int i = 0; i < num_points; i++) {
        points[i][0] = rand() % MAX_X;
        points[i][1] = rand() % MAX_Y;
    }
}

// Initialize clusters randomly
void initialize_clusters(int clusters[MAX_CLUSTERS][2], int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        clusters[i][0] = rand() % MAX_X;
        clusters[i][1] = rand() % MAX_Y;
    }
}

// Calculate Euclidean distance between two points
int euclidean_distance(int x1, int y1, int x2, int y2) {
    return ((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2));
}

// Assign points to nearest cluster
void assign_points_to_clusters(int num_points, int points[MAX_X][MAX_Y], int num_clusters, int clusters[MAX_CLUSTERS][2], int cluster_assignments[num_points]) {
    for (int i = 0; i < num_points; i++) {
        int min_distance = __INT_MAX__;
        int nearest_cluster = -1;
        for (int j = 0; j < num_clusters; j++) {
            int distance = euclidean_distance(points[i][0], points[i][1], clusters[j][0], clusters[j][1]);
            if (distance < min_distance) {
                min_distance = distance;
                nearest_cluster = j;
            }
        }
        cluster_assignments[i] = nearest_cluster;
    }
}

// Re-calculate cluster centers as the average of points assigned to it
void recalculate_clusters(int num_points, int points[MAX_X][MAX_Y], int num_clusters, int clusters[MAX_CLUSTERS][2], int cluster_assignments[num_points]) {
    int num_points_in_cluster[MAX_CLUSTERS] = {0};
    int sum_x[MAX_CLUSTERS] = {0};
    int sum_y[MAX_CLUSTERS] = {0};
    for (int i = 0; i < num_points; i++) {
        int cluster = cluster_assignments[i];
        num_points_in_cluster[cluster]++;
        sum_x[cluster] += points[i][0];
        sum_y[cluster] += points[i][1];
    }
    for (int j = 0; j < num_clusters; j++) {
        if (num_points_in_cluster[j] > 0) {
            clusters[j][0] = sum_x[j] / num_points_in_cluster[j];
            clusters[j][1] = sum_y[j] / num_points_in_cluster[j];
        }
    }
}

// Print the assignment of points to clusters
void print_cluster_assignments(int num_points, int cluster_assignments[num_points]) {
    printf("Cluster assignments:\n");
    for (int i = 0; i < num_points; i++) {
        printf("%d ", cluster_assignments[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int num_points = 50;
    int points[MAX_X][MAX_Y];
    generate_points(num_points, points);
    int num_clusters = 3;
    int clusters[MAX_CLUSTERS][2];
    initialize_clusters(clusters, num_clusters);
    int cluster_assignments[num_points];
    printf("Initial cluster centers:\n");
    for (int i = 0; i < num_clusters; i++) {
        printf("(%d,%d) ", clusters[i][0], clusters[i][1]);
    }
    printf("\n");
    for (int i = 0; i < MAX_ITERATIONS; i++) {
        assign_points_to_clusters(num_points, points, num_clusters, clusters, cluster_assignments);
        recalculate_clusters(num_points, points, num_clusters, clusters, cluster_assignments);
    }
    print_cluster_assignments(num_points, cluster_assignments);
    return 0;
}