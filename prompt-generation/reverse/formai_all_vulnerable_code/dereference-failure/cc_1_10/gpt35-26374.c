//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_PENDING_REQUESTS 10
#define BUFFER_SIZE 4096

void handle_sigchld(int signal) {
    pid_t child_pid;
    int status;

    while ((child_pid = waitpid(-1, &status, WNOHANG)) > 0) {
        if (WIFEXITED(status)) {
            printf("[INFO] Child process %d exited with status %d\n", child_pid, WEXITSTATUS(status));
        } else {
            printf("[INFO] Child process %d terminated abnormally\n", child_pid);
        }
    }
}

void proxy(int client_fd, struct sockaddr_in client_addr) {
    char buffer[BUFFER_SIZE];
    ssize_t n_bytes;
    struct sockaddr_in server_addr;
    int server_fd;

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("[ERROR] Failed to create socket for server");
        exit(EXIT_FAILURE);
    }

    if (connect(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("[ERROR] Failed to connect to server");
        exit(EXIT_FAILURE);
    }

    while ((n_bytes = read(client_fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(server_fd, buffer, n_bytes) < 0) {
            perror("[ERROR] Failed to write to server");
            exit(EXIT_FAILURE);
        }

        if ((n_bytes = read(server_fd, buffer, BUFFER_SIZE)) > 0) {
            if (write(client_fd, buffer, n_bytes) < 0) {
                perror("[ERROR] Failed to write to client");
                exit(EXIT_FAILURE);
            }
        } else {
            perror("[ERROR] Failed to read from server");
            exit(EXIT_FAILURE);
        }
    }

    if (n_bytes < 0) {
        perror("[ERROR] Failed to read from client");
        exit(EXIT_FAILURE);
    }

    close(server_fd);
    close(client_fd);
    exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[]) {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("[ERROR] Failed to create socket for server");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("[ERROR] Failed to bind socket with address");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, MAX_PENDING_REQUESTS) < 0) {
        perror("[ERROR] Failed to listen for incoming requests");
        exit(EXIT_FAILURE);
    }

    printf("[INFO] Listening for incoming connection on 127.0.0.1:8080\n");

    signal(SIGCHLD, handle_sigchld);

    while (1) {
        socklen_t client_len = sizeof(client_addr);

        if ((client_fd = accept(server_fd, (struct sockaddr *) &client_addr, &client_len)) < 0) {
            if (errno == EINTR) continue;
            perror("[ERROR] Failed to accept incoming connection");
            exit(EXIT_FAILURE);
        }

        if (fork() == 0) {
            close(server_fd);
            proxy(client_fd, client_addr);
        }

        close(client_fd);
    }

    return 0;
}