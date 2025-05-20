//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_CLIENTS 10
#define MAX_REQUEST_SIZE 1024

int main(int argc, char *argv[]) {
    int listen_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char request_buffer[MAX_REQUEST_SIZE];
    int request_length;
    struct hostent *host_info;

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        printf("Error creating socket.\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket.\n");
        exit(1);
    }

    if (listen(listen_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket.\n");
        exit(1);
    }

    printf("Server listening on port 8080...\n");

    while (1) {
        memset(&client_addr, 0, sizeof(client_addr));
        socklen_t client_size = sizeof(client_addr);
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, &client_size);
        if (client_socket == -1) {
            printf("Error accepting connection.\n");
            continue;
        }

        while (1) {
            memset(request_buffer, 0, MAX_REQUEST_SIZE);
            request_length = recv(client_socket, request_buffer, MAX_REQUEST_SIZE, 0);
            if (request_length <= 0) {
                printf("Client disconnected.\n");
                close(client_socket);
                break;
            }

            printf("Received request: %s\n", request_buffer);

            host_info = gethostbyaddr((char *)&client_addr.sin_addr, sizeof(client_addr.sin_addr), AF_INET);
            printf("Client IP: %s\n", inet_ntoa(*(struct in_addr *)host_info->h_addr));

            send(client_socket, "HTTP/1.1 200 OK\r\nContent-Length: 13\r\n\r\nHello, World!", 43, 0);
        }
    }

    close(listen_socket);
    return 0;
}