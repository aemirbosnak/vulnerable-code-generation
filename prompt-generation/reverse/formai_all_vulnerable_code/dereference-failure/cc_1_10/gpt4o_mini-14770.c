//GPT-4o-mini DATASET v1.0 Category: Simple Web Server ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

#define PORT 8080
#define BACKLOG 5
#define BUFFER_SIZE 1024

void* handle_client(void* client_socket) {
    int new_socket = *((int*)client_socket);
    free(client_socket);
    
    char buffer[BUFFER_SIZE];
    recv(new_socket, buffer, BUFFER_SIZE, 0);

    printf("Received request:\n%s\n", buffer);
    
    // Simple HTTP response
    char *response = "HTTP/1.1 200 OK\r\n"
                     "Content-Type: text/html\r\n"
                     "Content-Length: 48\r\n"
                     "\r\n"
                     "<html><body><h1>Hello, Client!</h1></body></html>";
    
    write(new_socket, response, strlen(response));
    close(new_socket);
    return NULL;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Set socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    
    // Bind the socket to the specified port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Start listening for connections
    if (listen(server_fd, BACKLOG) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);
    
    // Infinite loop to accept connections
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        
        // Print IP address of the connected client
        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &address.sin_addr, client_ip, sizeof(client_ip));
        printf("New connection from %s on port %d\n", client_ip, ntohs(address.sin_port));
        
        // Create thread to handle the client
        pthread_t thread_id;
        int* pclient = malloc(sizeof(int));
        *pclient = new_socket;
        if (pthread_create(&thread_id, NULL, handle_client, pclient) != 0) {
            perror("pthread_create");
            free(pclient);
        }
        pthread_detach(thread_id); // Detach the thread
    }

    return 0;
}