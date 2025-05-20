//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_PACKET_SIZE 65536

typedef struct ip_header {
    unsigned char header_length : 4;
    unsigned char version : 4;
    unsigned char type_of_service;
    unsigned short total_length;
    unsigned short identification;
    unsigned short fragment_offset;
    unsigned char time_to_live;
    unsigned char protocol;
    unsigned short checksum;
    unsigned int source_address;
    unsigned int destination_address;
} ip_header_t;

typedef struct tcp_header {
    unsigned short source_port;
    unsigned short destination_port;
    unsigned int sequence_number;
    unsigned int acknowledgement_number;
    unsigned char data_offset : 4;
    unsigned char reserved : 4;
    unsigned char flags;
    unsigned short window_size;
    unsigned short checksum;
    unsigned short urgent_pointer;
} tcp_header_t;

void parse_packet(unsigned char *buffer, int size) {
    ip_header_t *ip_header = (ip_header_t*) buffer;
    if (ip_header->protocol == IPPROTO_TCP) {
        tcp_header_t *tcp_header = (tcp_header_t*) (buffer + (ip_header->header_length * 4));
        printf("Source Port: %u\n", ntohs(tcp_header->source_port));
        printf("Destination Port: %u\n", ntohs(tcp_header->destination_port));
        printf("Sequence Number: %u\n", ntohl(tcp_header->sequence_number));
        printf("Acknowledgement Number: %u\n", ntohl(tcp_header->acknowledgement_number));
        printf("Data Offset: %u\n", tcp_header->data_offset * 4);
        printf("Flags: %02x\n", tcp_header->flags);
        printf("Window Size: %u\n\n", ntohs(tcp_header->window_size));
    }
}

int main(int argc, char *argv[]) {
    int socket_raw, size;
    struct sockaddr_in saddr;
    unsigned char *buffer = (unsigned char *) malloc(MAX_PACKET_SIZE);
    
    socket_raw = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    
    if (socket_raw < 0) {
        printf("Error creating raw socket. Try running with root privileges. \n");
        return 1;
    }
    
    while (1) {
        size = sizeof(saddr);
        memset(buffer, 0, MAX_PACKET_SIZE);
        
        int packet_size = recvfrom(socket_raw, buffer, MAX_PACKET_SIZE, 0, (struct sockaddr*)&saddr, &size);
        if (packet_size < 0) continue;
        
        parse_packet(buffer, packet_size);
    }
    
    return 0;
}