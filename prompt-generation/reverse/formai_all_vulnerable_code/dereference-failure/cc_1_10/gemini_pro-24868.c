//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// A simple TCP/IP server program that listens on a specified port and echoes back any data it receives.
int main(int argc, char** argv) {
    // Check if the correct number of arguments were provided.
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the port number from the command line arguments.
    int port = atoi(argv[1]);

    // Create a socket for listening for incoming connections.
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set up the socket address structure for the server.
    struct sockaddr_in serveraddr;
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(port);

    // Bind the socket to the server address.
    if (bind(listenfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Start listening for incoming connections.
    if (listen(listenfd, 5) < 0) {
        perror("listen");
        return EXIT_FAILURE;
    }

    // Loop forever, accepting incoming connections and echoing back any data that is received.
    while (1) {
        // Accept an incoming connection.
        int connfd = accept(listenfd, NULL, NULL);
        if (connfd < 0) {
            perror("accept");
            continue;
        }

        // Read data from the client.
        char buffer[1024];
        int n = read(connfd, buffer, sizeof(buffer));
        if (n < 0) {
            perror("read");
            close(connfd);
            continue;
        }

        // Write the data back to the client.
        if (write(connfd, buffer, n) < 0) {
            perror("write");
            close(connfd);
            continue;
        }

        // Close the connection.
        close(connfd);
    }

    // Close the listening socket.
    close(listenfd);

    return EXIT_SUCCESS;
}