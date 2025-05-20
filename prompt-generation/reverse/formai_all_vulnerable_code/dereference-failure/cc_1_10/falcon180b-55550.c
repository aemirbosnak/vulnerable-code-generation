//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define BACKLOG 10
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUF_SIZE];
    int addrlen;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        fprintf(stderr, "Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error binding socket\n");
        exit(1);
    }

    if (listen(listen_fd, BACKLOG) == -1) {
        fprintf(stderr, "Error listening on socket\n");
        exit(1);
    }

    printf("Server listening on port %s\n", argv[1]);

    while (TRUE) {
        addrlen = sizeof(client_addr);
        conn_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &addrlen);

        if (conn_fd == -1) {
            fprintf(stderr, "Error accepting connection\n");
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (TRUE) {
            memset(buffer, 0, BUF_SIZE);
            if (recv(conn_fd, buffer, BUF_SIZE, 0) <= 0) {
                fprintf(stderr, "Error receiving data\n");
                break;
            }

            printf("Received: %s", buffer);

            if (send(conn_fd, buffer, strlen(buffer), 0) <= 0) {
                fprintf(stderr, "Error sending data\n");
                break;
            }
        }

        close(conn_fd);
    }

    close(listen_fd);
    return 0;
}