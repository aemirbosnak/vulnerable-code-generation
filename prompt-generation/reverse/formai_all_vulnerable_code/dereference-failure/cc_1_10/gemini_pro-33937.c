//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>
#include <string.h>

#define BUFSIZE 1024

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in servaddr;
    struct hostent *he;
    char buf[BUFSIZE];
    int n;
    int i;clock_t start, end;
    double elapsed_time;

    if (argc != 2) {
        fprintf(stderr, "usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    if ((he = gethostbyname(argv[1])) == NULL) {  
        herror("gethostbyname");
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr = *((struct in_addr *)he->h_addr);
    servaddr.sin_port = htons(80);  

  
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    strcpy(buf, "GET / HTTP/1.1\nHost: ");
    strcat(buf, argv[1]);
    strcat(buf, "\n\n");

    n = write(sockfd, buf, strlen(buf));
    if (n < 0) {
        perror("write");
        exit(1);
    }

    while ((n = read(sockfd, buf, BUFSIZE)) > 0) {
        for (i = 0; i < n; i++) {
            putchar(buf[i]);
        }
    }

    if (n < 0) {
        perror("read");
        exit(1);
    }

    close(sockfd);

    return 0;
}