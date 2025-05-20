//Falcon2-11B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int weight;
} Node;

typedef struct {
    Node *data;
    int num_nodes;
    int max_weight;
    int *pivot;
    int *cluster_count;
} Cluster;

void merge_clusters(Cluster *a, Cluster *b) {
    int i, j, k;
    int *temp = (int *)malloc(sizeof(int) * MAX_SIZE);
    for (i = 0; i < MAX_SIZE; i++) {
        temp[i] = 0;
    }
    a->num_nodes += b->num_nodes;
    a->max_weight += b->max_weight;
    for (i = 0; i < b->num_nodes; i++) {
        a->data[i].data = b->data[i].data;
        a->data[i].weight = b->data[i].weight;
        temp[b->data[i].data]++;
    }
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < temp[i]; j++) {
            for (k = 0; k < a->num_nodes; k++) {
                if (a->data[k].data == i) {
                    a->data[k].weight += b->data[j].weight;
                }
            }
        }
    }
    free(b->data);
    free(b);
    free(temp);
}

void cluster_data(Node *data, int num_nodes, int *pivot, int *cluster_count) {
    Cluster *clusters = (Cluster *)malloc(sizeof(Cluster) * num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        clusters[i].data = (Node *)malloc(sizeof(Node));
        clusters[i].num_nodes = 0;
        clusters[i].max_weight = 0;
        clusters[i].pivot = (int *)malloc(sizeof(int) * MAX_SIZE);
        clusters[i].cluster_count = (int *)malloc(sizeof(int) * MAX_SIZE);
        clusters[i].data->data = data[i].data;
        clusters[i].data->weight = data[i].weight;
        for (int j = i + 1; j < num_nodes; j++) {
            if (data[j].data == data[i].data) {
                clusters[i].num_nodes++;
                clusters[i].max_weight += data[j].weight;
            } else {
                clusters[j].num_nodes++;
                clusters[j].max_weight += data[j].weight;
            }
        }
    }
    for (int i = 0; i < num_nodes; i++) {
        for (int j = i + 1; j < num_nodes; j++) {
            if (clusters[i].num_nodes < clusters[j].num_nodes) {
                merge_clusters(&clusters[i], &clusters[j]);
            } else if (clusters[i].num_nodes == clusters[j].num_nodes) {
                if (clusters[i].max_weight < clusters[j].max_weight) {
                    merge_clusters(&clusters[i], &clusters[j]);
                } else if (clusters[i].max_weight == clusters[j].max_weight) {
                    if (clusters[i].pivot[clusters[j].pivot[clusters[i].num_nodes - 1]] > clusters[j].pivot[clusters[i].pivot[clusters[i].num_nodes - 1]]) {
                        merge_clusters(&clusters[i], &clusters[j]);
                    } else {
                        merge_clusters(&clusters[j], &clusters[i]);
                    }
                }
            }
        }
    }
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < clusters[i].num_nodes; j++) {
            cluster_count[clusters[i].data[j].data]++;
        }
    }
    free(clusters);
}

int main() {
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int num_nodes = sizeof(data) / sizeof(data[0]);
    int pivot = rand() % num_nodes;
    int *cluster_count = (int *)malloc(sizeof(int) * MAX_SIZE);
    cluster_data(data, num_nodes, &pivot, cluster_count);
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", cluster_count[i]);
    }
    printf("\n");
    return 0;
}