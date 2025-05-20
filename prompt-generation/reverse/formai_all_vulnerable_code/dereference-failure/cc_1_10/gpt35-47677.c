//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point {
    double x;
    double y;
} Point;

typedef struct cluster {
    Point centroid;
    int num_points;
    Point *points;
} Cluster;

double euclidean_distance(Point p1, Point p2) {
    double x_diff = p1.x - p2.x;
    double y_diff = p1.y - p2.y;
    double distance = sqrt((x_diff * x_diff) + (y_diff * y_diff));
    return distance;
}

double compute_mean_distance(Cluster cluster) {
    double sum_distances = 0;
    for (int i = 0; i < cluster.num_points; i++) {
        Point current_point = cluster.points[i];
        double current_distance = euclidean_distance(cluster.centroid, current_point);
        sum_distances += current_distance;
    }
    double mean_distance = sum_distances / cluster.num_points;
    return mean_distance;
}

void assign_points_to_clusters(Cluster *clusters, int num_clusters, Point *points, int num_points) {
    for (int i = 0; i < num_points; i++) {
        Point current_point = points[i];
        double min_distance = INFINITY;
        int nearest_cluster_index = -1;
        for (int j = 0; j < num_clusters; j++) {
            Cluster current_cluster = clusters[j];
            double current_distance = euclidean_distance(current_point, current_cluster.centroid);
            if (current_distance < min_distance) {
                min_distance = current_distance;
                nearest_cluster_index = j;
            }
        }
        clusters[nearest_cluster_index].points[clusters[nearest_cluster_index].num_points++] = current_point;
    }
}

void update_cluster_centroids(Cluster *clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        Cluster current_cluster = clusters[i];
        Point new_centroid = {0, 0};
        for (int j = 0; j < current_cluster.num_points; j++) {
            Point current_point = current_cluster.points[j];
            new_centroid.x += current_point.x;
            new_centroid.y += current_point.y;
        }
        new_centroid.x /= current_cluster.num_points;
        new_centroid.y /= current_cluster.num_points;
        current_cluster.centroid = new_centroid;
        current_cluster.num_points = 0;
    }
}

void print_clusters(Cluster *clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i + 1);
        Cluster current_cluster = clusters[i];
        printf("Centroid: (%.2lf, %.2lf)\n", current_cluster.centroid.x, current_cluster.centroid.y);
        printf("Points:\n");
        for (int j = 0; j < current_cluster.num_points; j++) {
            Point current_point = current_cluster.points[j];
            printf("(%.2lf, %.2lf)\n", current_point.x, current_point.y);
        }
        printf("\n");
    }
}

void k_means_clustering(Point *points, int num_points, int num_clusters) {
    Cluster *clusters = malloc(num_clusters * sizeof(Cluster));
    for (int i = 0; i < num_clusters; i++) {
        int random_point_index = rand() % num_points;
        Point random_point = points[random_point_index];
        Cluster new_cluster = {
            .centroid = random_point,
            .num_points = 0,
            .points = malloc(num_points * sizeof(Point))
        };
        clusters[i] = new_cluster;
    }
    assign_points_to_clusters(clusters, num_clusters, points, num_points);
    double current_mean_distance = 0;
    double previous_mean_distance = INFINITY;
    while (fabs(current_mean_distance - previous_mean_distance) > 0.01) {
        previous_mean_distance = current_mean_distance;
        for (int i = 0; i < num_clusters; i++) {
            Cluster current_cluster = clusters[i];
            double mean_distance = compute_mean_distance(current_cluster);
            current_mean_distance += mean_distance;
        }
        update_cluster_centroids(clusters, num_clusters);
        assign_points_to_clusters(clusters, num_clusters, points, num_points);
    }
    print_clusters(clusters, num_clusters);
    for (int i = 0; i < num_clusters; i++) {
        free(clusters[i].points);
    }
    free(clusters);
}

int main() {
    Point points[] = {
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
    int num_points = sizeof(points) / sizeof(Point);
    int num_clusters = 3;
    k_means_clustering(points, num_points, num_clusters);
    return 0;
}