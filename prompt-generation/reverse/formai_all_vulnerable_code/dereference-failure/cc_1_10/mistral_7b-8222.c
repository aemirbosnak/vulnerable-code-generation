//MISTRAL-7B DATASET v1.0 Category: Building a HTTP Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BOOM 1
#define SHOCKED "\033[1;31m========( ͡° ͜ʖ ͡°)========\033[0m"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("%s\n", SHOCKED);
        printf("Usage: %s <IP_ADDRESS> <PORT_NUMBER>\n", argv[0]);
        printf("%s\n", SHOCKED);
        return 1;
    }

    const char *ip_address = argv[1];
    int port_number = atoi(argv[2]);

    int sockfd;
    struct sockaddr_in server_address;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        printf("%s\n", SHOCKED);
        return 1;
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_number);
    inet_pton(AF_INET, ip_address, &server_address.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("connect");
        printf("%s\n", SHOCKED);
        return 1;
    }

    char request[1024];
    snprintf(request, sizeof(request), "GET / HTTP/1.1\r\nHost: %s:%d\r\nUser-Agent: Shockingly-Bad-Client/1.0\r\nAccept: */*\r\nConnection: close\r\n\r\n", ip_address, port_number);

    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("send");
        printf("%s\n", SHOCKED);
        return 1;
    }

    char response[1024];
    ssize_t n;
    while ((n = recv(sockfd, response, sizeof(response) - 1, 0)) > 0) {
        response[n] = '\0';
        printf("%s\n", response);
        memset(response, 0, sizeof(response));

        if (strstr(response, "\r\n\r\n") != NULL) {
            break;
        }
    }

    if (n < 0) {
        perror("recv");
        printf("%s\n", SHOCKED);
        return 1;
    }

    if (close(sockfd) < 0) {
        perror("close");
        printf("%s\n", SHOCKED);
        return 1;
    }

    if (BOOM) {
        printf("%s\n", SHOCKED);
        printf("KABOOM!\n");
        printf("%s\n", SHOCKED);
    }

    return 0;
}