//FormAI DATASET v1.0 Category: Port Scanner ; Style: rigorous
#include<stdio.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<netinet/in.h>

void scan_ports(const char *,int,int);
int main(int argc,char *argv[])
{
   char *ip_addr;
   int start_port,end_port;
   if(argc!=4)
   {
       printf("Usage: %s <ip address> <start port> <last port>\n",argv[0]);
       return 1;
   }
   ip_addr=argv[1];
   start_port=atoi(argv[2]);
   end_port=atoi(argv[3]);
   printf("Scanning %s for open TCP ports between %d and %d\n",ip_addr,start_port,end_port);
   scan_ports(ip_addr,start_port,end_port);
   return 0;
}

void scan_ports(const char *ip_addr,int start_port,int end_port)
{
    int sock,i,con_status,timeout=3;
    struct sockaddr_in target_addr;
    for(i=start_port;i<=end_port;i++)
    {
        sock = socket(AF_INET, SOCK_STREAM,0);
        if(sock<0)
        {
            printf("Error creating socket: %s\n",strerror(errno));
            return;
        }
        target_addr.sin_family = AF_INET;
        target_addr.sin_port=htons(i);
        target_addr.sin_addr.s_addr=inet_addr(ip_addr);
        memset(&(target_addr.sin_zero), '\0', 8);
        con_status=connect(sock,(struct sockaddr *)&target_addr,sizeof(struct sockaddr));
        if(con_status==0)
        {
            printf("Port %d is OPEN\n",i);
        }
        else if(errno==ECONNREFUSED)
        {
            printf("Port %d is CLOSED\n",i);
        }
        close(sock);
    }
}