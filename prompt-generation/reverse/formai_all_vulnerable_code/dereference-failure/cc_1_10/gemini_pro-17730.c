//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ifaddrs.h>
#include <netdb.h>
#include <unistd.h>

// A mind-bending struct to store all things network
struct NetworkMatrix {
    int **topology;
    char **hostnames;
    int num_nodes;
};

// A recursive function to map the network topology
void mapNetwork(struct NetworkMatrix *matrix, int node, int depth) {
    // If we've reached the maximum depth, return
    if (depth >= matrix->num_nodes) return;

    // Get the hostname for the node
    struct hostent *hostent = gethostbyaddr((const void *)&matrix->topology[node][0], sizeof(matrix->topology[node][0]), AF_INET);
    char *hostname = hostent ? hostent->h_name : "Unknown";

    // Print the hostname and depth for this node
    printf("%*s%s (%d)\n", depth * 4, "", hostname, node);

    // Recursively map the network for this node's neighbors
    for (int i = 0; i < matrix->num_nodes; i++) {
        if (matrix->topology[node][i] != 0) {
            mapNetwork(matrix, i, depth + 1);
        }
    }
}

int main() {
    // Get the list of network interfaces
    struct ifaddrs *ifaddrs, *ifa;
    if (getifaddrs(&ifaddrs) == -1) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }

    // Count the number of network interfaces
    int num_nodes = 0;
    for (ifa = ifaddrs; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_INET) {
            num_nodes++;
        }
    }

    // Create the network matrix
    struct NetworkMatrix matrix;
    matrix.topology = malloc(num_nodes * sizeof(int *));
    matrix.hostnames = malloc(num_nodes * sizeof(char *));
    for (int i = 0; i < num_nodes; i++) {
        matrix.topology[i] = malloc(num_nodes * sizeof(int));
        matrix.hostnames[i] = malloc(256 * sizeof(char));
    }

    // Populate the network matrix
    int index = 0;
    for (ifa = ifaddrs; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_INET) {
            struct sockaddr_in *addr = (struct sockaddr_in *)ifa->ifa_addr;
            matrix.topology[index][index] = addr->sin_addr.s_addr;
            strcpy(matrix.hostnames[index], ifa->ifa_name);
            index++;
        }
    }

    // Map the network topology
    mapNetwork(&matrix, 0, 0);

    // Free the network matrix
    for (int i = 0; i < num_nodes; i++) {
        free(matrix.topology[i]);
        free(matrix.hostnames[i]);
    }
    free(matrix.topology);
    free(matrix.hostnames);

    freeifaddrs(ifaddrs);

    return EXIT_SUCCESS;
}