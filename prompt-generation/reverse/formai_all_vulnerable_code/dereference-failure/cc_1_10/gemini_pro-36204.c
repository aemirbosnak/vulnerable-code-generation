//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/if_packet.h>
#include <linux/if_ether.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/udp.h>

#define MAX_PACKET_SIZE 65535
#define PROMISCUOUS_MODE 1

// Ethernet header structure
struct eth_header {
    unsigned char dst_mac[ETH_ALEN];
    unsigned char src_mac[ETH_ALEN];
    unsigned short type;
};

// IP header structure
struct ip_header {
    unsigned char version_and_header_length;
    unsigned char type_of_service;
    unsigned short total_length;
    unsigned short identification;
    unsigned short flags_and_fragment_offset;
    unsigned char time_to_live;
    unsigned char protocol;
    unsigned short header_checksum;
    unsigned int source_ip_address;
    unsigned int destination_ip_address;
};

// UDP header structure
struct udp_header {
    unsigned short source_port;
    unsigned short destination_port;
    unsigned short length;
    unsigned short checksum;
};

// Packet structure
struct packet {
    struct eth_header eth;
    struct ip_header ip;
    struct udp_header udp;
    unsigned char data[MAX_PACKET_SIZE - sizeof(struct eth_header) - sizeof(struct ip_header) - sizeof(struct udp_header)];
};

// Thread function
void *thread_function(void *arg) {
    // Get the socket descriptor
    int sockfd = *(int *)arg;

    // Allocate memory for the packet
    struct packet *packet = malloc(sizeof(struct packet));

    // Receive a packet
    int n = recvfrom(sockfd, packet, MAX_PACKET_SIZE, 0, NULL, NULL);
    if (n < 0) {
        perror("recvfrom()");
        free(packet);
        return NULL;
    }

    // Check if the packet is an ARP packet
    if (packet->eth.type == htons(ETH_P_ARP)) {
        // Print the ARP packet
        printf("ARP packet received:\n");
        printf("  Source MAC address: %02x:%02x:%02x:%02x:%02x:%02x\n", packet->eth.src_mac[0], packet->eth.src_mac[1], packet->eth.src_mac[2], packet->eth.src_mac[3], packet->eth.src_mac[4], packet->eth.src_mac[5]);
        printf("  Destination MAC address: %02x:%02x:%02x:%02x:%02x:%02x\n", packet->eth.dst_mac[0], packet->eth.dst_mac[1], packet->eth.dst_mac[2], packet->eth.dst_mac[3], packet->eth.dst_mac[4], packet->eth.dst_mac[5]);
        printf("  Sender IP address: %d.%d.%d.%d\n", (packet->data[7] & 0xFF), (packet->data[8] & 0xFF), (packet->data[9] & 0xFF), (packet->data[10] & 0xFF));
        printf("  Target IP address: %d.%d.%d.%d\n", (packet->data[11] & 0xFF), (packet->data[12] & 0xFF), (packet->data[13] & 0xFF), (packet->data[14] & 0xFF));
    }

    // Free the packet
    free(packet);

    return NULL;
}

int main(int argc, char **argv) {
    // Get the interface name
    char *interface = argv[1];

    // Create a raw socket
    int sockfd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (sockfd < 0) {
        perror("socket()");
        return -1;
    }

    // Set the socket to promiscuous mode
    int on = 1;
    if (setsockopt(sockfd, SOL_PACKET, PACKET_ADD_MEMBERSHIP, &on, sizeof(on)) < 0) {
        perror("setsockopt()");
        return -1;
    }

    // Bind the socket to the interface
    struct sockaddr_ll sll;
    memset(&sll, 0, sizeof(sll));
    sll.sll_family = AF_PACKET;
    sll.sll_protocol = htons(ETH_P_ALL);
    sll.sll_ifindex = if_nametoindex(interface);
    if (bind(sockfd, (struct sockaddr *)&sll, sizeof(sll)) < 0) {
        perror("bind()");
        return -1;
    }

    // Create a thread to receive packets
    pthread_t thread;
    pthread_create(&thread, NULL, thread_function, &sockfd);

    // Wait for the thread to finish
    pthread_join(thread, NULL);

    // Close the socket
    close(sockfd);

    return 0;
}