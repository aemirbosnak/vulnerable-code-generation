//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

// Function to handle client requests
void handle_client(int client_fd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Receive data from the client
    if ((bytes_received = recv(client_fd, buffer, BUFFER_SIZE, 0)) <= 0) {
        perror("recv");
        close(client_fd);
        return;
    }

    // Process the client's request
    // ...

    // Send a response to the client
    if (send(client_fd, buffer, bytes_received, 0) == -1) {
        perror("send");
        close(client_fd);
        return;
    }

    // Close the client socket
    close(client_fd);
}

// Function to set a socket to non-blocking mode
int set_nonblocking(int fd) {
    int flags;

    if ((flags = fcntl(fd, F_GETFL, 0)) == -1) {
        perror("fcntl");
        return -1;
    }

    if (fcntl(fd, F_SETFL, flags | O_NONBLOCK) == -1) {
        perror("fcntl");
        return -1;
    }

    return 0;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the port number from the command line
    int port = atoi(argv[1]);

    // Create a socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set the socket to non-blocking mode
    if (set_nonblocking(server_fd) == -1) {
        perror("set_nonblocking");
        close(server_fd);
        return EXIT_FAILURE;
    }

    // Bind the socket to the port
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        close(server_fd);
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) == -1) {
        perror("listen");
        close(server_fd);
        return EXIT_FAILURE;
    }

    // Initialize the set of active sockets
    fd_set active_fds;
    FD_ZERO(&active_fds);

    // Add the server socket to the set of active sockets
    FD_SET(server_fd, &active_fds);

    // Loop forever, handling incoming connections and requests
    while (1) {
        // Select the active sockets
        fd_set read_fds = active_fds;

        struct timeval timeout;
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;

        int select_result = select(FD_SETSIZE, &read_fds, NULL, NULL, &timeout);

        if (select_result == -1) {
            perror("select");
            close(server_fd);
            return EXIT_FAILURE;
        }

        // Check if there are any incoming connections
        if (FD_ISSET(server_fd, &read_fds)) {
            // Accept the incoming connection
            int client_fd = accept(server_fd, NULL, NULL);
            if (client_fd == -1) {
                perror("accept");
                close(server_fd);
                return EXIT_FAILURE;
            }

            // Set the client socket to non-blocking mode
            if (set_nonblocking(client_fd) == -1) {
                perror("set_nonblocking");
                close(client_fd);
                close(server_fd);
                return EXIT_FAILURE;
            }

            // Add the client socket to the set of active sockets
            FD_SET(client_fd, &active_fds);
        }

        // Check for data on the active sockets
        for (int fd = 0; fd < FD_SETSIZE; fd++) {
            if (FD_ISSET(fd, &read_fds) && fd != server_fd) {
                // Handle the client request
                handle_client(fd);
            }
        }
    }

    // Close the server socket
    close(server_fd);

    return EXIT_SUCCESS;
}