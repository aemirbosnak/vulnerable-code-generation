//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: futuristic
#include <pcap.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);

int main(int argc, char **argv)
{
    pcap_t *adhandle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program fp;
    bpf_u_int32 netmask = 0xffffff;
    int res;

    /* Open the adapter */
    if((adhandle=pcap_open_live(argv[1], 65535, 1, 1000, errbuf))==NULL)
    {
        fprintf(stderr, "Unable to open the adapter: %s\n", errbuf);
        return 1;
    }

    /* Compile the filter */
    if(pcap_compile(adhandle, &fp, argv[2], 0, netmask) == -1)
    {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(adhandle));
        return 1;
    }

    /* Set the filter */
    if(pcap_setfilter(adhandle, &fp) == -1)
    {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(adhandle));
        return 1;
    }

    /* Capture packets */
    if(pcap_loop(adhandle, -1, packet_handler, NULL) < 0)
    {
        fprintf(stderr, "Error capturing packets: %s\n", pcap_geterr(adhandle));
        return 1;
    }

    return 0;
}

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    const struct ether_header *eth_header;

    /* Get the Ethernet header */
    eth_header = (struct ether_header*)pkt_data;

    /* Print the source and destination MAC addresses */
    printf("Source MAC Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
           eth_header->ether_shost[0], eth_header->ether_shost[1],
           eth_header->ether_shost[2], eth_header->ether_shost[3],
           eth_header->ether_shost[4], eth_header->ether_shost[5]);

    printf("Destination MAC Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
           eth_header->ether_dhost[0], eth_header->ether_dhost[1],
           eth_header->ether_dhost[2], eth_header->ether_dhost[3],
           eth_header->ether_dhost[4], eth_header->ether_dhost[5]);

    /* Print the packet data */
    printf("Packet Data:");
    for(int i=0; i < header->len; i++)
    {
        printf("%02X ", *(pkt_data + i));
    }
    printf("\n");
}