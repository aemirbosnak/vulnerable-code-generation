//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

int main(int argc, char *argv[])
{
    // Our gratitude to the network gods for this blessed tool
    printf("Oh, mighty libpcap, we thank thee for this humble gift\n");

    // Let's capture some packets, shall we?
    char *device = pcap_lookupdev(NULL);
    if (!device)
    {
        fprintf(stderr, "No network devices found. Please check your configuration.\n");
        return EXIT_FAILURE;
    }

    // We shall sniff packets from the godly interface
    printf("We shall sniff packets from the godly interface: %s\n", device);

    // Let's set up our packet capture filter
    struct bpf_program filter;
    if (pcap_compile(pcap_open_live(device, BUFSIZ, 1, 1000, NULL), &filter, "tcp", 1, 0) < 0)
    {
        fprintf(stderr, "Error compiling filter. Please check your syntax.\n");
        return EXIT_FAILURE;
    }

    // We shall now commence the capture
    printf("Now, let the godly packets flow!\n");
    pcap_t *handle = pcap_open_live(device, BUFSIZ, 1, 1000, NULL);
    if (!handle)
    {
        fprintf(stderr, "Error opening live capture. Please check your permissions.\n");
        return EXIT_FAILURE;
    }

    // Let's loop through the packets and marvel at their celestial presence
    struct pcap_pkthdr *header;
    const unsigned char *data;
    while (pcap_next_ex(handle, &header, &data) >= 0)
    {
        // We shall now print the header to the console screen
        printf("Behold, a packet of heavenly origin! Its length is %d bytes\n", header->len);
        printf("Its timestamp is %u seconds and %u microseconds\n", header->ts.tv_sec, header->ts.tv_usec);

        // Let's examine the data payload
        printf("The payload, a treasure from the heavens, is:\n");
        for (int i = 0; i < header->len; i++)
        {
            printf("%02x ", data[i]);
        }
        printf("\n");

        // We shall now offer our thanks to the gods for this blessed packet
        printf("Thank you, oh mighty network gods, for this divine packet!\n");
    }

    // We have finished our capture. May the gods bless us!
    printf("May the gods bless us on our networking journey!\n");
    pcap_close(handle);

    return EXIT_SUCCESS;
}