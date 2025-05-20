//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LINE 1024
#define PORT 8080
#define BACKLOG 10

int main(int argc, char *argv[]) {
    int master_socket, client_socket, addrlen;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_LINE];
    int client_port;

    master_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (master_socket == -1) {
        perror("socket");
        exit(errno);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(master_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(errno);
    }

    if (listen(master_socket, BACKLOG) == -1) {
        perror("listen");
        exit(errno);
    }

    addrlen = sizeof(client_addr);
    while (1) {
        client_socket = accept(master_socket, (struct sockaddr *)&client_addr, &addrlen);
        if (client_socket == -1) {
            perror("accept");
            exit(errno);
        }

        client_port = ntohs(client_addr.sin_port);
        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), client_port);

        while (1) {
            memset(buffer, 0, sizeof(buffer));
            if (recv(client_socket, buffer, MAX_LINE, 0) <= 0) {
                perror("recv");
                exit(errno);
            }

            send(client_socket, buffer, strlen(buffer), 0);
        }

        close(client_socket);
    }

    return 0;
}