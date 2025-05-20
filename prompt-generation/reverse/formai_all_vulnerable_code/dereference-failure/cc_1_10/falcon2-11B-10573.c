//Falcon2-11B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define INF INT_MAX

// A* pathfinding algorithm
int aStar(int start, int end, int** graph, int num_nodes, int** distances, int** parent) {
    int n = num_nodes;
    int *distances_list = calloc(n, sizeof(int));
    int *parent_list = calloc(n, sizeof(int));
    int *queue = calloc(n, sizeof(int));

    // Initialize the queue with the start node
    queue[0] = start;
    distances_list[start] = 0;
    parent_list[start] = -1;
    distances[start] = 0;
    int *queue_front = &queue[0];
    int queue_size = 1;

    while (queue_size > 0) {
        // Get the node with the lowest f-score from the queue
        int node = queue[--queue_size];

        // Check if the current node is the goal
        if (node == end) {
            // Reconstruct the path
            int current = node;
            while (parent_list[current]!= -1) {
                parent[current] = parent_list[current];
                current = parent_list[current];
            }
            return distances[node];
        }

        // Expand the node
        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1) {
                int new_distance = distances_list[node] + graph[node][i];
                if (new_distance < distances_list[i]) {
                    distances_list[i] = new_distance;
                    parent_list[i] = node;
                    queue_front = &queue[queue_size++];
                    queue[queue_size++] = i;
                }
            }
        }
    }

    return INF;
}

int main() {
    int n = 8;
    int** graph = calloc(n, sizeof(int*));
    int* distances = calloc(n, sizeof(int));
    int* parent = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        distances[i] = INF;
        parent[i] = -1;
    }

    graph[0] = (int*)calloc(n, sizeof(int));
    graph[0][1] = 1;
    graph[0][3] = 1;
    graph[0][5] = 1;
    graph[0][7] = 1;

    graph[1] = (int*)calloc(n, sizeof(int));
    graph[1][2] = 1;
    graph[1][4] = 1;
    graph[1][6] = 1;
    graph[1][8] = 1;

    graph[2] = (int*)calloc(n, sizeof(int));
    graph[2][3] = 1;
    graph[2][5] = 1;
    graph[2][7] = 1;
    graph[2][8] = 1;

    graph[3] = (int*)calloc(n, sizeof(int));
    graph[3][4] = 1;
    graph[3][6] = 1;
    graph[3][8] = 1;

    graph[4] = (int*)calloc(n, sizeof(int));
    graph[4][6] = 1;
    graph[4][7] = 1;
    graph[4][8] = 1;

    graph[5] = (int*)calloc(n, sizeof(int));
    graph[5][6] = 1;
    graph[5][7] = 1;
    graph[5][8] = 1;

    graph[6] = (int*)calloc(n, sizeof(int));
    graph[6][7] = 1;
    graph[6][8] = 1;

    graph[7] = (int*)calloc(n, sizeof(int));
    graph[7][8] = 1;

    // Find the shortest path from 0 to 8
    int distance = aStar(0, 8, graph, n, distances, parent);
    printf("The shortest path from 0 to 8 is %d steps long.\n", distance);

    // Free memory
    for (int i = 0; i < n; i++) {
        free(distances[i]);
        free(parent[i]);
    }
    free(distances);
    free(parent);
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}