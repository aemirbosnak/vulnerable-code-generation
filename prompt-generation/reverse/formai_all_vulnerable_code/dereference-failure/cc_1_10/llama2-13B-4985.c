//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024
#define MAX_CONNECTIONS 1024

struct socket_info {
    int sock;
    struct sockaddr_in address;
    int port;
};

void init_sockets(void) {
    int i;
    for (i = 0; i < MAX_CONNECTIONS; i++) {
        struct socket_info *socket_info = malloc(sizeof(struct socket_info));
        socket_info->sock = socket(AF_INET, SOCK_STREAM, 0);
        if (socket_info->sock < 0) {
            perror("socket creation failed");
            exit(EXIT_FAILURE);
        }
        socket_info->address.sin_family = AF_INET;
        socket_info->address.sin_port = htons(0);
        if (bind(socket_info->sock, (struct sockaddr *)&socket_info->address, sizeof(socket_info->address)) < 0) {
            perror("binding failed");
            exit(EXIT_FAILURE);
        }
        listen(socket_info->sock, 3);
        printf("Listening on port %d...\n", socket_info->address.sin_port);
    }
}

void handle_connection(int sock) {
    struct socket_info *socket_info;
    socket_info = malloc(sizeof(struct socket_info));
    socket_info->sock = sock;
    socket_info->address.sin_family = AF_INET;
    socket_info->address.sin_port = htons(0);
    getsockname(sock, (struct sockaddr *)&socket_info->address, sizeof(socket_info->address));
    printf("Connection from %s on port %d...\n", inet_ntoa(socket_info->address.sin_addr), ntohs(socket_info->address.sin_port));
    // handle connection here
}

int main(void) {
    init_sockets();

    while (1) {
        int sock = accept(0, (struct sockaddr *)0, 0);
        handle_connection(sock);
    }

    return 0;
}