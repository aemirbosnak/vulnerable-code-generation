//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

void error(char* message) {
    perror(message);
    exit(1);
}

void get_request(int sockfd, char* url) {
    char buffer[BUFFER_SIZE];
    sprintf(buffer, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", url);
    write(sockfd, buffer, strlen(buffer));
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s url\n", argv[0]);
        exit(1);
    }

    struct hostent* server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Could not resolve host: %s\n", argv[1]);
        exit(1);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd < 0) {
        error("Could not create socket");
    }

    struct sockaddr_in server_address;
    bzero((char*)&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char*)server->h_addr, (char*)&server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(80);

    if (connect(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        error("Could not connect to server");
    }

    get_request(sockfd, argv[1]);

    char response[BUFFER_SIZE];
    memset(response, 0, BUFFER_SIZE);

    while (read(sockfd, response, BUFFER_SIZE - 1) > 0) {
        printf("%s", response);
        memset(response, 0, BUFFER_SIZE);
    }

    close(sockfd);

    return 0;
}