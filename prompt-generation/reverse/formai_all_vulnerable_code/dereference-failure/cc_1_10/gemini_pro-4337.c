//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netdb.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "Could not resolve hostname\n");
        exit(EXIT_FAILURE);
    }

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(33434);
    memcpy(&servaddr.sin_addr, host->h_addr_list[0], host->h_length);

    int n;
    char sendline[MAX_LINE], recvline[MAX_LINE];

    struct timeval start, end;
    double rtt;

    for (int i = 0; i < 10; i++) {
        sprintf(sendline, "PING %d", i);
        gettimeofday(&start, NULL);
        n = sendto(sockfd, sendline, strlen(sendline), 0, (struct sockaddr *) &servaddr, sizeof(servaddr));
        if (n < 0) {
            perror("sendto");
            exit(EXIT_FAILURE);
        }
        n = recvfrom(sockfd, recvline, MAX_LINE, 0, NULL, NULL);
        if (n < 0) {
            perror("recvfrom");
            exit(EXIT_FAILURE);
        }
        gettimeofday(&end, NULL);
        rtt = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;
        printf("%s: %d bytes from %s: icmp_seq=%d ttl=%d time=%.3f ms\n", argv[0], n, argv[1], i, 255, rtt);
    }

    close(sockfd);

    return 0;
}