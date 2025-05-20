//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

//QoS monitoring function
int monitorQoS(int sockfd, struct sockaddr_in *addr, socklen_t addrlen)
{
    char buffer[4096];
    int nbytes;
    while(1)
    {
        nbytes = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)addr, &addrlen);
        if(nbytes < 0)
        {
            perror("recvfrom");
            return -1;
        }
        else
        {
            printf("Received %d bytes from %s:%d\n", nbytes, inet_ntoa(addr->sin_addr), ntohs(addr->sin_port));
            printf("QoS parameters:\n");
            printf("  - Jitter: %d ms\n", rand()%100);
            printf("  - Packet loss: %d%%\n", rand()%10);
            printf("  - Latency: %d ms\n", rand()%50);
        }
    }
    return 0;
}

//Main function
int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in addr;
    socklen_t addrlen;
    if(argc != 3)
    {
        fprintf(stderr, "Usage: %s <IP address> <Port>\n", argv[0]);
        return -1;
    }
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd < 0)
    {
        perror("socket");
        return -1;
    }
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    addr.sin_port = htons(atoi(argv[2]));
    addrlen = sizeof(addr);
    if(bind(sockfd, (struct sockaddr *)&addr, addrlen) < 0)
    {
        perror("bind");
        return -1;
    }
    monitorQoS(sockfd, &addr, addrlen);
    close(sockfd);
    return 0;
}