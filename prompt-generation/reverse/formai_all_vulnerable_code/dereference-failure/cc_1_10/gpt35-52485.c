//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAXLINE 1024 //Maximum size of buffer
#define PORT 25 //Port number of SMTP server

void error(char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, n, flag = 1;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAXLINE];
    char rcv_buffer[MAXLINE];
    char *domain_name;
    
    if (argc < 2) {
        printf("Usage: %s <domain name>\n", argv[0]);
        exit(0);
    }
    domain_name = argv[1];
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");
    
    server = gethostbyname(domain_name);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server -> h_addr, (char *) &serv_addr.sin_addr.s_addr, server -> h_length);
    serv_addr.sin_port = htons(PORT);
    
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");
    
    recv(sockfd, rcv_buffer, sizeof(rcv_buffer), 0); //Receiving 220 message from SMTP server
    
    printf("%s\n", rcv_buffer);
    bzero(rcv_buffer, MAXLINE);
    
    char *helo_msg = "HELO smtp.example.com\r\n";
    n = write(sockfd, helo_msg, strlen(helo_msg));
    if (n < 0)
        error("ERROR writing to socket");
    
    recv(sockfd, rcv_buffer, sizeof(rcv_buffer), 0); //Receiving 250 message from SMTP server
    
    printf("%s\n", rcv_buffer);
    bzero(rcv_buffer, MAXLINE);
    
    char *mailfrom_msg = "MAIL FROM: <sender@example.com>\r\n";
    n = write(sockfd, mailfrom_msg, strlen(mailfrom_msg));
    if (n < 0)
        error("ERROR writing to socket");
    
    recv(sockfd, rcv_buffer, sizeof(rcv_buffer), 0); //Receiving 250 message from SMTP server
    
    printf("%s\n", rcv_buffer);
    bzero(rcv_buffer, MAXLINE);
    
    char *rcptto_msg = "RCPT TO: <receiver@example.com>\r\n";
    n = write(sockfd, rcptto_msg, strlen(rcptto_msg));
    if (n < 0)
        error("ERROR writing to socket");
    
    recv(sockfd, rcv_buffer, sizeof(rcv_buffer), 0); //Receiving 250 message from SMTP server
    
    printf("%s\n", rcv_buffer);
    bzero(rcv_buffer, MAXLINE);
    
    char *data_msg = "DATA\r\n";
    n = write(sockfd, data_msg, strlen(data_msg));
    if (n < 0)
        error("ERROR writing to socket");
    
    recv(sockfd, rcv_buffer, sizeof(rcv_buffer), 0); //Receiving 354 message from SMTP server
    
    printf("%s\n", rcv_buffer);
    bzero(rcv_buffer, MAXLINE);
    
    char *msg = "From: sender@example.com\nTo: receiver@example.com\nSubject: SMTP Client\n\nThis is a test message from SMTP Client\n.\r\n";
    n = write(sockfd, msg, strlen(msg));
    if (n < 0)
        error("ERROR writing to socket");
    
    recv(sockfd, rcv_buffer, sizeof(rcv_buffer), 0); //Receiving 250 message from SMTP server
    
    printf("%s\n", rcv_buffer);
    bzero(rcv_buffer, MAXLINE);
    
    char *quit_msg = "QUIT\r\n";
    n = write(sockfd, quit_msg, strlen(quit_msg));
    if (n < 0)
        error("ERROR writing to socket");
    
    recv(sockfd, rcv_buffer, sizeof(rcv_buffer), 0); //Receiving 221 message from SMTP server
    
    printf("%s\n", rcv_buffer);
    bzero(rcv_buffer, MAXLINE);
    
    close(sockfd);
    
    return 0;
}