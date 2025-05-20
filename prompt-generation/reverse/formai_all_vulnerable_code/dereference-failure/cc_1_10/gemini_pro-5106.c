//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Colors for pretty printing
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

// Maximum number of hops to traverse
#define MAX_HOPS 10

// Structure to store the topology information
typedef struct topology {
    char **nodes;
    int **edges;
    int num_nodes;
    int num_edges;
} topology;

// Function to create a new topology
topology *create_topology() {
    topology *t = malloc(sizeof(topology));
    t->nodes = NULL;
    t->edges = NULL;
    t->num_nodes = 0;
    t->num_edges = 0;
    return t;
}

// Function to add a node to the topology
void add_node(topology *t, char *node) {
    t->nodes = realloc(t->nodes, (t->num_nodes + 1) * sizeof(char *));
    t->nodes[t->num_nodes++] = strdup(node);
}

// Function to add an edge to the topology
void add_edge(topology *t, char *node1, char *node2) {
    int i, j;

    // Find the indices of the nodes in the topology
    for (i = 0; i < t->num_nodes; i++) {
        if (strcmp(t->nodes[i], node1) == 0) {
            break;
        }
    }

    for (j = 0; j < t->num_nodes; j++) {
        if (strcmp(t->nodes[j], node2) == 0) {
            break;
        }
    }

    // If either node is not found, return
    if (i == t->num_nodes || j == t->num_nodes) {
        return;
    }

    // Add the edge to the topology
    t->edges = realloc(t->edges, (t->num_edges + 1) * sizeof(int *));
    t->edges[t->num_edges++] = malloc(2 * sizeof(int));
    t->edges[t->num_edges - 1][0] = i;
    t->edges[t->num_edges - 1][1] = j;
}

// Function to print the topology
void print_topology(topology *t) {
    int i, j;

    printf("Nodes:\n");
    for (i = 0; i < t->num_nodes; i++) {
        printf("  %s\n", t->nodes[i]);
    }

    printf("Edges:\n");
    for (i = 0; i < t->num_edges; i++) {
        printf("  %s - %s\n", t->nodes[t->edges[i][0]], t->nodes[t->edges[i][1]]);
    }
}

// Function to free the topology
void free_topology(topology *t) {
    int i;

    for (i = 0; i < t->num_nodes; i++) {
        free(t->nodes[i]);
    }

    for (i = 0; i < t->num_edges; i++) {
        free(t->edges[i]);
    }

    free(t->nodes);
    free(t->edges);
    free(t);
}

// Function to map the network topology
topology *map_topology(char *host, int port, int hops) {
    int sockfd, i, j, k;
    struct sockaddr_in servaddr;
    char buf[1024];
    topology *t;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr.s_addr = inet_addr(host);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Send the number of hops to traverse
    sprintf(buf, "%d\n", hops);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the topology
    t = create_topology();
    while (recv(sockfd, buf, sizeof(buf), 0) > 0) {
        // Parse the topology
        char *node, *edge;
        node = strtok(buf, "\n");
        while (node != NULL) {
            add_node(t, node);
            edge = strtok(NULL, "\n");
            while (edge != NULL) {
                add_edge(t, node, edge);
                edge = strtok(NULL, "\n");
            }
            node = strtok(NULL, "\n");
        }
    }

    // Close the socket
    close(sockfd);

    return t;
}

int main(int argc, char **argv) {
    topology *t;

    // Check the command line arguments
    if (argc != 4) {
        printf("Usage: %s <host> <port> <hops>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Map the network topology
    t = map_topology(argv[1], atoi(argv[2]), atoi(argv[3]));

    // Print the topology
    printf("Network Topology:\n");
    print_topology(t);

    // Free the topology
    free_topology(t);

    return EXIT_SUCCESS;
}