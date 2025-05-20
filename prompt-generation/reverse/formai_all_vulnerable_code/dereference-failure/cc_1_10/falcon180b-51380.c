//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <IP address> <port number> <protocol>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);
    char *protocol = argv[3];

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    struct addrinfo *server_info = NULL;
    struct addrinfo hints = {
       .ai_family = AF_INET,
       .ai_socktype = SOCK_STREAM,
       .ai_protocol = protocol
    };

    if (getaddrinfo(ip_address, NULL, &hints, &server_info)!= 0) {
        printf("Error getting address info: %s\n", gai_strerror(errno));
        close(socket_fd);
        return 1;
    }

    connect(socket_fd, server_info->ai_addr, server_info->ai_addrlen);
    freeaddrinfo(server_info);

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    if (send(socket_fd, "GET / HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n"), 0)!= strlen("GET / HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n")) {
        printf("Error sending request: %s\n", strerror(errno));
        close(socket_fd);
        return 1;
    }

    int bytes_received = recv(socket_fd, buffer, BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
        printf("Error receiving response: %s\n", strerror(errno));
        close(socket_fd);
        return 1;
    }

    close(socket_fd);

    printf("Response:\n%s", buffer);

    return 0;
}