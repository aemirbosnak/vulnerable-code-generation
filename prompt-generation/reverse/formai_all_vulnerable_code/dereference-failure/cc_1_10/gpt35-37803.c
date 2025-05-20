//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// define some funny colors to distinguish clusters
#define YELLOW "\033[1;33m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define RESET "\033[0m"

// define the number of clusters
#define NUM_CLUSTERS 4

// define the data structure to represent a point
typedef struct Point {
    float x;
    float y;
} Point;

// define the data structure to represent a cluster
typedef struct Cluster {
    Point centroid;
    Point *points;
    size_t size;
} Cluster;

// function to calculate the distance between two points
float distance(Point *a, Point *b) {
    float dx = a->x - b->x;
    float dy = a->y - b->y;

    return sqrt(dx*dx + dy*dy);
}

// function to initialize clusters randomly
void initialize_clusters(Point *points, size_t size, Cluster *clusters, size_t num_clusters) {
    for (size_t c = 0; c < num_clusters; c++) {
        clusters[c].centroid.x = rand() % 100;
        clusters[c].centroid.y = rand() % 100;
        clusters[c].points = malloc(size * sizeof(Point));
        clusters[c].size = 0;
    }

    for (size_t i = 0; i < size; i++) {
        int c = rand() % num_clusters;
        clusters[c].points[clusters[c].size] = points[i];
        clusters[c].size++;
    }
}

// function to update the centroids of clusters
void update_cluster_centroids(Cluster *clusters, size_t num_clusters) {
    for (size_t c = 0; c < num_clusters; c++) {
        // calculate the average coordinates of all the points in the cluster
        float sum_x = 0.0;
        float sum_y = 0.0;

        for (size_t i = 0; i < clusters[c].size; i++) {
            sum_x += clusters[c].points[i].x;
            sum_y += clusters[c].points[i].y;
        }

        clusters[c].centroid.x = sum_x / clusters[c].size;
        clusters[c].centroid.y = sum_y / clusters[c].size;
    }
}

// function to assign each point to its closest cluster
void assign_points_to_clusters(Point *points, size_t size, Cluster *clusters, size_t num_clusters) {
    for (size_t i = 0; i < size; i++) {
        float min_distance = distance(&points[i], &clusters[0].centroid);
        size_t min_cluster = 0;

        for (size_t c = 1; c < num_clusters; c++) {
            float d = distance(&points[i], &clusters[c].centroid);

            if (d < min_distance) {
                min_distance = d;
                min_cluster = c;
            }
        }

        clusters[min_cluster].points[clusters[min_cluster].size] = points[i];
        clusters[min_cluster].size++;
    }
}

// function to print the clusters in a funny way
void print_clusters(Cluster *clusters, size_t num_clusters) {
    for (size_t c = 0; c < num_clusters; c++) {
        printf(YELLOW "Cluster %zu: centroid = (%.2f, %.2f)" RESET, c+1, clusters[c].centroid.x, clusters[c].centroid.y);
        printf("\n");

        for (size_t i = 0; i < clusters[c].size; i++) {
            printf(BLUE "    Point %zu: (%.2f, %.2f)" RESET, i+1, clusters[c].points[i].x, clusters[c].points[i].y);
            printf("\n");
        }

        printf(GREEN "    Size = %zu" RESET, clusters[c].size);
        printf(MAGENTA "\n\n");
    }
}

int main() {
    srand(time(NULL));

    // define some points randomly
    Point points[] = {
        {10.0, 20.0},
        {30.0, 40.0},
        {50.0, 60.0},
        {70.0, 80.0},
        {90.0, 100.0}
    };

    size_t size = sizeof(points) / sizeof(points[0]);

    // initialize clusters randomly
    Cluster clusters[NUM_CLUSTERS];
    initialize_clusters(points, size, clusters, NUM_CLUSTERS);

    // print the initial state of the clusters
    printf("Initial state of clusters:\n");
    print_clusters(clusters, NUM_CLUSTERS);

    // perform clustering
    for (int i = 0; i < 10; i++) {
        // assign each point to its closest cluster
        assign_points_to_clusters(points, size, clusters, NUM_CLUSTERS);

        // update the centroids of the clusters
        update_cluster_centroids(clusters, NUM_CLUSTERS);

        // print the state of the clusters after each iteration
        printf("State of clusters after iteration %d:\n", i+1);
        print_clusters(clusters, NUM_CLUSTERS);
    }

    // free memory allocated for points in each cluster
    for (size_t c = 0; c < NUM_CLUSTERS; c++) {
        free(clusters[c].points);
    }

    return 0;
}