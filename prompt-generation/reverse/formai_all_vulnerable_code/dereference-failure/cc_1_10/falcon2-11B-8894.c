//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 25
#define BUFSIZE 1024

int main() {
    int sockfd, bytes_read;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buf[BUFSIZE];
    char *message = "From: user@example.com\nTo: user@example.com\nSubject: Test\n\nThis is a test message.";

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("smtp.example.com");
    if (server == NULL) {
        perror("ERROR, no such host");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    bytes_read = write(sockfd, message, strlen(message));
    if (bytes_read < 0) {
        perror("ERROR writing to socket");
        exit(EXIT_FAILURE);
    }

    close(sockfd);
    return 0;
}