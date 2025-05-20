//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_LINE 1024
#define PORT 25

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, valread;
    struct sockaddr_in serv_addr, cli_addr;
    char sendline[MAX_LINE], recvline[MAX_LINE];
    char *token;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("Error: Failed to create socket\n");
        exit(1);
    }

    // Set server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Error: Failed to connect to server\n");
        exit(1);
    }

    // Send HELO command
    sprintf(sendline, "HELO %s\r\n", argv[1]);
    send(sockfd, sendline, strlen(sendline), 0);

    // Send MAIL FROM command
    sprintf(sendline, "MAIL FROM:<%s>\r\n", argv[1]);
    send(sockfd, sendline, strlen(sendline), 0);

    // Send RCPT TO command
    sprintf(sendline, "RCPT TO:<%s>\r\n", argv[2]);
    send(sockfd, sendline, strlen(sendline), 0);

    // Send DATA command
    sprintf(sendline, "DATA\r\n");
    send(sockfd, sendline, strlen(sendline), 0);

    // Send message body
    sprintf(sendline, "Subject: %s\r\n", argv[3]);
    send(sockfd, sendline, strlen(sendline), 0);
    sprintf(sendline, "\r\n%s", argv[4]);
    send(sockfd, sendline, strlen(sendline), 0);

    // Send QUIT command
    sprintf(sendline, "QUIT\r\n");
    send(sockfd, sendline, strlen(sendline), 0);

    // Close connection
    close(sockfd);

    return 0;
}