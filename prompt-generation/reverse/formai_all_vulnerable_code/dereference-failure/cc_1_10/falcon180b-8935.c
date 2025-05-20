//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUF_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <server_ip> <port>\n", argv[0]);
        exit(1);
    }

    server_sock = socket(AF_INET, SOCK_STREAM, 0);

    if (server_sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    while (1) {
        client_sock = accept(server_sock, (struct sockaddr *)&client_addr, sizeof(client_addr));

        if (client_sock == -1) {
            printf("Error accepting connection\n");
            exit(1);
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, BUF_SIZE);

            if (recv(client_sock, buffer, BUF_SIZE, 0) == 0) {
                printf("Client disconnected\n");
                close(client_sock);
                break;
            }

            send(server_sock, buffer, strlen(buffer), 0);

            if (recv(server_sock, buffer, BUF_SIZE, 0) == 0) {
                printf("Server disconnected\n");
                close(server_sock);
                close(client_sock);
                break;
            }

            send(client_sock, buffer, strlen(buffer), 0);
        }
    }

    return 0;
}