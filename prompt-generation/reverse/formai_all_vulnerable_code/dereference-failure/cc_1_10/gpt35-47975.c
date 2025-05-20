//FormAI DATASET v1.0 Category: Network Ping Test ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>

#define PING_TIMEOUT_SEC 1    // maximum waiting time for a packet in seconds
#define PING_TIMEOUT_USEC 0   // maximum waiting time for a packet in microseconds

struct ping_packet
{
    struct icmphdr hdr;          // ICMP header
    char msg[64 - sizeof(struct icmphdr)];    // message
};

unsigned short checksum(void *b, int len);                         // function to calculate checksum
void ping(const char *addr);                                       // function to send ping packets

int main(int argc, char **argv)
{
    if (argc != 2)    // check if only one argument (host address or IP) is provided
    {
        fprintf(stderr, "Usage: %s <address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ping(argv[1]);    // call the ping function to send ICMP packets

    return 0;
}

// function to calculate checksum
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
    result = ~sum;    // 1's complement of sum
    return result;
}

void ping(const char *addr)
{
    int sockfd, count;
    struct sockaddr_in address;
    struct hostent *host;
    struct timeval tv;
    fd_set readfds;
    socklen_t len;
    unsigned char ttl = 128;
    char buffer[1024];
    struct ping_packet packet;
    int packets_sent = 0, packets_received = 0, packet_loss = 0;

    // create a socket for sending/receiving ICMP packets
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // set TTL
    if (setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) < 0)
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // resolve the host name or IP address
    if ((host = gethostbyname(addr)) == NULL)
    {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    bcopy((char *) host->h_addr, (char *)&address.sin_addr.s_addr, host->h_length);

    // print the IP address of the host
    printf("PING %s (%s):\n", addr, inet_ntoa(address.sin_addr));

    while (1)
    {
        packets_sent++;
        // set the ICMP header values
        packet.hdr.type = ICMP_ECHO;
        packet.hdr.code = 0;
        packet.hdr.un.echo.id = getpid();
        packet.hdr.un.echo.sequence = packets_sent;
        memset(packet.msg, '1', sizeof(packet.msg));   // fill the message with 1

        packet.hdr.checksum = checksum(&packet, sizeof(packet));   // calculate the checksum

        // send the ping packet
        if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&address, sizeof(address)) <= 0)
        {
            perror("sendto");
            packet_loss++;
            continue;
        }

        tv.tv_sec = PING_TIMEOUT_SEC;
        tv.tv_usec = PING_TIMEOUT_USEC;

        // wait for the response packet
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);
        if (select(sockfd + 1, &readfds, NULL, NULL, &tv) <= 0)
        {
            printf("Request timed out.\n");
            packet_loss++;
            continue;
        }

        // receive the response packet
        len = sizeof(address);
        if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&address, &len) < 0)
        {
            perror("recvfrom");
            continue;
        }

        // check if the received packet is an ICMP Echo reply
        struct iphdr *ip_hdr = (struct iphdr *)buffer;
        int iphdr_len = ip_hdr->ihl * 4;
        struct icmphdr *icmp_hdr = (struct icmphdr *)(buffer + iphdr_len);
        if (icmp_hdr->type == ICMP_ECHOREPLY)
        {
            packets_received++;
            printf("Received packet from %s: ", inet_ntoa(address.sin_addr));
            printf("icmp_seq=%d ttl=%d time=%.2fms\n", icmp_hdr->un.echo.sequence, ip_hdr->ttl, tv.tv_sec * 1000.0 + tv.tv_usec / 1000.0);
        }
        else
            printf("Received packet is not an ICMP Echo reply.\n");

        sleep(1);   // wait for 1 second before sending the next packet
    }

    // print the statistics
    printf("\n--- %s ping statistics ---\n", addr);
    printf("%d packets transmitted, %d received, %d%% packet loss\n", packets_sent, packets_received, packet_loss * 100 / packets_sent);
    close(sockfd);
}