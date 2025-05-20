//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {

    char *url = argv[1];

    //parse url to extract host, path and port
    char *scheme = strtok(url, ":");
    char *host = strtok(NULL, "/");
    char *path = strtok(NULL, "");
    char *port = "80";
    if (strcmp(scheme, "https") == 0) {
        port = "443";
    }

    //get IP address of the host
    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    getaddrinfo(host, port, &hints, &result);

    //create socket and connect to server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    connect(sockfd, result->ai_addr, result->ai_addrlen);

    //compose HTTP GET request
    char request[BUF_SIZE];
    snprintf(request, BUF_SIZE, "GET /%s HTTP/1.1\r\n"
            "Host: %s\r\n"
            "Connection: close\r\n"
            "\r\n", path, host);

    //send HTTP request to server
    send(sockfd, request, strlen(request), 0);

    //receive HTTP response from server
    char response[BUF_SIZE];
    int nrecv, ntotal = 0;
    while ((nrecv = recv(sockfd, response + ntotal, BUF_SIZE - ntotal, 0)) > 0) {
        ntotal += nrecv;
    }
    response[ntotal] = '\0';

    //print HTTP response to console
    printf("%s", response);

    //close socket and free memory
    freeaddrinfo(result);
    close(sockfd);

    return 0;
}