//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 1234
#define BUFFER_SIZE 1024

struct node {
    int id;
    int port;
    char value[100];
};

int main(int argc, char **argv) {
    int sock;
    struct node *nodes;
    int node_count = 0;

    // Initialize the node list
    nodes = calloc(1, sizeof(struct node));
    nodes[0].id = 0;
    nodes[0].port = PORT;
    nodes[0].value[0] = '\0';
    node_count++;

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Set up the peer-to-peer network
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sock, 5) < 0) {
        perror("Listening failed");
        exit(1);
    }

    printf("Listening for connections...\n");

    // Search for the value in the distributed network
    while (1) {
        struct node *new_node;
        int client_sock;

        // Accept an incoming connection
        client_sock = accept(sock, NULL, NULL);
        if (client_sock < 0) {
            perror("Accept failed");
            exit(1);
        }

        // Read the value from the client
        read(client_sock, nodes[node_count].value, BUFFER_SIZE);
        nodes[node_count].value[strcspn(nodes[node_count].value, "\n")] = '\0';

        // Send the value to the other nodes
        for (int i = 0; i < node_count; i++) {
            if (i != node_count - 1) {
                send(sock, nodes[i].value, strlen(nodes[i].value), 0);
            }
        }

        // Increment the node count
        node_count++;

        // Check if the value has been found
        if (strcmp(nodes[node_count - 1].value, "found") == 0) {
            break;
        }
    }

    // Close the socket
    close(sock);

    return 0;
}