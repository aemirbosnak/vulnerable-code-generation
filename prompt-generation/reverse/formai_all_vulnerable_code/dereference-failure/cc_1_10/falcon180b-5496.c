//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/time.h>
#include <time.h>

int main(int argc, char **argv) {
    int sockfd;
    int portno;
    int n;
    char *ip;
    char buffer[1024];
    struct hostent *server;
    struct sockaddr_in serv_addr;
    struct timeval timeout;
    fd_set readfds;

    if (argc!= 4) {
        printf("Usage: %s <server> <port> <file>\n", argv[0]);
        exit(1);
    }

    ip = argv[1];
    portno = atoi(argv[2]);
    FILE *fp = fopen(argv[3], "r");

    if (fp == NULL) {
        printf("Error: File not found\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error: Socket creation failed\n");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Connection failed\n");
        exit(1);
    }

    printf("Connected to %s:%d\n", ip, portno);

    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    while (fgets(buffer, sizeof(buffer), fp)!= NULL) {
        n = strlen(buffer);
        send(sockfd, buffer, n, 0);
    }

    close(sockfd);
    close(fp);

    return 0;
}