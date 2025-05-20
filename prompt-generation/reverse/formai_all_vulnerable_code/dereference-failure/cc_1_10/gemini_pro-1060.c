//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
    int sockfd, n;
    struct ifreq ifr;
    struct sockaddr_in sin;
    unsigned char buf[1024];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <interface> <ip address>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    memset(&ifr, 0, sizeof(ifr));
    strncpy(ifr.ifr_name, argv[1], IFNAMSIZ);
    if (ioctl(sockfd, SIOCGIFADDR, &ifr) < 0) {
        perror("ioctl(SIOCGIFADDR)");
        exit(1);
    }

    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(argv[2]);
    if (connect(sockfd, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
        perror("connect");
        exit(1);
    }

    while (1) {
        memset(buf, 0, sizeof(buf));
        n = recv(sockfd, buf, sizeof(buf), 0);
        if (n < 0) {
            perror("recv");
            exit(1);
        }

        printf("Received %d bytes from %s\n", n, inet_ntoa(sin.sin_addr));
    }

    close(sockfd);
    return 0;
}