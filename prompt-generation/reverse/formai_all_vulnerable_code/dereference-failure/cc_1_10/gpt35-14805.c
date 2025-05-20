//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_SIZE 1024

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAX_SIZE];
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");

    // SMTP conversation
    memset(buffer, 0, MAX_SIZE);
    n = recv(sockfd, buffer, MAX_SIZE, 0);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n",buffer);

    char *hello = "HELO example.com\r\n";
    n = send(sockfd, hello, strlen(hello), 0);
    if (n < 0)
        error("ERROR writing to socket");

    memset(buffer, 0, MAX_SIZE);
    n = recv(sockfd, buffer, MAX_SIZE, 0);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n",buffer);

    char *mail_from = "MAIL FROM:<sender@example.com>\r\n";
    n = send(sockfd, mail_from, strlen(mail_from), 0);
    if (n < 0)
        error("ERROR writing to socket");

    memset(buffer, 0, MAX_SIZE);
    n = recv(sockfd, buffer, MAX_SIZE, 0);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n",buffer);

    char *rcpt_to = "RCPT TO:<recipient@example.com>\r\n";
    n = send(sockfd, rcpt_to, strlen(rcpt_to), 0);
    if (n < 0)
        error("ERROR writing to socket");

    memset(buffer, 0, MAX_SIZE);
    n = recv(sockfd, buffer, MAX_SIZE, 0);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n",buffer);

    char *data = "DATA\r\n";
    n = send(sockfd, data, strlen(data), 0);
    if (n < 0)
        error("ERROR writing to socket");

    memset(buffer, 0, MAX_SIZE);
    n = recv(sockfd, buffer, MAX_SIZE, 0);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n",buffer);

    char *message = "Subject: Test Message\r\nFrom: sender@example.com\r\nTo: recipient@example.com\r\n\r\nHello, this is a test message.\r\n.\r\n";
    n = send(sockfd, message, strlen(message), 0);
    if (n < 0)
        error("ERROR writing to socket");

    memset(buffer, 0, MAX_SIZE);
    n = recv(sockfd, buffer, MAX_SIZE, 0);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n",buffer);

    char *quit = "QUIT\r\n";
    n = send(sockfd, quit, strlen(quit), 0);
    if (n < 0)
        error("ERROR writing to socket");

    memset(buffer, 0, MAX_SIZE);
    n = recv(sockfd, buffer, MAX_SIZE, 0);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n",buffer);

    close(sockfd);
    return 0;
}