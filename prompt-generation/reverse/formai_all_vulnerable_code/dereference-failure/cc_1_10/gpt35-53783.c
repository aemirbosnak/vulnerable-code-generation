//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {

    char *host = "example.com"; // the host we want to connect to
    char *path = "/"; // the path to the resource we want to retrieve
    char request[1024]; // the request buffer
    char response[1024]; // the response buffer

    struct addrinfo hints, *res; // hints is used to specify the desired socket type
    int sockfd; // the socket file descriptor
    int bytes_received; // the number of bytes received in the response

    // clear the hints struct
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    // lookup the host and get the first result
    if (getaddrinfo(host, "http", &hints, &res) != 0) {
        fprintf(stderr, "Error: unable to lookup host\n");
        return 1;
    }

    // create a socket and connect to the server
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd < 0) {
        fprintf(stderr, "Error: unable to create socket\n");
        return 1;
    }

    if (connect(sockfd, res->ai_addr, res->ai_addrlen) < 0) {
        fprintf(stderr, "Error: unable to connect to server\n");
        return 1;
    }

    // generate the request and send it to the server
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);
    if (send(sockfd, request, strlen(request), 0) < 0) {
        fprintf(stderr, "Error: unable to send request to server\n");
        return 1;
    }

    // read the response from the server
    bytes_received = recv(sockfd, response, sizeof(response), 0);

    // print the response to stdout
    fwrite(response, 1, bytes_received, stdout);

    // close the socket and cleanup
    close(sockfd);
    freeaddrinfo(res);

    return 0;
}