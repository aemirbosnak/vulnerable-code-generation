//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct addrinfo hints, *res;
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_protocol = IPPROTO_UDP;
    hints.ai_flags = AI_PASSIVE;

    int err = getaddrinfo(argv[1], NULL, &hints, &res);
    if (err != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(err));
        return EXIT_FAILURE;
    }

    int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        freeaddrinfo(res);
        return EXIT_FAILURE;
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(3451);
    servaddr.sin_addr = ((struct sockaddr_in *)res->ai_addr)->sin_addr;

    char buf[BUF_SIZE];
    memset(buf, 0, sizeof(buf));
    strcpy(buf, "PING");

    ssize_t nbytes = sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (nbytes == -1) {
        perror("sendto");
        close(sockfd);
        freeaddrinfo(res);
        return EXIT_FAILURE;
    }

    struct sockaddr_in from;
    memset(&from, 0, sizeof(from));
    socklen_t fromlen = sizeof(from);

    nbytes = recvfrom(sockfd, buf, BUF_SIZE, 0, (struct sockaddr *)&from, &fromlen);
    if (nbytes == -1) {
        perror("recvfrom");
        close(sockfd);
        freeaddrinfo(res);
        return EXIT_FAILURE;
    }

    buf[nbytes] = '\0';
    printf("Received: %s\n", buf);

    close(sockfd);
    freeaddrinfo(res);

    return EXIT_SUCCESS;
}