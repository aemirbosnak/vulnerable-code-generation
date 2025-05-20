//FormAI DATASET v1.0 Category: Simple Web Server ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_HTTP_SIZE 1024
#define PORT 8080
#define MAX_CONNECTIONS 10

void *connection_handler(void *);

int main(int argc, char *argv[]) {

    int socket_desc, client_sock, c, *new_sock;
    struct sockaddr_in server, client;
    
    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc < 0) {
        printf("Could not create socket\n");
        return 1;
    }
    
    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);
    
    // Bind
    if (bind(socket_desc, (struct sockaddr *) &server, sizeof(server)) < 0) {
        printf("Bind failed\n");
        return 1;
    }
    
    // Listen
    listen(socket_desc, MAX_CONNECTIONS);
    printf("Server listening on port %d\n", PORT);
    
    // Accept incoming connections
    c = sizeof(struct sockaddr_in);
    while ((client_sock = accept(socket_desc, (struct sockaddr *) &client, (socklen_t *) &c))) {
        printf("Connection accepted\n");
        
        // Create a thread for this client
        pthread_t thread_id;
        new_sock = malloc(1);
        *new_sock = client_sock;
        
        if (pthread_create(&thread_id, NULL, connection_handler, (void *) new_sock) < 0) {
            printf("Could not create thread\n");
            return 1;
        }
        
        printf("Handler assigned\n");
    }
    
    if (client_sock < 0) {
        printf("Accept failed\n");
        return 1;
    }

    return 0;
}

void *connection_handler(void *socket_desc) {
    // Get the socket descriptor
    int sock = *(int *) socket_desc;
    int read_size;
    char client_message[MAX_HTTP_SIZE];
    char *response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<!DOCTYPE html><html><body><h1>Hello, World!</h1></body></html>";
    
    // Receive message from client
    if ((read_size = recv(sock, client_message, MAX_HTTP_SIZE, 0)) > 0) {
        printf("HTTP Request received: %s\n", client_message);
        send(sock, response, strlen(response), 0);
    }
    
    if (read_size == 0) {
        printf("Client disconnected\n");
        fflush(stdout);
    } else if (read_size == -1) {
        printf("Receive failed\n");
    }
    
    // Free the socket descriptor
    free(socket_desc);
    
    return 0;
}