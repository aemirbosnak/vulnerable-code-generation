//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <server_ip> <server_port>\n", argv[0]);
        exit(1);
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error: Failed to create socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Failed to connect to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (TRUE) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(server_socket, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            printf("Error: Failed to receive data from server\n");
            exit(1);
        }

        send(client_socket, buffer, bytes_received, 0);
    }

    close(server_socket);
    close(client_socket);

    return 0;
}