//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

int main(int argc, char *argv[])
{
    int sockfd, n, portno;
    struct sockaddr_in serv_addr;
    char buffer[BUFSIZE];
    struct timeval start, end;

    if (argc < 3) {
        fprintf(stderr, "usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    gettimeofday(&start, NULL);
    n = write(sockfd, "GET / HTTP/1.1\r\n\r\n", 19);
    if (n < 0) {
        perror("write");
        exit(1);
    }

    while ((n = read(sockfd, buffer, BUFSIZE)) > 0) ;
    if (n < 0) {
        perror("read");
        exit(1);
    }

    gettimeofday(&end, NULL);

    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

    printf("Elapsed time: %.3f seconds\n", elapsed);

    close(sockfd);

    return 0;
}