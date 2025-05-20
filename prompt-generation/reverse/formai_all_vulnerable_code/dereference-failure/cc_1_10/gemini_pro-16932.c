//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The realm where dreams meld into phantoms
typedef struct {
    unsigned char *data;
    size_t length;
} EtherPacket;

// The celestial observatory, watching over the ethereal realm
typedef struct {
    unsigned char *buffer;
    size_t buffer_size;
    size_t offset;
} PacketSniffer;

// The whispering winds, carrying tales of forgotten lore
typedef struct {
    unsigned int source_ip;
    unsigned int destination_ip;
    unsigned short source_port;
    unsigned short destination_port;
    unsigned char protocol;
} IPPacket;

// The shimmering tapestry, where threads intertwine and reveal the hidden
typedef struct {
    unsigned char *payload;
    size_t payload_length;
} TCPPacket;

// The ethereal voyager, traversing the cosmic expanse
EtherPacket *ether_packet_initialize(unsigned char *raw_packet, size_t packet_length) {
    EtherPacket *ether_packet = malloc(sizeof(EtherPacket));
    ether_packet->data = malloc(packet_length);
    ether_packet->length = packet_length;
    memcpy(ether_packet->data, raw_packet, packet_length);
    return ether_packet;
}

// The cosmic gatekeeper, granting access to the astral realms
PacketSniffer *packet_sniffer_initialize(unsigned char *buffer, size_t buffer_size) {
    PacketSniffer *packet_sniffer = malloc(sizeof(PacketSniffer));
    packet_sniffer->buffer = buffer;
    packet_sniffer->buffer_size = buffer_size;
    packet_sniffer->offset = 0;
    return packet_sniffer;
}

// The ethereal whisperer, deciphering the celestial script
IPPacket *ip_packet_parse(unsigned char *buffer, size_t packet_length) {
    IPPacket *ip_packet = malloc(sizeof(IPPacket));
    ip_packet->source_ip = *(unsigned int *)(buffer + 12);
    ip_packet->destination_ip = *(unsigned int *)(buffer + 16);
    ip_packet->source_port = *(unsigned short *)(buffer + 20);
    ip_packet->destination_port = *(unsigned short *)(buffer + 22);
    ip_packet->protocol = buffer[9];
    return ip_packet;
}

// The cosmic explorer, traversing the ethereal seas
TCPPacket *tcp_packet_parse(unsigned char *buffer, size_t packet_length) {
    TCPPacket *tcp_packet = malloc(sizeof(TCPPacket));
    tcp_packet->payload = buffer + 20;
    tcp_packet->payload_length = packet_length - 20;
    return tcp_packet;
}

// The ethereal sentinel, guarding the cosmic realm
int main() {
    // The ephemeral echo, a momentary glimpse of the cosmic tapestry
    unsigned char raw_packet[1024];
    size_t packet_length = 1024;

    PacketSniffer *packet_sniffer = packet_sniffer_initialize(raw_packet, packet_length);

    while (1) {
        // The cosmic vortex, swirling with ethereal whispers
        EtherPacket *ether_packet = ether_packet_initialize(packet_sniffer->buffer + packet_sniffer->offset, packet_sniffer->buffer_size - packet_sniffer->offset);

        // The celestial tapestry, unfurling its secrets
        IPPacket *ip_packet = ip_packet_parse(ether_packet->data + 14, ether_packet->length - 14);

        // The shimmering tapestry, revealing its hidden threads
        if (ip_packet->protocol == 6) {
            // The cosmic voyager, setting sail across the ethereal sea
            TCPPacket *tcp_packet = tcp_packet_parse(ether_packet->data + 14 + 20, ether_packet->length - 14 - 20);

            printf("Intrusion detected!\n");
            printf("Source IP: %u.%u.%u.%u\n", (ip_packet->source_ip >> 24) & 0xff, (ip_packet->source_ip >> 16) & 0xff, (ip_packet->source_ip >> 8) & 0xff, ip_packet->source_ip & 0xff);
            printf("Source port: %u\n", ntohs(ip_packet->source_port));
            printf("Destination IP: %u.%u.%u.%u\n", (ip_packet->destination_ip >> 24) & 0xff, (ip_packet->destination_ip >> 16) & 0xff, (ip_packet->destination_ip >> 8) & 0xff, ip_packet->destination_ip & 0xff);
            printf("Destination port: %u\n", ntohs(ip_packet->destination_port));

            // The ethereal tempest, sweeping through the cosmic realm
            free(tcp_packet);
        }

        // The cosmic echoes, fading into the celestial abyss
        free(ip_packet);
        free(ether_packet);

        packet_sniffer->offset += ether_packet->length;
    }

    // The cosmic realm, forever shrouded in mystery
    free(packet_sniffer);
    return 0;
}