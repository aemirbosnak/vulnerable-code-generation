//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define MAX_PACKET_SIZE 65535

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    // Check the command-line arguments
    if (argc < 2) {
        fprintf(stderr, "USAGE: %s [port]\n", argv[0]);
        exit(1);
    }

    // Create a raw socket to read IP packets
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_IP);
    if (sock < 0) {
        error("socket() failed");
    }

    // Set socket option to receive IP header in the packet
    int on = 1;
    if (setsockopt(sock, IPPROTO_IP, IP_HDRINCL, &on, sizeof(on)) < 0) {
        error("setsockopt() failed");
    }

    // Create a UDP socket to send packet to multicast group
    int sock_mcast = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock_mcast < 0) {
        error("socket() failed");
    }

    // Set socket option to allow multiple programs to listen on the same port
    int reuse = 1;
    if (setsockopt(sock_mcast, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0) {
        error("setsockopt() failed");
    }

    // Create a socket address for multicast group
    struct sockaddr_in mcast_addr;
    memset(&mcast_addr, 0, sizeof(mcast_addr));
    mcast_addr.sin_family = AF_INET;
    mcast_addr.sin_addr.s_addr = inet_addr("239.0.0.1");
    mcast_addr.sin_port = htons(atoi(argv[1]));

    // Bind the UDP socket to the multicast group address
    if (bind(sock_mcast, (struct sockaddr *)&mcast_addr, sizeof(mcast_addr)) < 0) {
        error("bind() failed");
    }

    // Join the multicast group
    struct ip_mreq mreq;
    memset(&mreq, 0, sizeof(mreq));
    mreq.imr_multiaddr.s_addr = inet_addr("239.0.0.1");
    mreq.imr_interface.s_addr = htonl(INADDR_ANY);
    if (setsockopt(sock_mcast, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq)) < 0) {
        error("setsockopt() failed");
    }

    // Continuously read packets and send to multicast group
    while (1) {
        unsigned char buffer[MAX_PACKET_SIZE];
        struct sockaddr_in source;
        socklen_t sourcelen = sizeof(source);
        ssize_t packetlen = recvfrom(sock, buffer, MAX_PACKET_SIZE, 0, (struct sockaddr *)&source, &sourcelen);
        if (packetlen < 0) {
            error("recvfrom() failed");
        }

        // Extract IP and TCP headers from packet
        struct iphdr *iph = (struct iphdr *)(buffer);
        if (iph->version == 4 && iph->protocol == IPPROTO_TCP) {
            struct tcphdr *tcph = (struct tcphdr *)(buffer + iph->ihl * 4);

            // Print packet details
            char source_ip[INET_ADDRSTRLEN];
            char dest_ip[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &iph->saddr, source_ip, INET_ADDRSTRLEN);
            inet_ntop(AF_INET, &iph->daddr, dest_ip, INET_ADDRSTRLEN);
            printf("Packet from %s:%u to %s:%u (length %ld)\n", source_ip, ntohs(tcph->source), dest_ip, ntohs(tcph->dest), packetlen);

            // Send packet to multicast group
            if (sendto(sock_mcast, buffer, packetlen, 0, (struct sockaddr *)&mcast_addr, sizeof(mcast_addr)) < 0) {
                error("sendto() failed");
            }
        }
    }

    // Close sockets
    close(sock);
    close(sock_mcast);

    return 0;
}