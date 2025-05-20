//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: introspective
// A unique example program to monitor network packets using C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h>

#define BUFFER_SIZE 65536

// Function to extract source and destination IP addresses from the packet
void process_packet(unsigned char* buffer, int size) {
    struct ethhdr *eth = (struct ethhdr *)buffer;

    // Check if it is an IP packet
    if(ntohs(eth->h_proto) == ETH_P_IP) {
        struct sockaddr_in source, dest;
        
        // Extract the IP addresses
        memset(&source, 0, sizeof(source));
        source.sin_addr.s_addr = *((unsigned long*)&(buffer[ETH_HLEN + 12]));
        
        memset(&dest, 0, sizeof(dest));
        dest.sin_addr.s_addr = *((unsigned long*)&(buffer[ETH_HLEN + 16]));
        
        // Print the IP addresses
        printf("Source IP: %s\n", inet_ntoa(source.sin_addr));
        printf("Destination IP: %s\n", inet_ntoa(dest.sin_addr));
    }
}

// Main function
int main() {
    int sock_raw;
    int data_size;
    struct sockaddr saddr;
    unsigned char* buffer = (unsigned char*)malloc(BUFFER_SIZE);

    // Creating the socket to monitor network packets with protocol IP and TCP
    sock_raw = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_IP));
    if(sock_raw < 0) {
        printf("Socket Error\n");
        return 1;
    }

    // Infinite loop to receive and process packets
    while(1) {
        int saddr_len = sizeof(saddr);
        data_size = recvfrom(sock_raw, buffer, BUFFER_SIZE, 0, &saddr, (socklen_t*)&saddr_len);

        if(data_size < 0) {
            printf("Recvfrom Error\n");
            return 1;
        }

        // Process the received packet
        process_packet(buffer, data_size);
    }

    close(sock_raw);
    printf("Finished\n");
    return 0;
}