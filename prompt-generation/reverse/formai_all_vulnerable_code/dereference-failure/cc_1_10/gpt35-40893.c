//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    char *url = argv[1];

    char *hostname;
    char *path;

    char *protocol = "http";

    if (strncmp(url, "http://", 7) == 0) {
        hostname = strtok(url + 7, "/");
    } else if (strncmp(url, "https://", 8) == 0) {
        protocol = "https";
        hostname = strtok(url + 8, "/");
    } else {
        hostname = strtok(url, "/");
    }

    path = strchr(url, '/');
    if (path == NULL) {
        path = "/";
    }

    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        printf("Error: Could not resolve hostname: %s\n", hostname);
        return 1;
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    memcpy(&server_address.sin_addr.s_addr, server->h_addr, server->h_length);
    server_address.sin_port = htons(80);

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        printf("Error: Could not create socket\n");
        return 1;
    }

    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Error: Could not connect to server\n");
        return 1;
    }

    char request[BUFFER_SIZE];
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, hostname);

    if (send(socket_fd, request, strlen(request), 0) < 0) {
        printf("Error: Could not send request\n");
        return 1;
    }

    char response[BUFFER_SIZE];
    memset(&response, 0, sizeof(response));

    if (recv(socket_fd, response, sizeof(response), 0) < 0) {
        printf("Error: Could not receive response\n");
        return 1;
    }

    printf("%s", response);

    close(socket_fd);
    return 0;
}