//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_CLUSTERS 10

typedef struct Cluster {
    int members[MAX_CLUSTERS];
    int cluster_num;
    struct Cluster* next;
} Cluster;

void insert_cluster(Cluster** head, int member, int cluster_num) {
    Cluster* new_cluster = malloc(sizeof(Cluster));
    new_cluster->members[0] = member;
    new_cluster->cluster_num = cluster_num;
    new_cluster->next = NULL;

    if (*head == NULL) {
        *head = new_cluster;
    } else {
        (*head)->next = new_cluster;
    }
}

void print_clusters(Cluster* head) {
    while (head) {
        printf("Cluster %d: ", head->cluster_num);
        for (int i = 0; i < MAX_CLUSTERS; i++) {
            if (head->members[i] != -1) {
                printf("%d ", head->members[i]);
            }
        }
        printf("\n");
        head = head->next;
    }
}

int main() {
    Cluster* head = NULL;

    insert_cluster(&head, 10, 1);
    insert_cluster(&head, 12, 1);
    insert_cluster(&head, 14, 1);
    insert_cluster(&head, 16, 2);
    insert_cluster(&head, 18, 2);
    insert_cluster(&head, 20, 2);

    print_clusters(head);

    return 0;
}