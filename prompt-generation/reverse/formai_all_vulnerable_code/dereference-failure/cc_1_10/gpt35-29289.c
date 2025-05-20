//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_NODES 10

// Structure to store node details
struct node {
    char *name;
    char *ip;
    int port;
    int connections[MAX_NODES];
    int num_connections;
};

// Global variables
struct node nodes[MAX_NODES];
int num_nodes = 0;

// Function to add a new node to the system
void add_node(char *name, char *ip, int port) {
    if (num_nodes < MAX_NODES) {
        nodes[num_nodes].name = malloc(strlen(name) + 1);
        strcpy(nodes[num_nodes].name, name);
        nodes[num_nodes].ip = malloc(strlen(ip) + 1);
        strcpy(nodes[num_nodes].ip, ip);
        nodes[num_nodes].port = port;
        nodes[num_nodes].num_connections = 0;
        num_nodes++;
    }
}

// Function to connect two nodes
void connect_nodes(int node1, int node2) {
    if (node1 < num_nodes && node2 < num_nodes) {
        if (nodes[node1].num_connections < MAX_NODES && nodes[node2].num_connections < MAX_NODES) {
            nodes[node1].connections[nodes[node1].num_connections] = node2;
            nodes[node1].num_connections++;
            nodes[node2].connections[nodes[node2].num_connections] = node1;
            nodes[node2].num_connections++;
        }
    }
}

// Function to send a message from one node to another
void send_message(int sender, int receiver, char *message) {
    if (sender < num_nodes && receiver < num_nodes) {
        if (strcmp(nodes[sender].ip, nodes[receiver].ip) == 0 && nodes[sender].port == nodes[receiver].port) {
            printf("Message from %s to %s: %s\n", nodes[sender].name, nodes[receiver].name, message);
        } else {
            int sock = socket(AF_INET, SOCK_STREAM, 0);
            struct sockaddr_in server_addr;
            server_addr.sin_family = AF_INET;
            server_addr.sin_addr.s_addr = inet_addr(nodes[receiver].ip);
            server_addr.sin_port = htons(nodes[receiver].port);
            connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
            send(sock, message, strlen(message), 0);
            close(sock);
            printf("Message from %s to %s (via %s): %s\n", nodes[sender].name, nodes[receiver].name, nodes[receiver].name, message);
        }
    }
}

int main() {
    // Initialize the nodes 
    add_node("Node1", "127.0.0.1", 8001);
    add_node("Node2", "127.0.0.1", 8002);
    add_node("Node3", "127.0.0.1", 8003);
    add_node("Node4", "127.0.0.1", 8004);
    add_node("Node5", "127.0.0.1", 8005);

    // Connect the nodes
    connect_nodes(0, 1);
    connect_nodes(1, 2);
    connect_nodes(2, 3);
    connect_nodes(3, 4);
    connect_nodes(4, 0);
    connect_nodes(0, 3);
    connect_nodes(3, 1);

    // Send some messages
    send_message(0, 1, "Hello Node2");
    send_message(1, 3, "Hi Node4, How are you?");
    send_message(2, 4, "Hey Node5, Let's connect");
    send_message(4, 0, "Hello Node1, It's been a while");

    return 0;
}