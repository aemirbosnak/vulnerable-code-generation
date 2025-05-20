//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

int main(int argc, char **argv)
{
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buf[BUFSIZE];
    struct timeval start, end;
    double elapsed;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server IP address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    gettimeofday(&start, NULL);

    for (int i = 0; i < 100; i++) {
        if ((n = read(sockfd, buf, BUFSIZE)) < 0) {
            perror("read");
            exit(EXIT_FAILURE);
        }
    }

    gettimeofday(&end, NULL);

    elapsed = (end.tv_sec - start.tv_sec) * 1000.0;
    elapsed += (end.tv_usec - start.tv_usec) / 1000.0;

    printf("Elapsed time: %.3f ms\n", elapsed);

    close(sockfd);
    return 0;
}