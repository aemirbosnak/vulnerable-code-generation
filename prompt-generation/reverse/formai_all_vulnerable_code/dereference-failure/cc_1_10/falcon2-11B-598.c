//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAXLINE 100

int main(int argc, char *argv[]) {
    int sockfd, numbytes;
    struct sockaddr_in serveraddr;
    char buffer[MAXLINE];
    int n;
    char *host = argv[1];
    int port = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error opening socket\n");
        exit(1);
    }

    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &serveraddr.sin_addr) <= 0) {
        fprintf(stderr, "Error converting hostname to address\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0) {
        fprintf(stderr, "Error connecting to server\n");
        exit(1);
    }

    while (1) {
        printf("POP3 client> ");
        fgets(buffer, MAXLINE, stdin);
        n = send(sockfd, buffer, strlen(buffer), 0);
        if (n < 0) {
            fprintf(stderr, "Error sending data\n");
            exit(1);
        }
        numbytes = recv(sockfd, buffer, MAXLINE, 0);
        if (numbytes <= 0) {
            fprintf(stderr, "Error receiving data\n");
            exit(1);
        }
        printf("%s\n", buffer);
    }

    return 0;
}