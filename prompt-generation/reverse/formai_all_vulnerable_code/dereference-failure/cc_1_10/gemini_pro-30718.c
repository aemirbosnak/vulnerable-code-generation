//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>

// Maximum number of hops to trace
#define MAX_HOPS 30

// Maximum size of a single hop's data
#define HOP_DATA_SIZE 1024

// Structure to store the data for a single hop
typedef struct hop {
    char *ip;
    int port;
    char *data;
} hop;

// Structure to store the data for the entire topology
typedef struct topology {
    int num_hops;
    hop *hops;
} topology;

// Function to print the topology
void print_topology(topology *t) {
    printf("Topology:\n");
    for (int i = 0; i < t->num_hops; i++) {
        printf("  Hop %d:\n", i + 1);
        printf("    IP: %s\n", t->hops[i].ip);
        printf("    Port: %d\n", t->hops[i].port);
        printf("    Data: %s\n", t->hops[i].data);
    }
}

// Function to free the memory allocated for the topology
void free_topology(topology *t) {
    for (int i = 0; i < t->num_hops; i++) {
        free(t->hops[i].ip);
        free(t->hops[i].data);
    }
    free(t->hops);
    free(t);
}

// Function to trace the network topology
topology *trace_topology(char *host, int port) {
    // Create a new topology
    topology *t = malloc(sizeof(topology));
    t->num_hops = 0;
    t->hops = NULL;

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        free_topology(t);
        return NULL;
    }

    // Connect to the host
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(host);
    if (connect(sockfd, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
        perror("connect");
        close(sockfd);
        free_topology(t);
        return NULL;
    }

    // Send a request to trace the topology
    char request[] = "TRACE";
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send");
        close(sockfd);
        free_topology(t);
        return NULL;
    }

    // Receive the response from the host
    char response[HOP_DATA_SIZE];
    int num_bytes_received = recv(sockfd, response, HOP_DATA_SIZE, 0);
    if (num_bytes_received == -1) {
        perror("recv");
        close(sockfd);
        free_topology(t);
        return NULL;
    }

    // Parse the response
    char *hop_data = strtok(response, "\n");
    while (hop_data != NULL) {
        // Create a new hop
        hop *h = malloc(sizeof(hop));
        h->ip = malloc(strlen(host) + 1);
        strcpy(h->ip, host);
        h->port = port;
        h->data = malloc(strlen(hop_data) + 1);
        strcpy(h->data, hop_data);

        // Add the hop to the topology
        t->hops = realloc(t->hops, (t->num_hops + 1) * sizeof(hop));
        t->hops[t->num_hops] = *h;
        t->num_hops++;

        // Get the next hop data
        hop_data = strtok(NULL, "\n");
    }

    // Close the socket
    close(sockfd);

    // Return the topology
    return t;
}

// Main function
int main(int argc, char *argv[]) {
    // Check the arguments
    if (argc != 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    // Trace the topology
    topology *t = trace_topology(argv[1], atoi(argv[2]));
    if (t == NULL) {
        printf("Error: Unable to trace the topology\n");
        return 1;
    }

    // Print the topology
    print_topology(t);

    // Free the memory allocated for the topology
    free_topology(t);

    return 0;
}