//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

// Create a socket and bind it to a port
int create_and_bind_socket(int port) {
    int sockfd;
    struct sockaddr_in servaddr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to a port
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Listen for incoming connections
void listen_for_connections(int sockfd) {
    if (listen(sockfd, 5) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
}

// Accept an incoming connection
int accept_connection(int sockfd) {
    int newsockfd;
    struct sockaddr_in cliaddr;
    socklen_t clilen;

    clilen = sizeof(cliaddr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cliaddr, &clilen);

    if (newsockfd == -1) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    return newsockfd;
}

// Read data from a socket
int read_from_socket(int sockfd, char *buffer, int buffer_size) {
    int n;

    n = read(sockfd, buffer, buffer_size);
    if (n == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    return n;
}

// Write data to a socket
int write_to_socket(int sockfd, char *buffer, int buffer_size) {
    int n;

    n = write(sockfd, buffer, buffer_size);
    if (n == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    return n;
}

// Close a socket
void close_socket(int sockfd) {
    close(sockfd);
}

// Main function
int main(int argc, char *argv[]) {
    int sockfd, newsockfd, port;
    char buffer[256];
    int n;

    // Get the port number from the command line
    if (argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    port = atoi(argv[1]);

    // Create a socket and bind it to a port
    sockfd = create_and_bind_socket(port);

    // Listen for incoming connections
    listen_for_connections(sockfd);

    // Accept an incoming connection
    newsockfd = accept_connection(sockfd);

    // Read data from the client
    n = read_from_socket(newsockfd, buffer, sizeof(buffer));

    // Write data to the client
    write_to_socket(newsockfd, buffer, n);

    // Close the sockets
    close_socket(newsockfd);
    close_socket(sockfd);

    return 0;
}