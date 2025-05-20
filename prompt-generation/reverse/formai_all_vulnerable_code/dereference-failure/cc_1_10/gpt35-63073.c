//FormAI DATASET v1.0 Category: Chat server ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define DEFAULT_PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    // Variable declarations
    int server_sockfd, client_sockfd, client_address_size;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE];

    // Allow configuration through command line arguments
    int port = DEFAULT_PORT;
    if(argc > 1) {
        port = atoi(argv[1]);
    }

    // Create socket
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_sockfd == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set server address
    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(port);

    // Bind socket to address and port
    if(bind(server_sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Error binding socket");
        close(server_sockfd);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if(listen(server_sockfd, MAX_CLIENTS) == -1) {
        perror("Error listening for incoming connections");
        close(server_sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %d\n", port);

    // Accept incoming connections
    while(1) {

        // Clear buffer
        memset(&buffer, 0, sizeof(buffer));

        // Get client address
        client_address_size = sizeof(client_address);

        // Accept connection
        client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &client_address_size);
        if(client_sockfd == -1) {
            perror("Error accepting connection");
            close(server_sockfd);
            exit(EXIT_FAILURE);
        }

        printf("Accepted a connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Receive message from client
        if(recv(client_sockfd, buffer, BUFFER_SIZE, 0) == -1) {
            perror("Error receiving message from client");
            close(client_sockfd);
            continue;
        }

        printf("Received message from client: %s", buffer);

        // Send message to client
        if(send(client_sockfd, buffer, strlen(buffer), 0) == -1) {
            perror("Error sending message to client");
            close(client_sockfd);
            continue;
        }

        printf("Sent message to client: %s", buffer);

        // Close client socket
        close(client_sockfd);

    }

    // Close server socket
    close(server_sockfd);
    
    return 0;
}