//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    int socket_fd, port_number, optval;
    struct sockaddr_in server_address;
    char buffer[256];

    if (argc!= 2) {
        printf("Usage: %s port_number\n", argv[0]);
        exit(1);
    }

    port_number = atoi(argv[1]);
    optval = 1;
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("socket");
        exit(1);
    }

    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_number);
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
        perror("setsockopt");
        exit(1);
    }

    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("connect");
        exit(1);
    }

    for (;;) {
        bzero(buffer, sizeof(buffer));
        read(socket_fd, buffer, sizeof(buffer));
        printf("Received: %s\n", buffer);
        send(socket_fd, buffer, strlen(buffer), 0);
        printf("Sent: %s\n", buffer);
    }

    close(socket_fd);
    return 0;
}