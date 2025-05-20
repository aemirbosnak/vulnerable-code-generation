//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_CLUSTER_NUM 10

typedef struct Cluster {
    int cluster_id;
    double avg_distance;
    struct Cluster *next;
} Cluster;

Cluster *insert_cluster(Cluster *head, int cluster_id, double avg_distance) {
    Cluster *new_cluster = (Cluster *)malloc(sizeof(Cluster));
    new_cluster->cluster_id = cluster_id;
    new_cluster->avg_distance = avg_distance;
    new_cluster->next = NULL;

    if (head == NULL) {
        head = new_cluster;
    } else {
        Cluster *last_cluster = head;
        while (last_cluster->next) {
            last_cluster = last_cluster->next;
        }
        last_cluster->next = new_cluster;
    }

    return head;
}

void print_clusters(Cluster *head) {
    Cluster *curr_cluster = head;
    while (curr_cluster) {
        printf("Cluster ID: %d, Avg Distance: %.2lf\n", curr_cluster->cluster_id, curr_cluster->avg_distance);
        curr_cluster = curr_cluster->next;
    }
}

int main() {
    Cluster *head = NULL;

    // Insert some clusters
    insert_cluster(head, 1, 5.0);
    insert_cluster(head, 2, 3.0);
    insert_cluster(head, 3, 7.0);
    insert_cluster(head, 4, 4.0);

    // Print the clusters
    print_clusters(head);

    return 0;
}