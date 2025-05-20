//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define NUM_POINTS 100
#define NUM_CLUSTERS 3
#define MAX_ITERATIONS 100

// data structure for a point in 2D space
typedef struct {
    double x;
    double y;
} point_t;

// data structure for a cluster
typedef struct {
    point_t centroid;
    point_t *points;
    int num_points;
} cluster_t;

// global variables
point_t *points;
cluster_t *clusters;
int num_iterations = 0;

// function to calculate the distance between two points
double distance(point_t p1, point_t p2) {
    double x_diff = p1.x - p2.x;
    double y_diff = p1.y - p2.y;
    return sqrt((x_diff * x_diff) + (y_diff * y_diff));
}

// function to initialize the clusters
void initialize_clusters() {
    int i;
    clusters = malloc(NUM_CLUSTERS * sizeof(cluster_t));
    for (i = 0; i < NUM_CLUSTERS; i++) {
        clusters[i].centroid = points[i];
        clusters[i].points = malloc(NUM_POINTS * sizeof(point_t));
        clusters[i].num_points = 0;
    }
}

// function to assign each point to the nearest cluster
void assign_clusters(int thread_num) {
    int i, j, closest_cluster;
    double min_distance, distance_to_cluster;
    for (i = thread_num; i < NUM_POINTS; i+=2) {
        min_distance = distance(points[i], clusters[0].centroid);
        closest_cluster = 0;
        for (j = 1; j < NUM_CLUSTERS; j++) {
            distance_to_cluster = distance(points[i], clusters[j].centroid);
            if (distance_to_cluster < min_distance) {
                min_distance = distance_to_cluster;
                closest_cluster = j;
            }
        }
        clusters[closest_cluster].points[clusters[closest_cluster].num_points++] = points[i];
    }
}

// function to update the clusters' centroids
void update_clusters(int thread_num) {
    int i, j;
    point_t sum;
    for (i = thread_num; i < NUM_CLUSTERS; i+=2) {
        sum.x = 0;
        sum.y = 0;
        for (j = 0; j < clusters[i].num_points; j++) {
            sum.x += clusters[i].points[j].x;
            sum.y += clusters[i].points[j].y;
        }
        clusters[i].centroid.x = sum.x / clusters[i].num_points;
        clusters[i].centroid.y = sum.y / clusters[i].num_points;
    }
}

// function to print the clusters' centroids and points
void print_clusters() {
    int i, j;
    for (i = 0; i < NUM_CLUSTERS; i++) {
        printf("Cluster %d Centroid: (%f, %f)\n", i, clusters[i].centroid.x, clusters[i].centroid.y);
        printf("Points:\n");
        for (j = 0; j < clusters[i].num_points; j++) {
            printf("(%f, %f) ", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }
}

// function to check if the clusters have converged or if we've reached the maximum number of iterations
int check_convergence() {
    int i;
    double distance_to_centroid;
    for (i = 0; i < NUM_CLUSTERS; i++) {
        distance_to_centroid = distance(clusters[i].centroid, points[i]);
        if (distance_to_centroid > 0.001) {
            return 0;
        }
    }
    return 1;
}

// thread function for calculating the clusters
void *calculate_clusters(void *arg) {
    int thread_num = *(int *)arg;
    while (num_iterations < MAX_ITERATIONS && check_convergence() == 0) {
        assign_clusters(thread_num);
        update_clusters(thread_num);
        num_iterations++;
    }
    pthread_exit(NULL);
}

int main() {
    // initialize points
    int i;
    points = malloc(NUM_POINTS * sizeof(point_t));
    for (i = 0; i < NUM_POINTS; i++) {
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;
    }

    // initialize clusters
    initialize_clusters();

    // create threads and calculate clusters
    pthread_t threads[NUM_CLUSTERS];
    int thread_args[NUM_CLUSTERS];
    for (i = 0; i < NUM_CLUSTERS; i++) {
        thread_args[i] = i;
        pthread_create(&threads[i], NULL, calculate_clusters, &thread_args[i]);
    }

    // wait for threads to finish
    for (i = 0; i < NUM_CLUSTERS; i++) {
        pthread_join(threads[i], NULL);
    }

    // print the clusters
    print_clusters();

    // free memory
    for (i = 0; i < NUM_CLUSTERS; i++) {
        free(clusters[i].points);
    }
    free(clusters);
    free(points);

    return 0;
}