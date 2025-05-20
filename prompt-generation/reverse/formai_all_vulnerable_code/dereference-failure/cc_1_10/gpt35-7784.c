//FormAI DATASET v1.0 Category: Client Server Application ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <signal.h>

#define MAX_BUFFER_SIZE 1024
#define SERVER_PORT 5555
#define MAX_CONNECTIONS 10

char buffer[MAX_BUFFER_SIZE];

// Signal handler to handle keyboard interrupts
void handle_sigint(int sig) {
    printf("\nCTRL-C detected, shutting down server...\n");
    exit(0);
}

// Function to make the file descriptor non-blocking
void make_non_blocking(int fd) {
    int flags = fcntl(fd, F_GETFL, 0);
    fcntl(fd, F_SETFL, flags | O_NONBLOCK);
}

// Function to create the server socket
int create_server_socket() {
    int server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket_fd < 0) {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }

    int opt_val = 1;
    setsockopt(server_socket_fd, SOL_SOCKET, SO_REUSEADDR, &opt_val, sizeof opt_val);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(SERVER_PORT);

    int bind_result = bind(server_socket_fd, (struct sockaddr*)&server_address, sizeof(server_address));
    if (bind_result < 0) {
        perror("Error binding server socket");
        exit(EXIT_FAILURE);
    }

    return server_socket_fd;
}

int main(int argc, char* argv[]) {
    signal(SIGINT, handle_sigint); // Set up signal handler for CTRL-C

    int server_socket_fd = create_server_socket();

    int listen_result = listen(server_socket_fd, MAX_CONNECTIONS);
    if (listen_result < 0) {
        perror("Error listening");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", SERVER_PORT);
    fflush(stdout);

    make_non_blocking(server_socket_fd); // Make server socket non-blocking

    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(server_socket_fd, &read_fds);

    while (1) {
        fd_set copy = read_fds;
        int num_fds = select(FD_SETSIZE, &copy, NULL, NULL, NULL);

        for (int fd = 0; fd < FD_SETSIZE; fd++) {
            if (FD_ISSET(fd, &copy)) {
                if (fd == server_socket_fd) { // New client connection
                    int client_socket_fd = accept(server_socket_fd, NULL, NULL);
                    if (client_socket_fd < 0) {
                        if (errno != EWOULDBLOCK) {
                            perror("Error accepting new connection");
                            exit(EXIT_FAILURE);
                        }
                    } else {
                        make_non_blocking(client_socket_fd);
                        FD_SET(client_socket_fd, &read_fds);
                        printf("New client connected with file descriptor %d\n", client_socket_fd);
                        fflush(stdout);
                    }
                } else { // Existing client sending message
                    int num_bytes_received = recv(fd, buffer, MAX_BUFFER_SIZE, 0);
                    if (num_bytes_received < 0) {
                        if (errno != EWOULDBLOCK) {
                            perror("Error receiving from client");
                            exit(EXIT_FAILURE);
                        }
                    } else if (num_bytes_received == 0) {
                        // Client has closed connection
                        printf("Client with file descriptor %d has disconnected\n", fd);
                        fflush(stdout);
                        close(fd);
                        FD_CLR(fd, &read_fds);
                    } else {
                        printf("Received message \"%.*s\" from client with file descriptor %d\n", num_bytes_received, buffer, fd);
                        fflush(stdout);
                    }
                }
            }
        }
    }

    return 0;
}