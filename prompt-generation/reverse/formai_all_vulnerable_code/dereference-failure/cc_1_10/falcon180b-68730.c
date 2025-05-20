//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: shape shifting
/* This is a simple HTTP Proxy server implemented in C */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>

#define TRUE  1
#define FALSE 0
#define MAX_LINE 1024
#define BACKLOG 10

typedef struct {
    int sock;
    char ip[16];
    int port;
} client_t;

int main(int argc, char **argv) {
    int listen_sock, client_sock, addrlen, new_sock, port = 8080;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_LINE];
    client_t clients[10];
    int max_clients = 0;

    if(argc > 1) {
        port = atoi(argv[1]);
    }

    listen_sock = socket(AF_INET, SOCK_STREAM, 0);

    if(listen_sock == -1) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);

    if(bind(listen_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if(listen(listen_sock, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    printf("HTTP Proxy listening on port %d\n", port);

    while(TRUE) {
        addrlen = sizeof(client_addr);
        new_sock = accept(listen_sock, (struct sockaddr *)&client_addr, &addrlen);

        if(new_sock == -1) {
            perror("accept");
            continue;
        }

        for(int i = 0 ; i < max_clients ; i++) {
            if(clients[i].sock == -1) {
                clients[i].sock = new_sock;
                strcpy(clients[i].ip, inet_ntoa(client_addr.sin_addr));
                clients[i].port = ntohs(client_addr.sin_port);
                max_clients++;
                break;
            }
        }

        if(max_clients == 10) {
            send(new_sock, "HTTP/1.0 503 Service Unavailable\r\n", strlen("HTTP/1.0 503 Service Unavailable\r\n"), 0);
            close(new_sock);
            continue;
        }

        printf("Client connected : %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    }

    return 0;
}