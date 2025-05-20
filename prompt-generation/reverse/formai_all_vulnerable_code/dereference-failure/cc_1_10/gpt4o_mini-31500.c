//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_NODES 5
#define BUFFER_SIZE 1024
#define PORT 8080

typedef struct Node {
    int id;
    struct Node* connections[MAX_NODES];
    int connection_count;
} Node;

Node* createNode(int id) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->id = id;
    node->connection_count = 0;
    return node;
}

void connectNodes(Node* a, Node* b) {
    if (a->connection_count < MAX_NODES) {
        a->connections[a->connection_count++] = b;
    }
    if (b->connection_count < MAX_NODES) {
        b->connections[b->connection_count++] = a;
    }
}

void visualizeGraph(Node* nodes[], int nodeCount) {
    for (int i = 0; i < nodeCount; i++) {
        printf("Node %d: ", nodes[i]->id);
        for (int j = 0; j < nodes[i]->connection_count; j++) {
            printf("%d ", nodes[i]->connections[j]->id);
        }
        printf("\n");
    }
}

void* nodeServer(void* arg) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    bind(server_fd, (struct sockaddr*)&address, sizeof(address));
    listen(server_fd, 3);
    
    char buffer[BUFFER_SIZE] = {0};
    
    while ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) >= 0) {
        read(new_socket, buffer, BUFFER_SIZE);
        printf("Received message: %s\n", buffer);
        close(new_socket);
    }
    
    return NULL;
}

void* nodeClient(void* arg) {
    int sock = 0;
    struct sockaddr_in serv_addr;
    
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error\n");
        return NULL;
    }
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("Invalid address or address not supported\n");
        return NULL;
    }
    
    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection failed\n");
        return NULL;
    }
    
    char message[BUFFER_SIZE];
    snprintf(message, sizeof(message), "Hello from Node %d", *(int*)arg);
    send(sock, message, strlen(message), 0);
    
    close(sock);
    return NULL;
}

int main() {
    pthread_t serverThread;
    Node* nodes[MAX_NODES];
    
    for (int i = 0; i < MAX_NODES; i++) {
        nodes[i] = createNode(i);
    }
    
    // Creating connections
    connectNodes(nodes[0], nodes[1]);
    connectNodes(nodes[1], nodes[2]);
    connectNodes(nodes[2], nodes[3]);
    connectNodes(nodes[3], nodes[4]);
    connectNodes(nodes[4], nodes[0]);
    
    visualizeGraph(nodes, MAX_NODES);
    
    // Starting server thread
    pthread_create(&serverThread, NULL, nodeServer, NULL);
    
    // Creating client threads to send messages
    for (int i = 0; i < MAX_NODES; i++) {
        pthread_t clientThread;
        pthread_create(&clientThread, NULL, nodeClient, (void*)&nodes[i]->id);
        pthread_detach(clientThread);
        sleep(1); // Give some time for the server to accept connections
    }

    // Wait for serverThread to finish (it won't in this case)
    pthread_join(serverThread, NULL);
    
    // Cleanup
    for (int i = 0; i < MAX_NODES; i++) {
        free(nodes[i]);
    }

    return 0;
}