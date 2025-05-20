//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    }

    // parse input URL
    char url[1024];
    strcpy(url, argv[1]);
    char *host = strtok(url, "/");
    char *path = strtok(NULL, "");

    // resolve host name
    struct hostent *he = gethostbyname(host);
    if (!he) {
        fprintf(stderr, "Unable to resolve host name %s\n", host);
        return 1;
    }
    char ip[16];
    inet_ntop(AF_INET, he->h_addr_list[0], ip, sizeof(ip));

    // create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    // connect to server
    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return 1;
    }

    // build HTTP request
    char request[1024];
    snprintf(request, sizeof(request), "GET /%s HTTP/1.1\r\nHost: %s\r\nUser-Agent: C HTTP Client\r\nConnection: close\r\n\r\n", path, host);

    // send HTTP request
    if (send(sock, request, strlen(request), 0) == -1) {
        perror("send");
        return 1;
    }

    // receive HTTP response
    char buffer[1024];
    while (recv(sock, buffer, sizeof(buffer), 0) > 0) {
        printf("%s", buffer);
        memset(buffer, 0, sizeof(buffer));
    }

    // cleanup
    close(sock);

    return 0;
}