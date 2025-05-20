//FormAI DATASET v1.0 Category: Firewall ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <sys/socket.h>

// Function to compare IP address and port number
int match_rule(char *ip, int port) {
    // Define the allowed IP addresses and port numbers
    char *allowed_ips[3] = {"192.168.1.1", "10.0.0.1", "172.16.0.1"};
    int allowed_ports[3] = {80, 443, 22};
    int i;

    // Check if IP address is allowed
    for (i = 0; i < 3; i++) {
        if (strcmp(ip, allowed_ips[i]) == 0) {
            break;
        }
    }
    if (i == 3) {
        return 0;
    }

    // Check if port number is allowed
    for (i = 0; i < 3; i++) {
        if (port == allowed_ports[i]) {
            break;
        }
    }
    if (i == 3) {
        return 0;
    }

    // If IP address and port are allowed, return 1
    return 1;
}

// Function to check incoming packets
void check_packet(unsigned char *buffer, int size) {
    struct iphdr *ip = (struct iphdr *)(buffer);
    struct sockaddr_in source, dest;
    unsigned short iphdrlen;

    // Extract IP header length
    iphdrlen = ip->ihl*4;
    if (iphdrlen < 20) {
        printf("Invalid IP header length: %d\n", iphdrlen);
        return;
    }

    // Get source and destination IP address
    memset(&source, 0, sizeof(source));
    source.sin_addr.s_addr = ip->saddr;
    memset(&dest, 0, sizeof(dest));
    dest.sin_addr.s_addr = ip->daddr;

    // Check if IP address is allowed
    if (!match_rule(inet_ntoa(source.sin_addr), ntohs(ip->protocol))) {
        printf("Blocked packet from %s\n", inet_ntoa(source.sin_addr));
        return;
    }

    // Check if packet is TCP or UDP
    if (ip->protocol == IPPROTO_TCP) {
        struct tcphdr *tcp = (struct tcphdr *)(buffer + iphdrlen);
        printf("Incoming TCP packet from %s:%d to %s:%d\n", inet_ntoa(source.sin_addr), ntohs(tcp->source), inet_ntoa(dest.sin_addr), ntohs(tcp->dest));
    } else if (ip->protocol == IPPROTO_UDP) {
        struct udphdr *udp = (struct udphdr *)(buffer + iphdrlen);
        printf("Incoming UDP packet from %s:%d to %s:%d\n", inet_ntoa(source.sin_addr), ntohs(udp->source), inet_ntoa(dest.sin_addr), ntohs(udp->dest));
    } else {
        printf("Unknown protocol: %d\n", ip->protocol);
    }
}

int main() {
    int sock_raw, saddr_size, data_size;
    struct sockaddr saddr;
    unsigned char *buffer = (unsigned char *)malloc(65536);
    
    // Create raw socket
    sock_raw = socket(AF_INET , SOCK_RAW , IPPROTO_RAW);
    if (sock_raw < 0) {
        printf("Failed to create raw socket\n");
        return 1;
    }

    // Loop to check for incoming packets
    while (1) {
        saddr_size = sizeof(saddr);
        data_size = recvfrom(sock_raw, buffer, 65536, 0, &saddr, (socklen_t*)&saddr_size);
        if (data_size < 0) {
            printf("Failed to receive incoming packet\n");
            return 1;
        }
        check_packet(buffer, data_size);
    }

    return 0;
}