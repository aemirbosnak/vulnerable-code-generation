//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <fcntl.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024
#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[]) {
    int listen_fd, client_fd, sock;
    struct sockaddr_in server_addr, client_addr;
    int opt = TRUE;
    int addrlen = sizeof(struct sockaddr_in);
    char buffer[BUFFER_SIZE];
    int bytes_read;

    if (argc!= 3) {
        printf("Usage:./proxy <IP> <Port>\n");
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (listen_fd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(listen_fd, 5) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    while (TRUE) {
        sock = accept(listen_fd, (struct sockaddr *)&client_addr, &addrlen);

        if (sock == -1) {
            printf("Error accepting connection\n");
            exit(1);
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (TRUE) {
            bytes_read = recv(sock, buffer, BUFFER_SIZE, 0);

            if (bytes_read <= 0) {
                break;
            }

            send(sock, buffer, bytes_read, 0);
        }

        close(sock);
    }

    close(listen_fd);
    exit(0);
}