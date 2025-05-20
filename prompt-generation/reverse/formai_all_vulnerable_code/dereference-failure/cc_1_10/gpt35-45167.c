//FormAI DATASET v1.0 Category: Network Ping Test ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PACKET_SIZE 64
#define RECV_TIMEOUT 2
#define MAX_TTL 64
#define MAX_RETRIES 3

// This function calculates the checksum of the packet
unsigned short calcChecksum(unsigned short *buf, int nwords)
{
    unsigned long sum = 0;
    while (nwords > 1)
    {
        sum += *buf++;
        nwords -= 2;
    }
    if (nwords == 1)
    {
        sum += *(unsigned char *)buf;
    }
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    return (unsigned short)(~sum);
}

// This function sends the ping packet
int sendPing(int sockfd, struct sockaddr_in *dest_addr, int seq_no)
{
    char packet[PACKET_SIZE];
    memset(packet, 0, sizeof(packet));
    struct icmp *icmp_hdr = (struct icmp *)packet;
    icmp_hdr->icmp_type = ICMP_ECHO;
    icmp_hdr->icmp_code = 0;
    icmp_hdr->icmp_id = getpid();
    icmp_hdr->icmp_seq = seq_no;
    memset(&icmp_hdr->icmp_data, (int)'@', sizeof(icmp_hdr->icmp_data));
    icmp_hdr->icmp_cksum = calcChecksum((unsigned short *)icmp_hdr, sizeof(packet));
    if (sendto(sockfd, packet, sizeof(packet), 0, (struct sockaddr *)dest_addr, sizeof(*dest_addr)) < 0)
    {
        perror("sendto error");
        return -1;
    }
    return 0;
}

// This function receives the ping response
int recvPing(int sockfd, struct sockaddr_in *src_addr, int *seq_no)
{
    char packet[PACKET_SIZE];
    socklen_t addrlen = sizeof(*src_addr);
    struct iphdr *ip_hdr;
    struct icmp *icmp_hdr;
    int len;
    struct timeval timeout;
    timeout.tv_sec = RECV_TIMEOUT;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
    if ((len = recvfrom(sockfd, packet, sizeof(packet), 0, (struct sockaddr *)src_addr, &addrlen)) < 0)
    {
        if(errno==EAGAIN || errno==EWOULDBLOCK){
            printf("Request timed out\n");
        }
        return -1;
    }
    ip_hdr = (struct iphdr *)packet;
    icmp_hdr = (struct icmp *)(packet + (ip_hdr->ihl * 4));
    if (icmp_hdr->icmp_type == ICMP_ECHOREPLY && icmp_hdr->icmp_id == getpid() && icmp_hdr->icmp_seq == *seq_no)
    {
        return 0;
    }
    return -1;
}

// This function performs the ping test for a given destination
int pingHost(struct sockaddr_in *dest_addr, int ttl, int nretries)
{
    int sockfd, seq_no = 0, result, retry;
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0)
    {
        perror("socket error");
        return -1;
    }
    setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl));
    for(retry=0;retry<nretries;retry++){
        if (sendPing(sockfd, dest_addr, seq_no) < 0)
        {
            close(sockfd);
            return -1;
        }
        if (recvPing(sockfd, dest_addr, &seq_no) == 0)
        {
            close(sockfd);
            return 0;
        }
    }
    close(sockfd);
    return -1;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <destination IP>\n", argv[0]);
        exit(1);
    }
    struct addrinfo hints, *res, *p;
    struct sockaddr_in *addr;
    char ipstr[INET_ADDRSTRLEN];
    int result, ttl;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    if ((result = getaddrinfo(argv[1], NULL, &hints, &res)) != 0)
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(result));
        exit(1);
    }
    for (p = res; p != NULL; p = p->ai_next)
    {
        addr = (struct sockaddr_in *)p->ai_addr;
        if (pingHost(addr, 1, 1) == 0)
        {
            ttl = 1;
            while (ttl <= MAX_TTL)
            {
                printf("%d. ", ttl);
                inet_ntop(AF_INET, &(addr->sin_addr), ipstr, INET_ADDRSTRLEN);
                printf("%s ", ipstr);
                if (pingHost(addr, ttl, MAX_RETRIES) == 0)
                {
                    printf("OK\n");
                    break;
                }
                else
                {
                    printf("NO RESPONSE\n");
                }
                ttl++;
            }
            freeaddrinfo(res);
            return 0;
        }
    }
    printf("Could not connect to host\n");
    freeaddrinfo(res);
    return -1;
}