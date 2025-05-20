//FormAI DATASET v1.0 Category: Firewall ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PACKET_SIZE 65535

// this function checks if the packet should be allowed or denied based on source and destination IP addresses
int check_packet(struct in_addr source_ip, struct in_addr dest_ip) {
    // insert your custom rules here
    if (strcmp(inet_ntoa(source_ip), "10.0.0.1") == 0) {
        printf("Packet denied: source IP is blacklisted\n");
        return 0;
    }
    if (strcmp(inet_ntoa(dest_ip), "192.168.1.1") == 0) {
        printf("Packet denied: destination IP is blacklisted\n");
        return 0;
    }
    // if the packet passes all rules, allow it
    printf("Packet allowed\n");
    return 1;
}

int main() {
    // create socket to receive packets
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    // set socket options to receive all IP packets
    const int one = 1;
    if (setsockopt(sock, IPPROTO_IP, IP_HDRINCL, &one, sizeof(one)) < 0) {
        perror("setsockopt");
        exit(1);
    }

    // bind socket to any interface and port
    struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = 0;
    sin.sin_addr.s_addr = INADDR_ANY;
    if (bind(sock, (struct sockaddr*)&sin, sizeof(sin)) < 0) {
        perror("bind");
        exit(1);
    }

    // receive packets
    char packet_buffer[MAX_PACKET_SIZE];
    struct sockaddr_in sin_remote;
    socklen_t sin_remote_len = sizeof(sin_remote);
    while (1) {
        int packet_size = recvfrom(sock, packet_buffer, MAX_PACKET_SIZE, 0, (struct sockaddr*)&sin_remote, &sin_remote_len);
        if (packet_size < 0) {
            perror("recvfrom");
            exit(1);
        }

        // extract source and destination IP addresses from IP packet header
        struct in_addr source_ip, dest_ip;
        memcpy(&source_ip, packet_buffer + 12, sizeof(source_ip));
        memcpy(&dest_ip, packet_buffer + 16, sizeof(dest_ip));

        // check if packet should be allowed or denied
        if (!check_packet(source_ip, dest_ip)) {
            printf("Packet dropped\n");
            continue;
        }

        // packet passed all checks, forward it to destination
        if (sendto(sock, packet_buffer, packet_size, 0, (struct sockaddr*)&sin_remote, sin_remote_len) < 0) {
            perror("sendto");
            exit(1);
        }
    }

    return 0;
}