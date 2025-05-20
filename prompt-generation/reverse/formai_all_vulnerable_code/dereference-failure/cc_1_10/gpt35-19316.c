//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define DEFAULT_PORT 80

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return -1;
    }

    char *url = argv[1];
    char *hostname = strtok(url, "/");
    char *path = strtok(NULL, "") ? : "/";

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(DEFAULT_PORT);
    inet_pton(AF_INET, hostname, &server_address.sin_addr);

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("Error in creating socket");
        return -1;
    }

    if (connect(socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Error in connection");
        return -1;
    }

    char request[BUFFER_SIZE] = {0};
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, hostname);

    if (send(socket_fd, request, strlen(request), 0) < 0) {
        perror("Error in sending request");
        return -1;
    }

    char response[BUFFER_SIZE] = {0};
    while (recv(socket_fd, response, BUFFER_SIZE, 0) > 0) {
        printf("%s", response);
        memset(response, 0, sizeof(response));
    }

    close(socket_fd);

    return 0;
}