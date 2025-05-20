//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

typedef struct socket_descriptor {
    int fd;
    char* host;
    int port;
} socket_descriptor;

int create_socket(socket_descriptor* sock) {
    if ((sock->fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return -1;
    }
    return 0;
}

int connect_to_server(socket_descriptor* sock) {
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(sock->port);
    if (inet_pton(AF_INET, sock->host, &serv_addr.sin_addr) <= 0) {
        perror("inet_pton");
        return -1;
    }
    if (connect(sock->fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return -1;
    }
    return 0;
}

int send_request(socket_descriptor* sock, char* request) {
    int len = strlen(request);
    if (send(sock->fd, request, len, 0) != len) {
        perror("send");
        return -1;
    }
    return 0;
}

int receive_response(socket_descriptor* sock, char* buffer, size_t len) {
    int nread;
    while ((nread = recv(sock->fd, buffer, len, 0)) > 0) {
        if (nread == len)
            return 0;
        buffer += nread;
        len -= nread;
    }
    if (nread < 0) {
        perror("recv");
        return -1;
    }
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return -1;
    }
    socket_descriptor sock;
    sock.host = argv[1];
    sock.port = atoi(argv[2]);

    if (create_socket(&sock) < 0)
        return -1;
    if (connect_to_server(&sock) < 0)
        return -1;

    char request[] = "GET / HTTP/1.1\r\n\r\n";
    if (send_request(&sock, request) < 0)
        return -1;

    char buffer[4096];
    if (receive_response(&sock, buffer, sizeof(buffer)) < 0)
        return -1;

    printf("%s", buffer);

    close(sock.fd);
    return 0;
}