//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

// Structure to store network topology information
typedef struct ntm_info {
    int num_nodes;
    int **adj_matrix;
} ntm_info;

// Function to create a new network topology mapper
ntm_info *ntm_create(int num_nodes) {
    ntm_info *ntm = malloc(sizeof(ntm_info));
    ntm->num_nodes = num_nodes;
    ntm->adj_matrix = malloc(sizeof(int *) * num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        ntm->adj_matrix[i] = malloc(sizeof(int) * num_nodes);
        memset(ntm->adj_matrix[i], 0, sizeof(int) * num_nodes);
    }
    return ntm;
}

// Function to destroy a network topology mapper
void ntm_destroy(ntm_info *ntm) {
    for (int i = 0; i < ntm->num_nodes; i++) {
        free(ntm->adj_matrix[i]);
    }
    free(ntm->adj_matrix);
    free(ntm);
}

// Function to add an edge to a network topology mapper
void ntm_add_edge(ntm_info *ntm, int node1, int node2) {
    ntm->adj_matrix[node1][node2] = 1;
    ntm->adj_matrix[node2][node1] = 1;
}

// Function to print a network topology mapper
void ntm_print(ntm_info *ntm) {
    for (int i = 0; i < ntm->num_nodes; i++) {
        for (int j = 0; j < ntm->num_nodes; j++) {
            printf("%d ", ntm->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to map a network topology
void *ntm_map(void *arg) {
    ntm_info *ntm = (ntm_info *)arg;

    // Create a socket
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("socket");
        return NULL;
    }

    // Bind the socket to a local address and port
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(0);
    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        return NULL;
    }

    // Send a broadcast message to all nodes in the network
    int bcast_len = sizeof(struct sockaddr_in);
    addr.sin_addr.s_addr = INADDR_BROADCAST;
    char bcast_msg[] = "NTM_MAP";
    if (sendto(sock, bcast_msg, strlen(bcast_msg), 0, (struct sockaddr *)&addr, bcast_len) < 0) {
        perror("sendto");
        return NULL;
    }

    // Receive responses from nodes in the network
    char recv_buf[1024];
    while (1) {
        struct sockaddr_in from_addr;
        socklen_t from_len = sizeof(from_addr);
        int recv_len = recvfrom(sock, recv_buf, sizeof(recv_buf), 0, (struct sockaddr *)&from_addr, &from_len);
        if (recv_len < 0) {
            perror("recvfrom");
            return NULL;
        }

        // Parse the response message
        char *node_id = strtok(recv_buf, ":");
        char *neighbors = strtok(NULL, ":");
        int node_id_int = atoi(node_id);
        char *neighbor;
        while ((neighbor = strtok(NULL, ":")) != NULL) {
            int neighbor_int = atoi(neighbor);
            ntm_add_edge(ntm, node_id_int, neighbor_int);
        }
    }

    // Close the socket
    close(sock);

    return NULL;
}

int main() {
    // Create a network topology mapper
    ntm_info *ntm = ntm_create(10);

    // Create a thread to map the network topology
    pthread_t thread;
    if (pthread_create(&thread, NULL, ntm_map, (void *)ntm) != 0) {
        perror("pthread_create");
        return EXIT_FAILURE;
    }

    // Wait for the thread to finish
    if (pthread_join(thread, NULL) != 0) {
        perror("pthread_join");
        return EXIT_FAILURE;
    }

    // Print the network topology
    ntm_print(ntm);

    // Destroy the network topology mapper
    ntm_destroy(ntm);

    return EXIT_SUCCESS;
}