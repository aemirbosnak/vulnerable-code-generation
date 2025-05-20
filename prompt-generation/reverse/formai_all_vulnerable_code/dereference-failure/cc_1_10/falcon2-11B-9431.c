//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int server_fd, client_fd, n;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addrlen;

    if (argc < 2) {
        fprintf(stderr, "usage: %s port\n", argv[0]);
        exit(1);
    }

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(server_fd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    addrlen = sizeof(client_addr);
    client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addrlen);
    if (client_fd < 0) {
        perror("accept");
        exit(1);
    }

    char buffer[1024];
    n = read(client_fd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("read");
        exit(1);
    }
    printf("Received message: %s\n", buffer);

    n = write(client_fd, "Message received", sizeof("Message received"));
    if (n < 0) {
        perror("write");
        exit(1);
    }

    close(client_fd);
    close(server_fd);

    return 0;
}