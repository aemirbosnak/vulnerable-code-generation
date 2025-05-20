//Falcon2-11B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct cluster {
    int size;
    int* data;
    int num_clusters;
    int* cluster_ids;
} cluster;

void create_cluster(cluster* cluster, int* data, int num_clusters) {
    cluster->data = (int*)malloc(sizeof(int) * num_clusters);
    cluster->num_clusters = num_clusters;
    cluster->cluster_ids = (int*)malloc(sizeof(int) * num_clusters);

    int i, j;
    for (i = 0; i < num_clusters; i++) {
        cluster->cluster_ids[i] = i;
        cluster->data[i] = data[i];
    }
}

int get_nearest_cluster(cluster* clusters, int* data, int num_clusters, int* nearest_cluster) {
    int min_dist = 0, min_id = 0;
    for (int i = 0; i < num_clusters; i++) {
        int dist = 0;
        for (int j = 0; j < num_clusters; j++) {
            if (clusters[i].data[j]!= data[j]) {
                dist++;
            }
        }
        if (dist < min_dist) {
            min_dist = dist;
            min_id = i;
        }
    }
    *nearest_cluster = min_id;
    return min_dist;
}

void merge_clusters(cluster* clusters, int num_clusters, int* data, int* cluster_ids, int* merged_clusters) {
    int i, j, k;
    for (i = 0; i < num_clusters; i++) {
        for (j = i + 1; j < num_clusters; j++) {
            int dist = get_nearest_cluster(clusters, data, num_clusters, &merged_clusters[k]);
            if (dist == 0) {
                clusters[merged_clusters[k]].size += clusters[i].size + clusters[j].size;
                clusters[merged_clusters[k]].data = (int*)realloc(clusters[merged_clusters[k]].data, clusters[merged_clusters[k]].size * sizeof(int));
                clusters[merged_clusters[k]].cluster_ids = (int*)realloc(clusters[merged_clusters[k]].cluster_ids, clusters[merged_clusters[k]].size * sizeof(int));
                for (k = 0; k < clusters[i].size; k++) {
                    clusters[merged_clusters[k]].data[i] = data[k];
                }
                for (k = 0; k < clusters[j].size; k++) {
                    clusters[merged_clusters[k]].data[i + clusters[i].size] = data[k];
                }
                cluster_ids[i] = cluster_ids[j];
                free(clusters[i].data);
                free(clusters[i].cluster_ids);
                free(clusters[j].data);
                free(clusters[j].cluster_ids);
                free(clusters[i].data);
                free(clusters[i].cluster_ids);
                free(clusters[j].data);
                free(clusters[j].cluster_ids);
                clusters[i].data = NULL;
                clusters[i].cluster_ids = NULL;
                clusters[j].data = NULL;
                clusters[j].cluster_ids = NULL;
                clusters[i].size = 0;
                clusters[j].size = 0;
                clusters[i].num_clusters = 0;
                clusters[j].num_clusters = 0;
                clusters[merged_clusters[k]].data = clusters[i].data;
                clusters[merged_clusters[k]].cluster_ids = clusters[i].cluster_ids;
                clusters[merged_clusters[k]].size += clusters[i].size;
                clusters[merged_clusters[k]].num_clusters = clusters[i].num_clusters;
                clusters[merged_clusters[k]].cluster_ids = clusters[i].cluster_ids;
                clusters[merged_clusters[k]].num_clusters = clusters[i].num_clusters;
                clusters[merged_clusters[k]].size += clusters[j].size;
                clusters[merged_clusters[k]].data = (int*)realloc(clusters[merged_clusters[k]].data, clusters[merged_clusters[k]].size * sizeof(int));
                clusters[merged_clusters[k]].cluster_ids = (int*)realloc(clusters[merged_clusters[k]].cluster_ids, clusters[merged_clusters[k]].size * sizeof(int));
                for (k = 0; k < clusters[j].size; k++) {
                    clusters[merged_clusters[k]].data[i + clusters[i].size] = data[k];
                }
                clusters[merged_clusters[k]].size += clusters[j].size;
                clusters[merged_clusters[k]].num_clusters += 1;
            }
        }
    }
}

void print_clusters(cluster* clusters, int num_clusters) {
    int i;
    printf("Clusters:\n");
    for (i = 0; i < num_clusters; i++) {
        printf("Cluster %d: ", i);
        for (int j = 0; j < clusters[i].size; j++) {
            printf("%d ", clusters[i].data[j]);
        }
        printf("\n");
    }
}

int main() {
    int data[MAX_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int num_clusters = 3;
    cluster clusters[num_clusters];
    create_cluster(clusters, data, num_clusters);
    print_clusters(clusters, num_clusters);

    int merged_clusters[num_clusters];
    merge_clusters(clusters, num_clusters, data, clusters[0].cluster_ids, merged_clusters);
    print_clusters(clusters, num_clusters);

    return 0;
}