//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_NODES 100 // maximum nodes in the network
#define MAX_CONNECTIONS 1000 // maximum number of connections

// structure to store the details of a node in the network
typedef struct {
    int id;
    int num_neighbors;
    int neighbor_ids[MAX_NODES];
} Node;

// global variables
int num_nodes = 0;
Node nodes[MAX_NODES];
pthread_mutex_t lock; // mutex lock for accessing shared variables
pthread_t threads[MAX_NODES]; // array of threads to be created

void add_node(int id) {
    nodes[num_nodes].id = id;
    nodes[num_nodes].num_neighbors = 0;
    num_nodes++;
}

void add_connection(int id1, int id2) {
    // find the nodes with the given ids
    int index1 = -1, index2 = -1;
    for (int i = 0; i < num_nodes; i++) {
        if (nodes[i].id == id1) {
            index1 = i;
        } else if (nodes[i].id == id2) {
            index2 = i;
        }
    }
    // add the connection
    if (index1 != -1 && index2 != -1) {
        nodes[index1].neighbor_ids[nodes[index1].num_neighbors] = id2;
        nodes[index1].num_neighbors++;
        nodes[index2].neighbor_ids[nodes[index2].num_neighbors] = id1;
        nodes[index2].num_neighbors++;
    }
}

void print_topology() {
    printf("Topology:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d is connected to:", nodes[i].id);
        for (int j = 0; j < nodes[i].num_neighbors; j++) {
            printf(" %d", nodes[i].neighbor_ids[j]);
        }
        printf("\n");
    }
}

void* thread_function(void* arg) {
    int node_id = *((int*) arg);
    Node* node;
    // find the node with the given id
    for (int i = 0; i < num_nodes; i++) {
        if (nodes[i].id == node_id) {
            node = &nodes[i];
            break;
        }
    }
    // thread-safe printing
    pthread_mutex_lock(&lock);
    printf("Neighbors of node %d:\n", node_id);
    for (int i = 0; i < node->num_neighbors; i++) {
        printf("%d\n", node->neighbor_ids[i]);
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    // initialize mutex lock
    pthread_mutex_init(&lock, NULL);

    // add nodes and connections to the network
    add_node(1);
    add_node(2);
    add_node(3);
    add_connection(1, 2);
    add_connection(2, 3);

    // print the topology
    print_topology();

    // create a thread for each node
    for (int i = 0; i < num_nodes; i++) {
        int* node_id = (int*) malloc(sizeof(int)); // allocate memory for the argument
        *node_id = nodes[i].id;
        pthread_create(&threads[i], NULL, thread_function, (void*) node_id);
    }

    // wait for all threads to finish
    for (int i = 0; i < num_nodes; i++) {
        pthread_join(threads[i], NULL);
    }

    // destroy mutex lock
    pthread_mutex_destroy(&lock);

    return 0;
}