//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
#include <net/if.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>

void process_packet(unsigned char *buffer, int size);

int main()
{
    int sock_raw;
    struct sockaddr_in saddr;
    unsigned char *buffer = (unsigned char *)malloc(65536);

    printf("Packet Monitoring Started...\n");

    sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);

    if (sock_raw < 0)
    {
        printf("Socket Error\n");
        return 1;
    }

    while (1)
    {
        int saddr_size = sizeof(saddr);
        int data_size = recvfrom(sock_raw, buffer, 65536, 0, (struct sockaddr *)&saddr, (socklen_t *)&saddr_size);

        if (data_size < 0)
        {
            printf("Recvfrom Error, Failed to get packets\n");
            return 1;
        }

        process_packet(buffer, data_size);
    }

    close(sock_raw);

    printf("Packet Monitoring Stopped\n");

    return 0;
}

void process_packet(unsigned char *buffer, int size)
{
    struct iphdr *iph = (struct iphdr *)(buffer + sizeof(struct ethhdr));
    unsigned short iphdrlen = iph->ihl * 4;

    struct tcphdr *tcph = (struct tcphdr *)(buffer + iphdrlen + sizeof(struct ethhdr));

    unsigned int source_port = ntohs(tcph->source);
    unsigned int dest_port = ntohs(tcph->dest);
    unsigned int source_ip = ntohl(iph->saddr);
    unsigned int dest_ip = ntohl(iph->daddr);

    printf("Source IP: %d.%d.%d.%d\n", (source_ip >> 24) & 0xff, (source_ip >> 16) & 0xff, (source_ip >> 8) & 0xff, source_ip & 0xff);
    printf("Destination IP: %d.%d.%d.%d\n", (dest_ip >> 24) & 0xff, (dest_ip >> 16) & 0xff, (dest_ip >> 8) & 0xff, dest_ip & 0xff);
    printf("Source Port: %u\n", source_port);
    printf("Destination Port: %u\n", dest_port);
    printf("\n");
}