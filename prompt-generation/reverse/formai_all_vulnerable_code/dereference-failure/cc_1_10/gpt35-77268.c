//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<unistd.h>

#define BUF_SIZE 1024
#define HOST "imap.gmail.com"
#define PORT "993"
#define USER "example@gmail.com"
#define PASS "example_password"

int main(int argc, char *argv[]) {
    int sockfd, numBytes;
    char buffer[BUF_SIZE], command[BUF_SIZE], response[BUF_SIZE];
    struct addrinfo hints, *p, *servinfo;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    int status = getaddrinfo(HOST, PORT, &hints, &servinfo);
    if(status) {
        printf("Error: %s", gai_strerror(status));
        return -1;
    }
    for(p = servinfo; p != NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if(sockfd == -1) {
            printf("Error creating socket");
            continue;
        }
        if(connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            printf("Error connecting");
            continue;
        }
        break;
    }
    freeaddrinfo(servinfo);
    numBytes = recv(sockfd, buffer, BUF_SIZE, 0);
    printf("%s", buffer);
    sprintf(command, ". login %s %s\r\n", USER, PASS);
    send(sockfd, command, strlen(command), 0);
    numBytes = recv(sockfd, response, BUF_SIZE, 0);
    printf("%s", response);
    sprintf(command, ". select inbox\r\n");
    send(sockfd, command, strlen(command), 0);
    numBytes = recv(sockfd, response, BUF_SIZE, 0);
    printf("%s", response);
    sprintf(command, ". fetch 1:* full\r\n");
    send(sockfd, command, strlen(command), 0);
    numBytes = recv(sockfd, response, BUF_SIZE, 0);
    while(strstr(response, "OK") == NULL) {
        numBytes = recv(sockfd, response, BUF_SIZE, 0);
        printf("%s", response);
    }
    close(sockfd);
    return 0;
}