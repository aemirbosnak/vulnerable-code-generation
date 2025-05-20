//FormAI DATASET v1.0 Category: Port Scanner ; Style: accurate
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in target;
    if(argc!=2)
    {
        printf("Usage: %s <target>\n",argv[0]);
        exit(0);
    }
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0)
    {
        printf("\nSocket creation error: %s\n",strerror(errno));
        exit(0);
    }
    memset(&target,'0',sizeof(target));
    target.sin_family=AF_INET;
    target.sin_port=htons(1);
    if(inet_pton(AF_INET,argv[1],&target.sin_addr)<=0)
    {
        printf("\nInvalid Target IP Address:%s\n",argv[1]);
        exit(0);
    }
    printf("\nScanning Target:%s\n",argv[1]);
    int i;
    for(i=1;i<=65535;i++)
    {
        target.sin_port=htons(i);
        if(connect(sockfd,(struct sockaddr*)&target,sizeof(target))==0)
        {
            printf("\nPort %d - OPEN\n",i);
            close(sockfd);
            sockfd=socket(AF_INET,SOCK_STREAM,0);
            if(sockfd<0)
            {
                printf("\nSocket creation error: %s\n",strerror(errno));
                exit(0);
            }
            continue;
        }
    }
    printf("\n\nScan Complete.\n");
    return 0;
}