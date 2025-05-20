//FormAI DATASET v1.0 Category: Client Server Application ; Style: active
// This is a simple chat program between a client and server
// The client sends a message to the server, which then broadcasts it to all other connected clients
// The server also broadcasts messages sent by other clients to all connected clients

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAXSIZE 1024

// Global variables
int client_count = 0;
int sock_fd;
int clients[10];

// Function to broadcast message to all connected clients
void broadcast(char *msg, int sender_id) {
    for (int i = 0; i < client_count; i++) {
        if (clients[i] != sender_id) {
            if (send(clients[i], msg, strlen(msg), 0) < 0) {
                perror("Send failed");
                exit(EXIT_FAILURE);
            }
        }
    }
}

// Thread function to handle incoming messages from clients
void *handle_messages(void *args) {
    char buf[MAXSIZE];
    int client_id = *(int *) args;
    int byte_count;
    
    while ((byte_count = recv(client_id, buf, MAXSIZE, 0)) > 0) {
        buf[byte_count] = '\0';
        printf("Received message from client %d: %s\n", client_id, buf);
        broadcast(buf, client_id);
        memset(buf, 0, MAXSIZE);
    }
    
    // Remove disconnected client from clients array
    for (int i = 0; i < client_count; i++) {
        if (clients[i] == client_id) {
            clients[i] = -1;
        }
    }
    client_count--;
    close(client_id);
    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    int port = atoi(argv[1]);
    
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);
    
    if (bind(sock_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    
    if (listen(sock_fd, 10) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Server running on port %d...\n", port);
    
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        
        int client_id = accept(sock_fd, (struct sockaddr *) &client_addr, &client_addr_len);
        if (client_id < 0) {
            perror("Accept failed");
            continue;
        }
        
        // Add new client to clients array
        clients[client_count] = client_id;
        client_count++;
        
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_messages, &client_id) != 0) {
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }
    }
    
    close(sock_fd);
    return 0;
}