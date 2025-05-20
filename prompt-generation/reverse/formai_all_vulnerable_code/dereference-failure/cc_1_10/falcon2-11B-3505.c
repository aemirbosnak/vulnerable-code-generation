//Falcon2-11B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_CLUSTERS 10

typedef struct cluster {
    int data_count;
    int* data;
    int* distances;
} cluster;

int compare_distance(const void* a, const void* b) {
    return ((cluster*)b)->distances[0] - ((cluster*)a)->distances[0];
}

int* init_clusters(int num_clusters, int* data, int data_size) {
    int* clusters = (int*)malloc(num_clusters * sizeof(int));
    for (int i = 0; i < num_clusters; i++) {
        clusters[i] = 0;
    }
    return clusters;
}

void print_clusters(int* clusters, int num_clusters, int* data, int data_size) {
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d: ", i);
        for (int j = 0; j < clusters[i]; j++) {
            printf("%d ", data[j]);
        }
        printf("\n");
    }
}

void init_cluster(cluster* cluster, int data_count, int* data) {
    cluster->data_count = data_count;
    cluster->data = (int*)malloc(data_count * sizeof(int));
    memcpy(cluster->data, data, data_count * sizeof(int));
    cluster->distances = (int*)malloc(data_count * sizeof(int));
    for (int i = 0; i < data_count; i++) {
        cluster->distances[i] = i;
    }
}

int* merge_clusters(cluster* clusters, int* clusters_count, int num_clusters, int data_size) {
    qsort(clusters_count, num_clusters, sizeof(int), compare_distance);
    int* merged_clusters = (int*)malloc(num_clusters * sizeof(int));
    for (int i = 0; i < num_clusters; i++) {
        int cluster_index = clusters_count[i];
        int cluster_data_count = clusters[cluster_index].data_count;
        int* cluster_data = clusters[cluster_index].data;
        int* cluster_distances = clusters[cluster_index].distances;
        merged_clusters[i] = cluster_data_count;
        int* merged_data = (int*)malloc(cluster_data_count * sizeof(int));
        for (int j = 0; j < cluster_data_count; j++) {
            int merged_index = cluster_distances[j];
            merged_data[j] = cluster_data[merged_index];
        }
        clusters[cluster_index].data_count = 0;
        clusters[cluster_index].data = NULL;
        clusters[cluster_index].distances = NULL;
        free(cluster_data);
        free(cluster_distances);
    }
    return merged_clusters;
}

void merge_clusters_recursive(cluster* clusters, int* clusters_count, int num_clusters, int data_size) {
    if (num_clusters == 1) {
        return;
    }
    int* merged_clusters = merge_clusters(clusters, clusters_count, num_clusters, data_size);
    clusters_count[0] += merged_clusters[0];
    for (int i = 1; i < num_clusters; i++) {
        clusters_count[i] = merged_clusters[i];
    }
    free(merged_clusters);
    merge_clusters_recursive(clusters, clusters_count, num_clusters / 2, data_size);
    merge_clusters_recursive(clusters, clusters_count, num_clusters / 2, data_size);
}

int main() {
    int num_clusters = 3;
    int num_data = 7;
    int data[7] = {1, 2, 3, 4, 5, 6, 7};
    int* clusters = init_clusters(num_clusters, data, num_data);
    for (int i = 0; i < num_clusters; i++) {
        init_cluster(clusters + i, num_data, data);
    }
    merge_clusters_recursive(clusters, clusters, num_clusters, num_data);
    print_clusters(clusters, num_clusters, data, num_data);
    return 0;
}