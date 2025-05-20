//FormAI DATASET v1.0 Category: Firewall ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <unistd.h>

#define TCP_PROTOCOL 6

int main(int argc, char *argv[])
{
    int sock_raw;
    struct sockaddr_in saddr;
    struct ifreq ifr;
    char *interface = "eth0";
    unsigned char *buffer = malloc(65536);
    int ret_val, i;

    // Create a raw socket that will listen for incoming traffic on TCP port 80
    sock_raw = socket(AF_INET, SOCK_RAW, TCP_PROTOCOL);
    if (sock_raw < 0) {
        perror("Socket Error");
        return 1;
    }

    // Set interface to listen on
    strncpy(ifr.ifr_name, interface, IFNAMSIZ);
    if (setsockopt(sock_raw, SOL_SOCKET, SO_BINDTODEVICE, (void *)&ifr, sizeof(ifr)) < 0) {
        perror("setsockopt(SO_BINDTODEVICE) failed");
        return 1;
    }

    while (1) {
        memset(buffer, 0, 65536);
        ret_val = recvfrom(sock_raw, buffer, 65536, 0, NULL, NULL);
        if (ret_val < 0) {
            perror("Failed to receive packet");
            return 1;
        } else {
            struct iphdr *ip_header = (struct iphdr *)buffer;
            if (ip_header->protocol == TCP_PROTOCOL) {
                struct tcphdr *tcp_header = (struct tcphdr *)(buffer + ip_header->ihl * 4);
                if (ntohs(tcp_header->dest) == 80) {
                    printf("Received a TCP packet on port 80\n");
                    printf("Source IP: %s\n", inet_ntoa(*(struct in_addr *)&ip_header->saddr));
                    printf("Destination IP: %s\n", inet_ntoa(*(struct in_addr *)&ip_header->daddr));
                    printf("Source Port: %d\n", ntohs(tcp_header->source));
                    printf("Destination Port: %d\n", ntohs(tcp_header->dest));
                }
            }
        }
    }

    return 0;
}