//FormAI DATASET v1.0 Category: Network Ping Test ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <time.h>

/* Function to calculate checksum */
unsigned short checksum(unsigned short *buf, int len)
{
    unsigned long sum = 0;
    while (len--)
    {
        sum += *buf++;
    }
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    return (unsigned short)(~sum);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <hostname or IP address>\n", argv[0]);
        return 1;
    }
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL)
    {
        printf("Unknown host %s\n", argv[1]);
        return 1;
    }
    struct in_addr **addr_list = (struct in_addr **)host->h_addr_list;
    struct sockaddr_in dest_addr;
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(0);
    dest_addr.sin_addr = *addr_list[0];
    int icmp_socket = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (icmp_socket < 0)
    {
        printf("Failed to create ICMP socket. Please make sure you have root privilege.\n");
        return 1;
    }
    int ttl_val = 64;
    if (setsockopt(icmp_socket, IPPROTO_IP, IP_TTL, &ttl_val, sizeof(ttl_val)) != 0)
    {
        printf("Failed to set TTL value.\n");
        return 1;
    }
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    if (setsockopt(icmp_socket, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) != 0)
    {
        printf("Failed to set socket timeout.\n");
        return 1;
    }
    char send_buf[64] = {0};
    struct icmphdr *icmp_hdr = (struct icmphdr *)send_buf;
    icmp_hdr->type = ICMP_ECHO;
    icmp_hdr->code = 0;
    icmp_hdr->checksum = 0;
    icmp_hdr->un.echo.id = (unsigned short)getpid();
    memset(&send_buf[sizeof(struct icmphdr)], 's', sizeof(send_buf) - sizeof(struct icmphdr));
    icmp_hdr->checksum = checksum((unsigned short *)send_buf, sizeof(send_buf));
    int seq_no = 0;
    int total_time_ms = 0;
    int total_pkt_sent = 0;
    int total_pkt_recv = 0;
    int min_time_ms = 999;
    int max_time_ms = 0;
    printf("PING %s (%s) 56(84) bytes of data.\n", argv[1], inet_ntoa(*addr_list[0]));
    while (1)
    {
        struct sockaddr_in recv_addr;
        socklen_t recv_len = sizeof(recv_addr);
        char recv_buf[512] = {0};
        struct timeval start_time;
        gettimeofday(&start_time, NULL);
        if (sendto(icmp_socket, send_buf, sizeof(send_buf), 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) <= 0)
        {
            printf("Failed to send ICMP packet.\n");
            return 1;
        }
        total_pkt_sent++;
        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(icmp_socket, &read_fds);
        char ip_addr[INET_ADDRSTRLEN];
        int sel_res = select(icmp_socket + 1, &read_fds, NULL, NULL, &timeout);
        if (sel_res < 0)
        {
            printf("select() system call failed.\n");
            return 1;
        }
        else if (sel_res == 0)
        {
            printf("Request timed out.\n");
        }
        else
        {
            if (recvfrom(icmp_socket, recv_buf, sizeof(recv_buf), 0, (struct sockaddr *)&recv_addr, &recv_len) < 0)
            {
                printf("Failed to receive ICMP packet.\n");
                return 1;
            }
            struct icmphdr *icmp_hdr = (struct icmphdr *)(recv_buf + sizeof(struct iphdr));
            if (icmp_hdr->type == ICMP_ECHOREPLY)
            {
                gettimeofday(&start_time, NULL);
                total_pkt_recv++;
                int time_ms = (int)(start_time.tv_sec - (time_t)icmp_hdr->un.echo.sequence * 1000) + (start_time.tv_usec - icmp_hdr->checksum) / 1000;
                if (time_ms < min_time_ms) min_time_ms = time_ms;
                if (time_ms > max_time_ms) max_time_ms = time_ms;
                total_time_ms += time_ms;
                struct sockaddr_in *src_addr = (struct sockaddr_in *)&recv_addr;
                inet_ntop(AF_INET, &(src_addr->sin_addr), ip_addr, INET_ADDRSTRLEN);
                printf("%d bytes from %s: icmp_seq=%d ttl=%d time=%d ms\n", (int)sizeof(struct icmphdr), ip_addr, icmp_hdr->un.echo.sequence, (int)ttl_val, time_ms);
            }
        }
        if (total_pkt_sent == 4) break;
        sleep(1);
    }
    float packet_loss = (float)(total_pkt_sent - total_pkt_recv) / total_pkt_sent * 100;
    printf("\n--- %s ping statistics ---\n", argv[1]);
    printf("%d packets transmitted, %d received, %0.1f%% packet loss, time %dms\n", total_pkt_sent, total_pkt_recv, packet_loss, total_time_ms);
    if (total_pkt_recv > 0)
    {
        printf("rtt min/avg/max = %d/%0.2f/%d ms\n", min_time_ms, (float)total_time_ms / total_pkt_recv, max_time_ms);
    }
    close(icmp_socket);
    return 0;
}