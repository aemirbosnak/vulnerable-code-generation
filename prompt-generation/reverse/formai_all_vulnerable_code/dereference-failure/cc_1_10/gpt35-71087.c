//FormAI DATASET v1.0 Category: Network Ping Test ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <string.h>
#include <sys/time.h>

#define BUFFER_SIZE 1024
#define ICMP_ECHO_REQUEST 8
#define ICMP_ECHO_REPLY 0
#define ICMP_HEADER_SIZE 8
#define IP_HEADER_SIZE 20

char buffer[BUFFER_SIZE];

int checksum(unsigned short *ptr, int nbytes)
{
    unsigned long sum;
    unsigned short oddbyte;
    unsigned short answer;

    sum = 0;
    while (nbytes > 1)
    {
        sum += *ptr++;
        nbytes -= 2;
    }

    if (nbytes == 1)
    {
        oddbyte = 0;
        *((unsigned char*)&oddbyte) = *(unsigned char*)ptr;
        sum += oddbyte;
    }

    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    answer = (short)~sum;

    return answer;
}

void ping(int sd, struct sockaddr_in *addr)
{
    struct icmp *icmp_header = (struct icmp*)buffer;
    icmp_header->icmp_type = ICMP_ECHO_REQUEST;
    icmp_header->icmp_code = 0;
    icmp_header->icmp_hun.ih_idseq.icd_id = getpid();
    icmp_header->icmp_hun.ih_idseq.icd_seq = 0;
    memset((void*)icmp_header->icmp_data, 0xff, 56);
    icmp_header->icmp_cksum = checksum((unsigned short*)icmp_header, sizeof(struct icmp));

    sendto(sd, buffer, ICMP_HEADER_SIZE + 56, 0, (struct sockaddr*)addr, sizeof(struct sockaddr_in));
}

int pong(int sd, struct sockaddr_in *addr, long long int *elapsed_time)
{
    int addr_len = sizeof(struct sockaddr_in);
    struct timeval begin, end;

    gettimeofday(&begin, NULL);

    int n = recvfrom(sd, buffer, BUFFER_SIZE, 0, (struct sockaddr*)addr, &addr_len);

    gettimeofday(&end, NULL);

    *elapsed_time = (end.tv_sec - begin.tv_sec) * 1000LL + (end.tv_usec - begin.tv_usec) / 1000LL;

    struct iphdr *ip_header = (struct iphdr*)buffer;
    if (ip_header->protocol == IPPROTO_ICMP)
    {
        struct icmp *icmp_header = (struct icmp*)(buffer + IP_HEADER_SIZE);
        if (icmp_header->icmp_type == ICMP_ECHO_REPLY)
        {
            return 1;
        }
    }

    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <IP address>\n", argv[0]);
        exit(1);
    }

    const char *host = argv[1];
    struct hostent *he;
    struct in_addr **addr_list;

    if ((he = gethostbyname(host)) == NULL)
    {
        perror("gethostbyname");
        exit(1);
    }

    addr_list = (struct in_addr**)he->h_addr_list;

    int sd;
    if ((sd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) == -1)
    {
        perror("socket");
        exit(1);
    }

    struct timeval timeout = { 1, 0 };
    setsockopt(sd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout));

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(struct sockaddr_in));
    addr.sin_family = AF_INET;
    addr.sin_port = 0;
    addr.sin_addr = **addr_list;

    printf("PING %s (%s)\n", host, inet_ntoa(**addr_list));

    int received = 0;
    long long int elapsed_time, min_time = 999999, max_time = 0, average_time = 0;

    for (int i = 0; i < 10; i++)
    {
        ping(sd, &addr);

        if (pong(sd, &addr, &elapsed_time))
        {
            received++;

            printf("PONG %d bytes from %s: icmp_seq=%d time=%lld ms\n", ICMP_HEADER_SIZE + 56, host, i + 1, elapsed_time);

            average_time += elapsed_time;
            if (elapsed_time < min_time) { min_time = elapsed_time; }
            if (elapsed_time > max_time) { max_time = elapsed_time; }
        }
        else
        {
            printf("NO PONG\n");
        }

        sleep(1);
    }

    if (received > 0)
    {
        printf("\n--- %s ping statistics ---\n", host);
        printf("%d packets transmitted, %d received, %.0f%% packet loss, time %lldms\n", 10, received, ((float)(10 - received) / 10.0f) * 100.0f, max_time - min_time);
        printf("rtt min/avg/max = %lld/%lld/%lld ms\n", min_time, average_time / received, max_time);
    }

    close(sd);

    return 0;
}