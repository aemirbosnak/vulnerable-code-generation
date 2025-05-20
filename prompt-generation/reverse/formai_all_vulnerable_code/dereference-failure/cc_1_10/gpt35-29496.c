//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_REQUEST_SIZE 2048

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Usage: %s <url>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *url = argv[1];
    char request[MAX_REQUEST_SIZE];
    memset(request, 0, MAX_REQUEST_SIZE);

    // parse the URL to extract hostname and file path
    char *hostname, *path;
    char *protocol = strtok(url, ":/");
    if (strcmp(protocol, "http") != 0) {
        printf("Error: only HTTP protocol is supported.\n");
        exit(EXIT_FAILURE);
    }

    hostname = strtok(NULL, "/");
    path = url + strlen(protocol) + strlen(hostname) + 3;

    // resolve the hostname to an IP address
    struct hostent *he;
    struct in_addr **addr_list;
    he = gethostbyname(hostname);
    if (he == NULL) {
        printf("Error: could not resolve hostname %s.\n", hostname);
        exit(EXIT_FAILURE);
    }

    addr_list = (struct in_addr **) he->h_addr_list;
    char *ip_addr = inet_ntoa(*addr_list[0]);

    // create a socket and connect to the server
    int socket_fd;
    struct sockaddr_in server_address;
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        printf("Error: socket creation failed.\n");
        exit(EXIT_FAILURE);
    }

    server_address.sin_addr.s_addr = inet_addr(ip_addr);
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);

    if (connect(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("Error: could not connect to server.\n");
        exit(EXIT_FAILURE);
    }

    // create the HTTP GET request and send it to the server
    snprintf(request, MAX_REQUEST_SIZE, "GET /%s HTTP/1.1\r\n"
                                         "Host: %s\r\n"
                                         "Connection: close\r\n\r\n", path, hostname);
    write(socket_fd, request, strlen(request));

    // receive the response from the server and print it to the console
    char response_buffer[BUFSIZ];
    memset(response_buffer, 0, BUFSIZ);

    bool headers_finished = false;
    while (read(socket_fd, response_buffer, BUFSIZ - 1) > 0) {
        printf("%s", response_buffer);

        if (!headers_finished) {
            char *end_of_headers = strstr(response_buffer, "\r\n\r\n");
            if (end_of_headers != NULL)
                headers_finished = true;
        }

        memset(response_buffer, 0, BUFSIZ);
    }

    close(socket_fd);

    return 0;
}