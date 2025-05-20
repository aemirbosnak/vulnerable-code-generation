//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point* points;
    int num_points;
} Dataset;

typedef struct {
    Point centroid;
    int num_assigned_points;
} Cluster;

Dataset* create_dataset(int num_points) {
    Dataset* dataset = (Dataset*)malloc(sizeof(Dataset));
    dataset->points = (Point*)malloc(sizeof(Point) * num_points);
    dataset->num_points = num_points;

    for (int i = 0; i < num_points; i++) {
        dataset->points[i].x = (double)rand() / RAND_MAX;
        dataset->points[i].y = (double)rand() / RAND_MAX;
    }

    return dataset;
}

void free_dataset(Dataset* dataset) {
    free(dataset->points);
    free(dataset);
}

Cluster* create_cluster(Point centroid) {
    Cluster* cluster = (Cluster*)malloc(sizeof(Cluster));
    cluster->centroid = centroid;
    cluster->num_assigned_points = 0;

    return cluster;
}

void free_cluster(Cluster* cluster) {
    free(cluster);
}

double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

void assign_points_to_clusters(Dataset* dataset, Cluster* clusters, int num_clusters) {
    for (int i = 0; i < dataset->num_points; i++) {
        Point point = dataset->points[i];

        double min_distance = INFINITY;
        Cluster* closest_cluster = NULL;

        for (int j = 0; j < num_clusters; j++) {
            Cluster* cluster = &clusters[j];

            double distance_to_centroid = distance(point, cluster->centroid);

            if (distance_to_centroid < min_distance) {
                min_distance = distance_to_centroid;
                closest_cluster = cluster;
            }
        }

        closest_cluster->num_assigned_points++;
    }
}

void update_centroids(Dataset* dataset, Cluster* clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        Cluster* cluster = &clusters[i];

        cluster->centroid.x = 0;
        cluster->centroid.y = 0;

        for (int j = 0; j < dataset->num_points; j++) {
            Point point = dataset->points[j];

            if (distance(point, cluster->centroid) < INFINITY) {
                cluster->centroid.x += point.x;
                cluster->centroid.y += point.y;
            }
        }

        cluster->centroid.x /= cluster->num_assigned_points;
        cluster->centroid.y /= cluster->num_assigned_points;
    }
}

int main() {
    int num_points = 1000;
    int num_clusters = 3;

    Dataset* dataset = create_dataset(num_points);

    Cluster* clusters = (Cluster*)malloc(sizeof(Cluster) * num_clusters);

    for (int i = 0; i < num_clusters; i++) {
        Point centroid = { (double)rand() / RAND_MAX, (double)rand() / RAND_MAX };
        clusters[i] = *create_cluster(centroid);
    }

    int num_iterations = 10;

    for (int i = 0; i < num_iterations; i++) {
        assign_points_to_clusters(dataset, clusters, num_clusters);
        update_centroids(dataset, clusters, num_clusters);
    }

    for (int i = 0; i < num_clusters; i++) {
        Cluster* cluster = &clusters[i];

        printf("Cluster %d:\n", i);
        printf("  Centroid: (%f, %f)\n", cluster->centroid.x, cluster->centroid.y);
        printf("  Number of assigned points: %d\n", cluster->num_assigned_points);
    }

    free_dataset(dataset);
    for (int i = 0; i < num_clusters; i++) {
        free_cluster(&clusters[i]);
    }
    free(clusters);

    return 0;
}