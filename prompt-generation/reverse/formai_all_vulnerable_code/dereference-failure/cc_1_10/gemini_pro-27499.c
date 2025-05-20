//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_HOPS 30
#define MAX_NODES 100

struct node {
    char *ip_address;
    int num_hops;
    int visited;
};

struct node nodes[MAX_NODES];
int num_nodes = 0;

void add_node(char *ip_address, int num_hops) {
    if (num_nodes >= MAX_NODES) {
        fprintf(stderr, "Error: too many nodes\n");
        return;
    }

    nodes[num_nodes].ip_address = strdup(ip_address);
    nodes[num_nodes].num_hops = num_hops;
    nodes[num_nodes].visited = 0;

    num_nodes++;
}

void print_nodes() {
    for (int i = 0; i < num_nodes; i++) {
        printf("%s %d\n", nodes[i].ip_address, nodes[i].num_hops);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <ip_address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Add the starting node to the list.
    add_node(argv[1], 0);

    while (num_nodes > 0) {
        // Find the node with the smallest number of hops.
        int min_hops = MAX_HOPS;
        int min_hops_node = -1;

        for (int i = 0; i < num_nodes; i++) {
            if (nodes[i].visited || nodes[i].num_hops >= min_hops) {
                continue;
            }

            min_hops = nodes[i].num_hops;
            min_hops_node = i;
        }

        if (min_hops_node == -1) {
            fprintf(stderr, "Error: no more nodes to visit\n");
            return EXIT_FAILURE;
        }

        // Visit the node.
        nodes[min_hops_node].visited = 1;

        // Try to connect to the node.
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            perror("socket");
            return EXIT_FAILURE;
        }

        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = inet_addr(nodes[min_hops_node].ip_address);
        addr.sin_port = htons(80);

        if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
            perror("connect");
            close(sockfd);
            continue;
        }

        // Send a request to the node.
        char request[] = "GET / HTTP/1.0\r\n\r\n";
        if (send(sockfd, request, strlen(request), 0) == -1) {
            perror("send");
            close(sockfd);
            continue;
        }

        // Receive a response from the node.
        char response[1024];
        int bytes_received = recv(sockfd, response, sizeof(response), 0);
        if (bytes_received == -1) {
            perror("recv");
            close(sockfd);
            continue;
        }

        // Parse the response from the node.
        char *start = strstr(response, "Location: ");
        if (start == NULL) {
            close(sockfd);
            continue;
        }

        char *end = strchr(start, '\n');
        if (end == NULL) {
            close(sockfd);
            continue;
        }

        *end = '\0';

        // Add the next node to the list.
        add_node(start + 10, min_hops + 1);

        // Close the socket.
        close(sockfd);
    }

    // Print the list of nodes.
    print_nodes();

    return EXIT_SUCCESS;
}