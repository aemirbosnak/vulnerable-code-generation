//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0
#define PORT 12345
#define MAX 100
#define SA struct sockaddr

void fatal(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int create_socket(int domain, int type, int protocol) {
    int sock = socket(domain, type, protocol);
    if (sock == -1) {
        fatal("socket failed");
    }
    return sock;
}

int connect_socket(int sock, const SA *addr, socklen_t addrlen) {
    if (connect(sock, addr, addrlen) == -1) {
        fatal("connect failed");
    }
    return TRUE;
}

int send_recv_msg(int sock, char *send_msg, char *recv_msg, int max) {
    if (send(sock, send_msg, strlen(send_msg), 0) == -1) {
        fatal("send failed");
    }
    memset(recv_msg, 0, max);
    if (recv(sock, recv_msg, max, 0) == -1) {
        fatal("recv failed");
    }
    return TRUE;
}

void close_socket(int sock) {
    if (close(sock) == -1) {
        fatal("close failed");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <IP address> <port number> <message>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    int port = atoi(argv[2]);
    char *msg = argv[3];

    int sock = create_socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &server_addr.sin_addr);
    server_addr.sin_port = htons(port);

    if (!connect_socket(sock, (SA *)&server_addr, sizeof(server_addr))) {
        close_socket(sock);
        return 1;
    }

    char recv_msg[MAX];
    if (!send_recv_msg(sock, msg, recv_msg, MAX)) {
        close_socket(sock);
        return 1;
    }

    printf("Received message: %s\n", recv_msg);

    close_socket(sock);
    return 0;
}