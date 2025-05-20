//MISTRAL-7B DATASET v1.0 Category: Port Scanner ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>
#include <arpa/inet.h>

#define PORT_MIN 1
#define PORT_MAX 65535
#define BUFFER_SIZE 1024
#define BANNER "🚀 Port Scanner 3000 🌠\nScanning IP: %s from Port %d to %d\n"

void die(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int ip, port_start, port_end, sockfd, i;
    char ipstr[INET_ADDRSTRLEN];
    struct sockaddr_in server_addr;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s IP_ADDRESS PORT_RANGE\n", argv[0]);
        return 1;
    }

    ip = inet_addr(argv[1]);
    if (ip == INADDR_NONE) {
        fprintf(stderr, "Invalid IP address: %s\n", argv[1]);
        return 1;
    }

    port_start = atoi(argv[2]);
    port_end = port_start + 1;

    if (ssockopen(ip, port_start, IPPROTO_TCP, &sockfd) < 0) {
        fprintf(stderr, "Can't open socket to %s:%d\n", inet_ntoa(*(struct in_addr*)&ip), port_start);
        return 1;
    }

    printf(BANNER, argv[1], port_start, port_end);

    for (i = port_start; i <= port_end; i++) {
        memset(&server_addr, 0, sizeof(struct sockaddr_in));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(i);
        server_addr.sin_addr.s_addr = ip;

        if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(struct sockaddr)) < 0) {
            continue;
        }

        printf("🎯 Port %d OPEN!\n", i);
        close(sockfd);
        break;
    }

    close(sockfd);

    if (i > port_end) {
        printf("💔 All ports closed!\n");
    }

    return 0;
}

int ssockopen(const char *host, int port, int protocol, int *sockfd) {
    int retries = 5;

    while ((*sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        if (retries-- <= 0) {
            perror("socket");
            return -1;
        }
        sleep(1);
    }

    struct hostent *hp = gethostbyname(host);
    if (!hp) {
        herror("gethostbyname");
        close(*sockfd);
        return -1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(struct sockaddr_in));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    bcopy(hp->h_addr, &server_addr.sin_addr.s_addr, hp->h_length);

    if (connect(*sockfd, (struct sockaddr*)&server_addr, sizeof(struct sockaddr)) < 0) {
        close(*sockfd);
        return -1;
    }

    return 0;
}