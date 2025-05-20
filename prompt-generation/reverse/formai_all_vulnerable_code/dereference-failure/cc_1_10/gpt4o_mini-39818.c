//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Server code
void start_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Forcefully attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Binding the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Listening for connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    printf("Server started and listening on port %d\n", PORT);
    
    while (1) {
        // Accepting new connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        
        // Reading data from client
        read(new_socket, buffer, BUFFER_SIZE);
        
        // Calculate the square of the number
        int num = atoi(buffer);
        int square = num * num;
        
        // Send back the square
        sprintf(buffer, "%d", square);
        send(new_socket, buffer, strlen(buffer), 0);
        printf("Client sent: %d, Server responded: %d\n", num, square);
        
        // Closing the socket
        close(new_socket);
    }
}

// Client code
void start_client() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};
    
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return;
    }
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    // Convert IPv4 address from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return;
    }
    
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return;
    }
    
    // Interact with user
    int num;
    printf("Enter a number to get its square: ");
    scanf("%d", &num);
    
    // Send number to server
    sprintf(buffer, "%d", num);
    send(sock, buffer, strlen(buffer), 0);
    
    // Receive square from the server
    read(sock, buffer, BUFFER_SIZE);
    printf("Server responded with square: %s\n", buffer);
    
    // Closing socket
    close(sock);
}

int main(int argc, char const *argv[]) {
    if (argc > 1 && strcmp(argv[1], "server") == 0) {
        start_server();
    } else if (argc > 1 && strcmp(argv[1], "client") == 0) {
        start_client();
    } else {
        printf("Usage: %s server|client\n", argv[0]);
    }
    
    return 0;
}