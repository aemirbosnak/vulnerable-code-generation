//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    // Step 1: Parse command line arguments
    if(argc < 2) {
        printf("Usage: %s <host>[:<port>]/<path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *host = strtok(argv[1], ":/");
    char *port = strtok(NULL, ":/");
    char *path = strtok(NULL, ":");

    if(!port) port = "80";
    if(!path) path = "/";

    // Step 2: Resolve host name to IP address
    struct addrinfo hints = {0}, *res;
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if(getaddrinfo(host, port, &hints, &res) != 0) {
        perror("getaddrinfo");
        exit(EXIT_FAILURE);
    }

    // Step 3: Create socket and connect to server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(connect(sockfd, res->ai_addr, res->ai_addrlen) != 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Step 4: Send HTTP request to server
    char *request = malloc(1024);
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s:%s\r\n\r\n", path, host, port);
    send(sockfd, request, strlen(request), 0);

    // Step 5: Receive HTTP response from server
    char response[4096];
    int n = recv(sockfd, response, sizeof(response), 0);

    if(n < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Step 6: Print HTTP response to console
    printf("%.*s\n", n, response);

    // Step 7: Close socket and free memory
    close(sockfd);
    freeaddrinfo(res);
    free(request);

    return 0;
}