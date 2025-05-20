//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 10
#define MAX_ITERATIONS 100

typedef struct {
    double x;
    double y;
    int cluster_id;
} DataPoint;

typedef struct {
    double x;
    double y;
} Centroid;

int num_points = 0;
int num_clusters = 0;

void read_data(const char *filename, DataPoint points[]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file.\n");
        exit(EXIT_FAILURE);
    }
    while (fscanf(file, "%lf %lf", &points[num_points].x, &points[num_points].y) == 2) {
        points[num_points].cluster_id = -1; // Initialize cluster ID
        num_points++;
    }
    fclose(file);
}

double euclidean_distance(DataPoint p, Centroid c) {
    return sqrt(pow(p.x - c.x, 2) + pow(p.y - c.y, 2));
}

void initialize_centroids(Centroid centroids[], DataPoint points[]) {
    srand(time(0)); // Seed for random generation
    for (int i = 0; i < num_clusters; i++) {
        int random_index = rand() % num_points;
        centroids[i] = (Centroid){points[random_index].x, points[random_index].y};
    }
}

void assign_clusters(DataPoint points[], Centroid centroids[]) {
    for (int i = 0; i < num_points; i++) {
        double min_distance = INFINITY;
        int nearest_cluster = -1;

        for (int j = 0; j < num_clusters; j++) {
            double distance = euclidean_distance(points[i], centroids[j]);
            if (distance < min_distance) {
                min_distance = distance;
                nearest_cluster = j;
            }
        }
        points[i].cluster_id = nearest_cluster;
    }
}

void update_centroids(DataPoint points[], Centroid centroids[]) {
    double sum_x[MAX_CLUSTERS] = {0};
    double sum_y[MAX_CLUSTERS] = {0};
    int count[MAX_CLUSTERS] = {0};

    for (int i = 0; i < num_points; i++) {
        int cluster_id = points[i].cluster_id;
        sum_x[cluster_id] += points[i].x;
        sum_y[cluster_id] += points[i].y;
        count[cluster_id]++;
    }

    for (int j = 0; j < num_clusters; j++) {
        if (count[j] > 0) {
            centroids[j].x = sum_x[j] / count[j];
            centroids[j].y = sum_y[j] / count[j];
        }
    }
}

void print_results(DataPoint points[], Centroid centroids[]) {
    for (int i = 0; i < num_points; i++) {
        printf("Point(%.2f, %.2f) is in cluster %d\n", points[i].x, points[i].y, points[i].cluster_id);
    }
    printf("\nCentroids:\n");
    for (int j = 0; j < num_clusters; j++) {
        printf("Centroid %d: (%.2f, %.2f)\n", j, centroids[j].x, centroids[j].y);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <data_file> <number_of_clusters>\n", argv[0]);
        return EXIT_FAILURE;
    }

    num_clusters = atoi(argv[2]);
    if (num_clusters < 1 || num_clusters > MAX_CLUSTERS) {
        fprintf(stderr, "Number of clusters must be between 1 and %d\n", MAX_CLUSTERS);
        return EXIT_FAILURE;
    }

    DataPoint points[MAX_POINTS];
    Centroid centroids[MAX_CLUSTERS];

    read_data(argv[1], points);

    initialize_centroids(centroids, points);

    for (int iteration = 0; iteration < MAX_ITERATIONS; iteration++) {
        assign_clusters(points, centroids);
        update_centroids(points, centroids);
    }

    print_results(points, centroids);

    return EXIT_SUCCESS;
}