//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_NAME "mail.example.com"
#define SERVER_PORT 110
#define ACCOUNT "your_email@example.com"
#define PASSWORD "your_password"

int main() {
    struct hostent *host;
    struct sockaddr_in serverAddr;

    if ((host = gethostbyname(SERVER_NAME)) == NULL) {
        fprintf(stderr, "Error: No such host\n");
        exit(1);
    }

    bzero(&serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    bcopy((char *)host->h_addr, (char *)&serverAddr.sin_addr.s_addr, host->h_length);
    serverAddr.sin_port = htons(SERVER_PORT);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Error connecting");
        exit(1);
    }

    char buf[1024];
    printf("POP3 client connecting to %s:%d\n", SERVER_NAME, SERVER_PORT);

    if (send(sockfd, "USER " ACCOUNT "\r\n", 13, 0) < 0) {
        perror("Error sending USER command");
        exit(1);
    }
    if (send(sockfd, "PASS " PASSWORD "\r\n", 12, 0) < 0) {
        perror("Error sending PASS command");
        exit(1);
    }
    if (send(sockfd, "STAT\r\n", 7, 0) < 0) {
        perror("Error sending STAT command");
        exit(1);
    }

    if (recv(sockfd, buf, 1024, 0) < 0) {
        perror("Error receiving STAT response");
        exit(1);
    }

    printf("Received STAT response:\n%s", buf);

    if (recv(sockfd, buf, 1024, 0) < 0) {
        perror("Error receiving QUIT response");
        exit(1);
    }

    printf("Received QUIT response:\n%s", buf);

    close(sockfd);
    exit(0);
}