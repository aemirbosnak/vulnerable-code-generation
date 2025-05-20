//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netdb.h>

#define MAX 1024

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    if(argc<3)
    {
        fprintf(stderr,"Usage: %s hostname port\n", argv[0]);
        exit(1);
    }
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX];

    sockfd=socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd<0)
    {
        error("Error opening socket");
    }

    server=gethostbyname(argv[1]);
    if(server==NULL)
    {
        fprintf(stderr,"Error, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if(connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
    {
        error("Error connecting");
    }

    printf("\nEnter command:\n");

    fgets(buffer,MAX,stdin);
    n = write(sockfd,buffer,strlen(buffer));
    if (n < 0)
    {
         error("Error writing to socket");
    }

    bzero(buffer,MAX);
    n = read(sockfd,buffer,MAX);
    if (n < 0)
    {
         error("Error reading from socket");
    }

    printf("\nOutput: %s\n",buffer);
    close(sockfd);
    return 0;
}