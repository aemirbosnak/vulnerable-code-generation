//Falcon2-11B DATASET v1.0 Category: Building a HTTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    struct protoent *proto;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr, "Hostname not found\n");
        exit(1);
    }

    portno = htons(80); // Default port for HTTP

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = portno;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    char request[100];
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1], argv[1]);

    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("send failed");
        exit(1);
    }

    int n;
    char buffer[1024];
    n = recv(sockfd, buffer, 1024, 0);

    if (n < 0) {
        perror("recv failed");
        exit(1);
    }

    printf("Response: %s", buffer);

    close(sockfd);
    return 0;
}