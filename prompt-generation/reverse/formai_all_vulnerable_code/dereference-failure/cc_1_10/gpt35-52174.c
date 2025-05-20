//FormAI DATASET v1.0 Category: Network Ping Test ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdbool.h>

#define PACKET_SIZE 56

unsigned short checksum(void *b, int len)
{
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;

    if (len == 1)
        sum += *(unsigned char *)buf;

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

void ping(int sockfd, struct sockaddr_in *addr, int timeout)
{
    if (sockfd <= 0)
        return;

    int packet_size = sizeof(struct icmphdr) + PACKET_SIZE;
    char packet[packet_size];
    memset(packet, 0, packet_size);

    struct icmphdr *icmp = (struct icmphdr *)packet;
    icmp->type = ICMP_ECHO;
    icmp->code = 0;
    icmp->un.echo.id = getpid();

    struct timeval tv;
    gettimeofday(&tv, NULL);

    icmp->un.echo.sequence = tv.tv_usec;
    icmp->checksum = checksum(icmp, packet_size);

    if (sendto(sockfd, packet, packet_size, 0, (struct sockaddr *)addr, sizeof(*addr)) <= 0)
    {
        printf("Unable to send packet: %s\n", strerror(errno));
        close(sockfd);
        return;
    }

    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(sockfd, &fds);

    struct timeval timeout_tv;
    timeout_tv.tv_sec = timeout / 1000;
    timeout_tv.tv_usec = (timeout % 1000) * 1000;

    if (select(sockfd + 1, &fds, NULL, NULL, &timeout_tv) <= 0)
    {
        printf("Timeout: %s\n", strerror(errno));
        close(sockfd);
        return;
    }

    char recv_packet[IP_MAXPACKET];
    struct sockaddr_in r_addr;
    socklen_t addr_len = sizeof(r_addr);

    if (recvfrom(sockfd, recv_packet, IP_MAXPACKET, 0, (struct sockaddr *)&r_addr, &addr_len) <= 0)
    {
        printf("Unable to recv packet: %s\n", strerror(errno));
        close(sockfd);
        return;
    }

    struct iphdr *ip = (struct iphdr *)recv_packet;
    int ip_header_len = ip->ihl << 2;

    struct icmphdr *recv_icmp = (struct icmphdr *)(recv_packet + ip_header_len);
    if (recv_icmp->type == ICMP_ECHOREPLY)
        printf("Received icmp_seq=%d time=%dms from %s\n", recv_icmp->un.echo.sequence, (int)(tv.tv_usec - recv_icmp->un.echo.sequence), inet_ntoa(r_addr.sin_addr));
    else
        printf("Something went wrong!\n");

    close(sockfd);
}

int main()
{
    struct hostent *host;
    struct sockaddr_in addr;

    const char *hostname = "www.google.com";

    if ((host = gethostbyname(hostname)) == NULL)
    {
        printf("Unable to resolve hostname: %s\n", strerror(errno));
        return 1;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(0);
    addr.sin_addr = *((struct in_addr *)host->h_addr);

    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd <= 0)
    {
        printf("Unable to create socket: %s\n", strerror(errno));
        return 1;
    }

    int timeout = 1000;
    ping(sockfd, &addr, timeout);

    return 0;
}