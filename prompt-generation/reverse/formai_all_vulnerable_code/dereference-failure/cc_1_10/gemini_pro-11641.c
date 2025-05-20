//GEMINI-pro DATASET v1.0 Category: System administration ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <errno.h>

#define PORT 8080

static int server_socket;

static void sigint_handler(int signo) {
    if (signo == SIGINT) {
        close(server_socket);
        exit(0);
    }
}

static void handle_client(int client_socket) {
    char buffer[1024];
    int n;

    while ((n = read(client_socket, buffer, sizeof(buffer))) > 0) {
        write(client_socket, buffer, n);
    }

    if (n < 0) {
        perror("read");
    }

    close(client_socket);
}

int main(int argc, char *argv[]) {
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    socklen_t client_addr_len;
    int client_socket;

    signal(SIGINT, sigint_handler);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(server_socket, 5) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        client_addr_len = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            if (errno == EINTR) {
                continue;
            }
            perror("accept");
            exit(1);
        }

        pid_t pid = fork();
        if (pid == 0) {
            close(server_socket);
            handle_client(client_socket);
            exit(0);
        } else if (pid > 0) {
            close(client_socket);
        } else {
            perror("fork");
            exit(1);
        }
    }

    return 0;
}