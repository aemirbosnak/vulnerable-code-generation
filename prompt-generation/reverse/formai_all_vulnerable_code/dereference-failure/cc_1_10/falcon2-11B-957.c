//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the structure for a node in the network
struct node {
    int id;
    int neighbors[10];
};

// Function to create a new node
struct node* create_node(int id) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->id = id;
    for (int i = 0; i < 10; i++) {
        node->neighbors[i] = -1;
    }
    return node;
}

// Function to print the neighbors of a node
void print_neighbors(struct node* node) {
    for (int i = 0; i < 10; i++) {
        if (node->neighbors[i]!= -1) {
            printf("Node %d is connected to node %d\n", node->id, node->neighbors[i]);
        }
    }
}

// Function to create a new connection between two nodes
void add_connection(struct node* node1, int neighbor1, struct node* node2, int neighbor2) {
    node1->neighbors[neighbor1] = node2->id;
    node2->neighbors[neighbor2] = node1->id;
}

// Function to find the shortest path between two nodes
void find_shortest_path(struct node* node1, int neighbor1, struct node* node2, int neighbor2) {
    struct node* current = node1;
    int path[10];
    int distance = 0;
    int current_id = node1->id;
    int next_id = node1->neighbors[neighbor1];
    int prev_id = node1->id;

    while (current_id!= node2->id) {
        path[distance] = next_id;
        distance++;
        current = current->neighbors[next_id];
        next_id = current->id;
        prev_id = current_id;
        current_id = next_id;
    }
    path[distance] = prev_id;
    printf("The shortest path between node %d and node %d is:\n", node1->id, node2->id);
    for (int i = 0; i < distance; i++) {
        printf("Node %d -> Node %d\n", path[i], path[i+1]);
    }
}

// Function to find the shortest path between all pairs of nodes
void find_shortest_path_all_pairs() {
    struct node* node1 = create_node(1);
    struct node* node2 = create_node(2);
    struct node* node3 = create_node(3);
    struct node* node4 = create_node(4);
    struct node* node5 = create_node(5);

    add_connection(node1, 0, node2, 1);
    add_connection(node1, 1, node3, 2);
    add_connection(node1, 2, node4, 3);
    add_connection(node1, 3, node5, 4);
    add_connection(node2, 4, node3, 3);
    add_connection(node3, 0, node4, 2);
    add_connection(node4, 1, node5, 4);
    add_connection(node5, 2, node1, 1);

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            find_shortest_path(node1, 0, node2, 1);
        }
    }
}

// Main function
int main() {
    pthread_t threads[5];
    int thread_id;

    for (thread_id = 0; thread_id < 5; thread_id++) {
        pthread_create(&threads[thread_id], NULL, find_shortest_path_all_pairs, NULL);
    }

    for (thread_id = 0; thread_id < 5; thread_id++) {
        pthread_join(threads[thread_id], NULL);
    }

    return 0;
}