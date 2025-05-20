//FormAI DATASET v1.0 Category: Network Ping Test ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/ip_icmp.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define PACKET_SIZE 64

struct packet
{
    struct icmphdr hdr;
    char msg[PACKET_SIZE-sizeof(struct icmphdr)];
};

void printUsage(char *programName)
{
    printf("Usage: %s target\n", programName);
}

int validateArgs(int argc, char *argv[])
{
    if (argc < 2)
        return 0;

    struct addrinfo hints, *res;
    int status;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET; // IPv4
    hints.ai_socktype = SOCK_RAW; // Raw Socket

    status = getaddrinfo(argv[1], NULL, &hints, &res);
    if (status != 0)
        return 0;

    freeaddrinfo(res);
    return 1;
}

unsigned short calcChecksum(void *data, int length)
{
    unsigned short *buf = (unsigned short *)data;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; length > 1; length -= 2)
        sum += *(buf++);

    if (length == 1)
        sum += *(unsigned char *)buf;

    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    result = ~sum;

    return result;
}

int main(int argc, char *argv[])
{
    if (!validateArgs(argc, argv))
    {
        printUsage(argv[0]);
        return 0;
    }

    struct addrinfo hints, *res;
    int status, sockfd, timeout = 2;
    char ip[INET_ADDRSTRLEN];
    struct packet packet;
    struct icmphdr *icmphdr;
    struct sockaddr_in addr;
    int addrSize = sizeof(addr);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET; // IPv4
    hints.ai_socktype = SOCK_RAW; // Raw Socket

    status = getaddrinfo(argv[1], NULL, &hints, &res);
    if (status != 0)
    {
        printf("Error: %s\n", gai_strerror(status));
        return 1;
    }

    memcpy(&addr.sin_addr, &((struct sockaddr_in *)(res->ai_addr))->sin_addr, sizeof(struct in_addr));
    inet_ntop(AF_INET, &(addr.sin_addr), ip, INET_ADDRSTRLEN);
    printf("PING %s ...\n", ip);

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0)
    {
        perror("socket");
        return 2;
    }

    memset(&packet, 0, sizeof(packet));
    icmphdr = &packet.hdr;
    icmphdr->type = ICMP_ECHO;
    icmphdr->checksum = calcChecksum(&packet, sizeof(packet));

    int n;
    struct timeval read_timeout;
    fd_set descriptors;

    for (int i = 0; i < 5; i++)
    {
        icmphdr->un.echo.sequence = i+1;
        icmphdr->checksum = 0;
        icmphdr->checksum = calcChecksum(&packet, sizeof(packet));

        printf("Sending packet %d ...\n", i+1);
        sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&addr, sizeof(addr));

        FD_ZERO(&descriptors);
        FD_SET(sockfd, &descriptors);

        read_timeout.tv_sec = timeout;
        read_timeout.tv_usec = 0;
        
        n = select(sockfd+1, &descriptors, NULL, NULL, &read_timeout);
        if (n < 0)
        {
            perror("select");
            break;
        }
        else if (n == 0)
        {
            printf("Packet lost!\n");
            continue; // Timed Out
        }
        else
        {
            struct packet recv_packet;

            n = recvfrom(sockfd, &recv_packet, sizeof(recv_packet), 0, (struct sockaddr *)&addr, &addrSize);
            if (n < 0)
            {
                perror("recvfrom");
                break;
            }

            printf("Received packet %d\n", i+1);
        }

        sleep(1);
    }

    close(sockfd);

    return 0;
}