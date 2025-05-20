//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: satisfied
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

int main()
{
    int sock_raw;
    int tcp=0,udp=0,icmp=0,others=0,total=0;
    int i,j;

    struct sockaddr_in saddr;

    unsigned char *buffer = (unsigned char *) malloc(65536); 

    sock_raw = socket(AF_INET , SOCK_RAW , IPPROTO_TCP);

    if(sock_raw < 0)
    {
        perror("Socket Error");
        return 1;
    }

    while(1)
    {
        int saddr_length = sizeof(saddr);
        
        //Receive a packet
        ssize_t packet_size = recvfrom(sock_raw , buffer , 65536 , 0 , (struct sockaddr *)&saddr , (socklen_t*)&saddr_length);
        
        if(packet_size < 0)
        {
            perror("Recvfrom error");
            return 1;
        }

        //Get the IP header
        struct iphdr *iph = (struct iphdr*)buffer;
        ++total;

        switch (iph->protocol) 
        {
            case 1:  //ICMP Protocol 
                ++icmp;
                break;
            
            case 6:  //TCP Protocol
                ++tcp;
                break;
            
            case 17: //UDP Protocol
                ++udp;
                break;
            
            default: //Some Other Protocol like ARP etc.
                ++others;
                break;
        }
    }

    close(sock_raw);
    printf("Total packet: %d\n",total);
    printf("TCP packet: %d\n",tcp);
    printf("UDP packet: %d\n",udp);
    printf("ICMP packet: %d\n",icmp);
    printf("Others packet: %d\n",others);
    
    return 0;
}