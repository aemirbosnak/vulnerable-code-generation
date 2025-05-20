//FormAI DATASET v1.0 Category: Network Ping Test ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <signal.h>
#include <time.h>

#define PACKET_SIZE     64
#define MAX_PACKET_SIZE 1024
#define PING_SLEEP_TIME 1000000

int pingloop = 1;

typedef struct
{
    struct timeval time_begin;
    struct timeval time_end;
    short seq_no;
    int icmp_type;
} ping_packet;

unsigned short checksum(void *b, int len)
{
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;

    if (len == 1)
        sum += *(unsigned char *) buf;

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = (unsigned short) ~sum;

    return result;
}

void int_handler(int dummy)
{
    pingloop = 0;
}

void send_ping(int ping_sockfd, struct sockaddr_in *ping_addr, int seq_no, struct timeval *time_begin)
{
    char buffer[MAX_PACKET_SIZE];
    ping_packet *ping_pkt = (ping_packet *) buffer;
    struct timeval present_time;

    memset(buffer, 0, MAX_PACKET_SIZE);

    ping_pkt->seq_no = seq_no;
    gettimeofday(&present_time, NULL);
    ping_pkt->time_begin = *time_begin;

    ssize_t packet_size = sizeof(ping_packet);

    ping_pkt->icmp_type = ICMP_ECHO;

    // Append ICMP checksum to packet
    ping_pkt->icmp_type = checksum(ping_pkt, packet_size);

    // Send packet to target
    if (sendto(ping_sockfd, ping_pkt, packet_size, 0, (struct sockaddr *) ping_addr, sizeof(*ping_addr)) <= 0)
        printf("Packet Sending Failed!\n");
}

void recv_ping(int ping_sockfd, struct sockaddr_in *ping_addr, int seq_no, struct timeval *tvrecv)
{
    char buffer[MAX_PACKET_SIZE];
    ping_packet *ping_pkt = (ping_packet *) buffer;
    struct sockaddr_in r_addr;
    socklen_t r_addr_len = sizeof(r_addr);
    ssize_t packet_size = sizeof(ping_packet);

    while (1)
    {
        ssize_t recv_len = recvfrom(ping_sockfd, buffer, packet_size, 0, (struct sockaddr *) &r_addr, &r_addr_len);

        if (recv_len < 0)
            continue;

        if (ping_pkt->icmp_type == ICMP_ECHOREPLY && ping_pkt->seq_no == seq_no)
        {
            gettimeofday(tvrecv, NULL);
            break;
        }
    }
}

void ping(const char *host)
{
    int ping_sockfd;
    struct sockaddr_in ping_addr;
    pid_t pid = getpid();
    struct hostent *hostinfo;
    int pack_no = 0;
    struct timeval tv_begin, tv_end, tv_interval;

    ping_sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (ping_sockfd < 0)
    {
        printf("Failed to create socket!\n");
        return;
    }

    // Register signal handler
    signal(SIGINT, int_handler);

    // Resolve host name
    hostinfo = gethostbyname(host);
    if (!hostinfo)
    {
        printf("Failed to resolve host name!\n");
        return;
    }

    memset(&ping_addr, 0, sizeof(ping_addr));
    ping_addr.sin_family = AF_INET;
    ping_addr.sin_addr = *((struct in_addr *) hostinfo->h_addr);

    printf("PING %s (%s):\n", host, inet_ntoa(ping_addr.sin_addr));

    while (pingloop)
    {
        pack_no++;
        gettimeofday(&tv_begin, NULL);
        send_ping(ping_sockfd, &ping_addr, pack_no, &tv_begin);

        recv_ping(ping_sockfd, &ping_addr, pack_no, &tv_end);

        timersub(&tv_end, &tv_begin, &tv_interval);
        double rtt = tv_interval.tv_sec * 1000 + tv_interval.tv_usec / 1000.0;

        if (pingloop)
        {
            printf("%d bytes of data received from %s in %0.2f ms\n", PACKET_SIZE, host, rtt);
            usleep(PING_SLEEP_TIME);
        }
    }

    close(ping_sockfd);
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Destination Host Required!\n");
        return 0;
    }

    ping(argv[1]);
    return 0;
}