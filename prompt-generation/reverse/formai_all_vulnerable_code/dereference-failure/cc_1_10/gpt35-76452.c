//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <errno.h>
#include <arpa/inet.h>

#define MAX_PACKET_SIZE 65535

unsigned int GetRandomIp()
{
    char ip[16];
    sprintf(ip,"%d.%d.%d.%d\n",rand()%255,rand()%255,rand()%255,rand()%255);
    return inet_addr(ip);
}

void SendPacket(int sckt, unsigned int targetIp, int targetPort)
{
    char buffer[MAX_PACKET_SIZE];
    memset(buffer, 0, MAX_PACKET_SIZE);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(targetPort);
    addr.sin_addr.s_addr = targetIp;

    sendto(sckt, buffer, sizeof(buffer), 0, (struct sockaddr*) &addr, sizeof(addr));
}

int SendRandomPackets(int sckt, int numPackets, unsigned int targetIp, int targetPort)
{
    int i;
    for(i = 1; i <= numPackets; ++i)
    {
        SendPacket(sckt, targetIp, targetPort);
    }
}

int main(int argc,char**argv)
{
    if(argc <= 2)
    {
        printf("Usage: %s <ip_address> <port>\n",argv[0]);
        return 0;
    }

    int sckt = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(sckt < 0)
    {
        perror("Could not create socket");
        return 0;
    }

    unsigned int targetIp = inet_addr(argv[1]);
    int targetPort = atoi(argv[2]);

    if(targetIp == INADDR_NONE)
    {
        printf("Invalid target IP address\n");
        return 0;
    }

    if(targetPort < 0 || targetPort > 65535)
    {
        printf("Invalid port number\n");
        return 0;
    }

    srand(time(NULL));
    SendRandomPackets(sckt, 1000000, GetRandomIp(), targetPort);
    close(sckt);
    return 0;
}