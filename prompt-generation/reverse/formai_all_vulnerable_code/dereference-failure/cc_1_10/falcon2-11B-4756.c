//Falcon2-11B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <string.h>

#define MAX_CLUSTERS 10
#define MAX_CLUSTER_SIZE 100

typedef struct cluster {
    int size;
    int* elements;
} cluster_t;

void* cluster_sort(void* arg) {
    cluster_t* cluster = (cluster_t*) arg;

    int i;
    for (i = 0; i < cluster->size; i++) {
        printf("%d ", cluster->elements[i]);
    }
    printf("\n");

    return NULL;
}

void* cluster_merge(void* arg) {
    cluster_t* cluster1 = (cluster_t*) arg;
    cluster_t* cluster2 = (cluster_t*) malloc(sizeof(cluster_t));

    int i;
    for (i = 0; i < cluster1->size; i++) {
        cluster2->elements[i] = cluster1->elements[i];
    }

    cluster1->size += cluster2->size;
    free(cluster2);

    return NULL;
}

int main() {
    srand(time(NULL));

    int num_clusters = MAX_CLUSTERS;
    int num_elements = 1000;
    int* elements = (int*) malloc(sizeof(int) * num_elements);
    for (int i = 0; i < num_elements; i++) {
        elements[i] = rand() % 100;
    }

    cluster_t* clusters = (cluster_t*) malloc(sizeof(cluster_t) * num_clusters);
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].size = rand() % MAX_CLUSTER_SIZE;
        clusters[i].elements = (int*) malloc(sizeof(int) * clusters[i].size);
        for (int j = 0; j < clusters[i].size; j++) {
            clusters[i].elements[j] = rand() % num_elements;
        }
    }

    pthread_t threads[num_clusters];
    for (int i = 0; i < num_clusters; i++) {
        pthread_create(&threads[i], NULL, cluster_sort, (void*) &clusters[i]);
    }

    for (int i = 0; i < num_clusters; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_t merge_thread = pthread_self();
    pthread_detach(merge_thread);

    int num_merged_clusters = 0;
    cluster_t* merged_clusters = (cluster_t*) malloc(sizeof(cluster_t) * num_clusters);
    for (int i = 0; i < num_clusters; i++) {
        if (clusters[i].size > 1) {
            pthread_create(&merge_thread, NULL, cluster_merge, (void*) &clusters[i]);
            num_merged_clusters++;
        }
    }

    for (int i = 0; i < num_clusters; i++) {
        pthread_join(merge_thread, NULL);
    }

    for (int i = 0; i < num_merged_clusters; i++) {
        printf("Cluster %d: ", i + 1);
        for (int j = 0; j < merged_clusters[i].size; j++) {
            printf("%d ", merged_clusters[i].elements[j]);
        }
        printf("\n");
    }

    return 0;
}