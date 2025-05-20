//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// function to handle client requests
void handle_request(int client_socket) {
    char buffer[1024];
    int read_size, sent_size;
    
    // receive message from client
    if ((read_size = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        printf("Received message: %s", buffer);
        
        // send response to client
        char message[] = "Hello from server!";
        sent_size = send(client_socket, message, strlen(message), 0);
        printf("Sent message: %s\n", message);
    }
    close(client_socket);
}

int main(int argc, char *argv[]) {
    int server_socket, client_socket, port_number;
    struct sockaddr_in server_address, client_address;
    
    // set default port number and IP address
    port_number = 8080;
    char *ip_address = "127.0.0.1";
    
    // custom configuration from command-line arguments
    if (argc == 3) {
        ip_address = argv[1];
        port_number = atoi(argv[2]);
    }
    
    // create socket for server
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // configure server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(ip_address);
    server_address.sin_port = htons(port_number);
    
    // bind socket to server address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Socket binding failed");
        exit(EXIT_FAILURE);
    }
    
    // listen for incoming client connections
    if (listen(server_socket, 5) == -1) {
        perror("Socket listening failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Server listening on %s:%d\n", ip_address, port_number);
    
    // accept incoming client connections
    while (1) {
        int client_length = sizeof(client_address);
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t *)&client_length)) == -1) {
            perror("Socket accept failed");
            exit(EXIT_FAILURE);
        }
        
        printf("Client connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        
        // handle client requests in separate process
        if (fork() == 0) {
            handle_request(client_socket);
            exit(0);
        }
    }
    
    close(server_socket);
    return 0;
}