//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s [Server IP Address] [Server Port Number] [Email Address]\n", argv[0]);
        exit(1);
    }

    // Create a socket
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error: Could not create socket\n");
        exit(1);
    }

    // Connect to the server
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));

    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        printf("Error: Invalid server IP address\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) < 0) {
        printf("Error: Could not connect to server\n");
        exit(1);
    }

    char recvbuf[MAX_BUF_SIZE], sendbuf[MAX_BUF_SIZE];
    int numbytes = 0;

    // Read the server's greeting
    numbytes = recv(sockfd, recvbuf, sizeof(recvbuf), 0);
    recvbuf[numbytes] = '\0';
    printf("%s", recvbuf);

    // Send the EHLO command
    sprintf(sendbuf, "EHLO %s\r\n", argv[3]);
    send(sockfd, sendbuf, strlen(sendbuf), 0);

    // Read the server's response
    numbytes = recv(sockfd, recvbuf, sizeof(recvbuf), 0);
    recvbuf[numbytes] = '\0';
    printf("%s", recvbuf);

    // Send the MAIL FROM command
    printf("From: ");
    fgets(sendbuf, sizeof(sendbuf), stdin);
    sprintf(sendbuf, "MAIL FROM: <%s>", strtok(sendbuf, "\n"));
    strcat(sendbuf, "\r\n");
    send(sockfd, sendbuf, strlen(sendbuf), 0);

    // Read the server's response
    numbytes = recv(sockfd, recvbuf, sizeof(recvbuf), 0);
    recvbuf[numbytes] = '\0';
    printf("%s", recvbuf);

    // Send the RCPT TO command
    printf("To: ");
    fgets(sendbuf, sizeof(sendbuf), stdin);
    sprintf(sendbuf, "RCPT TO: <%s>", strtok(sendbuf, "\n"));
    strcat(sendbuf, "\r\n");
    send(sockfd, sendbuf, strlen(sendbuf), 0);

    // Read the server's response
    numbytes = recv(sockfd, recvbuf, sizeof(recvbuf), 0);
    recvbuf[numbytes] = '\0';
    printf("%s", recvbuf);

    // Send the DATA command
    sprintf(sendbuf, "DATA\r\n");
    send(sockfd, sendbuf, strlen(sendbuf), 0);

    // Read the server's response
    numbytes = recv(sockfd, recvbuf, sizeof(recvbuf), 0);
    recvbuf[numbytes] = '\0';
    printf("%s", recvbuf);

    // Send the message body
    printf("Subject: ");
    fgets(sendbuf, sizeof(sendbuf), stdin);
    sprintf(sendbuf, "Subject: %s\r\n", strtok(sendbuf, "\n"));
    send(sockfd, sendbuf, strlen(sendbuf), 0);

    printf("Message body (End message by \".\" on its own line):\n");
    while (fgets(sendbuf, sizeof(sendbuf), stdin)) {
        if (strcmp(sendbuf, ".\n") == 0) {
            break;
        }
        send(sockfd, sendbuf, strlen(sendbuf), 0);
    }

    // Send the QUIT command
    sprintf(sendbuf, "QUIT\r\n");
    send(sockfd, sendbuf, strlen(sendbuf), 0);

    // Read the server's response
    numbytes = recv(sockfd, recvbuf, sizeof(recvbuf), 0);
    recvbuf[numbytes] = '\0';
    printf("%s", recvbuf);

    // Close the socket
    close(sockfd);

    return 0;
}