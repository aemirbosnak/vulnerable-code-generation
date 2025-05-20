//FormAI DATASET v1.0 Category: Network Ping Test ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <errno.h>
#include <sys/time.h>
#include <unistd.h>

#define PACKET_SIZE 64
#define MAX_NO_OF_PACKETS 3

/* Checksum function */
unsigned short getCheckSum(void *buff, int buffSize) {
    unsigned short *buffer = buff;
    unsigned int total = 0;
    unsigned short checksum = 0;

    while (buffSize > 1) {
        total += *buffer;
        buffer++;
        buffSize -= 2;
    }

    if (buffSize == 1) {
        total += *(unsigned char *)buffer;
    }

    checksum = (total >> 16) + (total & 0xffff);
    checksum += (checksum >> 16);
    return (unsigned short)(~checksum);
}

/* Ping function */
void ping(int sockfd, struct sockaddr_in *addr, char *ipAddress) {
    int packetNo = 1;
    struct timeval startTime, endTime, timeDiff;
    char packet[PACKET_SIZE];
    int bytesSent = 0;
    int bytesRecv = 0;
    int packetsLost = 0;
    char recvPacket[PACKET_SIZE];
    socklen_t addrLen = sizeof(*addr);

    printf("\nPinging %s with %d packets...\n", ipAddress, MAX_NO_OF_PACKETS);
    memset(&packet, 0, sizeof(packet));

    /* ICMP header setup */
    struct icmp *icmpHeader = (struct icmp *)packet;
    icmpHeader->icmp_type = ICMP_ECHO;
    icmpHeader->icmp_code = 0;
    icmpHeader->icmp_id = htons(getpid());
    icmpHeader->icmp_seq = htons(packetNo);
    memset(&icmpHeader->icmp_data, 0xa5, PACKET_SIZE - sizeof(struct icmp));

    icmpHeader->icmp_cksum = getCheckSum((void *)icmpHeader, PACKET_SIZE);

    /* Start sending 3 packets */
    while (packetNo <= MAX_NO_OF_PACKETS) {
        bytesSent = sendto(sockfd, packet, sizeof(packet), 0, (struct sockaddr *)addr, sizeof(*addr));
        if (bytesSent <= 0) {
            printf("Error: Packet %d lost (Error - %d)\n", packetNo, errno);
            packetsLost++;
        }
        packetNo++;
        usleep(1000000);  /* Maximum ping rate */
    }

    /* Set 1 second timeout for receiving messages */
    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO,&tv,sizeof(tv)) < 0) {
        printf("Error: setsockopt() failed");
        close(sockfd);
        exit(1);
    }

    int numNoOfPackets = 0, expectedSeqNo = 1;
    /* Start receiving packets */
    while(numNoOfPackets < MAX_NO_OF_PACKETS) {
        int n = recvfrom(sockfd, recvPacket, sizeof(recvPacket), 0, (struct sockaddr *)addr, &addrLen);
        if (n <= 0) {
            printf("Error: Packet %d lost (Timeout)\n", expectedSeqNo);
            packetsLost++;
        } else {
            struct iphdr *ipHdr = (struct iphdr *)recvPacket;
            struct icmphdr *icmpHdr = (struct icmphdr *)(recvPacket + (ipHdr->ihl << 2));
            if (icmpHdr->type == ICMP_ECHOREPLY) {
                gettimeofday(&endTime, NULL);
                timersub(&endTime, &startTime, &timeDiff);
                printf("Reply from %s in %ldms: Bytes=%d Time=%ldms TTL=%d\n",
                    inet_ntoa(addr->sin_addr), timeDiff.tv_sec * 1000 + timeDiff.tv_usec / 1000,
                    PACKET_SIZE, timeDiff.tv_sec * 1000 + timeDiff.tv_usec / 1000,
                    ipHdr->ttl);
            } else {
                packetsLost++;
            }
        }
        expectedSeqNo++;
        numNoOfPackets++;
        usleep(1000000);  /* Maximum ping rate */
    }

    /* Print Statistics */
    printf("\nPing statistics for %s:\n", ipAddress);
    printf("\tPackets: Sent = %d, Received = %d, Lost = %d (%.2f percent loss)\n", MAX_NO_OF_PACKETS, MAX_NO_OF_PACKETS - packetsLost, packetsLost, (float) packetsLost / MAX_NO_OF_PACKETS * 100);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage - ./ping <IP address>\n"); 
        exit(1);
    }

    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        printf("Error: Socket creation failed (errno: %d)\n", errno);
        exit(1);
    }

    struct hostent *host = gethostbyname(argv[1]);
    if (!host) {
        printf("Error: Unknown host %s\n", argv[1]);
        close(sockfd);
        exit(1);
    }

    char *ipAddress = inet_ntoa(*(struct in_addr *)host->h_addr_list[0]);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ipAddress);

    ping(sockfd, &addr, ipAddress);

    close(sockfd);
    return 0;
}