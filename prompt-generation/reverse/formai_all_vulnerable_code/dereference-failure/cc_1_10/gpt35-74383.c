//FormAI DATASET v1.0 Category: Network Ping Test ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <sys/time.h>
#include <unistd.h>

#define PACKET_SIZE 4096

int main(int argc, char *argv[])
{
    struct sockaddr_in addr;
    struct hostent *host;
    int sockfd, packetsSent = 0, packetsReceived = 0, packetsLost;
    char *hostAddr;
    char packet[PACKET_SIZE];
    struct timeval tvStart, tvEnd;
    double rtt = 0;
    int msgCount = 0;
    int ttlVal, timeoutVal;
    unsigned long destIP;
    struct icmp* icmp_hdr;
    struct timeval *start_tv, *end_tv;
    int offset = sizeof(struct iphdr), rcvd;
    struct iphdr *iph;
    struct icmphdr *icmphdr;

    if(argc != 2)
    {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    hostAddr = argv[1];

    host = gethostbyname(hostAddr);

    if(host == NULL)
    {
        printf("Could not resolve hostname %s\n", hostAddr);
        exit(1);
    }

    printf("PING %s (%s):\n", host->h_name, inet_ntoa(*(struct in_addr*)host->h_addr));

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

    if(sockfd < 0)
    {
        perror("Socket creation error");
        exit(1);
    }

    memset(&addr, 0, sizeof(struct sockaddr_in));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = *(unsigned int*)host->h_addr_list[0];

    icmp_hdr = (struct icmp*) packet;
    icmp_hdr->icmp_type = ICMP_ECHO;
    icmp_hdr->icmp_code = 0;
    icmp_hdr->icmp_seq = 0;

    gettimeofday((struct timeval*) icmp_hdr->icmp_data, NULL);

    icmp_hdr->icmp_cksum = 0;
    icmp_hdr->icmp_cksum = htons(~(ICMP_ECHO << 8));

    printf("\nPING RESULTS:\n");

    while(msgCount < 10)
    {
        packetsSent++;

        if(sendto(sockfd, packet, sizeof(struct icmp), 0, (struct sockaddr*)&addr, sizeof(struct sockaddr)) < 0)
        {
            perror("Packet sending error");
            continue;
        }

        msgCount++;

        if(recv(sockfd, packet, PACKET_SIZE, 0))
        {
            packetsReceived++;

            iph = (struct iphdr*) packet;
            icmphdr = (struct icmphdr*) (packet + offset);

            if(icmphdr->type == ICMP_ECHOREPLY)
            {
                if(icmphdr->un.echo.id == getpid())
                {
                    end_tv = (struct timeval*) (packet + offset + sizeof(struct icmphdr));
                    start_tv = (struct timeval*) (icmphdr + 1);
                    timersub(end_tv, start_tv, &tvEnd);
                    rtt = tvEnd.tv_sec * 1000 + tvEnd.tv_usec / 1000;
                    printf("%d bytes from %s: icmp_req=%d ttl=%d time=%.2fms\n", PACKET_SIZE, inet_ntoa(addr.sin_addr), icmphdr->un.echo.sequence, iph->ttl, rtt);
                }
            }
        }

        sleep(1);
    }

    packetsLost = packetsSent - packetsReceived;
    printf("\n--- %s ping statistics ---\n", hostAddr);
    printf("%d packets transmitted, %d received, %d%% packet loss, time %dms\n", packetsSent, packetsReceived, packetsLost / packetsSent * 100, (int)rtt);

    close(sockfd);
    return 0;
}