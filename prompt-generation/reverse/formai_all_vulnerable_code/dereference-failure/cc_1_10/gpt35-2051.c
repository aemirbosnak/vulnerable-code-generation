//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAXDATASIZE 4096

int main(int argc, char *argv[]) {
    int sockfd, numbytes;
    char buf[MAXDATASIZE];
    struct hostent *he;
    struct sockaddr_in their_addr;
    
    if (argc != 3) {
        fprintf(stderr,"usage: %s hostname port\n", argv[0]);
        exit(1);
    }
    
    if ((he=gethostbyname(argv[1])) == NULL) {
        perror("gethostbyname");
        exit(1);
    }
    
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }
    
    their_addr.sin_family = AF_INET;
    their_addr.sin_port = htons(atoi(argv[2]));
    their_addr.sin_addr = *((struct in_addr *)he->h_addr);
    memset(&(their_addr.sin_zero), '\0', 8);
    
    if (connect(sockfd, (struct sockaddr *)&their_addr, sizeof(struct sockaddr)) == -1) {
        perror("connect");
        exit(1);
    }
    
    if (recv(sockfd, buf, MAXDATASIZE-1, 0) == -1) {
        perror("recv");
        exit(1);
    }
    buf[numbytes] = '\0';
    printf("%s",buf);
    
    char *email = "From: chatbot@example.com\r\nTo: user@example.com\r\nSubject: Hello, World\r\n\r\nThis is the body of the email.";
    
    if (send(sockfd, email, strlen(email), 0) == -1) {
        perror("send");
        exit(1);
    }
    
    close(sockfd);
    
    return 0;
}