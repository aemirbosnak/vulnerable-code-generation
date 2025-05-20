//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <url>\n", argv[0]);
        exit(1);
    }
    char *url = argv[1];
    char *host = url;
    char *path = "/";
    char *port = "80";
    char *header_template = "GET %s HTTP/1.0\r\n"
                            "Host: %s\r\n"
                            "\r\n";
    struct hostent *he = gethostbyname(host);
    if (he == NULL) {
        printf("Error: could not resolve hostname: %s\n", host);
        exit(1);
    }
    struct in_addr **addr_list = (struct in_addr **) he->h_addr_list;
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(inet_ntoa(*addr_list[0]));
    server.sin_port = htons(atoi(port));
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        printf("Error: could not create socket\n");
        exit(1);
    }
    if (connect(socket_fd, (struct sockaddr *) &server, sizeof(server)) < 0) {
        printf("Error: could not connect to server: %s\n", host);
        exit(1);
    }
    char *header = (char *) malloc(strlen(header_template) + strlen(path) + strlen(host) + 1);
    sprintf(header, header_template, path, host);
    if (send(socket_fd, header, strlen(header), 0) < 0) {
        printf("Error: could not send message to server\n");
        exit(1);
    }
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    while (recv(socket_fd, buffer, BUFFER_SIZE, 0) > 0) {
        printf("%s", buffer);
        memset(buffer, 0, BUFFER_SIZE);
    }
    close(socket_fd);
    return 0;
}