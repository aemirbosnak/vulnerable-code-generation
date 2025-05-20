//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 10
#define MAX_BUFF_SIZE 1024

struct Node {
    char ip[32];
    int port;
    int neighbors[MAX_CLIENTS];
    int neighbors_count;
};

struct Node nodes[MAX_CLIENTS];

int nodes_count = 0;

void add_node(char *ip, int port) {
    struct Node node;
    strcpy(node.ip, ip);
    node.port = port;
    node.neighbors_count = 0;
    nodes[nodes_count++] = node;
}

void add_neighbor(int node_index, int neighbor_index) {
    nodes[node_index].neighbors[nodes[node_index].neighbors_count++] = neighbor_index;
    nodes[neighbor_index].neighbors[nodes[neighbor_index].neighbors_count++] = node_index;
}

void print_nodes() {
    for(int i=0; i<nodes_count; i++) {
        printf("Node %d: %s:%d\n", i, nodes[i].ip, nodes[i].port);
        printf("Neighbors: ");
        for(int j=0; j<nodes[i].neighbors_count; j++) {
            printf("%d ", nodes[i].neighbors[j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {

    if(argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);

    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MAX_BUFF_SIZE] = {0};
       
    // create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
       
    // set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
       
    // bind socket to address
    if (bind(server_fd, (struct sockaddr *)&address, 
                                 sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
       
    // listen for connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is running on port %d\n", port);

    while(1) {

        // accept incoming client connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
                           (socklen_t*)&addrlen))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // receive message from client
        int num_bytes = read(new_socket, buffer, MAX_BUFF_SIZE);
        buffer[num_bytes] = '\0';
        printf("Received message: %s\n", buffer);

        //parse message and add nodes and neighbors
        char *ip = strtok(buffer, ":");
        int port = atoi(strtok(NULL, ":"));
        add_node(ip, port);
        while((ip = strtok(NULL, ":")) != NULL) {
            int neighbor_index = atoi(ip);
            add_neighbor(nodes_count-1, neighbor_index);
        }

        // print existing nodes and topology
        printf("Existing Nodes:\n");
        print_nodes();
    }

    return 0;
}