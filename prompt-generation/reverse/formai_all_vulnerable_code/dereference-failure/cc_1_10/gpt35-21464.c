//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFSIZE 1024

volatile sig_atomic_t stop;

void sigint_handler(int signum) {
    stop = 1;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    signal(SIGINT, sigint_handler);

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    int optval = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
        perror("setsockopt");
        exit(1);
    }

    struct sockaddr_in serveraddr;
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(atoi(argv[1]));

    if (bind(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("bind");
        exit(1);
    }

    char buf[BUFSIZE];
    struct sockaddr_in clientaddr;
    socklen_t clientlen;
    int nbytes;

    printf("QoS monitor started on port %s\n", argv[1]);

    while (!stop) {
        memset(buf, 0, BUFSIZE);
        clientlen = sizeof(clientaddr);
        nbytes = recvfrom(sockfd, buf, BUFSIZE, 0, (struct sockaddr*)&clientaddr, &clientlen);
        if (nbytes < 0) {
            perror("recvfrom");
            continue;
        }
        char clientip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &clientaddr.sin_addr, clientip, INET_ADDRSTRLEN);
        printf("Received %d bytes from client %s:%d\n", nbytes, clientip, ntohs(clientaddr.sin_port));
        printf("%s\n", buf);
    }

    printf("QoS monitor stopped\n");

    close(sockfd);
    return 0;
}