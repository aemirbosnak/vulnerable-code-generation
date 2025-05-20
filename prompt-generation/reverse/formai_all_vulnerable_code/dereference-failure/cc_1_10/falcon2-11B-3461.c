//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 25
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, valread;
    struct sockaddr_in serveraddr;
    struct hostent *server;
    char buf[BUF_SIZE];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <hostname> <to> \n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serveraddr.sin_addr.s_addr, server->h_length);
    serveraddr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    snprintf(buf, BUF_SIZE, "Subject: %s\r\nTo: %s\r\n\r\n%s", argv[2], argv[3], argv[4]);
    write(sockfd, buf, strlen(buf));

    close(sockfd);

    return 0;
}