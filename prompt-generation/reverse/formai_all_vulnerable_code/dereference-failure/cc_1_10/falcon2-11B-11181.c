//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 1024
#define SERVER_IP "www.google.com"

void print_usage(char *prog) {
    printf("Usage: %s [-t <test_time>] [-p <packet_size>]\n", prog);
}

int main(int argc, char *argv[]) {
    int socket_fd, client_fd, packet_size, test_time;
    char buf[BUF_SIZE];
    socklen_t client_addr_size;
    struct sockaddr_in server_addr, client_addr;

    if (argc < 3) {
        print_usage(argv[0]);
        exit(1);
    }

    packet_size = atoi(argv[2]);
    test_time = atoi(argv[1]);

    if (packet_size <= 0 || test_time <= 0) {
        fprintf(stderr, "Invalid packet size or test time\n");
        exit(1);
    }

    packet_size = htons(packet_size);

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    client_addr_size = sizeof(client_addr);
    client_fd = accept(socket_fd, (struct sockaddr *)&client_addr, &client_addr_size);
    if (client_fd < 0) {
        perror("accept");
        exit(1);
    }

    printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    if (send(client_fd, "GET / HTTP/1.1\r\nHost: ", 28, 0) < 0) {
        perror("send");
        exit(1);
    }

    if (send(client_fd, "\r\n", 2, 0) < 0) {
        perror("send");
        exit(1);
    }

    memset(buf, 0, sizeof(buf));
    if (recv(client_fd, buf, BUF_SIZE - 1, 0) < 0) {
        perror("recv");
        exit(1);
    }

    printf("Received response: %s\n", buf);

    close(client_fd);
    close(socket_fd);

    return 0;
}