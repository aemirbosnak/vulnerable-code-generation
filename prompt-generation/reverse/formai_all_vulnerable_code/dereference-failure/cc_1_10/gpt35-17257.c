//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: asynchronous
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BACKLOG 10 // Number of connections allowed to queue up
#define MAX_DATA_SIZE 1024 // Maximum number of bytes for data

// Function to handle error messages
void error(char *msg) {
    perror(msg);
    exit(1);
}

// Function to send data from one socket to another
void send_data(int from_fd, int to_fd) {
    char buffer[MAX_DATA_SIZE];
    ssize_t bytes_read = recv(from_fd, buffer, MAX_DATA_SIZE, 0);
    if (bytes_read <= 0) {
        return;
    }
    send(to_fd, buffer, bytes_read, 0);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        error("Usage: ./proxy <local port> <remote host>");
    }

    int local_port = atoi(argv[1]); // The port the proxy will listen on
    char *remote_host = argv[2]; // The host name the proxy will connect to
    int remote_port = 80; // The default port for HTTP

    // Resolve the remote host name to an IP address
    struct hostent *he = gethostbyname(remote_host);
    if (!he) {
        error("Could not resolve hostname.");
    }
    char *remote_ip = inet_ntoa(*((struct in_addr *)he->h_addr));

    // Define the local address structure for the proxy
    struct sockaddr_in local_addr;
    local_addr.sin_family = AF_INET; // IPv4
    local_addr.sin_port = htons(local_port); // Convert the port number to network byte order
    local_addr.sin_addr.s_addr = INADDR_ANY; // Listen on all available interfaces
    memset(local_addr.sin_zero, '\0', sizeof local_addr.sin_zero);

    // Create the socket for the proxy to listen on
    int local_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (local_fd == -1) {
        error("Could not create local socket.");
    }

    // Make the socket reusable
    int reuseaddr = 1;
    if (setsockopt(local_fd, SOL_SOCKET, SO_REUSEADDR, &reuseaddr, sizeof(int)) == -1) {
        error("Could not make local socket reusable.");
    }

    // Bind the socket to the local address
    if (bind(local_fd, (struct sockaddr *)&local_addr, sizeof local_addr) == -1) {
        error("Could not bind local socket.");
    }

    // Start listening for incoming connections
    if (listen(local_fd, BACKLOG) == -1) {
        error("Could not listen on local socket.");
    }

    while (1) { // Continue running until exited
        struct sockaddr_in remote_addr;
        socklen_t sin_size = sizeof remote_addr;

        // Accept an incoming connection
        int client_fd = accept(local_fd, (struct sockaddr *)&remote_addr, &sin_size);
        if (client_fd == -1) {
            error("Could not accept client socket.");
        }

        if (fork() == 0) { // Child process
            close(local_fd); // Close the listening socket in the child process

            // Define the remote address structure for the proxy to connect to
            remote_addr.sin_family = AF_INET;
            remote_addr.sin_port = htons(remote_port);
            remote_addr.sin_addr.s_addr = inet_addr(remote_ip);
            memset(remote_addr.sin_zero, '\0', sizeof remote_addr.sin_zero);

            // Create a socket for the proxy to connect to the remote server
            int remote_fd = socket(AF_INET, SOCK_STREAM, 0);
            if (remote_fd == -1) {
                error("Could not create remote socket.");
            }

            // Connect to the remote server
            if (connect(remote_fd, (struct sockaddr *)&remote_addr, sizeof remote_addr) == -1) {
                error("Could not connect to remote server.");
            }

            // Set the sockets to non-blocking mode
            fcntl(client_fd, F_SETFL, O_NONBLOCK);
            fcntl(remote_fd, F_SETFL, O_NONBLOCK);

            fd_set fds; // File descriptor set
            int max_fd = (client_fd > remote_fd ? client_fd : remote_fd) + 1; // Maximum file descriptor value plus 1

            while (1) { // Continue running until the connection is closed
                // Clear the file descriptor set and add the sockets to it
                FD_ZERO(&fds);
                FD_SET(client_fd, &fds);
                FD_SET(remote_fd, &fds);

                // Wait for activity on the sockets
                int activity = select(max_fd, &fds, NULL, NULL, NULL);
                if (activity == -1) {
                    error("Error in select.");
                }

                if (FD_ISSET(client_fd, &fds)) { // Client has data to send
                    send_data(client_fd, remote_fd);
                }

                if (FD_ISSET(remote_fd, &fds)) { // Remote server has data to send
                    send_data(remote_fd, client_fd);
                }
            }

            close(remote_fd);
            close(client_fd);
            exit(0);
        }

        close(client_fd); // Close the client socket in the parent process
    }

    return 0;
}