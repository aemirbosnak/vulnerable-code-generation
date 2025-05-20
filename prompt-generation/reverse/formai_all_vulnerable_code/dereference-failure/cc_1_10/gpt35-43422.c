//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: genious
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

void print_packet_info(const u_char *packet, struct pcap_pkthdr packet_header);

int main(int argc, char *argv[])
{
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *pcap_handle;
    struct pcap_pkthdr packet_header;
    const u_char *packet;
    char *device = NULL;
    int packets_to_capture = 0;
    int packet_count = 0;

    // Determine capture device
    if (argc > 1)
    {
        device = argv[1];
    }
    else
    {
        device = pcap_lookupdev(error_buffer);
        if (device == NULL)
        {
            printf("Error finding default capture device: %s\n", error_buffer);
            return 1;
        }
    }
    printf("Capturing on device: %s\n", device);

    // Open capture device
    pcap_handle = pcap_open_live(device, BUFSIZ, 1, 1000, error_buffer);
    if (pcap_handle == NULL)
    {
        printf("Error opening capture device %s: %s\n", device, error_buffer);
        return 1;
    }

    // Capture packets
    while ((packets_to_capture == 0 || packet_count < packets_to_capture) && pcap_next_ex(pcap_handle, &packet_header, &packet) == 1)
    {
        print_packet_info(packet, packet_header);
        packet_count++;
    }

    // Close capture device
    pcap_close(pcap_handle);
    printf("Captured %d packets\n", packet_count);

    return 0;
}

void print_packet_info(const u_char *packet, struct pcap_pkthdr packet_header)
{
    char timestamp_string[30];
    struct tm *local_time;
    time_t timestamp = packet_header.ts.tv_sec;
    local_time = localtime(&timestamp);
    strftime(timestamp_string, sizeof(timestamp_string), "%Y-%m-%d %H:%M:%S", local_time);

    printf("\nPacket:\n");
    printf("Timestamp: %s.%06ld\n", timestamp_string, packet_header.ts.tv_usec);
    printf("Length: %d bytes\n", packet_header.len);
    printf("Destination MAC: %02X:%02X:%02X:%02X:%02X:%02X\n", packet[0], packet[1], packet[2], packet[3], packet[4], packet[5]);
    printf("Source MAC: %02X:%02X:%02X:%02X:%02X:%02X\n", packet[6], packet[7], packet[8], packet[9], packet[10], packet[11]);
    printf("Protocol: ");
    if (packet[12] == 0x08 && packet[13] == 0x00)
    {
        printf("IP");
    }
    else if (packet[12] == 0x08 && packet[13] == 0x06)
    {
        printf("ARP");
    }
    else if (packet[12] == 0x86 && packet[13] == 0xDD)
    {
        printf("IPv6");
    }
    else
    {
        printf("Unknown");
    }
    printf("\n");
}