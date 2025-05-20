//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 25
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int n;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <message>\n", argv[0]);
        return 1;
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        fprintf(stderr, "Error creating socket\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error connecting to server: %s\n", strerror(errno));
        return 1;
    }

    sprintf(buffer, "HELO client\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    sprintf(buffer, "MAIL FROM:<%s>\r\n", argv[1]);
    send(sockfd, buffer, strlen(buffer), 0);

    sprintf(buffer, "RCPT TO:<%s>\r\n", argv[1]);
    send(sockfd, buffer, strlen(buffer), 0);

    sprintf(buffer, "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    sprintf(buffer, "Subject: Test Message\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    sprintf(buffer, "This is a test message.\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    sprintf(buffer, ".\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    close(sockfd);
    return 0;
}