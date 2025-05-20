//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 25
#define MAXDATASIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, numbytes;
    char buf[MAXDATASIZE];
    struct hostent *he;
    struct sockaddr_in their_addr;
    
    if(argc != 2) {
        fprintf(stderr, "usage: smtp_client hostname\n");
        exit(1);
    }
    
    if((he=gethostbyname(argv[1])) == NULL) {
        fprintf(stderr, "gethostbyname error\n");
        exit(1);
    }
    
    if((sockfd=socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        fprintf(stderr, "socket error\n");
        exit(1);
    }
    
    their_addr.sin_family = AF_INET;
    their_addr.sin_port = htons(PORT);
    their_addr.sin_addr = *((struct in_addr *)he->h_addr);
    memset(their_addr.sin_zero, '\0', sizeof their_addr.sin_zero);
    
    if(connect(sockfd, (struct sockaddr *)&their_addr, sizeof their_addr) == -1) {
        fprintf(stderr, "connect error\n");
        exit(1);
    }
    
    printf("220 Welcome to my SMTP server.\n");
    printf("HELO smtpclient.local\n");
    send(sockfd, "HELO smtpclient.local\r\n", strlen("HELO smtpclient.local\r\n"), 0);
    numbytes = recv(sockfd, buf, MAXDATASIZE-1, 0);
    buf[numbytes] = '\0';
    printf("%s", buf);
    
    printf("MAIL FROM:<sender@example.com>\n");
    send(sockfd, "MAIL FROM:<sender@example.com>\r\n", strlen("MAIL FROM:<sender@example.com>\r\n"), 0);
    numbytes = recv(sockfd, buf, MAXDATASIZE-1, 0);
    buf[numbytes] = '\0';
    printf("%s", buf);
    
    printf("RCPT TO:<recipient@example.com>\n");
    send(sockfd, "RCPT TO:<recipient@example.com>\r\n", strlen("RCPT TO:<recipient@example.com>\r\n"), 0);
    numbytes = recv(sockfd, buf, MAXDATASIZE-1, 0);
    buf[numbytes] = '\0';
    printf("%s", buf);
    
    printf("DATA\n");
    send(sockfd, "DATA\r\n", strlen("DATA\r\n"), 0);
    numbytes = recv(sockfd, buf, MAXDATASIZE-1, 0);
    buf[numbytes] = '\0';
    printf("%s", buf);
    
    printf("From: Sender <sender@example.com>\n");
    printf("To: Recipient <recipient@example.com>\n");
    printf("Subject: Hello World!\n\n");
    printf("Hello, World!\n");
    printf(".\n");
    send(sockfd, "From: Sender <sender@example.com>\r\n", strlen("From: Sender <sender@example.com>\r\n"), 0);
    send(sockfd, "To: Recipient <recipient@example.com>\r\n", strlen("To: Recipient <recipient@example.com>\r\n"), 0);
    send(sockfd, "Subject: Hello World!\r\n\r\n", strlen("Subject: Hello World!\r\n\r\n"), 0);
    send(sockfd, "Hello, World!\r\n.\r\n", strlen("Hello, World!\r\n.\r\n"), 0);
    numbytes = recv(sockfd, buf, MAXDATASIZE-1, 0);
    buf[numbytes] = '\0';
    printf("%s", buf);
    
    printf("QUIT\n");
    send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0);
    numbytes = recv(sockfd, buf, MAXDATASIZE-1, 0);
    buf[numbytes] = '\0';
    printf("%s", buf);
    
    close(sockfd);
    return 0;
}