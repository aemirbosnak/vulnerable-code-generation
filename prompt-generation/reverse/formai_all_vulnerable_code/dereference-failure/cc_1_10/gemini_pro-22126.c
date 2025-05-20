//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

/* Ethernet header */
struct eth_header {
        unsigned char dst[6];  /* Destination MAC address */
        unsigned char src[6];  /* Source MAC address */
        unsigned short ether_type;  /* EtherType */
};

/* IP header */
struct ip_header {
        unsigned char ip_hdr_len:4;      /* IP header length */
        unsigned char ip_version:4;       /* IP version */
        unsigned char ip_tos;        /* Type of service */
        unsigned short ip_len;       /* IP packet length */
        unsigned short ip_id;        /* IP identification */
        unsigned short ip_offset;     /* IP fragment offset */
        unsigned char ip_ttl;        /* IP time to live */
        unsigned char ip_protocol;    /* IP protocol */
        unsigned short ip_csum;       /* IP checksum */
        unsigned int ip_src_addr;     /* IP source address */
        unsigned int ip_dst_addr;     /* IP destination address */
};

/* TCP header */
struct tcp_header {
        unsigned short tcp_src_port;    /* TCP source port */
        unsigned short tcp_dst_port;    /* TCP destination port */
        unsigned int tcp_seq_num;     /* TCP sequence number */
        unsigned int tcp_ack_num;     /* TCP acknowledgement number */
        unsigned char tcp_hdr_len:4;      /* TCP header length */
        unsigned char tcp_flags:4;       /* TCP flags */
        unsigned short tcp_window;      /* TCP window size */
        unsigned short tcp_csum;       /* TCP checksum */
        unsigned short tcp_urg_ptr;     /* TCP urgent pointer */
};

/* Function to print Ethernet header */
void print_eth_header(struct eth_header *eth) {
        printf("Ethernet Header:\n");
        printf("Destination MAC: %.2X:%.2X:%.2X:%.2X:%.2X:%.2X\n", eth->dst[0], eth->dst[1], eth->dst[2], eth->dst[3], eth->dst[4], eth->dst[5]);
        printf("Source MAC: %.2X:%.2X:%.2X:%.2X:%.2X:%.2X\n", eth->src[0], eth->src[1], eth->src[2], eth->src[3], eth->src[4], eth->src[5]);
        printf("EtherType: %.4X\n", ntohs(eth->ether_type));
}

/* Function to print IP header */
void print_ip_header(struct ip_header *ip) {
        printf("IP Header:\n");
        printf("IP Version: %d\n", ip->ip_version);
        printf("IP Header Length: %d bytes\n", ip->ip_hdr_len * 4);
        printf("IP Type of Service: %d\n", ip->ip_tos);
        printf("IP Packet Length: %d bytes\n", ntohs(ip->ip_len));
        printf("IP Identification: %d\n", ntohs(ip->ip_id));
        printf("IP Fragment Offset: %d\n", ntohs(ip->ip_offset));
        printf("IP Time to Live: %d\n", ip->ip_ttl);
        printf("IP Protocol: %d\n", ip->ip_protocol);
        printf("IP Checksum: %d\n", ntohs(ip->ip_csum));
        printf("IP Source Address: %s\n", inet_ntoa(*(struct in_addr *)&ip->ip_src_addr));
        printf("IP Destination Address: %s\n", inet_ntoa(*(struct in_addr *)&ip->ip_dst_addr));
}

/* Function to print TCP header */
void print_tcp_header(struct tcp_header *tcp) {
        printf("TCP Header:\n");
        printf("TCP Source Port: %d\n", ntohs(tcp->tcp_src_port));
        printf("TCP Destination Port: %d\n", ntohs(tcp->tcp_dst_port));
        printf("TCP Sequence Number: %d\n", ntohl(tcp->tcp_seq_num));
        printf("TCP Acknowledgement Number: %d\n", ntohl(tcp->tcp_ack_num));
        printf("TCP Header Length: %d bytes\n", tcp->tcp_hdr_len * 4);
        printf("TCP Flags: %d\n", tcp->tcp_flags);
        printf("TCP Window Size: %d\n", ntohs(tcp->tcp_window));
        printf("TCP Checksum: %d\n", ntohs(tcp->tcp_csum));
        printf("TCP Urgent Pointer: %d\n", ntohs(tcp->tcp_urg_ptr));
}

/* Main function */
int main() {
        // Open the network device
        char *dev = "eth0";
        pcap_t *handle = pcap_open_live(dev, BUFSIZ, 1, 1000, NULL);
        if (handle == NULL) {
                fprintf(stderr, "Couldn't open device %s: %s\n", dev, pcap_geterr(handle));
                return EXIT_FAILURE;
        }

        // Capture packets
        struct pcap_pkthdr *header;
        const unsigned char *packet;
        while (1) {
                int res = pcap_next_ex(handle, &header, &packet);
                if (res == 0) continue;
                if (res == -1) {
                        fprintf(stderr, "Error capturing packets: %s\n", pcap_geterr(handle));
                        break;
                }

                // Get the Ethernet header
                struct eth_header *eth = (struct eth_header *)packet;

                // Check if it's an IP packet
                if (ntohs(eth->ether_type) == 0x0800) {
                        // Get the IP header
                        struct ip_header *ip = (struct ip_header *)(packet + sizeof(struct eth_header));

                        // Check if it's a TCP packet
                        if (ip->ip_protocol == 6) {
                                // Get the TCP header
                                struct tcp_header *tcp = (struct tcp_header *)(packet + sizeof(struct eth_header) + sizeof(struct ip_header));

                                // Print the headers
                                print_eth_header(eth);
                                print_ip_header(ip);
                                print_tcp_header(tcp);
                        }
                }
        }

        // Close the device
        pcap_close(handle);
        return 0;
}