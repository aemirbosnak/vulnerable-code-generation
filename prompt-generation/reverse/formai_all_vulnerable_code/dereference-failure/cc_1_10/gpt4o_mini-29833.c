//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: inquisitive
#include <stdio.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <string.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ip *ip_hdr = (struct ip *)(packet + 14); // Skip Ethernet header (14 bytes)
    char src_ip[INET_ADDRSTRLEN];
    char dst_ip[INET_ADDRSTRLEN];

    inet_ntop(AF_INET, &ip_hdr->ip_src, src_ip, sizeof(src_ip));
    inet_ntop(AF_INET, &ip_hdr->ip_dst, dst_ip, sizeof(dst_ip));

    printf("Captured Packet: \n");
    printf("Source IP: %s\n", src_ip);
    printf("Destination IP: %s\n", dst_ip);
    printf("Protocol: %d\n", ip_hdr->ip_p);
    
    // Display UDP or TCP headers based on the protocol
    if (ip_hdr->ip_p == IPPROTO_UDP) {
        struct udphdr *udp_hdr = (struct udphdr *)(packet + 14 + sizeof(struct ip));
        printf("UDP Packet: Source Port: %d, Destination Port: %d\n",
               ntohs(udp_hdr->source), ntohs(udp_hdr->dest));
    } else if (ip_hdr->ip_p == IPPROTO_TCP) {
        struct tcphdr *tcp_hdr = (struct tcphdr *)(packet + 14 + sizeof(struct ip));
        printf("TCP Packet: Source Port: %d, Destination Port: %d\n",
               ntohs(tcp_hdr->source), ntohs(tcp_hdr->dest));
    }

    printf("-------------------------\n");
}

int main(int argc, char *argv[]) {
    pcap_if_t *alldevs, *device;
    char errbuf[PCAP_ERRBUF_SIZE];

    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Unable to find devices: %s\n", errbuf);
        return 1;
    }

    printf("Available Devices:\n");
    for (device = alldevs; device != NULL; device = device->next) {
        printf("%s\n", device->name);
    }

    printf("Enter device name to monitor (e.g., eth0): ");
    char device_name[100];
    scanf("%s", device_name);

    pcap_t *handle;
    handle = pcap_open_live(device_name, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Unable to open device %s: %s\n", device_name, errbuf);
        return 1;
    }

    printf("Starting packet capture on %s...\n", device_name);
    pcap_loop(handle, 0, packet_handler, NULL);

    pcap_freealldevs(alldevs);
    pcap_close(handle);
    return 0;
}