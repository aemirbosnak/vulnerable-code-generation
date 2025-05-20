//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_CLIENTS 100
#define BUFFER_SIZE 1024

// Function to handle error messages
void handleError(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

// Structure to hold QoS statistics
typedef struct {
    char ipAddress[INET_ADDRSTRLEN];
    int packetLoss;
    float latency;
    int jitter;
} QoSStats;

// Function to initialize server
int initServer(int port) {
    int sockfd;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        handleError("ERROR opening socket");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        handleError("ERROR on binding");
    }

    return sockfd;
}

// Function to simulate packet reception and record QoS statistics
void monitorQoS(int sockfd, QoSStats *stats) {
    char buffer[BUFFER_SIZE];
    struct sockaddr_in cli_addr;
    socklen_t addr_len = sizeof(cli_addr);
    
    // Simulate the reception of packets
    while (1) {
        int n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr*)&cli_addr, &addr_len);
        if (n < 0) {
            handleError("ERROR on recvfrom");
        }

        // Record the QoS statistics
        strcpy(stats->ipAddress, inet_ntoa(cli_addr.sin_addr));
        stats->packetLoss = rand() % 10; // Simulated packet loss
        stats->latency = (float)(rand() % 500) / 100.0; // Simulating latency in ms
        stats->jitter = rand() % 20; // Simulating jitter

        // Output the recorded QoS statistics
        printf("Received packet from %s\n", stats->ipAddress);
        printf("Packet Loss: %d%%, Latency: %.2f ms, Jitter: %d ms\n\n", 
                stats->packetLoss, stats->latency, stats->jitter);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int port = atoi(argv[1]);
    QoSStats stats;

    // Initialize server
    int sockfd = initServer(port);
    printf("Server is running on port %d\n", port);

    // Start QoS monitoring
    monitorQoS(sockfd, &stats);

    // Close the socket (not reachable in this example)
    close(sockfd);

    return 0;
}