//FormAI DATASET v1.0 Category: Network Ping Test ; Style: immersive
/****************************************************
 * Program: Network Ping Test
 * Author: My Chatbot
 * Date: 17th April, 2021
 * Description: This program is designed to test the connectivity and response time of a network by pinging an IP address using ICMP.
 ***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <time.h>

#define PACKET_SIZE 64

/* Function to calculate checksum of ICMP packet */
unsigned short calc_checksum(unsigned short *buf, int len)
{
    unsigned long sum = 0;
    while(len > 1)
    {
        sum += *buf++;
        len -= 2;
    }
    if(len == 1)
    {
        sum += *(unsigned char*)buf;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    return (unsigned short)(~sum);
}

/* Function to perform ping request */
bool do_ping(int sock, struct sockaddr *server_addr, int seq_no)
{
    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;

    char packet[PACKET_SIZE];

    struct icmphdr *icmp_hdr = (struct icmphdr*)packet;
    icmp_hdr->type = ICMP_ECHO;
    icmp_hdr->code = 0;
    icmp_hdr->checksum = 0;
    icmp_hdr->un.echo.id = getpid();
    icmp_hdr->un.echo.sequence = seq_no;
    for(int i=0; i<PACKET_SIZE-8; i++)
    {
        packet[8+i] = i+'0';
    }
    icmp_hdr->checksum = calc_checksum((unsigned short*)icmp_hdr, PACKET_SIZE);

    if(setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) != 0)
    {
        return false;
    }

    if(sendto(sock, packet, PACKET_SIZE, 0, server_addr, sizeof(struct sockaddr)) == -1)
    {
        return false;
    }

    char buffer[PACKET_SIZE+sizeof(struct iphdr)];
    memset(buffer, 0, sizeof(buffer));

    socklen_t len = sizeof(struct sockaddr);
    struct sockaddr_in *recv_addr = (struct sockaddr_in*)&buffer;
    struct iphdr *ip_hdr = (struct iphdr*)buffer;
    struct icmphdr *recv_icmp = (struct icmphdr*)(buffer + sizeof(struct iphdr));

    if(recvfrom(sock, buffer, PACKET_SIZE+sizeof(struct iphdr), 0, server_addr, &len) <= 0)
    {
        return false;
    }

    if(ip_hdr->daddr != recv_addr->sin_addr.s_addr || recv_icmp->un.echo.id != getpid() || recv_icmp->type != ICMP_ECHOREPLY)
    {
        return false;
    }

    return true;
}

/* Main function */
int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./ping <ip-address>\n");
        exit(EXIT_FAILURE);
    }

    const char* ip_addr_str = argv[1];

    struct addrinfo* result;
    struct addrinfo hints = {0};
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_RAW;
    hints.ai_protocol = IPPROTO_ICMP;
    int ret_val = getaddrinfo(ip_addr_str, NULL, &hints, &result);
    if(ret_val != 0)
    {
        printf("Error: Invalid IP Address!\n");
        exit(EXIT_FAILURE);
    }

    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if(sock < 0)
    {
        printf("Error: Could not create socket!\n");
        exit(EXIT_FAILURE);
    }

    int seq_no = 1;
    int success_count = 0, failure_count = 0;

    printf("Pinging %s with 64 bytes of data:\n", ip_addr_str);

    while(seq_no <= 10)
    {
        bool ret = do_ping(sock, result->ai_addr, seq_no);
        if(ret == true)
        {
            success_count++;
            printf("Reply from %s: bytes=%d time=%ldms\n", ip_addr_str, PACKET_SIZE, (long)(clock()*1000/CLOCKS_PER_SEC));
        }
        else
        {
            failure_count++;
            printf("Request timed out.\n");
        }
        seq_no++;
        sleep(1);
    }

    printf("\nPing statistics:\n    Packets: Sent = 10, Received = %d, Lost = %d (%d%% loss),\n", success_count, failure_count, (failure_count*10));
    printf("Approximate round trip times in milli-seconds:\n    Minimum = %dms, Maximum = %dms, Average = %.2fms\n", 
           (int)(clock()*1000/CLOCKS_PER_SEC), (int)(clock()*1000/CLOCKS_PER_SEC), (float)(clock()*1000/CLOCKS_PER_SEC)/10);

    close(sock);
    freeaddrinfo(result);
    return 0;
}