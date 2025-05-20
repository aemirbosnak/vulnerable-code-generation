//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>

#define MAXLINE 1024

void error(char *message){
    printf("%s\n", message);
    exit(1);
}

int main(int argc, char *argv[]){
    if(argc != 3){
        error("Usage: ./smtpclient <serveraddress> <port>");
    }

    int sockfd;
    struct sockaddr_in serveraddr;
    char buffer[MAXLINE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        error("Could not create socket!");
    }

    memset(&serveraddr, 0, sizeof(serveraddr));

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(atoi(argv[2]));

    if(inet_pton(AF_INET, argv[1], &serveraddr.sin_addr) <= 0){
        error("Could not convert IP address!");
    }

    if(connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0){
        error("Could not connect to server!");
    }

    printf("Connected to %s:%s\n", argv[1], argv[2]);

    recv(sockfd, buffer, MAXLINE, 0);
    printf("%s", buffer);

    strcpy(buffer, "HELO smtpclient\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(buffer, MAXLINE);

    recv(sockfd, buffer, MAXLINE, 0);
    printf("%s", buffer);
    bzero(buffer, MAXLINE);

    strcpy(buffer, "MAIL FROM:<sender-email>\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(buffer, MAXLINE);

    recv(sockfd, buffer, MAXLINE, 0);
    printf("%s", buffer);
    bzero(buffer, MAXLINE);

    strcpy(buffer, "RCPT TO:<recipient-email>\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(buffer, MAXLINE);

    recv(sockfd, buffer, MAXLINE, 0);
    printf("%s", buffer);
    bzero(buffer, MAXLINE);

    strcpy(buffer, "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(buffer, MAXLINE);

    recv(sockfd, buffer, MAXLINE, 0);
    printf("%s", buffer);
    bzero(buffer, MAXLINE);

    //This is where the message body is written
    strcpy(buffer, "Subject: SMTP Test mail\r\n\r\nHello, this is a test email from SMTP client.\nThanks,\nSMTP Client\r\n.\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(buffer, MAXLINE);

    recv(sockfd, buffer, MAXLINE, 0);
    printf("%s", buffer);

    strcpy(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(buffer, MAXLINE);

    recv(sockfd, buffer, MAXLINE, 0);
    printf("%s", buffer);
    bzero(buffer, MAXLINE);

    close(sockfd);
    printf("\nDisconnected from server!");
    
    return 0;
}