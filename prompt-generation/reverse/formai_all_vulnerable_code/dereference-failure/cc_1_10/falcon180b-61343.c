//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>

#define MAX_LINE 1024
#define SERVER_PORT 8080
#define BUFFER_SIZE 4096

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <server_address> <port>\n", argv[0]);
        exit(1);
    }

    char *server_address = argv[1];
    int server_port = atoi(argv[2]);

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        error("socket");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    inet_pton(AF_INET, server_address, &server_addr.sin_addr);

    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error("connect");
    }

    int client_socket = accept(server_socket, NULL, NULL);
    if (client_socket == -1) {
        error("accept");
    }

    char buffer[BUFFER_SIZE];
    while (1) {
        int bytes_read = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_read <= 0) {
            break;
        }

        char *line = strtok(buffer, "\r\n");
        while (line!= NULL) {
            send(server_socket, line, strlen(line), 0);
            line = strtok(NULL, "\r\n");
        }
    }

    close(client_socket);
    close(server_socket);

    return 0;
}