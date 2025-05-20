//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFF_SIZE 1024

int main(int argc, char **argv) {
    int listen_fd, conn_fd;
    struct sockaddr_in server_addr, client_addr;
    char buff[BUFF_SIZE];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        fprintf(stderr, "Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error binding socket\n");
        exit(1);
    }

    if (listen(listen_fd, 5) == -1) {
        fprintf(stderr, "Error listening on socket\n");
        exit(1);
    }

    while (1) {
        printf("Waiting for client connection...\n");
        socklen_t client_len = sizeof(client_addr);
        conn_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &client_len);
        if (conn_fd == -1) {
            fprintf(stderr, "Error accepting connection\n");
            continue;
        }

        printf("Client connected with IP %s and port %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buff, 0, BUFF_SIZE);
            int bytes_received = recv(conn_fd, buff, BUFF_SIZE, 0);
            if (bytes_received <= 0) {
                if (bytes_received == 0) {
                    printf("Client disconnected\n");
                } else {
                    fprintf(stderr, "Error receiving data from client\n");
                }
                break;
            }

            printf("Received data: %s", buff);

            send(conn_fd, buff, strlen(buff), 0);
        }

        close(conn_fd);
    }

    close(listen_fd);
    return 0;
}