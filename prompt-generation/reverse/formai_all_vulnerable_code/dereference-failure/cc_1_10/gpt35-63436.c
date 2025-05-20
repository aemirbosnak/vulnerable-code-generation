//FormAI DATASET v1.0 Category: Network Ping Test ; Style: interoperable
// Interoperable C Network Ping Test Example Program
// Minimum 50 lines

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PACKET_SIZE 64

// Function to calculate checksum
unsigned short calculateChecksum(unsigned short *buffer, int length)
{
    unsigned long sum = 0;
    while (length > 1)
    {
        sum += *buffer++;
        length -= 2;
    }
    if (length == 1)
    {
        sum += *(unsigned char *)buffer;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    return (unsigned short)(~sum);
}

// Function to send ICMP echo request
int sendICMPEchoRequest(int sockfd, struct sockaddr *destAddr, int seqNo)
{
    char sendBuffer[PACKET_SIZE] = {0};
    struct icmp *icmpPacket = (struct icmp *)sendBuffer;
    icmpPacket->icmp_type = ICMP_ECHO;
    icmpPacket->icmp_code = 0;
    icmpPacket->icmp_id = getpid();
    icmpPacket->icmp_seq = seqNo;
    for (int i = 0; i < PACKET_SIZE - sizeof(struct icmp); i++)
    {
        sendBuffer[sizeof(struct icmp) + i] = i % 256;
    }
    icmpPacket->icmp_cksum = calculateChecksum((unsigned short *)sendBuffer, PACKET_SIZE);
    if (sendto(sockfd, sendBuffer, sizeof(sendBuffer), 0, destAddr, sizeof(*destAddr)) == -1)
    {
        perror("Error: Cannot send ICMP request packet");
        return -1;
    }
    return 0;
}

// Function to receive ICMP echo reply
int receiveICMPEchoReply(int sockfd, struct sockaddr *srcAddr, int seqNo, struct timeval *recvTime)
{
    char recvBuffer[BUFFER_SIZE];
    struct msghdr recvMsg;
    struct iovec recviov;
    recvMsg.msg_name = (void *)srcAddr;
    recvMsg.msg_namelen = sizeof(*srcAddr);
    recvMsg.msg_iov = &recviov;
    recvMsg.msg_iovlen = 1;
    recvMsg.msg_iov->iov_base = recvBuffer;
    recvMsg.msg_iov->iov_len = sizeof(recvBuffer);
    recvMsg.msg_control = NULL;
    recvMsg.msg_controllen = 0;
    recvMsg.msg_flags = 0;
    if (recvmsg(sockfd, &recvMsg, 0) == -1)
    {
        perror("Error: Cannot receive ICMP reply packet");
        return -1;
    }
    struct iphdr *ipPacket = (struct iphdr *)recvBuffer;
    if (ipPacket->protocol != IPPROTO_ICMP)
    {
        printf("Error: Received packet is not ICMP echo reply\n");
        return -1;
    }
    struct icmp *icmpPacket = (struct icmp *)(recvBuffer + sizeof(struct iphdr));
    if (icmpPacket->icmp_id != getpid() || icmpPacket->icmp_seq != seqNo || icmpPacket->icmp_type != ICMP_ECHOREPLY)
    {
        printf("Error: Malformed ICMP echo reply\n");
        return -1;
    }
    if (gettimeofday(recvTime, NULL) == -1)
    {
        perror("Error: Cannot get time for ICMP echo reply");
        return -1;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <hostname/IP>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Creating socket file descriptor
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) == -1)
    {
        perror("Error: Cannot create raw socket");
        exit(EXIT_FAILURE);
    }

    // Resolving host name to IP address
    struct hostent *host;
    struct in_addr **addrList;
    char ipAddr[16];
    if ((host = gethostbyname(argv[1])) == NULL)
    {
        printf("Error: Hostname/IP address \"%s\" not found\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    addrList = (struct in_addr **)host->h_addr_list;
    strcpy(ipAddr, inet_ntoa(*addrList[0]));
    printf("Pinging %s (%s):\n", argv[1], ipAddr);

    // Setting destination address
    struct sockaddr_in destAddr;
    memset(&destAddr, 0, sizeof(destAddr));
    destAddr.sin_family = AF_INET;
    destAddr.sin_addr.s_addr = inet_addr(ipAddr);

    // Pinging the host
    struct timeval sendTime;
    struct timeval recvTime;
    double rttMs;
    for (int seqNo = 1; seqNo <= 10; seqNo++)
    {
        if (sendICMPEchoRequest(sockfd, (struct sockaddr *)&destAddr, seqNo) == -1)
        {
            continue;
        }
        if (gettimeofday(&sendTime, NULL) == -1)
        {
            perror("Error: Cannot get time for ICMP echo request");
            continue;
        }
        if (receiveICMPEchoReply(sockfd, (struct sockaddr *)&destAddr, seqNo, &recvTime) == -1)
        {
            continue;
        }
        rttMs = (recvTime.tv_sec - sendTime.tv_sec) * 1000.0 + (recvTime.tv_usec - sendTime.tv_usec) / 1000.0;
        printf("Seq=%d, RTT=%.2fms\n", seqNo, rttMs);
        sleep(1);
    }

    // Closing socket
    close(sockfd);

    return 0;
}