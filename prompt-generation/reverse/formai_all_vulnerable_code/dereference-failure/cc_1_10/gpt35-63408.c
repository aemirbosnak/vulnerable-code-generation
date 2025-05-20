//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 1000 //number of data points
#define K 4 //number of clusters
#define DIM 2 //dimension of space
#define MAX_ITERATIONS 100 //maximum number of iterations

typedef struct {
    double* coordinates;
    int label; //cluster label
} DataPoint;

typedef struct {
    double* centroid;
    int size; //number of points in the cluster
    DataPoint* points; //points in the cluster
} Cluster;

double distance(double* p1, double* p2, int dim) {
    double dist = 0;
    for (int i = 0; i < dim; i++) {
        dist += pow(p1[i] - p2[i], 2);
    }
    return sqrt(dist);
}

void init_centroids(DataPoint* data, Cluster* clusters, int n, int k, int dim) {
    //randomly select k points as initial centroids
    int* used = calloc(n, sizeof(int));
    for (int i = 0; i < k; i++) {
        int index;
        do {
            index = rand() % n;
        } while (used[index]);
        used[index] = 1;
        for (int j = 0; j < dim; j++) {
            clusters[i].centroid[j] = data[index].coordinates[j];
        }
        clusters[i].size = 0;
    }
    free(used);
}

void assign_points(DataPoint* data, Cluster* clusters, int n, int k, int dim) {
    //assign each point to the closest centroid
    for (int i = 0; i < n; i++) {
        double min_distance = INFINITY;
        int cluster_index = -1;
        for (int j = 0; j < k; j++) {
            double d = distance(data[i].coordinates, clusters[j].centroid, dim);
            if (d < min_distance) {
                min_distance = d;
                cluster_index = j;
            }
        }
        data[i].label = cluster_index;
        clusters[cluster_index].size++;
    }
    //allocate memory for points in each cluster
    for (int i = 0; i < k; i++) {
        clusters[i].points = malloc(clusters[i].size * sizeof(DataPoint));
    }
    //populate points array for each cluster
    int* cluster_sizes = calloc(k, sizeof(int));
    for (int i = 0; i < n; i++) {
        int cluster_index = data[i].label;
        clusters[cluster_index].points[cluster_sizes[cluster_index]] = data[i];
        cluster_sizes[cluster_index]++;
    }
    free(cluster_sizes);
}

void update_centroids(Cluster* clusters, int k, int dim) {
    //calculate new centroid for each cluster
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < dim; j++) {
            double sum = 0;
            for (int l = 0; l < clusters[i].size; l++) {
                sum += clusters[i].points[l].coordinates[j];
            }
            clusters[i].centroid[j] = sum / clusters[i].size;
        }
    }
}

void print_clusters(Cluster* clusters, int k, int dim) {
    for (int i = 0; i < k; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < clusters[i].size; j++) {
            printf("(%lf", clusters[i].points[j].coordinates[0]);
            for (int l = 1; l < dim; l++) {
                printf(", %lf", clusters[i].points[j].coordinates[l]);
            }
            printf(")\n");
        }
        printf("Centroid: (%lf", clusters[i].centroid[0]);
        for (int j = 1; j < dim; j++) {
            printf(", %lf", clusters[i].centroid[j]);
        }
        printf(")\n\n");
    }
}

int main() {
    srand(time(NULL));

    DataPoint* data = malloc(N * sizeof(DataPoint));
    for (int i = 0; i < N; i++) {
        data[i].coordinates = malloc(DIM * sizeof(double));
        for (int j = 0; j < DIM; j++) {
            data[i].coordinates[j] = ((double)rand() / RAND_MAX) * 10;
        }
    }

    Cluster* clusters = malloc(K * sizeof(Cluster));
    for (int i = 0; i < K; i++) {
        clusters[i].centroid = malloc(DIM * sizeof(double));
    }

    init_centroids(data, clusters, N, K, DIM);

    int iteration = 0;
    while (iteration < MAX_ITERATIONS) {
        assign_points(data, clusters, N, K, DIM);
        update_centroids(clusters, K, DIM);
        iteration++;
    }

    print_clusters(clusters, K, DIM);

    for (int i = 0; i < N; i++) {
        free(data[i].coordinates);
    }
    free(data);
    for (int i = 0; i < K; i++) {
        free(clusters[i].centroid);
        free(clusters[i].points);
    }
    free(clusters);

    return 0;
}