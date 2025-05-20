//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    // Check if port number is specified
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    // Get host and port from command line arguments
    char *host = argv[1];
    int port = atoi(argv[2]);

    // Create a TCP socket
    int sockfd;
    struct sockaddr_in server;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Set up the server address
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(host);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) == -1) {
        perror("connect");
        exit(1);
    }

    // Create a new socket for communication with client
    int client_sockfd;
    struct sockaddr_in client;
    client_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Set up the client address
    client.sin_family = AF_INET;
    client.sin_port = htons(0); // placeholder
    client.sin_addr.s_addr = htonl(INADDR_ANY);

    // Bind the client socket to a random port
    if (bind(client_sockfd, (struct sockaddr *)&client, sizeof(client)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections from clients
    if (listen(client_sockfd, 5) == -1) {
        perror("listen");
        exit(1);
    }

    // Accept a connection from a client
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_sockfd2;
    client_sockfd2 = accept(client_sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_sockfd2 == -1) {
        perror("accept");
        exit(1);
    }

    // Handle incoming data from the client
    char buffer[1024];
    int n;
    while ((n = read(client_sockfd2, buffer, sizeof(buffer))) > 0) {
        // Send the data to the server
        write(sockfd, buffer, n);
    }

    // Close all sockets
    close(client_sockfd);
    close(client_sockfd2);
    close(sockfd);

    return 0;
}