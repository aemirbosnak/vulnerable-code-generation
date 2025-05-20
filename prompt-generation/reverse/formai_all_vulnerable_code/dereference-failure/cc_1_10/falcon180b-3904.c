//Falcon-180B DATASET v1.0 Category: Networking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BACKLOG 10

void error_handling(char *message);

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;
    char buffer[1024];

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (listen_fd == -1) {
        error_handling("socket failed");
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(listen_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error_handling("bind failed");
    }

    if (listen(listen_fd, BACKLOG) < 0) {
        error_handling("listen");
    }

    printf("Server started on port %d\n", PORT);

    while (1) {
        clilen = sizeof(cli_addr);
        conn_fd = accept(listen_fd, (struct sockaddr *)&cli_addr, &clilen);

        if (conn_fd < 0) {
            error_handling("accept");
        }

        printf("Connection from %s on port %d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while (1) {
            bzero(buffer, sizeof(buffer));
            if (recv(conn_fd, buffer, sizeof(buffer), 0) <= 0) {
                error_handling("recv");
            }

            printf("Received message: %s\n", buffer);

            if (send(conn_fd, buffer, strlen(buffer), 0) < 0) {
                error_handling("send");
            }
        }

        close(conn_fd);
    }

    return 0;
}

void error_handling(char *message) {
    fprintf(stderr, "%s: %s\n", message, strerror(errno));
    exit(1);
}