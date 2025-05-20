//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: genious
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>

#define MAXSIZE 1024

void error(char *msg){
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]){
    int sockfd, portno, n;
    struct sockaddr_in serveraddr;
    char buffer[MAXSIZE];
    char message[MAXSIZE];
    char username[MAXSIZE];
    char password[MAXSIZE];
    char sender[MAXSIZE];
    char receiver[MAXSIZE];
    char subject[MAXSIZE];
    char email[MAXSIZE];

    if (argc != 3){
       fprintf(stderr,"usage: %s <hostname> <port>\n", argv[0]);
       exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0){
        error("ERROR opening socket");
    }

    bzero(&serveraddr, sizeof(serveraddr));
    portno = atoi(argv[2]);
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(portno);
    serveraddr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd,(struct sockaddr *)&serveraddr,sizeof(serveraddr)) < 0){
        error("ERROR: Connection failed!");
    }
    else{
        printf("\n Connection established!");
    }

    // authenticate
    printf("\n Enter your email address:");
    fgets(username, MAXSIZE, stdin);
    printf("\n Enter your password:");
    fgets(password, MAXSIZE, stdin);

    sprintf(message, "AUTH LOGIN\r\n");
    send(sockfd, message, strlen(message), 0);

    recv(sockfd, buffer, MAXSIZE, 0);
    if (buffer[0] != '3'){
        printf("\n Error: AUTH LOGIN command not accepted");
        exit(1);
    }

    sprintf(message, "%s\r\n", username);
    send(sockfd, message, strlen(message), 0);

    recv(sockfd, buffer, MAXSIZE, 0);
    if (buffer[0] != '3'){
        printf("\n Error: Username not accepted");
        exit(1);
    }

    sprintf(message, "%s\r\n", password);
    send(sockfd, message, strlen(message), 0);

    recv(sockfd, buffer, MAXSIZE, 0);
    if (buffer[0] != '2'){
        printf("\n Error: Password not accepted");
        exit(1);
    }
    else{
        printf("\n Authentication successful!");
    }

    // send email
    printf("\n Enter email address of Sender:");
    fgets(sender, MAXSIZE, stdin);
    printf("\n Enter email address of Recipient:");
    fgets(receiver, MAXSIZE, stdin);
    printf("\n Enter email Subject:");
    fgets(subject, MAXSIZE, stdin);
    printf("\n Enter email Body:");
    fgets(email, MAXSIZE, stdin);

    sprintf(message, "MAIL FROM:<%s>\r\n", sender);
    send(sockfd, message, strlen(message), 0);

    sprintf(message, "RCPT TO:<%s>\r\n", receiver);
    send(sockfd, message, strlen(message), 0);

    sprintf(message, "DATA\r\n");
    send(sockfd, message, strlen(message), 0);

    sprintf(message, "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n.\r\n", sender, receiver, subject, email);
    send(sockfd, message, strlen(message), 0);

    sprintf(message, "QUIT\r\n");
    send(sockfd, message, strlen(message), 0);

    recv(sockfd, buffer, MAXSIZE, 0);
    if (buffer[0] != '2'){
        printf("\n Error: Could not quit gracefully");
        exit(1);
    }
    else{
        printf("\n Email sent successfully!");
    }

    close(sockfd);
    return 0;
}