//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXBUF 1024

// Signal handler for SIGINT signal.
void sigint_handler(int signal_num) {
    printf("\nCaught signal %d, exiting.\n", signal_num);
    exit(0);
}

int main(int argc, char *argv[]) {
    // Check for correct number of arguments.
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;

    // Set up server address struct.
    memset(&server_addr, '\0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    // Create socket and bind.
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Server Socket: ");
        exit(EXIT_FAILURE);
    }

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Bind: ");
        exit(EXIT_FAILURE);
    }

    // Listen for connection.
    if (listen(server_socket, 10) == -1) {
        perror("Listen: ");
        exit(EXIT_FAILURE);
    }

    signal(SIGINT, sigint_handler);

    // Accept and handle connections.
    char buffer[MAXBUF];
    while(1) {
        memset(&client_addr, '\0', sizeof(client_addr));
        socklen_t addr_len = sizeof(client_addr);
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len)) == -1) {
            perror("Accept: ");
            exit(EXIT_FAILURE);
        }

        pid_t pid;
        if ((pid = fork()) == -1) {
            perror("Fork: ");
            exit(EXIT_FAILURE);
        } else if (pid > 0) {
            close(client_socket);
        } else {
            close(server_socket);

            int num_bytes;
            while ((num_bytes = recv(client_socket, buffer, MAXBUF, 0)) > 0) {
                if (send(server_socket, buffer, num_bytes, 0) == -1) {
                    perror("Send: ");
                    exit(EXIT_FAILURE);
                }
            }

            if (num_bytes == -1) {
                perror("Recv: ");
                exit(EXIT_FAILURE);
            }

            close(client_socket);
            exit(EXIT_SUCCESS);
        }
    }

    return 0;
}