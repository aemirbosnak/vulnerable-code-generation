//FormAI DATASET v1.0 Category: Simple Web Server ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sys/wait.h>

#define LISTEN_BACKLOG 50
#define MAX_BUFFER_SIZE 2048

static void handle_sigchld(int signum) {
    (void)signum;

    // Reap child processes that have exited to prevent zombies
    while (waitpid(-1, NULL, WNOHANG) > 0) {}
}

static void handle_connection(int fd) {
    char buffer[MAX_BUFFER_SIZE];
    ssize_t recv_size;

    // Read request from client
    recv_size = recv(fd, buffer, sizeof(buffer), 0);
    if (recv_size == 0) {
        fprintf(stderr, "Client closed connection\n");
        return;
    } else if (recv_size == -1) {
        perror("recv");
        return;
    }

    // Null-terminate the buffer for string manipulation
    buffer[recv_size] = '\0';

    // Print request for debugging purposes
    printf("Received request from client:\n%s\n", buffer);

    // Generate a response
    const char *response = "HTTP/1.1 200 OK\r\n"
                            "Content-Type: text/plain\r\n"
                            "Content-Length: 13\r\n"
                            "\r\n"
                            "Hello, World!";
    size_t response_size = strlen(response);

    // Send response to client
    ssize_t send_size = send(fd, response, response_size, 0);
    if (send_size == -1) {
        perror("send");
        return;
    } else if (send_size != response_size) {
        fprintf(stderr, "Incomplete send\n");
        return;
    }
}

int main(int argc, char *argv[]) {
    (void)argc;
    (void)argv;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set socket options to allow reuse of address and port
    int optval = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
        perror("setsockopt");
        return EXIT_FAILURE;
    }

    // Bind socket to port 8080
    struct sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(8080)
    };
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(sockfd, LISTEN_BACKLOG) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    // Register signal handler to reap child processes
    signal(SIGCHLD, handle_sigchld);

    while (1) {
        // Accept incoming connection
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int clientfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (clientfd == -1) {
            if (errno == EINTR) {
                continue;
            } else {
                perror("accept");
                return EXIT_FAILURE;
            }
        }

        // Fork a child process to handle the connection
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            return EXIT_FAILURE;
        } else if (pid == 0) {
            close(sockfd);
            handle_connection(clientfd);
            close(clientfd);
            exit(EXIT_SUCCESS);
        }

        // Parent process continues to accept more connections
        close(clientfd);
    }

    close(sockfd);
    return EXIT_SUCCESS;
}