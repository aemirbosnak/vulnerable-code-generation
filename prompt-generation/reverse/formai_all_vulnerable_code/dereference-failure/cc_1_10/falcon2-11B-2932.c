//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    int sockfd;
    struct hostent *server;
    struct sockaddr_in servaddr;

    char *host = argv[1];
    char *port = argv[2];

    memset((char *) &servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(host);
    servaddr.sin_port = htons(atoi(port));

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Error connecting");
        exit(1);
    }

    printf("Connected to %s:%s\n", host, port);

    char msg[256];
    strcpy(msg, "Subject: test\r\n\r\n");
    strcat(msg, "This is a test message\n");
    send(sockfd, msg, strlen(msg), 0);

    char buf[1024];
    int n = recv(sockfd, buf, sizeof(buf), 0);
    if (n < 0) {
        perror("Error receiving data");
        exit(1);
    }

    printf("%s\n", buf);

    close(sockfd);
    return 0;
}