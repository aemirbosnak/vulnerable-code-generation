//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

struct hostent *gethostbyname(const char *name);

int main(int argc, char *argv[]) {
    int sockfd, port, opt, addrlen;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[BUFFER_SIZE];
    char *ip;
    int i;

    if (argc!= 4) {
        printf("usage: %s <IP> <port> <host>\n", argv[0]);
        return 1;
    }

    ip = argv[1];
    port = atoi(argv[2]);
    opt = atoi(argv[3]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(ip);
    servaddr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        return 1;
    }

    addrlen = sizeof(cliaddr);
    if (getsockname(sockfd, (struct sockaddr *)&cliaddr, &addrlen) == -1) {
        perror("getsockname");
        return 1;
    }

    printf("Connected to %s:%d\n", inet_ntoa(servaddr.sin_addr), ntohs(servaddr.sin_port));
    printf("Local address: %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

    for (i = 0; i < opt; i++) {
        memset(buffer, 0, BUFFER_SIZE);
        if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
            perror("recv");
            return 1;
        }
        printf("%s\n", buffer);
    }

    close(sockfd);
    return 0;
}

struct hostent *gethostbyname(const char *name) {
    struct hostent *he;
    he = gethostbyname(name);
    if (he == NULL) {
        herror("gethostbyname");
        exit(1);
    }
    return he;
}