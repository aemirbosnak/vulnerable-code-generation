//FormAI DATASET v1.0 Category: Firewall ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>

// Define your allowed IP addresses here
#define ALLOWED_IP "192.168.10.23"
#define ALLOWED_IP2 "10.0.0.50"

// Define your allowed ports here
#define ALLOWED_PORT 80
#define ALLOWED_PORT2 22

// Custom function to handle incoming packets
void handle_packet(unsigned char* buffer, int size) {
    struct iphdr *ip = (struct iphdr*)buffer;
    if (ip->protocol == IPPROTO_TCP || ip->protocol == IPPROTO_UDP) {
        struct sockaddr_in src, dest;
        memset(&src, 0, sizeof(src));
        memset(&dest, 0, sizeof(dest));
        src.sin_addr.s_addr = ip->saddr;
        dest.sin_addr.s_addr = ip->daddr;
        if (ip->protocol == IPPROTO_TCP) {
            struct tcphdr *tcp = (struct tcphdr*)(buffer + sizeof(struct iphdr));
            printf("TCP packet: %s:%d > %s:%d\n", inet_ntoa(src.sin_addr), ntohs(tcp->source), inet_ntoa(dest.sin_addr), ntohs(tcp->dest));
            // Check if packet matches our allowed IPs and ports
            if ((strcmp(inet_ntoa(src.sin_addr), ALLOWED_IP) == 0 || strcmp(inet_ntoa(src.sin_addr), ALLOWED_IP2) == 0)
                && (ntohs(tcp->dest) == ALLOWED_PORT || ntohs(tcp->dest) == ALLOWED_PORT2)) {
                printf("ALLOWED\n");
            } else {
                printf("BLOCKED\n");
            }
        } else {
            struct udphdr *udp = (struct udphdr*)(buffer + sizeof(struct iphdr));
            printf("UDP packet: %s:%d > %s:%d\n", inet_ntoa(src.sin_addr), ntohs(udp->source), inet_ntoa(dest.sin_addr), ntohs(udp->dest));
            // Check if packet matches our allowed IPs and ports
            if ((strcmp(inet_ntoa(src.sin_addr), ALLOWED_IP) == 0 || strcmp(inet_ntoa(src.sin_addr), ALLOWED_IP2) == 0)
                && (ntohs(udp->dest) == ALLOWED_PORT || ntohs(udp->dest) == ALLOWED_PORT2)) {
                printf("ALLOWED\n");
            } else {
                printf("BLOCKED\n");
            }
        }
    }
}

int main() {
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_TCP|IPPROTO_UDP);
    if (sock == -1) {
        printf("Error creating socket!\n");
        exit(1);
    }
    // Set socket to not receive its own packets
    setsockopt(sock, IPPROTO_IP, IP_HDRINCL, &(int){1}, sizeof(int));
    setsockopt(sock, IPPROTO_IP, IP_MULTICAST_LOOP, &(int){0}, sizeof(int));
    // Bind socket to specified address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("YOUR_IP_ADDRESS_HERE");
    if (bind(sock, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        printf("Error binding socket!\n");
        exit(1);
    }
    // Receive packets
    unsigned char buffer[65536];
    while (1) {
        int len = recv(sock, buffer, 65536, 0);
        if (len > 0) {
            handle_packet(buffer, len);
        } else {
            printf("Error receiving packet: %s\n", strerror(errno));
        }
    }
    return 0;
}