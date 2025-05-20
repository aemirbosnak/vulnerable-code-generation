//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <netinet/in.h>
#include <netinet/ether.h>
#include <sys/ioctl.h>
#include <net/if.h>

#define MAX_PACKET_SIZE 65536

// The main function
int main(int argc, char *argv[]) {
    int sockfd;
    int sockopt;
    int pkt_recv = 0;
    struct sockaddr_in raw_addr;
    struct ifreq ifr;
    char *interface = NULL;
    char packet[MAX_PACKET_SIZE];

    // create raw socket
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) == -1) {
        perror("Failed to create raw socket!");
        exit(1);
    }

    // set socket option
    sockopt = 1;
    if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &sockopt, sizeof(sockopt)) < 0) {
        perror("Failed to set socket option!");
        exit(1);
    }

    // set interface name
    if (argc > 1) {
        interface = argv[1];
    } else {
        interface = "eth0";
    }
    strncpy(ifr.ifr_name, interface, strlen(interface));
    if (ioctl(sockfd, SIOCGIFINDEX, &ifr) < 0) {
        perror("Failed to get interface index!");
        exit(1);
    }

    // bind socket to interface
    memset(&raw_addr, 0, sizeof(raw_addr));
    raw_addr.sin_family = AF_INET;
    raw_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    raw_addr.sin_port = htons(0);
    raw_addr.sin_addr.s_addr = ((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr.s_addr;
    if (bind(sockfd, (struct sockaddr *)&raw_addr, sizeof(raw_addr)) == -1) {
        perror("Failed to bind socket!");
        exit(1);
    }

    // receive packets
    while (1) {
        int length;
        struct sockaddr saddr;
        int saddr_len = sizeof(saddr);
        length = recvfrom(sockfd, packet, MAX_PACKET_SIZE, 0, &saddr, &saddr_len);
        pkt_recv++;
        printf("Packet Received From %s\t Packets Received: %d\n", inet_ntoa(*(struct in_addr *)&saddr), pkt_recv);
    }

    // close socket
    close(sockfd);
    return 0;
}