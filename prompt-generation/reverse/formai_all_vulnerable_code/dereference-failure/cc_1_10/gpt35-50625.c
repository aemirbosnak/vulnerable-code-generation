//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_REQUEST_SIZE 1024

int main(int argc, char **argv) {
    // parse command line arguments
    if (argc < 2) {
        printf("Usage: ./http-client <url>\n");
        return 0;
    }

    char *url = argv[1];

    // parse the URL to get the host and path
    char *host = url;
    char *path = "/";
    char *path_start = strstr(url, "/");
    
    if (path_start != NULL) {
        host = strndup(url, path_start - url);
        path = path_start;
    }

    // resolve the IP address of the host
    struct addrinfo hints;
    struct addrinfo *result;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET; // IPv4
    hints.ai_socktype = SOCK_STREAM; // TCP

    if (getaddrinfo(host, "80", &hints, &result) != 0) {
        printf("Could not resolve host: %s\n", host);
        return 1;
    }

    // create a socket and connect to the server
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sock < 0) {
        printf("Could not create socket\n");
        return 1;
    }

    if (connect(sock, result->ai_addr, result->ai_addrlen) < 0) {
        printf("Could not connect to server\n");
        return 1;
    }

    // send an HTTP GET request
    char request[MAX_REQUEST_SIZE];
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);
    send(sock, request, strlen(request), 0);

    // receive the response and print it to the console
    char response[1024];
    int bytes_received = recv(sock, response, sizeof(response), 0);
    response[bytes_received] = '\0';

    printf("%s", response);

    // clean up
    freeaddrinfo(result);
    close(sock);
    free(host);
    
    return 0;
}