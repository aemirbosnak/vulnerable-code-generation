//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_RECV_BUFFER 1024

void handle_client(int client_socket) {
    char buffer[MAX_RECV_BUFFER];
    int n;

    while (1) {
        n = recv(client_socket, buffer, MAX_RECV_BUFFER, 0);
        if (n == 0) {
            close(client_socket);
            return;
        }
        if (n < 0) {
            perror("recv error");
            return;
        }
        printf("Received: %s\n", buffer);
        send(client_socket, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<h1>Hello, World!</h1>", -1, 0);
    }
}

int main(int argc, char *argv[]) {
    int server_socket, client_socket, port_number;
    struct sockaddr_in server_address, client_address;
    int addrlen;
    char buffer[MAX_RECV_BUFFER];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    port_number = atoi(argv[1]);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket error");
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(port_number);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind error");
        exit(1);
    }

    if (listen(server_socket, 5) < 0) {
        perror("listen error");
        exit(1);
    }

    while (1) {
        addrlen = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &addrlen);
        if (client_socket < 0) {
            perror("accept error");
            continue;
        }
        printf("New connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        handle_client(client_socket);
        close(client_socket);
    }

    return 0;
}