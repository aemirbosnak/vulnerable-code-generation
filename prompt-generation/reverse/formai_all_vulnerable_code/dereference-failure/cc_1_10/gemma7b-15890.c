//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Cluster {
    Node* head;
    int cluster_id;
} Cluster;

void insert_node(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
        *head = newNode;
    }
}

void create_cluster(Cluster** cluster, int cluster_id) {
    *cluster = (Cluster*)malloc(sizeof(Cluster));
    (*cluster)->head = NULL;
    (*cluster)->cluster_id = cluster_id;
}

void merge_clusters(Cluster* cluster1, Cluster* cluster2) {
    Node* head1 = cluster1->head;
    Node* head2 = cluster2->head;

    insert_node(&head1, head2->data);

    free(cluster2);
    cluster2 = NULL;
}

void print_clusters(Cluster* cluster) {
    Node* head = cluster->head;

    printf("Cluster ID: %d\n", cluster->cluster_id);
    printf("Members: ");

    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

int main() {
    int i, n, k;
    Cluster** clusters = NULL;

    printf("Enter the number of clusters: ");
    scanf("%d", &k);

    for (i = 0; i < k; i++) {
        create_cluster(&clusters, i);
    }

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        int data;
        printf("Enter the data of the node: ");
        scanf("%d", &data);
        insert_node(&clusters[0]->head, data);
    }

    merge_clusters(clusters[0], clusters[1]);

    print_clusters(clusters[0]);

    return 0;
}