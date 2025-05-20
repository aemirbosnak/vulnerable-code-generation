//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: %s URL\n", argv[0]);
        return 1;
    }

    char *url = argv[1];
    char protocol[8];
    char hostname[256];
    char path[1024];
    int port;

    if (sscanf(url, "%7[^://]://%255[^/]/%1023s", protocol, hostname, path) != 3) {
        printf("Invalid URL\n");
        return 1;
    }

    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Failed to resolve hostname\n");
        return 1;
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(80);
    memcpy(&address.sin_addr, host->h_addr_list[0], host->h_length);

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        printf("Failed to create socket\n");
        return 1;
    }

    if (connect(socket_fd, (struct sockaddr *)&address, sizeof(address)) == -1) {
        printf("Failed to connect\n");
        return 1;
    }

    char request[2048];
    sprintf(request,
            "GET /%s HTTP/1.1\r\n"
            "Host: %s\r\n"
            "Connection: close\r\n"
            "\r\n",
            path, hostname);

    int sent = send(socket_fd, request, strlen(request), 0);
    if (sent != strlen(request)) {
        printf("Failed to send request\n");
        return 1;
    }

    char response[4096];
    int received = 0;
    int chunk_size = 1;
    while (chunk_size > 0) {
        chunk_size = recv(socket_fd, response+received, 4096-received, 0);
        if (chunk_size == -1) {
            printf("Failed to receive response\n");
            return 1;
        }
        received += chunk_size;
    }
    response[received] = '\0';

    printf("%s", response);

    close(socket_fd);

    return 0;
}