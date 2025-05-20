//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: modular
#include <pcap.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Define buffer size and max packet size
#define BUFSIZE 1518
#define MAXPACKETSIZE 100

// Struct to hold packet information
typedef struct {
    int packet_len;
    u_char packet_data[MAXPACKETSIZE];
} Packet;

// Callback function for packet capture
void capture_packet(u_char* arg, const struct pcap_pkthdr* header, const u_char* pkt_data)
{
    // Create packet object and populate fields
    Packet* packet = (Packet*) malloc(sizeof(Packet));
    packet->packet_len = header->len;
    memcpy(packet->packet_data, pkt_data, header->len);
    
    // Write packet to file
    FILE* fp = (FILE*) arg;
    fwrite(packet, sizeof(Packet), 1, fp);
    
    // Clean up memory
    free(packet);
}

int main(int argc, char** argv)
{
    // Check for correct usage
    if (argc != 3) {
        printf("Usage: %s [interface] [output file]\n", argv[0]);
        return 1;
    }
    
    // Open output file
    FILE* fp = fopen(argv[2], "wb");
    if (fp == NULL) {
        printf("Error opening file: %s\n", argv[2]);
        return 1;
    }
    
    // Open capture device
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* handle = pcap_open_live(argv[1], BUFSIZE, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Error opening capture device: %s\n", errbuf);
        return 1;
    }
    
    // Start capturing packets
    pcap_loop(handle, -1, capture_packet, (u_char*) fp);
    
    // Close capture device and output file
    pcap_close(handle);
    fclose(fp);
    
    return 0;
}