//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define DEFAULT_PORT 80
#define DEFAULT_HOST "www.google.com"
#define BUF_SIZE 1024

int main(int argc, char **argv) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buf[BUF_SIZE];
    char *host = DEFAULT_HOST;
    int port = DEFAULT_PORT;
    struct timeval start, end;
    double elapsed;

    if (argc > 1) {
        host = argv[1];
    }
    if (argc > 2) {
        port = atoi(argv[2]);
    }

    printf("Testing internet speed to %s:%d...\n", host, port);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    server = gethostbyname(host);
    if (server == NULL) {
        perror("gethostbyname");
        return -1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char *) &serv_addr.sin_addr.s_addr, (char *) server->h_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return -1;
    }

    gettimeofday(&start, NULL);
    bzero(buf, BUF_SIZE);
    n = write(sockfd, buf, BUF_SIZE);
    if (n < 0) {
        perror("write");
        return -1;
    }
    bzero(buf, BUF_SIZE);
    n = read(sockfd, buf, BUF_SIZE);
    if (n < 0) {
        perror("read");
        return -1;
    }
    gettimeofday(&end, NULL);

    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

    printf("Time elapsed: %f seconds\n", elapsed);
    printf("Speed: %f bytes per second\n", (BUF_SIZE * 2) / elapsed);

    close(sockfd);

    return 0;
}