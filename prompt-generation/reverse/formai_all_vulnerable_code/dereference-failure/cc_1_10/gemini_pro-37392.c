//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {
    int sockfd, n, i, j;
    struct sockaddr_in servaddr;
    char buf[BUF_SIZE];
    struct timeval start, end;
    double elapsed;
    int num_bytes;
    int num_iterations;
    char *hostname;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <num_iterations>\n", argv[0]);
        return 1;
    }

    hostname = argv[1];
    num_iterations = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(80);

    if (inet_pton(AF_INET, hostname, &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        return 1;
    }

    for (i = 0; i < num_iterations; i++) {
        memset(buf, 0, sizeof(buf));
        strcpy(buf, "GET / HTTP/1.1\r\nHost: ");
        strcat(buf, hostname);
        strcat(buf, "\r\n\r\n");

        gettimeofday(&start, NULL);
        n = write(sockfd, buf, strlen(buf));
        if (n < 0) {
            perror("write");
            return 1;
        }

        num_bytes = 0;
        while ((n = read(sockfd, buf, BUF_SIZE)) > 0) {
            num_bytes += n;
        }
        gettimeofday(&end, NULL);

        elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
        printf("%d: %.2f seconds, %.2f kbps\n", i, elapsed, (num_bytes / elapsed) / 1024.0);
    }

    close(sockfd);

    return 0;
}