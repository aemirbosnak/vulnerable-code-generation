//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_NODES 100
#define BUFFER_SIZE 1024

typedef struct Node {
    char ip[16];
    int port;
} Node;

Node nodes[MAX_NODES];
int nodeCount = 0;

void addNode(const char* ip, int port) {
    if (nodeCount < MAX_NODES) {
        strcpy(nodes[nodeCount].ip, ip);
        nodes[nodeCount].port = port;
        nodeCount++;
    } else {
        printf("Node count exceeded!\n");
    }
}

void printTopology() {
    printf("Network Topology:\n");
    for (int i = 0; i < nodeCount; i++) {
        printf("Node %d: IP = %s, Port = %d\n", i, nodes[i].ip, nodes[i].port);
    }
}

void discoverNodes(const char* serverIp, int serverPort) {
    int sockfd;
    struct sockaddr_in serverAddr;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(serverPort);
    inet_pton(AF_INET, serverIp, &serverAddr.sin_addr);

    snprintf(buffer, BUFFER_SIZE, "DISCOVER NODES");
    sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    socklen_t addrLen = sizeof(serverAddr);
    int n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr*)&serverAddr, &addrLen);
    buffer[n] = '\0';

    close(sockfd);

    char* token = strtok(buffer, ";");
    while (token != NULL) {
        char ip[16];
        int port;

        sscanf(token, "%15[^:]:%d", ip, &port);
        addNode(ip, port);
        token = strtok(NULL, ";");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <Server IP> <Server Port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* serverIp = argv[1];
    int serverPort = atoi(argv[2]);

    discoverNodes(serverIp, serverPort);
    printTopology();

    return EXIT_SUCCESS;
}