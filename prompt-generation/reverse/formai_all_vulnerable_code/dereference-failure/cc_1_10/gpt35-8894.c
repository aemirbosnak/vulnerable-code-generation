//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: lively
#include <stdio.h>
#include <pcap.h>

void print_packet(const u_char *packet, struct pcap_pkthdr packet_header)
{
    // Print the packet length and timestamp
    printf("Packet length: %d\n", packet_header.len);
    printf("Timestamp: %s\n", ctime((const time_t*)&packet_header.ts.tv_sec));

    // Print the packet contents (hexadecimal and ASCII)
    for (int i = 0; i < packet_header.len; i++)
    {
        printf("%02x ", packet[i]);
        if ((i + 1) % 16 == 0)
        {
            printf(" ");
            for (int j = i - 15; j <= i; j++)
            {
                if (packet[j] >= 32 && packet[j] <= 126)
                    printf("%c", packet[j]);
                else
                    printf(".");
            }
            printf("\n");
        }
    }
    printf("\n");
}

int main()
{
    pcap_t *handle;
    char error_buffer[PCAP_ERRBUF_SIZE];
    struct pcap_pkthdr packet_header;
    const u_char *packet;

    // Open the network interface for capture
    handle = pcap_open_live("eth0", 65536, 1, 1000, error_buffer);
    if (handle == NULL)
    {
        printf("Couldn't open device: %s\n", error_buffer);
        return 1;
    }

    // Continuously capture packets and print their details
    while (1)
    {
        packet = pcap_next(handle, &packet_header);
        
        if (packet != NULL)
            print_packet(packet, packet_header);
    }

    // Close the capture handle
    pcap_close(handle);

    return 0;
}