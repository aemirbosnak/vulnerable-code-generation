//FormAI DATASET v1.0 Category: Network Ping Test ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PACKETSIZE  64

/* Function to calculate checksum */
unsigned short checkSum(unsigned short *buf, int nwords)
{
    unsigned long sum;

    for (sum = 0; nwords > 0; nwords--)
        sum += *buf++;
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    return ~sum;
}

/* Function to send ICMP Echo Request */
void sendPing(int sockfd, struct sockaddr_in *addr)
{
    int i, packSize, sentPacketCount = 0;
    char packet[PACKETSIZE], peerAddr[20];
    struct icmp *icmp;
    struct timeval *tval;

    packSize = sizeof(struct icmp) + PACKETSIZE;
    icmp = (struct icmp*) packet;

    icmp->icmp_type = ICMP_ECHO;
    icmp->icmp_code = 0;
    icmp->icmp_id = getpid() & 0xFFFF;
    icmp->icmp_seq = 0;
    tval = (struct timeval*) icmp->icmp_data;
    gettimeofday(tval, NULL);
    icmp->icmp_cksum = checkSum((unsigned short*) icmp, packSize/2);

    inet_ntop(AF_INET, &(addr->sin_addr), peerAddr, 20);

    /* Send Ping */
    if (sendto(sockfd, packet, packSize, 0, (struct sockaddr*) addr, sizeof(*addr)) == -1)
    {
        perror("Error sending ping");
    }
    else
    {
        printf("PING %s (%s) %d bytes of data\n", peerAddr, peerAddr, PACKETSIZE);
        sentPacketCount++;
    }
}

/* Function to receive ICMP Echo Reply */
void receivePing(int sockfd, struct sockaddr_in *addr)
{
    int i, packSize, count;
    char packet[PACKETSIZE];
    struct iphdr *ip;
    struct icmp *icmp;
    struct timeval *tvalRecv, tvalSend;
    socklen_t sockLen;

    count = recvfrom(sockfd, packet, PACKETSIZE, 0, (struct sockaddr*) addr, &sockLen);
    if (count == -1 || count == 0)
    {
        perror("PING Error: ");
        return;
    }

    ip = (struct iphdr*) packet;
    icmp = (struct icmp*) (packet + sizeof(struct iphdr));
    packSize = count - sizeof(struct iphdr);

    if (icmp->icmp_type == ICMP_ECHOREPLY)
    {
        tvalRecv = (struct timeval*) icmp->icmp_data;
        gettimeofday(&tvalSend, NULL);

        printf("%d bytes from %s: icmp_seq=%d ttl=%d time=%.2f ms\n", packSize, inet_ntoa(addr->sin_addr), icmp->icmp_seq, ip->ttl, (double)(tvalSend.tv_usec - tvalRecv->tv_usec)/1000 + (double)(tvalSend.tv_sec - tvalRecv->tv_sec)*1000);
    }
}

int main(int argc, char **argv)
{
    struct hostent *host;
    struct sockaddr_in addr;
    int sockfd, packetCount = 0;

    if (argc != 2)
    {
        printf("Please provide a valid hostname or IP address to ping\n");
        exit(0);
    }

    /* Create a raw socket */
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0)
    {
        perror("Failed to create socket");
        exit(1);
    }

    /* Resolve hostname to IP address */
    host = gethostbyname(argv[1]);
    if (host == NULL)
    {
        perror("Failed to resolve hostname");
        exit(1);
    }

    /* Set socket address */
    memset(&addr, 0, sizeof(struct sockaddr_in));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = *((unsigned long*) host->h_addr_list[0]);

    /* Send and receive Ping */
    sendPing(sockfd, &addr);
    receivePing(sockfd, &addr);

    /* Close socket */
    close(sockfd);

    return 0;
}