//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in server_addr;
    char *host, *port;
    char request[1024];
    char response[4096];
    int n;

    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <host> <port> <method>\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    port = argv[2];
    strcpy(request, argv[3]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));
    server_addr.sin_addr.s_addr = inet_addr(host);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", argv[3], host);
    send(sockfd, request, strlen(request), 0);

    while ((n = read(sockfd, response, sizeof(response))) > 0) {
        response[n] = '\0';
        printf("%s", response);
    }

    close(sockfd);

    return 0;
}