//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node {
    double x;
    double y;
    int cluster;
} Node;

double euclidean_distance(Node a, Node b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void k_means(Node* nodes, int k, int num_nodes) {
    Node* centers = (Node*) malloc(k * sizeof(Node));
    int* counts = (int*) calloc(k, sizeof(int));
    int converged = 0;
    
    // Pick initial centers
    for (int i = 0; i < k; i++) {
        centers[i] = nodes[rand() % num_nodes];
    }
    
    while (!converged) {
        // Reset counts and cluster assignments
        for (int i = 0; i < k; i++) {
            counts[i] = 0;
        }
        
        for (int i = 0; i < num_nodes; i++) {
            int cluster = 0;
            double min_distance = INFINITY;
            
            // Assign node to closest center
            for (int j = 0; j < k; j++) {
                double distance = euclidean_distance(nodes[i], centers[j]);
                
                if (distance < min_distance) {
                    min_distance = distance;
                    cluster = j;
                }
            }
            
            nodes[i].cluster = cluster;
            counts[cluster]++;
        }
        
        // Update centers
        for (int i = 0; i < k; i++) {
            double sum_x = 0, sum_y = 0;
            
            for (int j = 0; j < num_nodes; j++) {
                if (nodes[j].cluster == i) {
                    sum_x += nodes[j].x;
                    sum_y += nodes[j].y;
                }
            }
            
            if (counts[i] != 0) {
                centers[i].x = sum_x / counts[i];
                centers[i].y = sum_y / counts[i];
            }
        }
        
        // Check if converged
        for (int i = 0; i < num_nodes; i++) {
            double distance = euclidean_distance(nodes[i], centers[nodes[i].cluster]);
            
            if (distance > 0.0001) {
                converged = 0;
                break;
            } else {
                converged = 1;
            }
        }
    }
    
    // Print results
    for (int i = 0; i < k; i++) {
        printf("Cluster %d:\n", i + 1);
        
        for (int j = 0; j < num_nodes; j++) {
            if (nodes[j].cluster == i) {
                printf("(%f, %f)\n", nodes[j].x, nodes[j].y);
            }
        }
        
        printf("\n");
    }
    
    free(centers);
    free(counts);
}

int main() {
    Node nodes[] = {{1.0, 2.0}, {2.0, 1.0}, {3.0, 4.0}, {5.0, 7.0}, {7.0, 5.0}, {8.0, 6.0}};
    int k = 2;
    int num_nodes = sizeof(nodes) / sizeof(Node);
    
    k_means(nodes, k, num_nodes);
    
    return 0;
}