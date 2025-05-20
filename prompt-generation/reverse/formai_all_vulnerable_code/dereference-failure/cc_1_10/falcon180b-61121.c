//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

void print_usage() {
    fprintf(stderr, "Usage:./program <IP address> <port number>\n");
}

int main(int argc, char **argv) {
    if (argc!= 4) {
        print_usage();
        return 1;
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);
    char *hostname = argv[3];

    struct addrinfo hints, *server_info;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(ip_address, NULL, &hints, &server_info)!= 0) {
        fprintf(stderr, "Error: %s\n", gai_strerror(errno));
        return 1;
    }

    int socket_fd = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);
    if (socket_fd == -1) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return 1;
    }

    if (connect(socket_fd, server_info->ai_addr, server_info->ai_addrlen) == -1) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return 1;
    }

    printf("Connected to %s:%d\n", ip_address, port_number);

    char buffer[1024];
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int bytes_received = recv(socket_fd, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            fprintf(stderr, "Error: %s\n", strerror(errno));
            close(socket_fd);
            return 1;
        }

        printf("Received %d bytes: %s\n", bytes_received, buffer);
    }

    return 0;
}