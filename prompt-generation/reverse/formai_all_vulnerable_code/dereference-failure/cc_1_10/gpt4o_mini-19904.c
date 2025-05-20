//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: synchronous
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <netinet/ip_icmp.h>
#include <netinet/ether.h>

#define MAX_PROMISC_RETRIES 10

void packet_handler(u_char *user, const struct pcap_pkthdr *pkthdr, const u_char *packet) {
    struct ether_header *eth_header = (struct ether_header *)packet;
    struct ip *ip_header = (struct ip *)(packet + sizeof(struct ether_header));
    
    char src_ip[INET_ADDRSTRLEN];
    char dest_ip[INET_ADDRSTRLEN];

    inet_ntop(AF_INET, &ip_header->ip_src, src_ip, sizeof(src_ip));
    inet_ntop(AF_INET, &ip_header->ip_dst, dest_ip, sizeof(dest_ip));
    
    printf("Source MAC: %s ", ether_ntoa((struct ether_addr *)eth_header->ether_shost));
    printf("Dest MAC: %s ", ether_ntoa((struct ether_addr *)eth_header->ether_dhost));
    printf("Source IP: %s ", src_ip);
    printf("Dest IP: %s ", dest_ip);
    printf("Protocol: %d\n", ip_header->ip_p);
}

void start_capture(const char *device) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device, errbuf);
        exit(EXIT_FAILURE);
    }

    printf("Capturing packets on device: %s\n", device);
    pcap_loop(handle, 0, packet_handler, NULL);

    pcap_close(handle);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <device>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *device = argv[1];
    
    char errbuf[PCAP_ERRBUF_SIZE];
    if (pcap_lookupdev(errbuf) == NULL) {
        fprintf(stderr, "Error finding a device: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Confirm that the device is valid
    pcap_if_t *interfaces, *temp;
    if (pcap_findalldevs(&interfaces, errbuf) == -1) {
        fprintf(stderr, "Could not find devices: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    int device_found = 0;
    for (temp = interfaces; temp != NULL; temp = temp->next) {
        if (strcmp(temp->name, device) == 0) {
            device_found = 1;
            break;
        }
    }
    pcap_freealldevs(interfaces);

    if (!device_found) {
        fprintf(stderr, "Device %s not found.\n", device);
        return EXIT_FAILURE;
    }

    start_capture(device);
    return EXIT_SUCCESS;
}