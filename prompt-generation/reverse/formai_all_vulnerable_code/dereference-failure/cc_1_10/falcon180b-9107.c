//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LINE 1024
#define MAX_REQUESTS 100

int main(int argc, char *argv[]) {
    int listen_socket, client_socket, port = 8080;
    struct sockaddr_in server_addr, client_addr;
    char *ip_str = "127.0.0.1";
    int opt = 1;
    int addrlen = sizeof(client_addr);
    char buffer[MAX_LINE];
    int num_requests = 0;

    if (argc > 1) {
        port = atoi(argv[1]);
    }

    if ((listen_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip_str);
    server_addr.sin_port = htons(port);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(listen_socket, MAX_REQUESTS) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        if ((client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, &addrlen)) == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Connection from %s on port %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (num_requests < MAX_REQUESTS && (send(client_socket, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nConnection: close\r\n\r\n", 78, 0) > 0)) {
            memset(buffer, 0, MAX_LINE);
            num_requests++;
        }

        close(client_socket);
    }

    return 0;
}