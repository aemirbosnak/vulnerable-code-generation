//GEMINI-pro DATASET v1.0 Category: Networking ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

// A simple echo server that listens on a specified port and echoes back any data it receives.
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    // Parse the port number.
    int port = atoi(argv[1]);

    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    // Set the socket options.
    int optval = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *)&optval, sizeof(optval));

    // Bind the socket to the port.
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind");
        return 1;
    }

    // Listen for incoming connections.
    if (listen(sockfd, 5) < 0) {
        perror("listen");
        return 1;
    }

    // Accept incoming connections.
    while (1) {
        struct sockaddr_in cliaddr;
        socklen_t cliaddrlen = sizeof(cliaddr);
        int connfd = accept(sockfd, (struct sockaddr *)&cliaddr, &cliaddrlen);
        if (connfd < 0) {
            perror("accept");
            continue;
        }

        // Read data from the client.
        char buf[1024];
        int nread = read(connfd, buf, sizeof(buf));
        if (nread < 0) {
            perror("read");
            close(connfd);
            continue;
        }

        // Echo the data back to the client.
        write(connfd, buf, nread);

        // Close the connection.
        close(connfd);
    }

    // Close the socket.
    close(sockfd);

    return 0;
}