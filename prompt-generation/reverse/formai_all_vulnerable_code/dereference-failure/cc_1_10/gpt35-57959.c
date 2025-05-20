//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: irregular
/* Welcome to the Network Quality of Service (QoS) monitor */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>

/* Function prototypes */
void capture_packet(unsigned char* buffer, int size);
void print_packet(unsigned char* buffer, int size);

/* Main program */
int main() {
    int raw_socket;
    struct sockaddr_in server;
    unsigned char *buffer = (unsigned char *)malloc(65536); // Allocate 64 KB buffer

    printf("Starting QoS monitor...\n");

    // Create raw socket
    raw_socket = socket(AF_INET, SOCK_RAW, IPPROTO_UDP);
    if(raw_socket < 0) {
        printf("Error creating raw socket.\n");
        exit(1);
    }

    // Set socket options to receive all packets
    int one = 1;
    const int *val = &one;
    if(setsockopt(raw_socket, IPPROTO_IP, IP_HDRINCL, val, sizeof(one)) < 0) {
        printf("Error setting socket options.\n");
        exit(1);
    }

    // Set server structure data
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(0);

    // Bind socket to server
    if(bind(raw_socket, (struct sockaddr*)&server, sizeof(server)) < 0) {
        printf("Error binding socket to server.\n");
        exit(1);
    }

    printf("Waiting for incoming packets...\n");

    // Loop to capture and display packets
    while(1) {
        struct sockaddr_in client;
        int client_size = sizeof(client);
        int packet_size = recvfrom(raw_socket, buffer, 65536, 0, (struct sockaddr*)&client, &client_size);
        if(packet_size < 0) {
            printf("Error receiving packet.\n");
            exit(1);
        }
        capture_packet(buffer, packet_size);
        print_packet(buffer, packet_size);
    }

    // Close socket and free buffer
    close(raw_socket);
    free(buffer);

    return 0;
}

/* Function to capture and analyze the packet */
void capture_packet(unsigned char* buffer, int size) {
    struct iphdr *iph = (struct iphdr*)buffer;

    // Check if packet is IPv4
    if (iph->version == 4) {
        struct udphdr *udp = (struct udphdr*)(buffer + iph->ihl*4);
        int packet_length = ntohs(udp->len) + iph->ihl*4; // Length of entire packet
        
        // Print packet information
        printf("Packet Captured!\n");
        printf("Source IP: %s\n", inet_ntoa(*(struct in_addr *)&iph->saddr));
        printf("Destination IP: %s\n", inet_ntoa(*(struct in_addr *)&iph->daddr));
        printf("Source Port: %d\n", ntohs(udp->source));
        printf("Destination Port: %d\n", ntohs(udp->dest));
        printf("Packet Length: %d bytes\n", packet_length);
        printf("\n");
    }
}

/* Function to print the packet in hex format */
void print_packet(unsigned char* buffer, int size) {
    printf("Packet Hex Dump:\n");
    for(int i=0; i<size; i++) {
        printf("%02x ", buffer[i]);
        if(i%16 == 15) printf("\n");
    }
    printf("\n--------------------------------------------------------------\n");
}