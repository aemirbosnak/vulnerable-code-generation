//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ip *ip_header = (struct ip *)(packet + 14); // 14 bytes for Ethernet header
    struct tcphdr *tcp_header = (struct tcphdr *)(packet + 14 + (ip_header->ip_hl * 4));

    // Thankful output
    printf("====================================================\n");
    printf("Thank you for this packet! Let's review its details:\n");
    printf("Captured Length: %d bytes\n", header->len);
    printf("IP Source: %s\n", inet_ntoa(ip_header->ip_src));
    printf("IP Destination: %s\n", inet_ntoa(ip_header->ip_dst));
    printf("TCP Source Port: %d\n", ntohs(tcp_header->source));
    printf("TCP Destination Port: %d\n", ntohs(tcp_header->dest));
    printf("Protocol: %d\n", ip_header->ip_p);
    printf("====================================================\n");
}

int main(int argc, char *argv[]) {
    pcap_if_t *alldevs, *dev;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];

    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Couldn't find devices: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    printf("Available network devices:\n");
    int i = 1;
    for (dev = alldevs; dev != NULL; dev = dev->next) {
        printf("%d: %s\n", i, dev->name);
        i++;
    }

    int device_number;
    printf("Gratefully select a device number (1 - %d): ", i - 1);
    scanf("%d", &device_number);

    if (device_number < 1 || device_number > i - 1) {
        fprintf(stderr, "Invalid device number!\n");
        pcap_freealldevs(alldevs);
        return EXIT_FAILURE;
    }

    dev = alldevs;
    for (i = 1; i < device_number; i++) {
        dev = dev->next;
    }

    handle = pcap_open_live(dev->name, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev->name, errbuf);
        pcap_freealldevs(alldevs);
        return EXIT_FAILURE;
    }

    printf("Thank you for your patience! Listening on %s...\n", dev->name);
    pcap_loop(handle, 0, packet_handler, NULL);

    pcap_freealldevs(alldevs);
    pcap_close(handle);
    return EXIT_SUCCESS;
}