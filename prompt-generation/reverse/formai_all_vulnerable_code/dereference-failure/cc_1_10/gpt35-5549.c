//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <net/if.h>

#define BUFFER_SIZE 1024
#define PORT 8000

struct Node {
    struct in_addr addr;
    int neighbors;
    struct Node* next;
};

void addNeigbor(struct Node* node, struct in_addr neighbor) {
    struct Node* curr = node;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    struct Node* new_neighbor = malloc(sizeof(struct Node));
    new_neighbor->addr = neighbor;
    new_neighbor->neighbors = 0;
    new_neighbor->next = NULL;
    curr->next = new_neighbor;

    node->neighbors++;
}

void printNodes(struct Node* node) {
    struct Node* curr = node;
    while (curr != NULL) {
        char* ip = inet_ntoa(curr->addr);
        printf("%s %d\n", ip, curr->neighbors);
        curr = curr->next;
    }
}

int main() {
    struct ifaddrs *addrs, *tmp;
    int sockfd, len;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in servaddr, cliaddr;
    
    // Read network interfaces and their IP addresses
    if (getifaddrs(&addrs) < 0) {
        perror("Failed to get network interfaces");
        return -1;
    }

    // Initialize node map from address of each interface
    struct Node* nodes_head = malloc(sizeof(struct Node));
    nodes_head->addr.s_addr = htonl(INADDR_LOOPBACK);
    nodes_head->neighbors = 0;
    nodes_head->next = NULL;
    struct Node* curr_node = nodes_head;
    for (tmp = addrs; tmp != NULL; tmp = tmp->ifa_next) {
        if (tmp->ifa_addr->sa_family == AF_INET && (tmp->ifa_flags & IFF_LOOPBACK) == 0) {
            struct sockaddr_in *pAddr = (struct sockaddr_in *)tmp->ifa_addr;
            addNeigbor(curr_node, pAddr->sin_addr);
            
            // Add new node for each interface
            struct Node* new_node = malloc(sizeof(struct Node));
            new_node->addr = pAddr->sin_addr;
            new_node->neighbors = 0;
            new_node->next = NULL;
            curr_node->next = new_node;

            curr_node = new_node;
        }
    }
    freeifaddrs(addrs);

    // Create socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Bind socket to a specific port
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET; // IPv4
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0 ) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    len = sizeof(cliaddr);

    printf("Listening for packets...\n");
    while (1) {
        int n = recvfrom(sockfd, (char *)buffer, BUFFER_SIZE, MSG_WAITALL, ( struct sockaddr *) &cliaddr, &len);
        if (n <= 0) {
            continue;
        }

        char* ip = inet_ntoa(cliaddr.sin_addr);
        printf("Received packet from %s\n", ip);

        // Add neighbor node to sender node
        struct Node* curr = nodes_head->next;
        while (curr != NULL) {
            if (curr->addr.s_addr == cliaddr.sin_addr.s_addr) {
                addNeigbor(curr, cliaddr.sin_addr);
                break;
            }
            curr = curr->next;
        }
    }
    
    // Print final node map
    printf("Node map:\n");
    printNodes(nodes_head->next);

    // Clean up memory
    curr_node = nodes_head->next;
    while (curr_node != NULL) {
        struct Node* next_node = curr_node->next;
        free(curr_node);
        curr_node = next_node;
    }
    free(nodes_head);

    close(sockfd);
    return 0;
}