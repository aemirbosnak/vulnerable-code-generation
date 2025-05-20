//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int listen_sock, conn_sock, portno, n;
    struct sockaddr_in serv_addr, cli_addr;
    int opt = 1;
    char buffer[BUFFER_SIZE];

    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
        printf("Error creating socket");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(listen_sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error on binding\n");
        return 1;
    }

    if (listen(listen_sock, 5) < 0) {
        printf("Error on listen\n");
        return 1;
    }

    while (1) {
        conn_sock = accept(listen_sock, (struct sockaddr *) &cli_addr, (socklen_t *) &n);
        if (conn_sock < 0) {
            printf("Error on accept\n");
            continue;
        }

        printf("Connected to: %s\n", inet_ntoa(cli_addr.sin_addr));

        while (1) {
            n = read(conn_sock, buffer, BUFFER_SIZE);
            if (n < 0) {
                printf("Error reading from socket\n");
                break;
            }

            printf("Client message: %s\n", buffer);

            write(conn_sock, "Server: Hello, ", 13);
            write(conn_sock, buffer, strlen(buffer));
            write(conn_sock, "\n", 1);

            break;
        }

        close(conn_sock);
    }

    close(listen_sock);
    return 0;
}