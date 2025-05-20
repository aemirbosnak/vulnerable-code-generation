//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAXLINE 1024

struct sockaddr_in servaddr;

int main(int argc, char **argv)
{
    int sockfd;
    char recvline[MAXLINE];
    struct hostent *hp;

    if (argc != 3) {
        fprintf(stderr, "usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    hp = gethostbyname(argv[1]);
    if (hp == NULL) {
        fprintf(stderr, "gethostbyname error for %s\n", argv[1]);
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *)hp->h_addr_list[0], (char *)&servaddr.sin_addr, hp->h_length);
    servaddr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    while (1) {
        bzero(recvline, MAXLINE);
        if (recv(sockfd, recvline, MAXLINE, 0) < 0) {
            perror("recv");
            exit(1);
        }

        if (strcmp(recvline, "exit") == 0) {
            break;
        }

        printf("%s", recvline);
    }

    close(sockfd);

    return 0;
}