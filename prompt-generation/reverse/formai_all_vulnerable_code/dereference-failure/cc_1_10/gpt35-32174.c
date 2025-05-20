//FormAI DATASET v1.0 Category: Network Ping Test ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/time.h>

#define PING_PKT_S 64

unsigned short calc_chksum(void *b, int len)
{
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;

    if (len == 1)
        sum += *(unsigned char*)buf;

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;

    return result;
}

void send_ping(int icmp_sockfd, struct sockaddr_in *dest_addr, int ttl)
{
    struct icmp *icmp_pkt;
    char send_pkt[PING_PKT_S];
    int pkt_seq_num = 1;

    icmp_pkt = (struct icmp*)send_pkt;

    icmp_pkt->icmp_type = ICMP_ECHO;
    icmp_pkt->icmp_code = 0;
    icmp_pkt->icmp_id = getpid() & 0xFFFF;
    icmp_pkt->icmp_seq = pkt_seq_num++;
    memset(&icmp_pkt->icmp_data, 0xa5, PING_PKT_S - ICMP_MINLEN);

    icmp_pkt->icmp_cksum = 0;
    icmp_pkt->icmp_cksum = calc_chksum((unsigned short*)icmp_pkt, PING_PKT_S);

    if (setsockopt(icmp_sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) != 0)
    {
        printf("setsockopt error\n");
        return;
    }

    if (sendto(icmp_sockfd, send_pkt, PING_PKT_S, 0, (struct sockaddr*)dest_addr, sizeof(struct sockaddr)) <= 0)
    {
        printf("sendto error\n");
        return;
    }
}

int receive_ping(int icmp_sockfd, struct sockaddr_in *dest_addr, long *time_of_arrival)
{
    struct sockaddr_in sender;
    socklen_t sender_len = sizeof(sender);

    char recv_pkt[PING_PKT_S];

    fd_set read_set;
    FD_ZERO(&read_set);
    FD_SET(icmp_sockfd, &read_set);

    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    while (select(icmp_sockfd+1, &read_set, NULL, NULL, &timeout))
    {
        int recd_size = recvfrom(icmp_sockfd, recv_pkt, PING_PKT_S, 0, (struct sockaddr*)&sender, &sender_len);

        if (recd_size < 0)
        {
            printf("recvfrom error\n");
            break;
        }

        struct iphdr *ip_hdr = (struct iphdr*)recv_pkt;
        struct icmp *icmp_pkt = (struct icmp*)(recv_pkt + (ip_hdr->ihl * 4));

        if (icmp_pkt->icmp_type == ICMP_ECHOREPLY)
        {
            if (icmp_pkt->icmp_id == getpid())
            {
                *time_of_arrival = time(NULL);

                return 1;
            }
        }
    }

    return 0;
}

void ping_hosts(char *dest_host, int ttl, int repeat)
{
    struct hostent *host;
    struct sockaddr_in dest_addr;

    host = gethostbyname(dest_host);

    if (host == NULL)
    {
        printf("gethostbyname error\n");
        return;
    }

    memset(&dest_addr, 0, sizeof(struct sockaddr_in));
    memcpy((char*)&dest_addr.sin_addr, (char*)host->h_addr, host->h_length);

    dest_addr.sin_family = AF_INET;

    int icmp_sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

    if (icmp_sockfd < 0)
    {
        printf("socket error\n");
        return;
    }

    for (int i = 0; i < repeat; i++)
    {
        long time_of_arrival;

        send_ping(icmp_sockfd, &dest_addr, ttl);

        if (receive_ping(icmp_sockfd, &dest_addr, &time_of_arrival))
            printf("Ping to %s. Time: %ld\n", dest_host, time_of_arrival);
        else
            printf("Ping to %s. Timed out\n", dest_host);

        sleep(1);
    }

    close(icmp_sockfd);
}

int main()
{
    char *dest_hosts[3] = {"www.google.com", "www.facebook.com", "www.twitter.com"};

    for (int i = 0; i < 3; i++)
        ping_hosts(dest_hosts[i], 64, 3);

    return 0;
}