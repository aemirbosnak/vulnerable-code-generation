//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sys/time.h>
#include <assert.h>

#define BUF_SIZE 1024

static int server_socket;

void sigint_handler(int signum) {
    if (server_socket != -1) {
        close(server_socket);
    }
    exit(0);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);
    if (port <= 0 || port > 65535) {
        fprintf(stderr, "Invalid port number: %d\n", port);
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        exit(1);
    }

    int reuseaddr = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &reuseaddr, sizeof(reuseaddr)) == -1) {
        perror("setsockopt");
        close(server_socket);
        exit(1);
    }

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        close(server_socket);
        exit(1);
    }

    if (listen(server_socket, 5) == -1) {
        perror("listen");
        close(server_socket);
        exit(1);
    }

    signal(SIGINT, sigint_handler);

    fd_set read_fds;
    while (1) {
        FD_ZERO(&read_fds);
        FD_SET(server_socket, &read_fds);

        struct timeval timeout = { 1, 0 };
        int nfds = select(server_socket + 1, &read_fds, NULL, NULL, &timeout);
        if (nfds == -1) {
            perror("select");
            close(server_socket);
            exit(1);
        }

        if (FD_ISSET(server_socket, &read_fds)) {
            struct sockaddr_in client_addr;
            socklen_t client_addr_len = sizeof(client_addr);
            int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
            if (client_socket == -1) {
                perror("accept");
                continue;
            }

            // Create a new thread to handle the client connection
            pid_t child_pid = fork();
            if (child_pid == 0) {
                // Child process
                close(server_socket);

                char buf[BUF_SIZE];
                while (1) {
                    memset(buf, 0, BUF_SIZE);
                    int bytes_received = recv(client_socket, buf, BUF_SIZE - 1, 0);
                    if (bytes_received == -1) {
                        perror("recv");
                        close(client_socket);
                        exit(1);
                    } else if (bytes_received == 0) {
                        // Client closed the connection
                        printf("Client closed connection\n");
                        close(client_socket);
                        exit(0);
                    }

                    // Process the data received from the client
                    printf("Received: %s\n", buf);

                    // Send a response back to the client
                    int bytes_sent = send(client_socket, buf, strlen(buf), 0);
                    if (bytes_sent == -1) {
                        perror("send");
                        close(client_socket);
                        exit(1);
                    }
                }
            } else if (child_pid > 0) {
                // Parent process
                close(client_socket);
            } else {
                // Error creating child process
                perror("fork");
                close(client_socket);
            }
        }
    }

    close(server_socket);
    return 0;
}