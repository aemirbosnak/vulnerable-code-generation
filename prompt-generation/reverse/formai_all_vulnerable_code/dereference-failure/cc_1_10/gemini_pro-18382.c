//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAXLINE 8192

char* create_get_request(char* host, char* path) {
    char* request = malloc(MAXLINE);
    sprintf(request, "GET %s HTTP/1.1\r\n", path);
    sprintf(request, "%sHost: %s\r\n", request, host);
    strcat(request, "\r\n");
    return request;
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <host> <path>\n", argv[0]);
        exit(1);
    }

    char* host = argv[1];
    char* path = argv[2];

    // create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // resolve the hostname
    struct hostent* host_entry = gethostbyname(host);
    if (host_entry == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    // create a sockaddr_in structure
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr = *((struct in_addr*)host_entry->h_addr);

    // connect to the server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    // create the GET request
    char* request = create_get_request(host, path);

    // send the GET request
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send");
        exit(1);
    }

    // receive the response
    char response[MAXLINE];
    int bytes_received = recv(sockfd, response, MAXLINE, 0);
    if (bytes_received == -1) {
        perror("recv");
        exit(1);
    }

    // print the response
    printf("%s", response);

    // close the socket
    close(sockfd);

    return 0;
}