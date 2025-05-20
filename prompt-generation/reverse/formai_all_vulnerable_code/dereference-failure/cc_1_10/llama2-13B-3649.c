//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024
#define MAX_CONNECTIONS 100

struct socket_info {
    int sock;
    struct sockaddr_in address;
    int port;
};

void init_sockets(void);
void scan_ports(int start, int end);
void handle_connection(int sock);

int main(void) {
    init_sockets();
    scan_ports(1, 65535);
    return 0;
}

void init_sockets(void) {
    int i;
    struct socket_info *sockets = calloc(MAX_CONNECTIONS, sizeof(struct socket_info));

    for (i = 0; i < MAX_CONNECTIONS; i++) {
        sockets[i].sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sockets[i].sock == -1) {
            perror("socket creation failed");
            exit(1);
        }
    }
}

void scan_ports(int start, int end) {
    int i, j;
    struct socket_info *sockets = calloc(MAX_CONNECTIONS, sizeof(struct socket_info));

    for (i = start; i <= end; i++) {
        struct sockaddr_in address;
        address.sin_family = AF_INET;
        address.sin_port = htons(i);
        address.sin_addr.s_addr = INADDR_ANY;

        sockets[j].sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sockets[j].sock == -1) {
            perror("socket creation failed");
            exit(1);
        }

        if (connect(sockets[j].sock, (struct sockaddr *)&address, sizeof(address)) == -1) {
            perror("connection failed");
            close(sockets[j].sock);
            sockets[j].sock = -1;
        } else {
            printf("Connected to port %d\n", address.sin_port);
            handle_connection(sockets[j].sock);
        }

        j++;
    }
}

void handle_connection(int sock) {
    char buffer[1024];
    int bytes_received = recv(sock, buffer, 1024, 0);

    if (bytes_received == -1) {
        perror("receive failed");
        close(sock);
    } else {
        printf("Received message: %s\n", buffer);
        send(sock, "Hello, client!", 13, 0);
    }
}