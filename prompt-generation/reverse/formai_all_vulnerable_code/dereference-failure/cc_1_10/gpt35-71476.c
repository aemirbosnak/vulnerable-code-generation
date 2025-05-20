//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 80
#define BUFFER_SIZE 1024
#define USER_AGENT "Mozilla/5.0 (X11; Linux x86_64; rv:81.0) Gecko/20100101 Firefox/81.0"

int main(int argc, char *argv[]) {
    char *host;
    int sockfd, status;
    struct addrinfo hints, *res, *p;
    char *ip_address;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    host = argv[1];

    memset(&hints, 0 ,sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if ((status = getaddrinfo(host, "http", &hints, &res)) != 0) {
        fprintf(stderr, "Error: %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
    }

    for (p = res; p != NULL; p = p->ai_next) {
        void *addr;
        struct sockaddr_in *ipv4 = (struct sockaddr_in *) p->ai_addr;
        addr = &(ipv4->sin_addr);
        ip_address = malloc(INET_ADDRSTRLEN + 1);
        inet_ntop(p->ai_family, addr, ip_address, INET_ADDRSTRLEN);
        break;
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    if (sockfd == -1) {
        fprintf(stderr, "Error: Could not create socket\n");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
        fprintf(stderr, "Error: Could not connect to %s\n", host);
        exit(EXIT_FAILURE);
    }

    char *buffer = malloc(BUFFER_SIZE);
    sprintf(buffer, "GET / HTTP/1.1\r\nHost: %s\r\nUser-Agent: %s\r\nConnection: close\r\n\r\n", host, USER_AGENT);

    int bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
    printf("%d bytes sent\n\n", bytes_sent);

    int bytes_received;
    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    freeaddrinfo(res);
    free(buffer);
    free(ip_address);

    return 0;
}