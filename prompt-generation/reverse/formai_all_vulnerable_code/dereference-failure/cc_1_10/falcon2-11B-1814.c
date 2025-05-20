//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 8080
#define BUF_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int server_fd, conn_fd, n;
    struct sockaddr_in server_addr, client_addr;
    struct hostent *server;
    char buffer[BUF_SIZE];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0)
        error("Error opening socket");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        error("Error on binding");

    listen(server_fd, 3);

    while (1) {
        conn_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t *)&n);
        if (conn_fd < 0)
            error("Error on accepting");

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while ((n = recv(conn_fd, buffer, BUF_SIZE, 0)) > 0) {
            buffer[n] = '\0';
            printf("Received: %s\n", buffer);
            send(conn_fd, buffer, n, 0);
        }

        close(conn_fd);
    }

    close(server_fd);
    return 0;
}