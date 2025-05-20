//Falcon-180B DATASET v1.0 Category: Firewall ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);

    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    char host[NI_MAXHOST];
    char service[NI_MAXSERV];
    snprintf(service, NI_MAXSERV, "%d", port);

    if (getaddrinfo(NULL, service, &hints, &res)!= 0) {
        error("getaddrinfo");
    }

    int sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sock == -1) {
        error("socket");
    }

    if (bind(sock, res->ai_addr, res->ai_addrlen) == -1) {
        error("bind");
    }

    if (listen(sock, 5) == -1) {
        error("listen");
    }

    while (1) {
        struct addrinfo client_info;
        socklen_t client_info_size = sizeof(client_info);
        int client_sock = accept(sock, &client_info, &client_info_size);

        if (client_sock == -1) {
            if (errno == ECONNABORTED) {
                continue;
            } else {
                error("accept");
            }
        }

        char client_ip[NI_MAXHOST];
        char client_port[NI_MAXSERV];
        if (getnameinfo(&client_info.ai_addr, client_info.ai_addrlen, client_ip, NI_MAXHOST, client_port, NI_MAXSERV, 0) == 0) {
            printf("Accepted connection from %s:%s\n", client_ip, client_port);
        } else {
            printf("Accepted connection from unknown client\n");
        }

        close(client_sock);
    }

    return 0;
}