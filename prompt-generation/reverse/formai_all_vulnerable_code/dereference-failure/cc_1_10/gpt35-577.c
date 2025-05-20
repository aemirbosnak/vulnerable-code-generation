//FormAI DATASET v1.0 Category: Firewall ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<netinet/ip.h>
#include<netinet/tcp.h>
#include<netinet/udp.h>
#include<arpa/inet.h>

#define RST 1
#define ACK 2
#define FIN 4

int main() {
    printf("Welcome to my unique Firewall program!\n");

    //Creating raw socket to receive packets
    int sock_fd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sock_fd < 0) {
        printf("Error: Raw socket creation failed!!\nExiting...");
        return -1;
    }

    //Buffer to receive incoming packets
    unsigned char *buffer = (unsigned char *)malloc(65536);
    memset(buffer, 0, 65536);

    //Variables for tracking incoming packet details
    struct sockaddr_in incoming_addr;
    int incoming_size = sizeof(incoming_addr);
    struct iphdr *ip = (struct iphdr *)buffer;
    struct tcphdr *tcp = (struct tcphdr *)(buffer + sizeof(struct iphdr));

    printf("Firewall is up and running!\n");

    while(1) {
        //Receiving incoming packets
        int data_size = recvfrom(sock_fd, buffer, 65536, 0, (struct sockaddr *)&incoming_addr, (socklen_t*)&incoming_size);
        if (data_size < 0) {
            printf("Error: Packet reception failed!!\n");
            continue;
        }

        //Checking if the packet is TCP
        if (ip->protocol == IPPROTO_TCP) {
            printf("Incoming packet is TCP!\n");

            //Getting source and destination addresses
            char src_addr[INET_ADDRSTRLEN], dst_addr[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &(ip->saddr), src_addr, INET_ADDRSTRLEN);
            inet_ntop(AF_INET, &(ip->daddr), dst_addr, INET_ADDRSTRLEN);
            printf("Source IP : %s\n", src_addr);
            printf("Destination IP : %s\n", dst_addr);

            //Getting source and destination ports
            int src_port = ntohs(tcp->source);
            int dst_port = ntohs(tcp->dest);
            printf("Source Port : %d\n", src_port);
            printf("Destination Port : %d\n", dst_port);

            //Checking if the packet is originating from a certain IP address
            if (strcmp(src_addr, "192.168.0.1") == 0) {
                printf("Packet originating from 192.168.0.1 is blocked!\n");

                //Blocking the packet by sending a RST packet to the destination
                printf("Sending RST packet to block incoming packet...\n");

                //Creating raw socket for sending packets
                int send_sock_fd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
                if (send_sock_fd < 0) {
                    printf("Error: Raw socket creation failed!!\n");
                    continue;
                }

                //Setting up destination address for RST packet
                struct sockaddr_in dst;
                memset((char *)&dst, 0, sizeof(dst));
                dst.sin_family = AF_INET;
                dst.sin_addr.s_addr = inet_addr(dst_addr);
                dst.sin_port = htons(dst_port);

                //Building RST packet
                unsigned char rst_packet[65536];
                memset(rst_packet, 0, 65536);
                struct iphdr *ip_rst = (struct iphdr *)rst_packet;
                struct tcphdr *tcp_rst = (struct tcphdr *)(rst_packet + sizeof(struct iphdr));

                //Populating IP header fields
                ip_rst->ihl = 5;
                ip_rst->version = 4;
                ip_rst->id = htons(rand());
                ip_rst->ttl = 64;
                ip_rst->protocol = IPPROTO_TCP;
                ip_rst->saddr = inet_addr(src_addr);
                ip_rst->daddr = inet_addr(dst_addr);

                //Populating TCP header fields
                tcp_rst->source = htons(src_port);
                tcp_rst->dest = htons(dst_port);
                tcp_rst->seq = tcp->seq;
                tcp_rst->ack_seq = tcp->ack_seq;
                tcp_rst->doff = 5;
                tcp_rst->syn = 0;
                tcp_rst->ack = 1;
                tcp_rst->rst = 1;
                tcp_rst->window = htons(512);

                //Calculating TCP checksum
                unsigned short tcp_length = sizeof(struct tcphdr);
                tcp_rst->check = 0;
                unsigned short tcp_check = 0;
                unsigned short *ptr = (unsigned short *)tcp_rst;
                for (int i = 0; i < tcp_length/2; i++) {
                    tcp_check += htons(*(ptr + i));
                }
                tcp_rst->check = htons(~tcp_check);

                //Calculating IP checksum
                ip_rst->check = 0;
                unsigned short ip_check = 0;
                ptr = (unsigned short *)ip_rst;
                for (int i = 0; i < (ip_rst->ihl)*2; i++) {
                    ip_check += htons(*(ptr + i));
                }
                ip_rst->check = htons(~ip_check);

                //Sending RST packet
                int res = sendto(send_sock_fd, rst_packet, sizeof(struct iphdr) + sizeof(struct tcphdr), 0, (struct sockaddr *)&dst, sizeof(dst));
                if (res < 0) {
                    printf("Error: RST packet send failed!!\n");
                }
                else {
                    printf("Packet blocked successfully!\n");
                }

                //Closing send socket
                close(send_sock_fd);
            }
        }
    }
    return 0;
}