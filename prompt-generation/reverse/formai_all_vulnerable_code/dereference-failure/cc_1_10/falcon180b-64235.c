//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_LINE 1024
#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"

int main(int argc, char *argv[]) {
    int server_socket, client_socket, port;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_LINE];

    if (argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    port = atoi(argv[1]);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        memset(buffer, 0, MAX_LINE);

        if (recv(server_socket, buffer, MAX_LINE, 0) <= 0) {
            printf("Error receiving data from server\n");
            exit(1);
        }

        printf("Received from server: %s\n", buffer);

        if (send(client_socket, buffer, strlen(buffer), 0) <= 0) {
            printf("Error sending data to client\n");
            exit(1);
        }
    }

    close(server_socket);
    return 0;
}