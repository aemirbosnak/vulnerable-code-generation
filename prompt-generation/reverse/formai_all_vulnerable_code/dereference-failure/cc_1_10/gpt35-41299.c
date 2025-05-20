//FormAI DATASET v1.0 Category: Simple Web Server ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        error("No port provided, please provide a port as command-line argument\n");
    }
    
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[2048];
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
    {
        error("Error opening socket");
    }
    
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
         error("Error on binding");
    }
    
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
    
    printf("Server started listening on port %d\n", portno);
    
    while(1)
    {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) 
        {
            error("Error on accept");
        }
        
        bzero(buffer,2048);
        
        n = read(newsockfd,buffer,2047);
        if (n < 0) 
        {
            error("Error reading from socket");
        }
        
        printf("Received HTTP request:\n%s\n", buffer);
        
        char* response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Hello, World!</h1></body></html>";
        n = write(newsockfd, response, strlen(response));
        if (n < 0) 
        {
            error("Error writing to socket");
        }
        
        close(newsockfd);
    }
    
    close(sockfd);
    return 0;   
}