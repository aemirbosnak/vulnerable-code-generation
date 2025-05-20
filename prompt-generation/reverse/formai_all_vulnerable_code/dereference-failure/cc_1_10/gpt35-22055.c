//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define MAXDATASIZE 100

int main(int argc, char *argv[])
{
    int sockfd, numbytes;
    char buf[MAXDATASIZE];
    struct hostent *he;
    struct sockaddr_in their_addr; 
    int port;
    
    if (argc != 3) {
        fprintf(stderr,"Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }
    
    if ((he=gethostbyname(argv[1])) == NULL) {  
        herror("gethostbyname");
        exit(1);
    }
    
    if ((port=atoi(argv[2])) == 0) {
        fprintf(stderr,"Invalid port number: %s\n",argv[2]);
        exit(1);
    }
    
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }
    
    their_addr.sin_family = AF_INET;    
    their_addr.sin_port = htons(port);  
    their_addr.sin_addr = *((struct in_addr *)he->h_addr);
    memset(&(their_addr.sin_zero), '\0', 8);  
    
    if (connect(sockfd, (struct sockaddr *)&their_addr, sizeof(struct sockaddr)) == -1) {
        perror("connect");
        exit(1);
    }
    
    printf("Connected to %s on port %d\n", inet_ntoa(their_addr.sin_addr), ntohs(their_addr.sin_port));
    
    while(1) {
        printf("Enter a command: ");
        fgets(buf,MAXDATASIZE,stdin);
        numbytes = strlen(buf);
        
        if (send(sockfd, buf, numbytes, 0) == -1) {
            perror("send");
            exit(1);
        }
        
        if ((numbytes=recv(sockfd, buf, MAXDATASIZE-1, 0)) == -1) {
            perror("recv");
            exit(1);
        }
        
        buf[numbytes] = '\0';
        printf("%s",buf);
    }
    
    close(sockfd);
    
    return 0;
}