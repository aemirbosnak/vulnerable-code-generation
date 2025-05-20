//FormAI DATASET v1.0 Category: Network Ping Test ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <arpa/inet.h>

#define PACKET_SIZE 64 //Packet size of 64 bytes
#define MAX_WAIT_TIME 5 //Maximum wait time for response in seconds
#define MAX_NO_PACKETS 3 //Total number of packets per test

struct sockaddr_in target_addr; // Structure to hold target address info
int sockfd; // Socket file descriptor
long totalTime = 0; // Variable to keep track of total time taken for all packets

/* Function to calculate the checksum of the ICMP packet */
unsigned short calculate_checksum(unsigned short *buf, int len)
{
    unsigned long sum = 0;
    while (len > 1)
    {
        sum += *buf++;
        len -= 2;
    }
    if (len == 1)
        sum += *(unsigned char *)buf;
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    return (unsigned short)(~sum);
}

/* Function to send a single ICMP packet and wait for response */
int send_packet(int packet_no)
{
    int packetsize;
    struct icmp *pkt;
    struct timeval tv;
    char packet[PACKET_SIZE];
    pkt = (struct icmp *)packet;
    pkt->icmp_type = ICMP_ECHO;
    pkt->icmp_cksum = 0;
    pkt->icmp_seq = packet_no;
    pkt->icmp_id = getpid();
    packetsize = 8 + PACKET_SIZE;
    gettimeofday((struct timeval *)pkt->icmp_data, NULL);
    pkt->icmp_cksum = calculate_checksum((unsigned short *)pkt, packetsize);
    if (sendto(sockfd, packet, packetsize, 0, (struct sockaddr *)&target_addr, sizeof(target_addr)) < 0)
    {
        perror("sendto");
        return -1;
    }
    return 0;
}

/* Function to receive a single ICMP packet and calculate RTT */
int recv_packet(int packet_no)
{
    char packet[PACKET_SIZE];
    struct ip *ip_hdr = (struct ip *)packet;
    struct icmp *icmp_hdr = (struct icmp *)(packet + (ip_hdr->ip_hl << 2));
    int bytes, len;
    struct timeval tv_recv, tv_send, tv_result;
    socklen_t len_addr;
    len_addr = sizeof(struct sockaddr_in);
    if ((bytes = recvfrom(sockfd, packet, PACKET_SIZE, 0, (struct sockaddr *)&target_addr, &len_addr)) < 0)
    {
        perror("recvfrom");
        return -1;
    }
    gettimeofday(&tv_recv, NULL);
    tv_send = *(struct timeval *)icmp_hdr->icmp_data;
    tv_result.tv_sec = tv_recv.tv_sec - tv_send.tv_sec;
    tv_result.tv_usec = tv_recv.tv_usec - tv_send.tv_usec;
    if (tv_result.tv_usec < 0)
    {
        tv_result.tv_sec--;
        tv_result.tv_usec += 1000000;
    }
    double rtt = (tv_result.tv_sec * 1000.0) + (tv_result.tv_usec / 1000.0); //Calculate RTT in milliseconds
    totalTime += rtt;
    printf("%d bytes from %s: icmp_seq=%u ttl=%d time=%.2lf ms\n", bytes, inet_ntoa(ip_hdr->ip_src), icmp_hdr->icmp_seq, ip_hdr->ip_ttl, rtt);
    return 0;
}

/* Main function to run ping test */
int ping_test(char *ip)
{
    int i, packet_no, packets_sent = 0;
    struct hostent *host;
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0)
    {
        perror("socket");
        return -1;
    }
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = 0;
    if (inet_pton(AF_INET, ip, &(target_addr.sin_addr)) == 0)
    {
        printf("Invalid IP address\n");
        return -1;
    }
    printf("Starting ping test for %s\n", ip);
    for (i = 0; i < MAX_NO_PACKETS; i++)
    {
        packet_no = i + 1;
        if (send_packet(packet_no) < 0)
            continue;
        packets_sent++;
        if (recv_packet(packet_no) < 0)
            continue;
        sleep(1);
    }
    printf("\nPing test results for %s:\n", ip);
    if (packets_sent > 0)
    {
        printf("Packets sent: %d, Packets received: %d, Packet loss: %.0lf%%, Average RTT: %.2lf ms\n", packets_sent, MAX_NO_PACKETS, ((packets_sent - MAX_NO_PACKETS) * 100.0) / packets_sent, totalTime / MAX_NO_PACKETS);
    }
    else
    {
        printf("Ping test failed\n");
    }
    close(sockfd);
}

/* Example usage */
int main()
{
    ping_test("www.google.com");
    return 0;
}