//Falcon-180B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: unmistakable
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <net/if.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define SNAPLEN 65535
#define PCAP_ERRBUF_SIZE 256

pcap_t *pcap_handle;
char errbuf[PCAP_ERRBUF_SIZE];
char filter_exp[] = "tcp";

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char *argv[]) {
    char dev[100];
    char *dev_name = "lo";
    int i = 0;

    printf("Enter the device name to capture packets:\n");
    scanf("%s", dev);

    strcpy(dev_name, dev);

    pcap_handle = pcap_open_live(dev_name, SNAPLEN, 1, 1000, errbuf);

    if (pcap_handle == NULL) {
        printf("Error: %s\n", errbuf);
        exit(1);
    }

    printf("Press any key to stop capturing packets...\n");

    while (1) {
        if (pcap_dispatch(pcap_handle, -1, process_packet, NULL) == -1) {
            printf("Error: %s\n", pcap_geterr(pcap_handle));
            exit(1);
        }
    }

    return 0;
}

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct iphdr *ip_header;
    struct tcphdr *tcp_header;
    char src_ip[20], dest_ip[20];
    char src_port[6], dest_port[6];
    int i = 0;

    ip_header = (struct iphdr *) packet;
    tcp_header = (struct tcphdr *) (packet + ip_header->ihl * 4);

    inet_ntop(AF_INET, &ip_header->saddr, src_ip, 20);
    inet_ntop(AF_INET, &ip_header->daddr, dest_ip, 20);

    sprintf(src_port, "%d", ntohs(tcp_header->source));
    sprintf(dest_port, "%d", ntohs(tcp_header->dest));

    printf("Source IP: %s\n", src_ip);
    printf("Destination IP: %s\n", dest_ip);
    printf("Source Port: %s\n", src_port);
    printf("Destination Port: %s\n", dest_port);
    printf("\n");
}