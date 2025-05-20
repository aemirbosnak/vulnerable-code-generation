//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <string.h>
#include <signal.h>

#define MAX_PACKETS 100
#define SNAP_LEN 65535

int packet_count = 0;

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);
void signal_handler(int signal);

int main(int argc, char *argv[]) {
    pcap_if_t *alldevs, *device;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    
    // Check command line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the list of all available interfaces
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Find the required device
    for (device = alldevs; device != NULL; device = device->next) {
        if (strcmp(device->name, argv[1]) == 0) {
            break;
        }
    }

    if (device == NULL) {
        fprintf(stderr, "Device %s not found\n", argv[1]);
        pcap_freealldevs(alldevs);
        return EXIT_FAILURE;
    }

    // Open the device for packet capture
    handle = pcap_open_live(device->name, SNAP_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Unable to open device %s: %s\n", device->name, errbuf);
        pcap_freealldevs(alldevs);
        return EXIT_FAILURE;
    }

    pcap_freealldevs(alldevs);

    // Setup signal handler to end program gracefully on Ctrl+C
    signal(SIGINT, signal_handler);

    // Start capturing packets
    printf("Starting packet capture on interface %s...\n", device->name);
    pcap_loop(handle, MAX_PACKETS, process_packet, NULL);

    // Cleanup
    pcap_close(handle);
    printf("Capture complete. Total packets captured: %d\n", packet_count);

    return EXIT_SUCCESS;
}

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ip *ip_header;
    struct tcphdr *tcp_header;
    
    // Update the packet count
    packet_count++;

    // Extract IP header
    ip_header = (struct ip *)(packet + 14); // Skip Ethernet header
    // Extract TCP header
    tcp_header = (struct tcphdr *)(packet + 14 + (ip_header->ip_hl * 4)); // Skip IP header

    // Print packet information
    printf("Packet number: %d\n", packet_count);
    printf("Source IP: %s\n", inet_ntoa(ip_header->ip_src));
    printf("Destination IP: %s\n", inet_ntoa(ip_header->ip_dst));
    printf("Source Port: %d\n", ntohs(tcp_header->source));
    printf("Destination Port: %d\n", ntohs(tcp_header->dest));
    printf("TCP Flags: %d\n", tcp_header->fin << 0 | tcp_header->syn << 1 | tcp_header->rst << 2 | tcp_header->psh << 3 | tcp_header->ack << 4 | tcp_header->urg << 5);
    printf("----------------------------------------\n");
}

void signal_handler(int signal) {
    printf("\nSignal received: %d. Exiting...\n", signal);
    exit(EXIT_SUCCESS);
}