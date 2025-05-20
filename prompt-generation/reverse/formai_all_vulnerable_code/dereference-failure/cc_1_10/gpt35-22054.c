//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <pcap.h>
#include <netinet/if_ether.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <pthread.h>

#define PROMISC 1
#define TIMEOUT 1000

pcap_t *handle;
char *dev;
char errbuf[PCAP_ERRBUF_SIZE];
struct bpf_program fp;
bpf_u_int32 net;
bpf_u_int32 mask;
struct pcap_pkthdr header;
const u_char *packet;
char filter_exp[] = "";
int num_packets = 0;

void *scan_network(void *data)
{
    while (1)
    {
        if (pcap_next_ex(handle, &header, &packet) >= 0)
        {
            struct ether_header *eth_header = (struct ether_header *)packet;
            if (ntohs(eth_header->ether_type) == ETHERTYPE_IP)
            {
                struct iphdr *ip_header = (struct iphdr *)(packet + sizeof(struct ether_header));
                if (ip_header->protocol == IPPROTO_TCP)
                {
                    struct tcphdr *tcp_header = (struct tcphdr *)(packet + sizeof(struct ether_header) + sizeof(struct iphdr));
                    int source_port = ntohs(tcp_header->source);
                    int dest_port = ntohs(tcp_header->dest);
                    struct in_addr source_addr = {ip_header->saddr};
                    struct in_addr dest_addr = {ip_header->daddr};
                    printf("TCP packet from %s:%d to %s:%d\n", inet_ntoa(source_addr), source_port, inet_ntoa(dest_addr), dest_port);
                }
                else if (ip_header->protocol == IPPROTO_UDP)
                {
                    struct udphdr *udp_header = (struct udphdr *)(packet + sizeof(struct ether_header) + sizeof(struct iphdr));
                    int source_port = ntohs(udp_header->source);
                    int dest_port = ntohs(udp_header->dest);
                    struct in_addr source_addr = {ip_header->saddr};
                    struct in_addr dest_addr = {ip_header->daddr};
                    printf("UDP packet from %s:%d to %s:%d\n", inet_ntoa(source_addr), source_port, inet_ntoa(dest_addr), dest_port);
                }
            }
        }
    }

    pthread_exit(NULL);
}

int main(int argc, char **argv)
{
    // Find a suitable network interface
    char *dev = pcap_lookupdev(errbuf);
    if (dev == NULL)
    {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    // Open the network interface in promiscuous mode
    handle = pcap_open_live(dev, BUFSIZ, PROMISC, TIMEOUT, errbuf);
    if (handle == NULL)
    {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        exit(EXIT_FAILURE);
    }

    // Compile and set the packet filter
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1)
    {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }
    if (pcap_setfilter(handle, &fp) == -1)
    {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // Get network info
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1)
    {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    pthread_t tid;
    pthread_create(&tid, NULL, scan_network, NULL);

    pthread_join(tid, NULL);

    // Cleanup
    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}