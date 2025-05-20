//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<errno.h>
#include<netdb.h>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/wait.h>

#define MAX_BUFFER_SIZE 1024

int sockfd = -1;

void signal_handler(int signum)
{
    if(signum == SIGINT)
    {
        printf("Signal Interrupt detected!\n");
        if(sockfd != -1)
        {
            close(sockfd);
        }
        exit(1);
    }
}

int main(int argc, char** argv) 
{
    if(argc != 2)
    {
        printf("Usage: ./wifi_analyzer <IP>\n");
        exit(-1);
    }

    int status,sockfd;
    char buffer[MAX_BUFFER_SIZE];
    struct addrinfo hints;
    struct addrinfo *servinfo;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if((status = getaddrinfo(argv[1], "80", &hints, &servinfo)) != 0)
    {
        printf("Error: %s\n",gai_strerror(status));
        exit(-1);
    }

    sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);

    if(sockfd == -1)
    {
        printf("Error in socket(): %s\n",strerror(errno));
        exit(-1);
    }

    signal(SIGINT,signal_handler);

    if(connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen) == -1)
    {
        printf("Error in connect(): %s\n",strerror(errno));
        close(sockfd);
        exit(-1);
    }

    memset(&buffer,0,sizeof(buffer));

    sprintf(buffer,"GET / HTTP/1.1\r\nHOST: %s\r\n\r\n",argv[1]);

    status = send(sockfd,buffer,strlen(buffer),0);

    if(status == -1)
    {
        printf("Error in send(): %s\n",strerror(errno));
        close(sockfd);
        exit(-1);
    }

    while(recv(sockfd,buffer,MAX_BUFFER_SIZE-1,0) > 0)
    {
        printf("%s\n",buffer);
        memset(&buffer,0,sizeof(buffer));
    }

    close(sockfd);

    return 0;
}