//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <ctype.h>

#define MAX_LINE 1024
#define PORT 25

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char sendline[MAX_LINE];
    char recvline[MAX_LINE];

    if (argc!= 5) {
        printf("Usage:./smtp_client <server_ip> <sender_email> <receiver_email> <message>\n");
        exit(0);
    }

    strcpy(sendline, "HELO ");
    strcat(sendline, argv[1]);
    strcat(sendline, "\r\n");

    strcpy(sendline, "MAIL FROM: ");
    strcat(sendline, argv[2]);
    strcat(sendline, "\r\n");

    strcpy(sendline, "RCPT TO: ");
    strcat(sendline, argv[3]);
    strcat(sendline, "\r\n");

    strcpy(sendline, "DATA\r\n");
    strcat(sendline, argv[4]);
    strcat(sendline, "\r\n.\r\n");

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error: Unable to create socket\n");
        exit(0);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Unable to connect to server\n");
        exit(0);
    }

    if (send(sockfd, sendline, strlen(sendline), 0) < 0) {
        printf("Error: Unable to send data\n");
        exit(0);
    }

    while (1) {
        bzero(recvline, sizeof(recvline));
        n = recv(sockfd, recvline, MAX_LINE, 0);

        if (n <= 0) {
            break;
        }

        printf("%s", recvline);
    }

    close(sockfd);
    return 0;
}