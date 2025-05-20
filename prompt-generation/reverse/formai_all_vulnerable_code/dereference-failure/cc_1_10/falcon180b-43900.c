//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

void error_handling(char* message) {
    perror(message);
    exit(1);
}

int main(int argc, char* argv[]) {
    int client_socket;
    struct addrinfo hints, *server_info;
    char buffer[BUFFER_SIZE];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo("localhost", "8080", &hints, &server_info)!= 0) {
        error_handling("getaddrinfo");
    }

    client_socket = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);

    if (client_socket == -1) {
        error_handling("socket");
    }

    if (connect(client_socket, server_info->ai_addr, server_info->ai_addrlen) == -1) {
        error_handling("connect");
    }

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        fgets(buffer, BUFFER_SIZE, stdin);
        send(client_socket, buffer, strlen(buffer), 0);

        if (strcmp(buffer, "exit") == 0) {
            break;
        }

        memset(buffer, 0, BUFFER_SIZE);
        if (recv(client_socket, buffer, BUFFER_SIZE, 0) == -1) {
            error_handling("recv");
        }
        printf("Server: %s\n", buffer);
    }

    close(client_socket);

    return 0;
}