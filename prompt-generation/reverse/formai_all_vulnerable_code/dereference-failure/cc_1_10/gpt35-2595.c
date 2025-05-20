//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, port, response_length;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_address;
    struct hostent *server;
    char *request_format = "GET /%s HTTP/1.0\r\nHost: %s\r\n\r\n";

    if (argc < 3) {
        fprintf(stderr,"Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    port = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    memcpy(&server_address.sin_addr.s_addr, server->h_addr, server->h_length);
    server_address.sin_port = htons(port);

    if (connect(sockfd,(struct sockaddr *) &server_address,sizeof(server_address)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    char request[BUFFER_SIZE];
    sprintf(request, request_format, "/", argv[1]);

    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("ERROR sending request");
        exit(1);
    }

    memset(buffer, 0, BUFFER_SIZE);
    response_length = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);

    while (response_length > 0) {
        printf("%s", buffer);
        memset(buffer, 0, BUFFER_SIZE);
        response_length = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    }

    close(sockfd);
    return 0;
}