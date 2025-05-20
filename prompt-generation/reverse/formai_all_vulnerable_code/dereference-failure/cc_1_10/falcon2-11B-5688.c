//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 25

int main() {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char *host = "smtp.example.com";
    char message[] = "Subject: test message\r\n\r\nHello, World!";

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    server = gethostbyname(host);
    if (server == NULL) {
        perror("Error resolving host");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting");
        exit(1);
    }

    n = write(sockfd, message, strlen(message));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    n = read(sockfd, message, sizeof(message));
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }

    printf("Received: %s\n", message);

    close(sockfd);

    return 0;
}