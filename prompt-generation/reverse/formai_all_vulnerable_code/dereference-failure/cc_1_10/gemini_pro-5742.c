//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/time.h>

#define BUFSIZE 1024

int main(int argc, char **argv)
{
    int sockfd, n, i;
    struct sockaddr_in servaddr, cliaddr;
    char buf[BUFSIZE];
    struct timeval start, end;

    if (argc != 3) {
        printf("Usage: %s <SERVER_IP_ADDRESS> <SERVER_PORT>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    gettimeofday(&start, NULL);

    for (i = 0; i < 100; i++) {
        n = sendto(sockfd, buf, BUFSIZE, 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
        if (n == -1) {
            perror("sendto");
            exit(1);
        }
    }

    gettimeofday(&end, NULL);

    printf("Elapsed time: %fs\n", (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0);

    close(sockfd);

    return 0;
}