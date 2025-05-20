//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define SERVER "smtp.gmail.com"
#define PORT 587

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int n;

    if (argc!= 4) {
        printf("Usage:./smtp_client <username> <password> <recipient>\n");
        return 1;
    }

    strcpy(buffer, argv[1]);
    strcat(buffer, "\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    strcpy(buffer, argv[2]);
    strcat(buffer, "\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    strcpy(buffer, "MAIL FROM:<");
    strcat(buffer, argv[1]);
    strcat(buffer, ">\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    strcpy(buffer, "RCPT TO:<");
    strcat(buffer, argv[3]);
    strcat(buffer, ">\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    strcpy(buffer, "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    strcpy(buffer, "Subject: Test Email\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    strcpy(buffer, "\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    strcpy(buffer, "This is a test email sent using a C SMTP client.\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    strcpy(buffer, ".\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    close(sockfd);

    return 0;
}