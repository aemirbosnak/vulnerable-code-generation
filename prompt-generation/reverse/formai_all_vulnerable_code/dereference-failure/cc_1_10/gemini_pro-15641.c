//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

// Let's start with a global constant that defines the size of the ICMP packet we'll be sending.
#define ICMP_PACKET_SIZE 64

// Now, let's define the ICMP header structure.
struct icmp_header {
    unsigned char type;
    unsigned char code;
    unsigned short checksum;
    unsigned short id;
    unsigned short seq;
    char data[ICMP_PACKET_SIZE - 8];
};

// Here's a function that calculates the checksum of an ICMP packet.
unsigned short calculate_checksum(struct icmp_header *icmp_header) {
    unsigned long sum = 0;
    unsigned short *words = (unsigned short *)icmp_header;
    int words_count = sizeof(struct icmp_header) / sizeof(unsigned short);

    for (int i = 0; i < words_count; i++) {
        sum += words[i];
    }

    while (sum >> 16) {
        sum = (sum >> 16) + (sum & 0xffff);
    }

    return ~sum;
}

// Let's define a function that creates an ICMP packet.
struct icmp_header *create_icmp_packet() {
    struct icmp_header *icmp_header = malloc(sizeof(struct icmp_header));

    icmp_header->type = 8; // Echo request
    icmp_header->code = 0;
    icmp_header->checksum = 0; // We'll calculate the checksum later
    icmp_header->id = getpid(); // Process ID is used as the identifier
    icmp_header->seq = 0; // Sequence number is initialized to 0
    memset(icmp_header->data, 0, ICMP_PACKET_SIZE - 8); // Data is zeroed out

    return icmp_header;
}

// We'll need a function that sends an ICMP packet to a specified destination.
int send_icmp_packet(struct icmp_header *icmp_header, char *destination_ip) {
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    struct sockaddr_in destination_address;
    memset(&destination_address, 0, sizeof(destination_address));
    destination_address.sin_family = AF_INET;
    destination_address.sin_addr.s_addr = inet_addr(destination_ip);

    // Let's calculate the checksum of the ICMP packet.
    icmp_header->checksum = calculate_checksum(icmp_header);

    // Now, we send the ICMP packet.
    int bytes_sent = sendto(sockfd, icmp_header, sizeof(struct icmp_header), 0, (struct sockaddr *)&destination_address, sizeof(destination_address));
    if (bytes_sent < 0) {
        perror("sendto");
        return -1;
    }

    close(sockfd);

    return 0;
}

// Let's define a function that receives an ICMP packet and checks if it's a reply to our request.
int receive_icmp_packet(struct icmp_header *icmp_header) {
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    struct sockaddr_in source_address;
    socklen_t source_address_length = sizeof(source_address);

    // Let's wait for a reply.
    int bytes_received = recvfrom(sockfd, icmp_header, sizeof(struct icmp_header), 0, (struct sockaddr *)&source_address, &source_address_length);
    if (bytes_received < 0) {
        perror("recvfrom");
        return -1;
    }

    close(sockfd);

    // Now, let's check if the received packet is a reply to our request.
    if (icmp_header->type == 0 && icmp_header->code == 0 && icmp_header->id == getpid()) {
        return 0;
    } else {
        return -1;
    }
}

// Let's put it all together in a main function.
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <destination_ip>\n", argv[0]);
        return 1;
    }

    char *destination_ip = argv[1];

    struct icmp_header *icmp_header = create_icmp_packet();

    int sent = send_icmp_packet(icmp_header, destination_ip);
    if (sent < 0) {
        perror("send_icmp_packet");
        return 1;
    }

    int received = receive_icmp_packet(icmp_header);
    if (received < 0) {
        perror("receive_icmp_packet");
        return 1;
    }

    printf("Ping successful to %s\n", destination_ip);

    free(icmp_header);

    return 0;
}