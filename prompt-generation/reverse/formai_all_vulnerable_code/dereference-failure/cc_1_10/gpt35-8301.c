//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program fp;
    char filter_exp[] = "ip";
    bpf_u_int32 mask;
    bpf_u_int32 net;
    struct pcap_pkthdr header;
    const u_char *packet;

    // Print Cyberpunk Style Header
    printf("******************************\n");
    printf("*   C PACKET CAPTURER v1.0    *\n");
    printf("*  BY @HACKER_GUY             *\n");
    printf("******************************\n\n");

    // Check number of arguments
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return 1;
    }

    // Get network information
    if (pcap_lookupnet(argv[1], &net, &mask, errbuf) == -1)
    {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", argv[1], errbuf);
        net = 0;
        mask = 0;
    }

    // Open interface in promiscuous mode
    handle = pcap_open_live(argv[1], BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL)
    {
        fprintf(stderr, "Couldn't open device %s: %s\n", argv[1], errbuf);
        return 2;
    }

    // Compile filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1)
    {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 3;
    }

    // Apply the filter
    if (pcap_setfilter(handle, &fp) == -1)
    {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 4;
    }

    // Capture packets
    while (1)
    {
        packet = pcap_next(handle, &header);
        if (packet == NULL)
            continue;

        // Print packet information in Cyberpunk style
        printf("===============================================\n");
        printf("  Packet Received  |  Length: %d bytes  |  Time: %s", header.len, ctime((const time_t *)&header.ts.tv_sec));
        printf("===============================================\n\n");

        int i;
        for (i = 0; i < header.len; i++)
        {
            printf("%02x ", packet[i]);
            if ((i + 1) % 16 == 0)
                printf("\n");
        }
        printf("\n\n\n");
    }

    // Close interface
    pcap_close(handle);
    return 0;
}