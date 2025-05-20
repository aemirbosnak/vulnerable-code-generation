//FormAI DATASET v1.0 Category: Network Ping Test ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <sys/time.h>

#define PACKET_SIZE 4096
#define MAX_TRIES 3
#define MAX_PACKETS 100
#define PING_TIMEOUT 2
#define PING_SLEEP 1000000

void printUsage()
{
    printf("Usage: ./ping <hostname or ip address>\n");
}

unsigned short calculateChecksum(unsigned short *ptr, int length)
{
    unsigned long sum = 0;
    while (length > 1)
    {
        sum += *ptr;
        ptr++;
        length -= 2;
    }
    if (length == 1)
    {
        sum += *(unsigned char *)ptr;
    }
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    return ~sum;
}

struct timeval getTimeDifference(struct timeval start, struct timeval end)
{
    struct timeval difference;
    difference.tv_sec = end.tv_sec - start.tv_sec;
    if (start.tv_usec > end.tv_usec)
    {
        difference.tv_sec--;
        difference.tv_usec = 1000000 - start.tv_usec + end.tv_usec;
    }
    else
    {
        difference.tv_usec = end.tv_usec - start.tv_usec;
    }
    return difference;
}

void handlePingReply(int sockfd, const struct sockaddr *addr, char *ip_address, int ttl, int seq, struct timeval start_time)
{
    char packet_buffer[PACKET_SIZE];
    struct sockaddr_in reply_addr;
    socklen_t len = sizeof(reply_addr);
    ssize_t reply_size = recvfrom(sockfd, packet_buffer, PACKET_SIZE, 0, (struct sockaddr *)&reply_addr, &len);
    if (reply_size < 0)
    {
        fprintf(stderr, "Error: Failed to receive packet.\n");
    }
    else
    {
        struct iphdr *ip_packet = (struct iphdr *)packet_buffer;
        struct icmphdr *icmp_packet = (struct icmphdr *)(packet_buffer + ip_packet->ihl * 4);

        if (icmp_packet->type == ICMP_ECHOREPLY)
        {
            struct timeval end_time;
            gettimeofday(&end_time, NULL);

            struct timeval time_diff = getTimeDifference(start_time, end_time);
            double time_in_ms = time_diff.tv_sec * 1000 + (double)time_diff.tv_usec / 1000;

            printf("%d bytes from %s (%s): icmp_seq=%d ttl=%d time=%.3f ms\n",
                   reply_size, ip_address, inet_ntoa(reply_addr.sin_addr), seq, ttl, time_in_ms);
        }
    }
}

void sendPing(int sockfd, const struct sockaddr *addr, int ttl, int seq)
{
    char packet_buffer[PACKET_SIZE];
    memset(packet_buffer, 0, sizeof(packet_buffer));
    struct icmphdr *icmp_packet = (struct icmphdr *)packet_buffer;
    icmp_packet->type = ICMP_ECHO;
    icmp_packet->code = 0;
    icmp_packet->checksum = 0;
    icmp_packet->un.echo.id = htons(getpid());
    icmp_packet->un.echo.sequence = htons(seq);
    memset(packet_buffer + sizeof(struct icmphdr), 'Q', PACKET_SIZE - sizeof(struct icmphdr));
    icmp_packet->checksum = calculateChecksum((unsigned short *)icmp_packet, PACKET_SIZE);
    ssize_t sent_bytes = sendto(sockfd, packet_buffer, PACKET_SIZE, 0, addr, sizeof(struct sockaddr));
    if (sent_bytes < 0)
    {
        fprintf(stderr, "Error: Failed to send packet.\n");
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printUsage();
        return -1;
    }

    char *host_name = argv[1];

    struct hostent *host_entry = gethostbyname(host_name);

    if (host_entry == NULL)
    {
        fprintf(stderr, "Error: Could not resolve hostname\n");
        return -1;
    }

    struct in_addr **addr_list = (struct in_addr **)host_entry->h_addr_list;
    char *ip_address = inet_ntoa(*addr_list[0]);

    printf("Pinging %s (%s):\n", host_name, ip_address);

    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

    if (sockfd < 0)
    {
        fprintf(stderr, "Error: Could not create socket.\n");
        return -1;
    }

    struct timeval timeout;
    timeout.tv_sec = PING_TIMEOUT;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&timeout, sizeof(timeout));

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = 0;
    server_address.sin_addr = *addr_list[0];

    int ttl = 1, packets_sent = 0, packets_received = 0, seq = 0;

    while (ttl <= MAX_TRIES && packets_sent < MAX_PACKETS)
    {
        setsockopt(sockfd, IPPROTO_IP, IP_TTL, (char *)&ttl, sizeof(ttl));
        printf("%d:  ", ttl);

        struct timeval start_time;
        gettimeofday(&start_time, NULL);

        sendPing(sockfd, (struct sockaddr *)&server_address, ttl, seq);

        packets_sent++;
        seq++;

        int i;
        for (i = 0; i < 3; i++)
        {
            usleep(PING_SLEEP);
            handlePingReply(sockfd, (struct sockaddr *)&server_address, ip_address, ttl, seq - 1, start_time);
        }
        printf("\n");

        ttl++;
    }

    close(sockfd);

    return 0;
}