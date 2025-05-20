//Falcon-180B DATASET v1.0 Category: Networking ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/time.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 10
#define MAX_DATA_SIZE 1024

int main(int argc, char *argv[]) {
    int listen_sock, conn_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    char buffer[MAX_DATA_SIZE];

    if ((listen_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(listen_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(listen_sock, BACKLOG) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    while (TRUE) {
        addr_size = sizeof(client_addr);
        if ((conn_sock = accept(listen_sock, (struct sockaddr *)&client_addr, &addr_size)) == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (TRUE) {
            memset(buffer, 0, MAX_DATA_SIZE);
            if (recv(conn_sock, buffer, MAX_DATA_SIZE, 0) <= 0) {
                if (errno!= EWOULDBLOCK) {
                    perror("recv");
                    exit(EXIT_FAILURE);
                }
                break;
            }

            printf("Received data: %s", buffer);

            if (send(conn_sock, buffer, strlen(buffer), 0) == -1) {
                perror("send");
                exit(EXIT_FAILURE);
            }
        }

        close(conn_sock);
    }

    close(listen_sock);
    return 0;
}