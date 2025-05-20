//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s hostname port path\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *host = argv[1];
    char *port = argv[2];
    char *path = argv[3];
    char buffer[BUFFER_SIZE];
    int socket_fd, n, status;
    struct sockaddr_in server_address;
    struct hostent *server;

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host %s\n", host);
        exit(EXIT_FAILURE);
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(port));
    memcpy(&server_address.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    char request[BUFFER_SIZE];
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);

    n = write(socket_fd, request, strlen(request));
    if (n < 0) {
        perror("Error writing to socket");
        exit(EXIT_FAILURE);
    }

    memset(buffer, 0, BUFFER_SIZE);
    while ((n = read(socket_fd, buffer, BUFFER_SIZE - 1)) > 0) {
        if (fputs(buffer, stdout) == EOF) {
            perror("Error writing to stdout");
            exit(EXIT_FAILURE);
        }
        memset(buffer, 0, BUFFER_SIZE);
    }

    if (n < 0) {
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }

    close(socket_fd);
    return 0;
}