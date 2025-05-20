//Falcon2-11B DATASET v1.0 Category: Networking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main() {
    // Create a socket
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;
    int len = sizeof(server_addr);

    // Initialize the socket address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Bind the socket to the address
    if (bind(sockfd, (struct sockaddr *)&server_addr, len) < 0) {
        fprintf(stderr, "Error binding socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    listen(sockfd, 5);

    // Accept incoming connections
    int client_fd;
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    client_fd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
    if (client_fd < 0) {
        fprintf(stderr, "Error accepting connection: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Send a message to the client
    send(client_fd, "Hello, client!", strlen("Hello, client!"), 0);

    // Close the socket
    close(sockfd);
    close(client_fd);

    return 0;
}