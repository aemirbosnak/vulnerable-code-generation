//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_CLIENTS 5

int main(int argc, char *argv[])
{
    int listen_fd, conn_fd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    int addrlen = sizeof(cli_addr);

    if (argc < 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0) {
        fprintf(stderr, "ERROR opening socket\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(listen_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "ERROR on binding\n");
        exit(1);
    }

    if (listen(listen_fd, MAX_CLIENTS) < 0) {
        fprintf(stderr, "ERROR on listen\n");
        exit(1);
    }

    while (1) {
        conn_fd = accept(listen_fd, (struct sockaddr *) &cli_addr, &addrlen);
        if (conn_fd < 0) {
            perror("accept");
            continue;
        }

        printf("New client connected: %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        char buffer[256];
        while (1) {
            bzero(buffer, 256);
            recv(conn_fd, buffer, 255, 0);
            if (strlen(buffer) > 0) {
                printf("Client said: %s\n", buffer);
                if (strcmp(buffer, "quit") == 0) {
                    break;
                }
                send(conn_fd, buffer, strlen(buffer), 0);
            }
        }

        close(conn_fd);
    }

    close(listen_fd);
    return 0;
}