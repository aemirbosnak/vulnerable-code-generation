//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 25
#define MAX_SIZE 4096

int main(int argc, char** argv) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buffer[MAX_SIZE];

    if(argc != 3) {
        printf("Usage: %s <IP address> <message>\n", argv[0]);
        return -1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return -1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    if(connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1) {
        printf("Error connecting to server: %s\n", strerror(errno));
        close(sockfd);
        return -1;
    }

    snprintf(buffer, MAX_SIZE, "HELO %s\r\n", argv[1]);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, MAX_SIZE, 0);

    snprintf(buffer, MAX_SIZE, "MAIL FROM: <%s>\r\n", argv[0]);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, MAX_SIZE, 0);

    snprintf(buffer, MAX_SIZE, "RCPT TO: <%s>\r\n", argv[2]);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, MAX_SIZE, 0);

    snprintf(buffer, MAX_SIZE, "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, MAX_SIZE, 0);

    snprintf(buffer, MAX_SIZE, "%s\r\n", argv[3]);
    send(sockfd, buffer, strlen(buffer), 0);

    snprintf(buffer, MAX_SIZE, ".\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, MAX_SIZE, 0);

    snprintf(buffer, MAX_SIZE, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, MAX_SIZE, 0);

    close(sockfd);
    return 0;
}