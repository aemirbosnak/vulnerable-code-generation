//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_NAME_LENGTH 50

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    char ipAddress[INET_ADDRSTRLEN];
    int status; // 1 for active, 0 for inactive
} Node;

Node nodeList[MAX_NODES];
int nodeCount = 0;

void addNode(const char* name, const char* ip) {
    if (nodeCount < MAX_NODES) {
        strcpy(nodeList[nodeCount].name, name);
        strcpy(nodeList[nodeCount].ipAddress, ip);
        nodeList[nodeCount].status = 1; // active by default
        nodeCount++;
    } else {
        printf("Node list is full!\n");
    }
}

void displayNodes() {
    printf("\nNetwork Topology:\n");
    printf("===================================\n");
    for (int i = 0; i < nodeCount; i++) {
        printf("Node Name: %s, IP Address: %s, Status: %s\n", 
               nodeList[i].name, 
               nodeList[i].ipAddress, 
               nodeList[i].status == 1 ? "Active" : "Inactive");
    }
    printf("===================================\n");
}

void checkNodeStatus() {
    struct sockaddr_in sa;
    for (int i = 0; i < nodeCount; i++) {
        memset(&sa, 0, sizeof(sa));
        sa.sin_family = AF_INET;
        sa.sin_port = htons(80); // check HTTP service
        inet_pton(AF_INET, nodeList[i].ipAddress, &sa.sin_addr);

        if (connect(socket(AF_INET, SOCK_STREAM, 0), (struct sockaddr *)&sa, sizeof(sa)) == 0) {
            nodeList[i].status = 1; // active
        } else {
            nodeList[i].status = 0; // inactive
        }
    }
}

void getLocalIpAddress() {
    struct ifaddrs *ifaddr, *ifa;
    getifaddrs(&ifaddr);
    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_INET) {
            char addr[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &((struct sockaddr_in *)ifa->ifa_addr)->sin_addr, addr, sizeof(addr));
            addNode(ifa->ifa_name, addr);
        }
    }
    freeifaddrs(ifaddr);
}

int main() {
    printf("Welcome to the C Network Topology Mapper!\n");
    getLocalIpAddress();

    // Add some sample nodes
    addNode("Router", "192.168.1.1");
    addNode("Server", "192.168.1.2");
    addNode("Client_A", "192.168.1.3");
    addNode("Client_B", "192.168.1.4");

    // Check the status of the nodes
    printf("Checking node statuses...\n");
    checkNodeStatus();

    // Display the current network topology
    displayNodes();
    
    return 0;
}