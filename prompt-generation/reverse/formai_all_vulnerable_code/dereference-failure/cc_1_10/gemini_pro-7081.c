//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];

    struct sockaddr_in sockaddr;
    memset(&sockaddr, 0, sizeof(sockaddr));
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_addr.s_addr = inet_addr(hostname);

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    char *buf = malloc(1024);
    memset(buf, 0, 1024);
    strcpy(buf, "PING");

    int nbytes = sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&sockaddr, sizeof(sockaddr));
    if (nbytes < 0) {
        perror("sendto");
        exit(1);
    }

    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;

    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);

    int ret = select(sockfd + 1, &readfds, NULL, NULL, &tv);
    if (ret < 0) {
        perror("select");
        exit(1);
    }

    if (FD_ISSET(sockfd, &readfds)) {
        nbytes = recvfrom(sockfd, buf, 1024, 0, NULL, NULL);
        if (nbytes < 0) {
            perror("recvfrom");
            exit(1);
        }

        printf("Received %d bytes: %s\n", nbytes, buf);
    } else {
        printf("No response from host\n");
    }

    close(sockfd);
    free(buf);

    return 0;
}