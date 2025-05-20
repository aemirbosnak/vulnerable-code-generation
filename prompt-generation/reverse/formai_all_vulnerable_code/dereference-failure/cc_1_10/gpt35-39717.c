//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <netinet/in.h>
#include <linux/if_ether.h>
#include <linux/if_packet.h>
#include <linux/ip.h>
#include <linux/tcp.h>

#define MAX_PACKET_SIZE 65536
#define QOS_THRESHOLD 1000000

int main(int argc, char *argv[]) {
    int sock, ifindex, rv, i;
    struct ifreq ifr;
    struct sockaddr_ll saddr;
    char packet_buffer[MAX_PACKET_SIZE];
    struct iphdr *iph;
    struct tcphdr *tcph;
    uint32_t source_ip, dest_ip;
    uint16_t source_port, dest_port;
    float qos, total_qos = 0;
    
    if (argc != 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        exit(1);
    }
    
    // Open RAW socket
    sock = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_IP));
    if (sock < 0) {
        perror("socket");
        exit(1);
    }
    
    // Get interface index
    memset(&ifr, 0, sizeof(ifr));
    strncpy(ifr.ifr_name, argv[1], IFNAMSIZ - 1);
    ioctl(sock, SIOCGIFINDEX, &ifr);
    ifindex = ifr.ifr_ifindex;
    
    // Bind socket to interface
    memset(&saddr, 0, sizeof(saddr));
    saddr.sll_family = AF_PACKET;
    saddr.sll_protocol = htons(ETH_P_IP);
    saddr.sll_ifindex = ifindex;
    bind(sock, (struct sockaddr *) &saddr, sizeof(saddr));
    
    while (1) {
        // Receive packet
        rv = recv(sock, packet_buffer, MAX_PACKET_SIZE, 0);
        if (rv < 0) {
            perror("recv");
            exit(1);
        }
        
        // Handle IP packet
        iph = (struct iphdr *) (packet_buffer + sizeof(struct ethhdr));
        source_ip = ntohl(iph->saddr);
        dest_ip = ntohl(iph->daddr);
        
        if (iph->protocol == IPPROTO_TCP) {
            // Handle TCP packet
            tcph = (struct tcphdr *) (packet_buffer + sizeof(struct ethhdr) + sizeof(struct iphdr));
            source_port = ntohs(tcph->source);
            dest_port = ntohs(tcph->dest);
            
            // Calculate QoS
            qos = ((float) (ntohl(iph->tot_len) / (float) rv)) / 1000000.0;
            total_qos += qos;
            
            // Print packet details
            printf("Source IP: %d.%d.%d.%d:%d, Dest IP: %d.%d.%d.%d:%d, QoS: %f\n",
                   (source_ip >> 24) & 0xFF, (source_ip >> 16) & 0xFF, (source_ip >> 8) & 0xFF, source_ip & 0xFF, source_port,
                   (dest_ip >> 24) & 0xFF, (dest_ip >> 16) & 0xFF, (dest_ip >> 8) & 0xFF, dest_ip & 0xFF, dest_port, qos);
            
            // Check QoS threshold
            if (total_qos > QOS_THRESHOLD) {
                printf("QoS threshold exceeded! Total QoS: %f\n", total_qos);
                exit(1);
            }
        }
    }
    
    return 0;
}