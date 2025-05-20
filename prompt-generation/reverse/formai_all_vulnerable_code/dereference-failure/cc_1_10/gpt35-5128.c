//FormAI DATASET v1.0 Category: Network Ping Test ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <errno.h>

#define PACKET_SIZE 4096
#define PING_TIMEOUT 5000 // milliseconds

unsigned short calc_checksum(unsigned short *buf, int len);
int ping(struct sockaddr_in *pingaddr, int pingsock, char *pingpacket, int packet_size);
void print_usage();
int main(int argc, char *argv[]);

// This function calculates the checksum of the packet
unsigned short calc_checksum(unsigned short* buf, int len)
{
    unsigned long sum = 0;
    while (len > 1)
    {
        sum += *buf++;
        len -= 2;
    }
    if (len == 1)
    {
        sum += *(unsigned char*)buf;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    return (unsigned short)(~sum);
}

// This function sends an ICMP packet and waits for a response
int ping(struct sockaddr_in *pingaddr, int pingsock, char *pingpacket, int packet_size)
{
    struct timeval timeout;
    timeout.tv_sec = PING_TIMEOUT / 1000;
    timeout.tv_usec = (PING_TIMEOUT % 1000) * 1000;
    if (setsockopt(pingsock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout)) < 0)
    {
        perror("setsockopt failed");
        return -1;
    }
    int send_result = sendto(pingsock, pingpacket, packet_size, 0, (struct sockaddr*)pingaddr, sizeof(struct sockaddr_in));
    if (send_result < 0)
    {
        perror("sendto failed");
        return -1;
    }
    else if (send_result != packet_size)
    {
        printf("sendto failed: sent %d bytes instead of %d\n", send_result, packet_size);
        return -1;
    }
    char recvpacket[PACKET_SIZE];
    memset(recvpacket, 0, PACKET_SIZE);
    int recv_result = recvfrom(pingsock, recvpacket, PACKET_SIZE, 0, NULL, NULL);
    if (recv_result < 0)
    {
        if (errno == EAGAIN || errno == EWOULDBLOCK)
        {
            printf("Request timed out.\n");
            return 1;
        }
        else
        {
            perror("recvfrom failed");
            return -1;
        }
    }
    struct iphdr *ip_header = (struct iphdr*)recvpacket;
    if (ip_header->protocol != IPPROTO_ICMP)
    {
        printf("Received non-ICMP packet.\n");
        return -1;
    }
    struct icmphdr *icmp_header = (struct icmphdr*)(recvpacket + (ip_header->ihl << 2));
    if (icmp_header->type == ICMP_ECHOREPLY)
    {
        printf("Reply from %s: bytes=%d time=%dms\n", inet_ntoa(pingaddr->sin_addr), recv_result - (ip_header->ihl << 2) - ICMP_MINLEN, (int)(timeout.tv_sec * 1000 + timeout.tv_usec / 1000));
    }
    else if (icmp_header->type == ICMP_DEST_UNREACH)
    {
        printf("Destination unreachable.\n");
        return -1;
    }
    else
    {
        printf("Received ICMP packet type %d\n", icmp_header->type);
        return -1;
    }
    return 0;
}

// This function prints usage information
void print_usage()
{
    printf("Usage: ./ping [hostname or IP address]\n");
}

// This is the main function
int main(int argc, char *argv[])
{
    // Check if the user provided a hostname or IP address
    if (argc != 2)
    {
        print_usage();
        return 1;
    }
    // Create a socket
    int pingsock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (pingsock < 0)
    {
        perror("socket failed");
        return 1;
    }
    // Resolve the hostname or IP address
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL)
    {
        printf("Failed to resolve hostname or IP address.\n");
        return 1;
    }
    char *ip_address = inet_ntoa(*(struct in_addr*)host->h_addr_list[0]);
    printf("Pinging %s (%s):\n", argv[1], ip_address);
    // Prepare the ICMP packet
    char pingpacket[PACKET_SIZE];
    memset(pingpacket, 0, PACKET_SIZE);
    struct icmphdr *icmp_header = (struct icmphdr*)pingpacket;
    icmp_header->type = ICMP_ECHO;
    icmp_header->code = 0;
    icmp_header->checksum = 0;
    icmp_header->un.echo.id = getpid() & 0xFFFF;
    icmp_header->un.echo.sequence = 0;
    char *data = pingpacket + sizeof(struct icmphdr);
    strncpy(data, "hello", 5);
    int packet_size = sizeof(struct icmphdr) + 5;
    icmp_header->checksum = calc_checksum((unsigned short*)pingpacket, packet_size);
    // Ping the remote host 5 times
    struct sockaddr_in pingaddr;
    memset(&pingaddr, 0, sizeof(struct sockaddr_in));
    pingaddr.sin_family = AF_INET;
    pingaddr.sin_port = 0;
    pingaddr.sin_addr.s_addr = inet_addr(ip_address);
    int i;
    for (i = 0; i < 5; i++)
    {
        if (ping(&pingaddr, pingsock, pingpacket, packet_size) < 0)
        {
            printf("Ping failed.\n");
            return 1;
        }
        sleep(1);
    }
    close(pingsock);
    return 0;
}