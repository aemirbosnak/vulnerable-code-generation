//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUF_SIZE 1024

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
} client_t;

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
} server_t;

void error(char *msg) {
    perror(msg);
    exit(1);
}

void usage() {
    printf("Usage: ./proxy <listen_port> <target_host> <target_port>\n");
    exit(1);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        usage();
    }

    int listen_port = atoi(argv[1]);
    char *target_host = argv[2];
    int target_port = atoi(argv[3]);

    int listen_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sockfd < 0) {
        error("Error creating listen socket");
    }

    struct sockaddr_in listen_addr;
    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_addr.s_addr = INADDR_ANY;
    listen_addr.sin_port = htons(listen_port);

    if (bind(listen_sockfd, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) < 0) {
        error("Error binding listen socket");
    }

    if (listen(listen_sockfd, 5) < 0) {
        error("Error listening on listen socket");
    }

    while (1) {
        client_t client;
        socklen_t client_addrlen = sizeof(client.addr);
        client.sockfd = accept(listen_sockfd, (struct sockaddr *)&client.addr, &client_addrlen);
        if (client.sockfd < 0) {
            error("Error accepting client connection");
        }

        server_t server;
        server.sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (server.sockfd < 0) {
            error("Error creating server socket");
        }

        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = inet_addr(target_host);
        server_addr.sin_port = htons(target_port);

        if (connect(server.sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            error("Error connecting to server");
        }

        char buf[MAX_BUF_SIZE];
        int nread;
        while ((nread = read(client.sockfd, buf, MAX_BUF_SIZE)) > 0) {
            if (write(server.sockfd, buf, nread) != nread) {
                error("Error writing to server");
            }
        }

        if (nread < 0) {
            error("Error reading from client");
        }

        close(client.sockfd);
        close(server.sockfd);
    }

    close(listen_sockfd);

    return 0;
}