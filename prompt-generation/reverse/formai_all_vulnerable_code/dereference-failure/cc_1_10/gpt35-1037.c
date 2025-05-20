//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <sys/types.h>
#include <sys/socket.h>

void calculate_time_delay(struct timeval *out, struct timeval *in)
{
    if ((out->tv_usec -= in->tv_usec) < 0)
    {
        --out->tv_sec;
        out->tv_usec += 1000000;
    }
    out->tv_sec -= in->tv_sec;
}

void ping_remote_host(const char *hostname)
{
    struct sockaddr_in remote_addr;
    struct hostent *host_info;
    struct timeval start_time, end_time;
    int sockfd, sequence = 0;
    const char *packet = "Network Quality of Service Monitor";
    char rec_buffer[1024];

    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0)
    {
        perror("socket");
        return;
    }

    if ((host_info = gethostbyname(hostname)) == NULL)
    {
        fprintf(stderr, "Unknown host %s.\n", hostname);
        return;
    }

    memset(&remote_addr, 0, sizeof(struct sockaddr_in));
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_addr = *((struct in_addr *)host_info->h_addr);

    while (1)
    {
        gettimeofday(&start_time, NULL);

        struct icmp *icmp_packet = (struct icmp *)malloc(sizeof(struct icmp));
        icmp_packet->icmp_type = ICMP_ECHO;
        icmp_packet->icmp_code = 0;
        icmp_packet->icmp_id = getpid();
        icmp_packet->icmp_seq = sequence++;
        icmp_packet->icmp_cksum = 0;
        icmp_packet->icmp_cksum = htons(~(ICMP_ECHO << 8) & 0xffff);

        sendto(sockfd, icmp_packet, sizeof(struct icmp), 0, (struct sockaddr *)&remote_addr, sizeof(remote_addr));

        socklen_t addrlen = sizeof(struct sockaddr_in);
        recvfrom(sockfd, rec_buffer, sizeof(rec_buffer), 0, (struct sockaddr *)&remote_addr, &addrlen);

        gettimeofday(&end_time, NULL);

        if (addrlen == sizeof(struct sockaddr_in) && !strcmp(inet_ntoa(remote_addr.sin_addr), host_info->h_name))
        {
            struct icmp *rec_icmp_packet = (struct icmp *)rec_buffer;
            if (rec_icmp_packet->icmp_id == getpid() && rec_icmp_packet->icmp_seq == (sequence - 1))
            {
                struct timeval *send_time = (struct timeval *)rec_icmp_packet->icmp_data;
                calculate_time_delay(&end_time, send_time);
                printf("Received ICMP packet from %s with a delay of %ld.%06ld seconds\n", hostname, end_time.tv_sec, end_time.tv_usec);
            }
        }

        sleep(1);
    }

    close(sockfd);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }
    ping_remote_host(argv[1]);

    return 0;
}