//LLAMA2-13B DATASET v1.0 Category: CPU usage monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_NODES 1024
#define MAX_STRING 1024

struct node {
    int id;
    char name[128];
    char ip[INET_ADDRSTRLEN];
    int64_t cpus[8];
};

struct packet {
    int src;
    int dst;
    char data[1024];
};

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[1024];
    struct node *nodes;
    int i, j, k;

    // Initialize nodes
    nodes = calloc(MAX_NODES, sizeof(struct node));
    for (i = 0; i < MAX_NODES; i++) {
        nodes[i].id = i;
        nodes[i].name[0] = '\0';
        nodes[i].ip[0] = '\0';
        for (j = 0; j < 8; j++) {
            nodes[i].cpus[j] = 0;
        }
    }

    // Initialize socket
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(1234);

    // Bind socket to address and port
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sock, 5) < 0) {
        perror("Listen failed");
        exit(1);
    }

    // Loop forever to handle incoming packets
    while (1) {
        // Receive packet from client
        if (recvfrom(sock, buffer, 1024, 0, (struct sockaddr *)&client_addr, &client_len) < 0) {
            perror("Recvfrom failed");
            exit(1);
        }

        // Parse packet data
        for (i = 0; i < 8; i++) {
            if (sscanf(buffer, "%d%n", &nodes[nodes->id].cpus[i], &k) < 0) {
                break;
            }
            nodes[nodes->id].cpus[i] = nodes[nodes->id].cpus[i] + nodes[nodes->id].cpus[i];
        }

        // Send acknowledgement packet back to client
        struct packetack {
            int src;
            int dst;
        };
        struct packetack pk;
        pk.src = client_addr.sin_addr.s_addr;
        pk.dst = server_addr.sin_addr.s_addr;
        sendto(sock, &pk, sizeof(pk), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
    }

    return 0;
}