//FormAI DATASET v1.0 Category: Networking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 12345
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 5

void *handle_client(void *arg);

int main(void) {
    int server_socket, client_socket, addr_size;
    struct sockaddr_in server_addr, client_addr;
    pthread_t thread_id;
    int client_cnt = 0;
    int *client_sockets;
    
    // Create server socket
    if((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }
    
    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // use current IP address
    server_addr.sin_port = htons(PORT);
    
    // Bind server socket to address
    if(bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding server socket");
        exit(EXIT_FAILURE);
    }
    
    // Listen for incoming connections
    if(listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Error listening for incoming connections");
        exit(EXIT_FAILURE);
    }
    
    printf("Server listening on port %d\n", PORT);
    
    client_sockets = calloc(MAX_CLIENTS, sizeof(int));
    
    while(1) {
        addr_size = sizeof(client_addr);
        if((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t *)&addr_size)) < 0) {
            perror("Error accepting incoming connection");
            exit(EXIT_FAILURE);
        }
        
        client_cnt++;
        if(client_cnt <= MAX_CLIENTS) {
            client_sockets[client_cnt-1] = client_socket;
            printf("Client connected, ID: %d\n", client_cnt);
            pthread_create(&thread_id, NULL, handle_client, (void *)&client_sockets[client_cnt-1]);
        }
        else {
            printf("Maximum number of clients reached\n");
            close(client_socket);
        }
    }
    
    close(server_socket);
    free(client_sockets);
    return 0;
}

void *handle_client(void *arg) {
    int socket = *(int*)arg;
    char buffer[BUFFER_SIZE];
    int bytes_recv;
    
    while((bytes_recv = recv(socket, buffer, BUFFER_SIZE, 0)) > 0) {
        printf("Received message from client: %s", buffer);
        // Send message back to client
        send(socket, buffer, bytes_recv, 0);
        memset(buffer, 0, BUFFER_SIZE);
    }
    
    printf("Client disconnected\n");
    close(socket);
    pthread_exit(NULL);
}