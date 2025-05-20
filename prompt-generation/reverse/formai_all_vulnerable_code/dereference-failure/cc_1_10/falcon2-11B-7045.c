//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 8080

int main(int argc, char *argv[])
{
    int server_fd, conn_fd, len, n;
    struct sockaddr_in address;
    struct hostent *server;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }

    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    bcopy((char *)server->h_addr, (char *)&address.sin_addr.s_addr, server->h_length);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        exit(1);
    }

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind");
        exit(1);
    }

    listen(server_fd, 5);

    while (1) {
        conn_fd = accept(server_fd, NULL, NULL);
        if (conn_fd < 0) {
            perror("accept");
            exit(1);
        }

        bzero((char *)&address, sizeof(address));
        address.sin_family = AF_INET;
        address.sin_port = htons(PORT);
        bcopy((char *)server->h_addr, (char *)&address.sin_addr.s_addr, server->h_length);

        len = sizeof(address);
        if (connect(conn_fd, (struct sockaddr *)&address, len) < 0) {
            perror("connect");
            exit(1);
        }

        printf("Client connected\n");

        while ((n = read(conn_fd, NULL, 1)) > 0) {
            printf("Received: %s\n", (char *)NULL);
            write(conn_fd, "Hello, World!", 13);
        }
    }

    close(server_fd);
    close(conn_fd);

    return 0;
}