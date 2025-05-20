//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

typedef struct Cluster {
    int idx;
    struct Cluster* next;
    double avg_dist;
    double* data;
} Cluster;

void insert_cluster(Cluster** head, int idx, double* data) {
    Cluster* new_node = (Cluster*)malloc(sizeof(Cluster));
    new_node->idx = idx;
    new_node->next = NULL;
    new_node->avg_dist = 0.0;
    new_node->data = data;

    if (*head == NULL) {
        *head = new_node;
    } else {
        (*head)->next = new_node;
    }
}

void calculate_avg_dist(Cluster* head) {
    while (head) {
        double total_dist = 0.0;
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                if (i != j) {
                    double dist = sqrt(pow(head->data[i] - head->data[j], 2) + pow(head->data[i] - head->data[j], 2));
                    total_dist += dist;
                }
            }
        }
        head->avg_dist = total_dist / (MAX * (MAX - 1));
        head = head->next;
    }
}

int main() {
    Cluster* head = NULL;
    insert_cluster(&head, 0, (double*)malloc(MAX * sizeof(double)));
    insert_cluster(&head, 1, (double*)malloc(MAX * sizeof(double)));
    insert_cluster(&head, 2, (double*)malloc(MAX * sizeof(double)));

    calculate_avg_dist(head);

    for (Cluster* cluster = head; cluster; cluster = cluster->next) {
        printf("Cluster %d has an average distance of %.2lf\n", cluster->idx, cluster->avg_dist);
    }

    return 0;
}