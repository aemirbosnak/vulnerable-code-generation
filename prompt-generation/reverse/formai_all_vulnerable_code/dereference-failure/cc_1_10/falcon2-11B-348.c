//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: scalable
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

// Function to create a TCP socket
int create_socket(int port) {
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding to socket");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Function to accept incoming connections
int accept_connections(int sockfd, int port) {
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    if ((sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len)) < 0) {
        perror("Error accepting connection");
        exit(EXIT_FAILURE);
    }

    printf("Connection accepted from: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // Read data from the client
    char buffer[1024];
    ssize_t bytes_read = read(sockfd, buffer, sizeof(buffer));

    if (bytes_read < 0) {
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }

    printf("Received data: %s\n", buffer);

    // Send data to the client
    printf("Sending data back to client...\n");
    write(sockfd, "Hello, client!\n", strlen("Hello, client!"));

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int port = atoi(argv[1]);
    int sockfd = create_socket(port);
    accept_connections(sockfd, port);

    return 0;
}