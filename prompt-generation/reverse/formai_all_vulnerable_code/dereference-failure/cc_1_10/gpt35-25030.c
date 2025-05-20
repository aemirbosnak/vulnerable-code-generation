//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: inquisitive
#include<stdio.h>
#include<pcap.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<netinet/ether.h>
#include<netinet/ip.h>
#include<netinet/tcp.h>
#include<time.h>
#include<arpa/inet.h>

void print_ethernet_header(const u_char* packet);
void print_ip_header(const u_char* packet);
void print_tcp_packet(const u_char* packet);

int main(int argc, char* argv[])
{
    pcap_t* handle;
    const u_char* packet;
    char* dev;
    struct pcap_pkthdr header;

    char errbuf[PCAP_ERRBUF_SIZE];

    dev = pcap_lookupdev(errbuf);

    if (dev == NULL)
    {
        fprintf(stderr, "Unable to find the default device: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);

    if (handle == NULL)
    {
        fprintf(stderr, "Could not open device %s: %s\n", dev, errbuf);
        return EXIT_FAILURE;
    }

    while(1)
    {
        packet = pcap_next(handle, &header);

        if (packet != NULL)
        {
            print_ethernet_header(packet);

            if(header.len < (sizeof(struct ether_header) + sizeof(struct iphdr) + sizeof(struct tcphdr)))
                continue;

            print_ip_header(packet);

            if (IPPROTO_TCP == ((struct iphdr*)(packet + sizeof(struct ether_header)))->protocol)
            {
                print_tcp_packet(packet);
            }
        }
    }

    pcap_close(handle);
    return EXIT_SUCCESS;
}

void print_ethernet_header(const u_char* packet)
{
    struct ether_header* eth = (struct ether_header*) (packet);
    printf("\nEthernet Header:\n");
    printf("\tSource MAC: %s\n", ether_ntoa((const struct ether_addr*) eth->ether_shost));
    printf("\tDestination MAC: %s\n", ether_ntoa((const struct ether_addr*) eth->ether_dhost));
}

void print_ip_header(const u_char* packet)
{
    struct iphdr* iph = (struct iphdr*)(packet + sizeof(struct ether_header));
    printf("\nIP Header:\n");
    printf("\tSource IP: %s\n", inet_ntoa((struct in_addr) {iph->saddr}));
    printf("\tDestination IP: %s\n", inet_ntoa((struct in_addr) {iph->daddr}));
}

void print_tcp_packet(const u_char* packet)
{
    struct iphdr* iph = (struct iphdr*)(packet + sizeof(struct ether_header));
    struct tcphdr* tcph = (struct tcphdr*)(packet + sizeof(struct ether_header) + sizeof(struct iphdr));

    int payload_size = ntohs(iph->tot_len) - (iph->ihl*4) - (tcph->doff*4);
    char* payload = (char*)(packet + sizeof(struct ether_header) + sizeof(struct iphdr) + (tcph->doff*4));

    printf("\nTCP Packet:\n");
    printf("\tSource Port: %d\n", ntohs(tcph->source));
    printf("\tDestination Port: %d\n", ntohs(tcph->dest));
    printf("\tSequence Number: %u\n", ntohl(tcph->seq));
    printf("\tACK Sequence Number: %u\n", ntohl(tcph->ack_seq));
    printf("\tHeader Length: %d bytes\n", tcph->doff*4);
    printf("\tWindow Size: %d\n", ntohs(tcph->window));
    printf("\tChecksum: %d\n", ntohs(tcph->check));

    if (payload_size > 0)
    {
        printf("\nTCP Payload:\n");
        printf("\tPayload Size: %d bytes\n", payload_size);
        printf("\tPayload: %s\n", payload);
    }
}