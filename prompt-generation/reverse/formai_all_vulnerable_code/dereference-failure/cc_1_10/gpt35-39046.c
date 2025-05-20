//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: mind-bending
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>

#define SNAP_LEN 65535
#define SIZE_ETHERNET 14

int main(int argc, char const *argv[])
{

    char *device = NULL; //device for capture
    char error_buffer[PCAP_ERRBUF_SIZE]; //buffer for error

    pcap_t *handle = NULL; //session handle
    struct pcap_pkthdr header; //packet header
    const u_char *packet = NULL; //actual packet

    //find device for capture
    device = pcap_lookupdev(error_buffer);
    if (device == NULL)
    {
        fprintf(stderr, "Couldn't find default device: %s\n", error_buffer);
        return (EXIT_FAILURE);
    }

    //open device for capture
    handle = pcap_open_live(device, SNAP_LEN, 1, 1000, error_buffer);
    if (handle == NULL)
    {
        fprintf(stderr, "Couldn't open device %s: %s\n", device, error_buffer);
        return (EXIT_FAILURE);
    }

    //packet capture loop
    while (1)
    {
        //capture packet
        packet = pcap_next(handle, &header);
        if (packet == NULL)
        {
            continue;
        }

        //print packet info
        printf("Packet captured (%d bytes)\n", header.len);

        //print packet data
        int i;
        for (i = SIZE_ETHERNET; i < header.len; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("\n");
    }

    //close handle
    pcap_close(handle);

    return (EXIT_SUCCESS);
}