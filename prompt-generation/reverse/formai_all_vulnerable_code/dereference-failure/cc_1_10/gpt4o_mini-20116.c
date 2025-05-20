//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_NODES 100
#define BUFFER_SIZE 1024

typedef struct Node {
    char ip_address[16];
    int port;
    int visited;
    struct Node* next;
} Node;

Node* create_node(const char* ip, int port) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strncpy(new_node->ip_address, ip, 16);
    new_node->port = port;
    new_node->visited = 0;
    new_node->next = NULL;
    return new_node;
}

void add_node(Node** head, const char* ip, int port) {
    Node* new_node = create_node(ip, port);
    new_node->next = *head;
    *head = new_node;
}

void print_nodes(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("Node IP: %s Port: %d\n", current->ip_address, current->port);
        current = current->next;
    }
}

void cleanup_nodes(Node* head) {
    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int ping_node(const char* ip, int port) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    
    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return 0;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    
    // Convert IP address from text to binary form
    if (inet_pton(AF_INET, ip, &server_addr.sin_addr) <= 0) {
        printf("Invalid address: %s\n", ip);
        close(sock);
        return 0;
    }

    // Try to connect
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Failed to connect to %s:%d\n", ip, port);
        close(sock);
        return 0;
    }

    // Connection successful
    snprintf(buffer, BUFFER_SIZE, "PING\n");
    send(sock, buffer, strlen(buffer), 0);
    close(sock);
    return 1;
}

void scan_network(Node** head) {
    Node* current = *head;
    while (current != NULL) {
        if (!current->visited) {
            printf("Pinging %s:%d...\n", current->ip_address, current->port);
            if (ping_node(current->ip_address, current->port)) {
                printf("Success: Reachable\n");
            } else {
                printf("Failed: Unreachable\n");
            }
            current->visited = 1;
        }
        current = current->next;
    }
}

int main() {
    Node* network_topology = NULL;

    // Sample nodes added
    add_node(&network_topology, "192.168.1.1", 8080);
    add_node(&network_topology, "192.168.1.2", 8080);
    add_node(&network_topology, "192.168.1.3", 8080);
    
    printf("Current Network Topology:\n");
    print_nodes(network_topology);
    
    printf("\nScanning Network...\n");
    scan_network(&network_topology);
    
    cleanup_nodes(network_topology);
    return 0;
}