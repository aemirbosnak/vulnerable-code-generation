//GEMINI-pro DATASET v1.0 Category: Networking ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Create a socket and bind it to a port
int create_and_bind_socket(int port) {
    int sockfd;
    struct sockaddr_in addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the socket options
    int opt = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to a port
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Listen for incoming connections
int listen_for_connections(int sockfd) {
    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    return 0;
}

// Accept an incoming connection
int accept_connection(int sockfd) {
    int newsockfd;
    struct sockaddr_in addr;
    socklen_t addrlen = sizeof(addr);

    // Accept the connection
    newsockfd = accept(sockfd, (struct sockaddr*)&addr, &addrlen);
    if (newsockfd < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    return newsockfd;
}

// Send data to a client
int send_data(int sockfd, char* data) {
    int n;

    // Send the data
    n = send(sockfd, data, strlen(data), 0);
    if (n < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    return n;
}

// Receive data from a client
int receive_data(int sockfd, char* buffer) {
    int n;

    // Receive the data
    n = recv(sockfd, buffer, 1024, 0);
    if (n < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    return n;
}

// Close a socket
int close_socket(int sockfd) {
    // Close the socket
    close(sockfd);

    return 0;
}

// Main function
int main(int argc, char* argv[]) {
    int sockfd, newsockfd, port;
    char buffer[1024];

    // Check the number of arguments
    if (argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the port number
    port = atoi(argv[1]);

    // Create a socket and bind it to a port
    sockfd = create_and_bind_socket(port);

    // Listen for incoming connections
    listen_for_connections(sockfd);

    // Accept an incoming connection
    newsockfd = accept_connection(sockfd);

    // Send data to the client
    send_data(newsockfd, "Hello, world!\n");

    // Receive data from the client
    receive_data(newsockfd, buffer);

    // Print the data received from the client
    printf("Received: %s\n", buffer);

    // Close the sockets
    close_socket(newsockfd);
    close_socket(sockfd);

    return 0;
}