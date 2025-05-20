//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define BUFSIZE 1024

char *hostname;
int port;
int sockfd;
struct sockaddr_in servaddr;

void usage() {
    fprintf(stderr, "Usage: %s hostname port\n", hostname);
    exit(1);
}

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        usage();
    }

    hostname = argv[1];
    port = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("socket");
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if (inet_pton(AF_INET, hostname, &servaddr.sin_addr) <= 0) {
        error("inet_pton");
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        error("connect");
    }

    char buf[BUFSIZE];
    int n;
    struct timeval start, end;

    gettimeofday(&start, NULL);
    while ((n = read(sockfd, buf, BUFSIZE)) > 0) {
        write(STDOUT_FILENO, buf, n);
    }
    gettimeofday(&end, NULL);

    if (n < 0) {
        error("read");
    }

    close(sockfd);

    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    double bytes = n;
    double kbps = bytes / elapsed / 1024.0;

    printf("\nSpeed: %.2f kbps\n", kbps);

    return 0;
}