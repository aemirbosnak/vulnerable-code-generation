//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int main(int argc, char **argv)
{
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <port> <host> <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int port = atoi(argv[1]);
    char *host = argv[2];
    char *path = argv[3];

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_aton(host, &server_addr.sin_addr);

    int client_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sock == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    if (connect(client_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    char request[BUFFER_SIZE];
    snprintf(request, BUFFER_SIZE, "GET %s HTTP/1.1\nHost: %s\n\n", path, host);

    if (send(client_sock, request, strlen(request), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    char response[BUFFER_SIZE];
    int bytes_received = recv(client_sock, response, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    response[bytes_received] = '\0';
    printf("%s", response);

    close(client_sock);

    return EXIT_SUCCESS;
}