//FormAI DATASET v1.0 Category: Client Server Application ; Style: intelligent
#include <stdio.h>  
#include <stdlib.h>  
#include <sys/socket.h>  
#include <string.h>  
#include <netinet/in.h>  
#include <netdb.h>  
#include <unistd.h>  
#include <arpa/inet.h>  
#include <fcntl.h>  

#define PORT 8080  
#define MAXLEN 1024  

void error(char *msg)  
{  
    perror(msg);  
    exit(1);  
}  

int main(int argc, char *argv[])  
{  
    int sockfd, newsockfd, portno;  
    socklen_t clilen;  
    char buffer[MAXLEN];  
    struct sockaddr_in serv_addr, cli_addr;  
    int n;  
    if (argc < 2)   
    {  
        fprintf(stderr,"usage %s port\n", argv[0]);  
        exit(1);  
    }  

    sockfd = socket(AF_INET, SOCK_STREAM, 0);  
    if (sockfd < 0)  
        error("ERROR opening socket");  

    bzero((char *) &serv_addr, sizeof(serv_addr));  
    portno = atoi(argv[1]);  

    serv_addr.sin_family = AF_INET;  
    serv_addr.sin_addr.s_addr = INADDR_ANY;  
    serv_addr.sin_port = htons(portno);  

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)  
        error("ERROR on binding");  

    listen(sockfd,5);  
    clilen = sizeof(cli_addr);  

    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);  
    if (newsockfd < 0)  
        error("ERROR on accept");  

    bzero(buffer,MAXLEN);  
    n = read(newsockfd,buffer,MAXLEN);  
    if (n < 0) error("ERROR reading from socket");  
    printf("Message from client: %s\n",buffer);  

    n = write(newsockfd,"I got your message",18);  
    if (n < 0) error("ERROR writing to socket");  

    close(newsockfd);  
    close(sockfd);  
    return 0;  
}