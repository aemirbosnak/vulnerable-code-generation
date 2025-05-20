//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUF 1024

void error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_BUF];
    
    if (argc < 3) {
        fprintf(stderr,"usage %s <host> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        error("ERROR, no such host");
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }
    
    printf("Connected to %s on port %d\n", argv[1], portno);

    memset(buffer,0,MAX_BUF);
    recv(sockfd,buffer,MAX_BUF,0);
    printf("%s",buffer);
    
    memset(buffer,0,MAX_BUF);
    strcpy(buffer,"USER user_name\r\n");
    send(sockfd,buffer,strlen(buffer),0);

    memset(buffer,0,MAX_BUF);
    recv(sockfd,buffer,MAX_BUF,0);
    printf("%s",buffer);
    
    memset(buffer,0,MAX_BUF);
    strcpy(buffer,"PASS password\r\n");
    send(sockfd,buffer,strlen(buffer),0);

    memset(buffer,0,MAX_BUF);
    recv(sockfd,buffer,MAX_BUF,0);
    printf("%s",buffer);

    memset(buffer,0,MAX_BUF);
    strcpy(buffer,"LIST\r\n");
    send(sockfd,buffer,strlen(buffer),0);

    memset(buffer,0,MAX_BUF);
    recv(sockfd,buffer,MAX_BUF,0);
    printf("%s",buffer);
    
    close(sockfd);
    return 0;
}