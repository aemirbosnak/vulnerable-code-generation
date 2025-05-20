//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

#define DATASIZE 56
#define IP_HEADER_SIZE sizeof(struct iphdr)
#define ICMP_MIN_HEADER_SIZE sizeof(struct icmphdr)
#define PACKETSIZE (ICMP_MIN_HEADER_SIZE + DATASIZE)
#define PINGER_MAX_TTL 30
#define PINGER_TIMEOUT 2
#define PINGER_MAX_RETRIES 3

static int in_cksum(unsigned short *ptr, int nbytes);

int main(int argc, char *argv[])
{
    int sockfd, i, flag, ttl;
    char ip_address[16], dest_ip_address[16];
    struct iphdr *iph;
    struct icmphdr *icmph;
    struct sockaddr_in dest_addr, source_addr;
    char packet[PACKETSIZE];
    int one = 1;
    const int *val = &one;
    int seq = 0, pid = getpid();
    int count = 1, data_sent = 0, data_received = 0;
    float loss = 0;
    struct timeval start_time, end_time, t_time;
    float total_time = 0, avg_time = 0;
    fd_set read_set;

    if (argc != 2)
    {
        printf("Usage: ./ping <ip_address>\n");
        return 1;
    }

    // Get the source IP
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
    if (sockfd < 0)
    {
        perror("socket() error");
        return 1;
    }

    if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, val, sizeof(one)) < 0)
    {
        perror("setsockopt() error");
        return 1;
    }

    getsockname(sockfd, (struct sockaddr *)&source_addr, &(socklen_t){sizeof(source_addr)});
    inet_ntop(AF_INET, &(source_addr.sin_addr), ip_address, INET_ADDRSTRLEN);

    printf("PING %s (%s)\n\n", argv[1], ip_address);
    strncpy(dest_ip_address, argv[1], 15);

    iph = (struct iphdr *)packet;
    memset(iph, 0, IP_HEADER_SIZE);
    iph->ihl = 5;
    iph->version = 4;
    iph->tos = 16;
    iph->id = htons(1557);
    iph->ttl = PINGER_MAX_TTL;
    iph->protocol = IPPROTO_ICMP;
    inet_pton(AF_INET, dest_ip_address, &(iph->daddr));

    icmph = (struct icmphdr *)(packet + IP_HEADER_SIZE);
    memset(icmph, 0, ICMP_MIN_HEADER_SIZE);
    icmph->type = ICMP_ECHO;
    icmph->un.echo.id = htons(pid);

    printf("PING %s (%s) 56(84) bytes of data.\n", argv[1], dest_ip_address);

    while (count <= PINGER_MAX_RETRIES)
    {
        seq++;
        memset(packet + IP_HEADER_SIZE + ICMP_MIN_HEADER_SIZE, seq, DATASIZE);

        gettimeofday(&start_time, 0);
        icmph->un.echo.sequence = htons(seq);
        icmph->checksum = 0;
        icmph->checksum = in_cksum((unsigned short *)icmph, ICMP_MIN_HEADER_SIZE + DATASIZE);

        if (sendto(sockfd, packet, IP_HEADER_SIZE + ICMP_MIN_HEADER_SIZE + DATASIZE, 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) <= 0)
        {
            printf("Error Sending Request.\n");
            sleep(1);
            continue;
        }
        data_sent++;

        //wait for reply
        FD_ZERO(&read_set);
        FD_SET(sockfd, &read_set);
        t_time.tv_sec = PINGER_TIMEOUT;
        t_time.tv_usec = 0;

        flag = select(sockfd + 1, &read_set, NULL, NULL, &t_time);

        if (flag == 0)
        {
            printf("Request Timeout.\n");
            count++;
            continue;
        }

        if (recvfrom(sockfd, packet, PACKETSIZE, 0, NULL, NULL) <= 0)
        {
            printf("Receive Error.\n");
            continue;
        }

        gettimeofday(&end_time, 0);
        total_time += (float)(end_time.tv_sec - start_time.tv_sec) + (float)(end_time.tv_usec - start_time.tv_usec) / 1000000.0;
        data_received++;
        loss = ((float)(data_sent - data_received) / (float)data_sent) * 100.0;
        avg_time = (float)total_time / (float)data_received;

        printf("%i bytes from %s: icmp_seq=%i ttl=%i time=%.3f ms\n", DATASIZE, dest_ip_address, seq, iph->ttl, avg_time * 1000.0);

        fflush(stdout);
        sleep(1);
    }

    printf("\n--- %s ping statistics ---\n", argv[1]);
    printf("%i packets transmitted, %i received, %.2f%% packet loss, time %.0fms\n", data_sent, data_received, loss, total_time * 1000);
    printf("rtt min/avg/max/mdev = %.3f/%.3f/%.3f/%.3f ms\n", avg_time, avg_time, avg_time, 0.0);

    close(sockfd);
    return 0;
}

static int in_cksum(unsigned short *ptr, int nbytes)
{
    register int sum;
    u_short oddbyte;
    register u_short answer;

    sum = 0;
    while (nbytes > 1)
    {
        sum += *ptr++;
        nbytes -= 2;
    }

    if (nbytes == 1)
    {
        oddbyte = 0;
        *((u_char *)&oddbyte) = *(u_char *)ptr;
        sum += oddbyte;
    }

    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    answer = (u_short)~sum;

    return (answer);
}