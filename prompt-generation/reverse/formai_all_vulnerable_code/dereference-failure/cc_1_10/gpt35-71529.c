//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#define BUF_SIZE 1024

char buf[BUF_SIZE];

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    memset((char *)&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char *)&serv_addr.sin_addr.s_addr,(char *)server->h_addr,server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    n = read(sockfd,buf,BUF_SIZE-1);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n",buf);

    char login[50] = "LOGIN user@domain.com password123\n";
    n = write(sockfd, login, strlen(login));
    if (n < 0)
        error("ERROR writing to socket");

    memset(buf,0,BUF_SIZE);
    n = read(sockfd,buf,BUF_SIZE-1);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n",buf);

    char select[50] = "SELECT INBOX\n";
    n = write(sockfd, select, strlen(select));
    if (n < 0)
        error("ERROR writing to socket");

    memset(buf,0,BUF_SIZE);
    n = read(sockfd,buf,BUF_SIZE-1);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n",buf);

    char logout[50] = "LOGOUT\n";
    n = write(sockfd, logout, strlen(logout));
    if (n < 0)
        error("ERROR writing to socket");

    memset(buf,0,BUF_SIZE);
    n = read(sockfd,buf,BUF_SIZE-1);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n",buf);

    close(sockfd);
    return 0;
}