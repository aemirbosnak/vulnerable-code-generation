//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAtTail(Node** head, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int main() {

    // Create a linked list
    Node* head = NULL;

    // Insert data into the linked list
    insertAtTail(&head, 10);
    insertAtTail(&head, 20);
    insertAtTail(&head, 30);
    insertAtTail(&head, 40);
    insertAtTail(&head, 50);

    // Cluster the data
    int clusters = cluster(head);

    // Print the number of clusters
    printf("Number of clusters: %d", clusters);

    return 0;
}

int cluster(Node* head) {

    // Calculate the distance between each data point and the center of each cluster
    int distances[MAX];
    for (int i = 0; i < MAX; i++) {
        distances[i] = -1;
    }

    // Create a distance matrix
    int** matrix = (int**)malloc(sizeof(int*) * MAX);
    for (int i = 0; i < MAX; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * MAX);
    }

    // Calculate the distances
    for (Node* node = head; node != NULL; node++) {
        for (int i = 0; i < MAX; i++) {
            distances[i] = abs(node->data - i);
        }
    }

    // Create the clusters
    int clusters = 0;
    for (int i = 0; i < MAX; i++) {
        int minDistance = distances[i];
        int cluster = -1;
        for (int j = 0; j < MAX; j++) {
            if (distances[j] < minDistance) {
                minDistance = distances[j];
                cluster = j;
            }
        }
        matrix[cluster][i] = 1;
        clusters++;
    }

    // Free the memory
    for (int i = 0; i < MAX; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return clusters;
}