//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: mathematical
#include<stdio.h>
#include<string.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<netdb.h>
#include<unistd.h>
#include<stdlib.h>

#define PORT 110
#define MAXDATASIZE 1024

int main(int argc, char *argv[])
{
    int sockfd, numbytes;
    char buf[MAXDATASIZE];
    struct hostent *he;
    struct sockaddr_in their_addr;

    if(argc != 3) {
        fprintf(stderr, "usage: pop3client hostname username\n");
        exit(1);
    }

    if((he = gethostbyname(argv[1])) == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    their_addr.sin_family = AF_INET;
    their_addr.sin_port = htons(PORT);
    their_addr.sin_addr = *((struct in_addr *)he->h_addr);
    bzero(&(their_addr.sin_zero),8);

    if(connect(sockfd, (struct sockaddr *)&their_addr, sizeof(struct sockaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    numbytes = recv(sockfd, buf, MAXDATASIZE-1, 0);
    buf[numbytes] = '\0';

    printf("%s", buf);
    printf("Mathematical style POP3 client example program started:\n");

    char usermessage[80];
    sprintf(usermessage, "USER %s\r\n", argv[2]);
    send(sockfd, usermessage, strlen(usermessage), 0);
    numbytes = recv(sockfd, buf, MAXDATASIZE-1, 0);
    buf[numbytes] = '\0';
    printf("%s", buf);

    char passmessage[80];
    printf("Enter your password:\n");
    scanf("%s", usermessage);
    sprintf(passmessage, "PASS %s\r\n", usermessage);
    send(sockfd, passmessage, strlen(passmessage), 0);
    numbytes = recv(sockfd, buf, MAXDATASIZE-1, 0);
    buf[numbytes] = '\0';
    printf("%s", buf);

    send(sockfd, "STAT\r\n", 6, 0);
    numbytes = recv(sockfd, buf, MAXDATASIZE-1, 0);
    buf[numbytes] = '\0';
    printf("%s", buf);

    int mailcount;
    sscanf(buf, "+OK %d ", &mailcount);
    printf("You have %d mails.\n", mailcount);

    for(int i = 1; i <= mailcount; i++) {
        sprintf(usermessage, "RETR %d\r\n", i);
        send(sockfd, usermessage, strlen(usermessage), 0);
        numbytes = recv(sockfd, buf, MAXDATASIZE-1, 0);
        buf[numbytes] = '\0';
        printf("Mail %d:\n%s\n", i, buf);
    }

    send(sockfd, "QUIT\r\n", 6, 0);
    numbytes = recv(sockfd, buf, MAXDATASIZE-1, 0);
    buf[numbytes] = '\0';
    printf("%s", buf);

    close(sockfd);
    return 0;
}