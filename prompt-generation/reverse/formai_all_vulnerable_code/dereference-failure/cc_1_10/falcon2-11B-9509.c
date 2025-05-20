//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <host> <port> <proxy_port>\n", argv[0]);
        return 1;
    }

    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    int result = getaddrinfo(argv[1], "http", &hints, &res);
    if (result!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(result));
        return 1;
    }

    struct addrinfo *ai = res;
    freeaddrinfo(res);

    int sockfd = socket(ai->ai_family, ai->ai_socktype, ai->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server_addr, client_addr;
    socklen_t addrlen = sizeof(client_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return 1;
    }

    int yes = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));

    freeaddrinfo(ai);

    while (1) {
        char buf[1024];
        int len = recv(sockfd, buf, sizeof(buf), 0);
        if (len == -1) {
            perror("recv");
            return 1;
        }

        char request[1024];
        strncpy(request, buf, len);
        request[len] = '\0';

        char response[1024];
        strcpy(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body>");
        strcat(response, buf);
        strcat(response, "</body></html>");

        int sent = send(sockfd, response, strlen(response), 0);
        if (sent == -1) {
            perror("send");
            return 1;
        }
    }

    return 0;
}