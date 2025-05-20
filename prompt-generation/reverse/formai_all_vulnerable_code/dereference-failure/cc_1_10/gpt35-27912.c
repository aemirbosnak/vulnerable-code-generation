//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFSIZE 8192
#define ERROR(msg) { perror(msg); exit(1); }

void relay(int fd1, int fd2) {
    char buffer[BUFSIZE];
    int read_size = recv(fd1, buffer, BUFSIZE, 0);
    while (read_size > 0) {
        if (send(fd2, buffer, read_size, 0) < 0) {
            ERROR("send() failed");
        }
        read_size = recv(fd1, buffer, BUFSIZE, 0);
    }
}

int main(int argc, char **argv) {
    if (argc != 3) { fprintf(stderr, "usage: %s <target-ip> <target-port>\n", argv[0]); exit(1); }

    // create server socket
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) { ERROR("socket() failed"); }

    // bind server socket to local address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8080);
    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        ERROR("bind() failed");
    }

    // listen for incoming connections
    if (listen(server_sock, SOMAXCONN) < 0) { ERROR("listen() failed"); }

    // accept and handle incoming connections
    int client_sock;
    struct sockaddr_in client_addr;
    socklen_t addrlen = sizeof(client_addr);
    while ((client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &addrlen))) {
        printf("accepted connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // create target socket
        int target_sock = socket(AF_INET, SOCK_STREAM, 0);
        if (target_sock < 0) { ERROR("socket() failed"); }

        // connect to target server
        struct sockaddr_in target_addr;
        memset(&target_addr, 0, sizeof(target_addr));
        target_addr.sin_family = AF_INET;
        target_addr.sin_addr.s_addr = inet_addr(argv[1]);
        target_addr.sin_port = htons(strtol(argv[2], (char**)NULL, 10));
        if (connect(target_sock, (struct sockaddr*)&target_addr, sizeof(target_addr)) < 0) {
            ERROR("connect() failed");
        }

        // relay traffic between client and target sockets
        if (fork() == 0) {
            close(server_sock);
            relay(client_sock, target_sock);
            close(target_sock);
            exit(0);
        }
        close(client_sock);
    }
    close(server_sock);
    return 0;
}