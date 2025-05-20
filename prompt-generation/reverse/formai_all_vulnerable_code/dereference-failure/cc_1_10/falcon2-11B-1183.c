//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: light-weight
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define PORT_NUM 1024

int main(int argc, char *argv[]) {
    int socket_fd, num_bytes_recvd, port_num;
    struct sockaddr_in server_addr;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    port_num = atoi(argv[1]);

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("socket");
        exit(1);
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port_num);

    if (bind(socket_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(socket_fd, 1) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        num_bytes_recvd = recvfrom(socket_fd, NULL, 0, 0, NULL, NULL);
        if (num_bytes_recvd < 0) {
            perror("recvfrom");
            exit(1);
        }
    }

    close(socket_fd);
    return 0;
}