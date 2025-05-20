//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: careful
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
#define MAX_REQUEST_LEN 4096
#define RESPONSE_HEADER "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nConnection: close\r\n\r\n"
#define INDEX_HTML "<html><body><h1>Welcome to My Simple Web Server!</h1></body></html>"

int main(int argc, char *argv[]) {
    int listen_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_size;
    char request[MAX_REQUEST_LEN];

    if ((listen_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(errno);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(errno);
    }

    if (listen(listen_socket, 10) == -1) {
        perror("listen");
        exit(errno);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        if ((client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, &client_addr_size)) == -1) {
            perror("accept");
            exit(errno);
        }

        printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        memset(request, 0, MAX_REQUEST_LEN);

        if (recv(client_socket, request, MAX_REQUEST_LEN, 0) == -1) {
            perror("recv");
            exit(errno);
        }

        printf("Request: %s\n", request);

        send(client_socket, RESPONSE_HEADER, strlen(RESPONSE_HEADER), 0);
        send(client_socket, INDEX_HTML, strlen(INDEX_HTML), 0);

        close(client_socket);
    }

    return 0;
}