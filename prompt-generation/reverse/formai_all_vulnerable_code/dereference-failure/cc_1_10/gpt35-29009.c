//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<string.h>

int main()
{
    char hostname[100];
    char path[100];
    int portno = 80;
    int sockfd;
    struct hostent *server;
    struct sockaddr_in serv_addr;
    char message[1000],response[2000];

    printf("Enter the hostname: ");
    fgets(hostname,100,stdin);
    printf("Enter the path: ");
    fgets(path,100,stdin);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        perror("Socket Failed");
        exit(1);
    }

    server = gethostbyname(hostname);
    if(server == NULL)
    {
        perror("Unable to resolve hostname");
        exit(1);
    }

    bzero(&serv_addr,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    bcopy(server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);

    if(connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
    {
        perror("Connection Failed");
        exit(1);
    }

    sprintf(message,"GET /%s HTTP/1.1\r\nHost: %s\r\n\r\n",path,hostname);
    if(send(sockfd,message,strlen(message),0) < 0)
    {
        perror("Send Failed");
        exit(1);
    }

    if(recv(sockfd,response,sizeof(response),0) < 0)
    {
        perror("Receive Failed");
        exit(1);
    }

    printf("Response: \n%s",response);
    close(sockfd);
    return 0;
}