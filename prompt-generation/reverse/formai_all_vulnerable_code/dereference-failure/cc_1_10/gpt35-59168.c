//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int data;
    int cluster;
    struct node* next;
} node_t;

void printCluster(int cluster, node_t* head) {
    printf("\nCluster %d:\n", cluster);
    node_t* ptr = head;
    while (ptr != NULL) {
        if (ptr->cluster == cluster) {
            printf("%d ", ptr->data);
        }
        ptr = ptr->next;
    }
}

void assignCluster(node_t* head, int k) {
    int cluster = 1;
    node_t* ptr = head;
    int count = 0;
    while (ptr != NULL) {
        ptr->cluster = cluster;
        count++;
        if (count >= k) {
            cluster++;
            count = 0;
        }
        ptr = ptr->next;
    }
}

int getRandom(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    srand(time(NULL));
    // Generate random data
    node_t* head = (node_t*)malloc(sizeof(node_t));
    node_t* ptr = head;
    for (int i = 0; i < 100; i++) {
        ptr->data = getRandom(1, 1000);
        ptr->next = (node_t*)malloc(sizeof(node_t));
        ptr = ptr->next;
    }
    ptr->next = NULL;
    // Assign clusters
    int k = 5;
    assignCluster(head, k);
    // Print data by clusters
    for (int i = 1; i <= k; i++) {
        printCluster(i, head);
    }
    return 0;
}