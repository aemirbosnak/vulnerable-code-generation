//FormAI DATASET v1.0 Category: Network Ping Test ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define PACKET_SIZE 64
#define ICMP_ECHO_REQUEST 8
#define ICMP_ECHO_REPLY 0
#define MAX_WAIT_TIME 5
#define MAX_NO_OF_PACKETS 5

int icmp_seq = 0;

struct icmp_hdr
{
    uint8_t type;
    uint8_t code;
    uint16_t checksum;
    uint16_t ident;
    uint16_t seq;
};

struct ip_hdr
{
    uint8_t version_and_len;
    uint8_t tos;
    uint16_t total_len;
    uint16_t ident;
    uint16_t flags_and_offset;
    uint8_t ttl;
    uint8_t protocol;
    uint16_t checksum;
    uint32_t source_ip;
    uint32_t dest_ip;
};

uint16_t calculate_checksum(uint16_t *buf, int len);

void send_packet(int sockfd, struct sockaddr_in *addr, int pid)
{
    char packet[PACKET_SIZE];
    struct icmp_hdr *icmp_hdr_ptr;
    icmp_hdr_ptr = (struct icmp_hdr *)packet;

    icmp_hdr_ptr->type = ICMP_ECHO_REQUEST;
    icmp_hdr_ptr->code = 0;
    icmp_hdr_ptr->ident = pid;
    icmp_hdr_ptr->seq = icmp_seq++;
    icmp_hdr_ptr->checksum = 0;
    memset(packet + sizeof(struct icmp_hdr), 'A', PACKET_SIZE - sizeof(struct icmp_hdr));

    icmp_hdr_ptr->checksum = calculate_checksum((uint16_t *)packet, PACKET_SIZE);
    sendto(sockfd, packet, PACKET_SIZE, 0, (struct sockaddr *)addr, sizeof(*addr));
}

int receive_packet(int sockfd, struct sockaddr_in *addr, int seq, double *time_diff, char *from_ip)
{
    char packet[PACKET_SIZE];
    struct ip_hdr *ip_hdr_ptr;
    struct icmp_hdr *icmp_hdr_ptr;
    struct timeval tv;
    fd_set read_fd;
    int ret, len = sizeof(*addr);
    double send_time;
    memset(packet, 0, PACKET_SIZE);

    FD_ZERO(&read_fd);
    FD_SET(sockfd, &read_fd);

    tv.tv_sec = MAX_WAIT_TIME;
    tv.tv_usec = 0;

    ret = select(sockfd + 1, &read_fd, NULL, NULL, &tv);

    if (ret < 0)
    {
        return -1;
    }
    else if (ret == 0)
    {

        return 2;
    }
    else
    {
        if (FD_ISSET(sockfd, &read_fd))
        {
            ret = recvfrom(sockfd, packet, PACKET_SIZE, 0, (struct sockaddr *)addr, (socklen_t *)&len);
            if (ret <= 0)
            {
                return -1;
            }

            ip_hdr_ptr = (struct ip_hdr *)packet;
            icmp_hdr_ptr = (struct icmp_hdr *)(packet + ((ip_hdr_ptr->version_and_len & 0x0f) * 4));
            *time_diff = (double)(time(NULL) - icmp_hdr_ptr->ident);
            if (icmp_hdr_ptr->type == ICMP_ECHO_REPLY && icmp_hdr_ptr->seq == seq)
            {
                strcpy(from_ip, inet_ntoa(addr->sin_addr));
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    return 0;
}

uint16_t calculate_checksum(uint16_t *buf, int len)
{
    uint32_t sum = 0;
    while (len > 1)
    {
        sum += *buf++;
        len -= 2;
    }
    if (len)
    {
        sum += *(unsigned char *)buf;
    }
    while (sum >> 16)
    {
        sum = (sum & 0xffff) + (sum >> 16);
    }
    return (uint16_t)(~sum);
}

int main(int argc, char *argv[])
{
    int sockfd, ret, i, count = 0;
    struct sockaddr_in addr;
    char dest_ip[20], from_ip[20];
    double time_diff;
    char *prog_name = argv[0];
    char usage_str[] = "Usage: %s <target_ip>\n";

    if (argc != 2)
    {
        fprintf(stderr, usage_str, prog_name);
        exit(1);
    }

    memset(from_ip, 0, sizeof(from_ip));
    memset(&addr, 0, sizeof(addr));

    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0)
    {
        perror("socket");
        exit(1);
    }

    strcpy(dest_ip, argv[1]);

    addr.sin_family = AF_INET;
    addr.sin_port = 0;
    addr.sin_addr.s_addr = inet_addr(dest_ip);

    printf("PING %s (%s): %d data bytes\n", dest_ip, inet_ntoa(addr.sin_addr), PACKET_SIZE - sizeof(struct icmp_hdr));

    for (i = 0; i < MAX_NO_OF_PACKETS; i++)
    {
        send_packet(sockfd, &addr, (int)getpid());
        ret = receive_packet(sockfd, &addr, i, &time_diff, from_ip);
        if (ret == -1)
        {
            perror("recvfrom");
            exit(1);
        }
        else if (ret == 0)
        {
            printf("Timeout.\n");
        }
        else if (ret == 1)
        {
            printf("%d bytes from %s: icmp_seq=%d ttl=%d time=%.2f ms\n", PACKET_SIZE - sizeof(struct icmp_hdr), from_ip, i, 64, time_diff);
            count++;
        }
        else if (ret == 2)
        {
            printf("Timeout.\n");
        }
        sleep(1);
    }
    printf("--- %s ping statistics ---\n", dest_ip);
    printf("%d packets transmitted, %d received, %.0f%% packet loss\n", MAX_NO_OF_PACKETS, count, (1 - (double)count / MAX_NO_OF_PACKETS) * 100);
    close(sockfd);
    return 0;
}