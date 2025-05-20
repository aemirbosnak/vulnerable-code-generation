//FormAI DATASET v1.0 Category: Networking ; Style: optimized
// A unique C Networking example program
// This program implements a server that accepts connections from multiple clients,
// and echoes back any messages it receives from the clients.
// It also allows the clients to disconnect gracefully.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define BACKLOG 10
#define BUFF_SIZE 1024

volatile sig_atomic_t stop = 0;

void handle_sigint(int sig) {
    stop = 1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);

    // Create a socket for listening for connections
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1) {
        perror("socket");
        return 1;
    }

    // Set socket options to allow reuse of address and port
    int optval = 1;
    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
        perror("setsockopt");
        return 1;
    }

    // Bind the socket to a port
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(port),
        .sin_addr.s_addr = INADDR_ANY
    };
    if (bind(listenfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        return 1;
    }

    // Start listening for connections
    if (listen(listenfd, BACKLOG) == -1) {
        perror("listen");
        return 1;
    }

    // Register signal handler for SIGINT
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = handle_sigint;
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    // Loop to accept connections and handle IO with clients
    while (!stop) {
        // Accept a connection from a client
        struct sockaddr_in client_addr;
        socklen_t client_addrlen = sizeof(client_addr);
        int connfd = accept(listenfd, (struct sockaddr *)&client_addr, &client_addrlen);
        if (connfd == -1) {
            if (errno == EINTR) {
                // Signal interrupted accept, continue looping
                continue;
            } else {
                perror("accept");
                return 1;
            }
        }

        // Handle IO with client
        char buff[BUFF_SIZE];
        ssize_t num_read;
        while ((num_read = read(connfd, buff, BUFF_SIZE)) > 0) {
            if (write(connfd, buff, num_read) != num_read) {
                perror("write");
                break;
            }
        }

        // Close connection with client
        if (num_read == -1) {
            perror("read");
        }
        if (close(connfd) == -1) {
            perror("close");
            return 1;
        }
    }

    // Close the listening socket
    if (close(listenfd) == -1) {
        perror("close");
        return 1;
    }

    return 0;
}