//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

int main(int argc, char *argv[])
{
    struct timeval start, end;
    int sockfd, n, i;
    char buf[BUFSIZE];
    socklen_t addrlen;
    struct sockaddr_in serveraddr;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server IP address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr(argv[1]);
    serveraddr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    gettimeofday(&start, NULL);

    for (i = 0; i < 10; i++) {
        memset(buf, 0, sizeof(buf));
        n = read(sockfd, buf, BUFSIZE);
        if (n < 0) {
            perror("read");
            exit(EXIT_FAILURE);
        }
    }

    gettimeofday(&end, NULL);

    printf("Elapsed time: %ld ms\n", (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000);

    close(sockfd);

    return EXIT_SUCCESS;
}