//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>

#define PORT 8080
#define MAXLINE 1024

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if ( (server = gethostbyname("localhost")) == NULL ) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }

    portno = PORT;
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "ERROR opening socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "ERROR connecting\n");
        exit(1);
    }

    char buf[MAXLINE];
    char *p;

    printf("Enter a line to be sent: ");
    fgets(buf, MAXLINE, stdin);
    p = buf;

    while (p - buf < MAXLINE) {
        if (send(sockfd, p, strlen(p), 0) < 0) {
            fprintf(stderr, "ERROR sending data\n");
            exit(1);
        }
        p += strlen(p);
    }

    close(sockfd);
    return 0;
}