//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <net/if.h>

#define MAX_PACKET_LENGTH 65535

int main () {
    int sockfd;
    ssize_t packet_size;
    char packet_buffer[MAX_PACKET_LENGTH];

    struct sockaddr_in address;
    struct sockaddr_in source_address;
    struct iphdr *ip_header;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sockfd < 0) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        fprintf(stderr, "Error binding socket: %s\n", strerror(errno));
        exit(1);
    }

    printf("Listening for network packets...\n");

    while (1) {
        packet_size = recvfrom(sockfd, packet_buffer, MAX_PACKET_LENGTH, 0, NULL, NULL);
        if (packet_size < 0) {
            fprintf(stderr, "Error receiving packet: %s\n", strerror(errno));
            continue;
        }

        ip_header = (struct iphdr *) packet_buffer;
        memset(&source_address, 0, sizeof(source_address));
        source_address.sin_addr.s_addr = ip_header->saddr;

        printf("Received packet from %s\n", inet_ntoa(source_address.sin_addr));
    }

    return 0;
}