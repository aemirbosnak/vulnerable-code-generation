//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAX_PORT 65535

void print_usage() {
    printf("Usage:./port_scanner <target_ip>\n");
    exit(1);
}

void print_results(int sockfd) {
    int port;
    while ((port = getport(sockfd))!= -1) {
        printf("%d\n", port);
    }
}

int getport(int sockfd) {
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(0);

    if (bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        return -1;
    }

    int port = ntohs(addr.sin_port);
    return port;
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        print_usage();
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    struct hostent* host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "Error: No such host\n");
        exit(1);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(0);
    addr.sin_addr = *((struct in_addr*)host->h_addr);

    if (connect(sockfd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        perror("connect");
        exit(1);
    }

    int port;
    while ((port = getport(sockfd))!= -1) {
        printf("%d\n", port);
    }

    close(sockfd);
    return 0;
}