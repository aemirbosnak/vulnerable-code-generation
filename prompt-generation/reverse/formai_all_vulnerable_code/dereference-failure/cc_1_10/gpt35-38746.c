//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_RECV_BUFF 1024

// Function to create a socket and connect to server
int create_socket(char *host, char *port) {
    struct addrinfo hints, *servinfo, *p;
    int sock_fd, status;
    
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((status = getaddrinfo(host, port, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(1);
    }

    for (p = servinfo; p != NULL; p = p->ai_next) {
        if ((sock_fd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket error");
            continue;
        }

        if (connect(sock_fd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sock_fd);
            perror("connect error");
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "failed to create socket\n");
        exit(1);
    }

    freeaddrinfo(servinfo);
    return sock_fd;
}

// Function to send HTTP GET request to server and print the response
void send_get_request(int sock_fd, char *host, char *path) {
    char send_buff[1024];
    char recv_buff[MAX_RECV_BUFF];
    int bytes_recv;
    sprintf(send_buff, "GET /%s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);

    if (send(sock_fd, send_buff, strlen(send_buff), 0) == -1) {
        perror("send error");
        exit(1);
    }

    bytes_recv = recv(sock_fd, recv_buff, MAX_RECV_BUFF, 0);

    if (bytes_recv == -1) {
        perror("recv error");
        exit(1);
    }

    printf("HTTP Response:\n%s\n", recv_buff);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    int sock_fd = create_socket(argv[1], argv[2]);
    printf("Connected to %s:%s\n", argv[1], argv[2]);

    send_get_request(sock_fd, argv[1], "index.html");

    close(sock_fd);
    return 0;
}