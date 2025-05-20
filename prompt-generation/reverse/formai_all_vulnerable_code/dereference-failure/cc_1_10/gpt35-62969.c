//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_BUFFER 2048
#define SUCCESS 0
#define FAILURE -1

int pop3client(char *, char *, char *, char *);

int main()
{
    char *username = ""; //Enter your email here
    char *password = ""; //Enter your password here
    char *pop3server = ""; //Enter your POP3 server here
    char *port = "110"; //POP3 port number is 110

    int status = pop3client(username, password, pop3server, port);

    if(status == SUCCESS) {
        printf("Emails fetched successfully!");
    } else {
        printf("Failed to fetch emails");
    }

    return 0;
}

int pop3client(char *username, char *password, char *pop3server, char *port)
{
    int sockfd, bytes_received;
    char recvBuffer[MAX_BUFFER], sendBuffer[MAX_BUFFER];
    struct addrinfo hints, *servinfo, *p;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if(getaddrinfo(pop3server, port, &hints, &servinfo) != 0) {
        perror("getaddrinfo");
        return FAILURE;
    }

    for(p=servinfo; p!=NULL; p=p->ai_next) {
        if((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if(connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("connect");
            continue;
        }

        break;
    }

    if(p == NULL) {
        fprintf(stderr, "Failed to connect\n");
        return FAILURE;
    }

    freeaddrinfo(servinfo);

    //Authenticate user
    sprintf(sendBuffer, "USER %s\r\n", username);
    if(send(sockfd, sendBuffer, strlen(sendBuffer), 0) == -1) {
        perror("send");
        return FAILURE;
    }

    bytes_received = recv(sockfd, recvBuffer, MAX_BUFFER-1, 0);
    recvBuffer[bytes_received] = '\0';
    printf("%s\n", recvBuffer);

    if(strncmp(recvBuffer, "+OK", 3) == 0) {
        sprintf(sendBuffer, "PASS %s\r\n", password);
        if(send(sockfd, sendBuffer, strlen(sendBuffer), 0) == -1) {
            perror("send");
            return FAILURE;
        }

        bytes_received = recv(sockfd, recvBuffer, MAX_BUFFER-1, 0);
        recvBuffer[bytes_received] = '\0';
        printf("%s\n", recvBuffer);

        if(strncmp(recvBuffer, "+OK", 3) != 0) {
            fprintf(stderr, "Invalid password\n");
            return FAILURE;
        }
    } else {
        fprintf(stderr, "Invalid username\n");
        return FAILURE;
    }

    //Fetch emails
    sprintf(sendBuffer, "LIST\r\n");
    if(send(sockfd, sendBuffer, strlen(sendBuffer), 0) == -1) {
        perror("send");
        return FAILURE;
    }

    bytes_received = recv(sockfd, recvBuffer, MAX_BUFFER-1, 0);
    recvBuffer[bytes_received] = '\0';
    printf("%s", recvBuffer);

    if(strncmp(recvBuffer, "+OK", 3) == 0) {
        sprintf(sendBuffer, "QUIT\r\n");
        if(send(sockfd, sendBuffer, strlen(sendBuffer), 0) == -1) {
            perror("send");
            return FAILURE;
        }
    } else {
        fprintf(stderr, "Failed to fetch emails\n");
        return FAILURE;
    }

    close(sockfd);
    return SUCCESS;
}