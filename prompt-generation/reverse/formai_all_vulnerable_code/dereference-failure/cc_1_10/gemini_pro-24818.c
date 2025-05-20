//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>
#include <signal.h>

#define BUFSIZE 1024

int sockfd;
struct sockaddr_in servaddr;

void sigint_handler(int signum) {
    close(sockfd);
    exit(0);
}

int main(int argc, char **argv) {
    int port, n;
    char *host;
    char buf[BUFSIZE];
    struct hostent *hp;
    struct timeval start, end;
    double elapsed;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    port = atoi(argv[2]);

    if ((hp = gethostbyname(host)) == NULL) {
        fprintf(stderr, "gethostbyname: %s\n", hstrerror(h_errno));
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    signal(SIGINT, sigint_handler);

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    memcpy(&servaddr.sin_addr.s_addr, hp->h_addr, hp->h_length);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    gettimeofday(&start, NULL);

    if ((n = write(sockfd, "PING", 4)) == -1) {
        perror("write");
        exit(1);
    }

    if ((n = read(sockfd, buf, BUFSIZE)) == -1) {
        perror("read");
        exit(1);
    }

    gettimeofday(&end, NULL);

    elapsed = (end.tv_sec - start.tv_sec) * 1000.0;
    elapsed += (end.tv_usec - start.tv_usec) / 1000.0;

    printf("RTT: %.3f ms\n", elapsed);

    close(sockfd);

    return 0;
}