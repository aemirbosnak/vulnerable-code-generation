//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <time.h>

#define SNAP_LEN 65535
#define PORT 8080
#define TIME_FORMAT "%Y-%m-%d %H:%M:%S"

void packet_handler(u_char *user, const struct pcap_pkthdr *pkthdr, const u_char *packet) {
    struct ip *ip_header = (struct ip*)(packet + 14); // Skip Ethernet header
    char timestamp[20];
    
    time_t now = time(NULL);
    strftime(timestamp, sizeof(timestamp), TIME_FORMAT, localtime(&now));

    printf("[%s] Packet captured: ", timestamp);
    
    // Display source and destination IP addresses
    printf("Src: %s, Dst: %s\n", inet_ntoa(ip_header->ip_src), inet_ntoa(ip_header->ip_dst));

    // Display packet size
    printf("Packet size: %d bytes\n", pkthdr->len);

    // Example of user-defined rules for search in the packets
    if(ntohs(ip_header->ip_p) == PORT) {
        printf("Warning: Packet using reserved port detected!\n");
    }

    printf("------------------------------------------------------\n");
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_if_t *devices, *temp;
    pcap_t *handle;
    
    // Check for available devices
    if (pcap_findalldevs(&devices, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    printf("Available network devices:\n");
    for (temp = devices; temp != NULL; temp = temp->next) {
        printf(" - %s\n", temp->name);
    }

    // Assume here we choose the first device; in a real scenario, a user should select
    handle = pcap_open_live(devices->name, SNAP_LEN, 1, 1000, errbuf);
    
    if (handle == NULL) {
        fprintf(stderr, "Error opening device %s: %s\n", devices->name, errbuf);
        pcap_freealldevs(devices);
        return EXIT_FAILURE;
    }
    
    printf("Monitoring packets on device: %s\n", devices->name);
    
    // Start packet capturing
    pcap_loop(handle, 10, packet_handler, NULL);
    
    // Cleanup
    pcap_close(handle);
    pcap_freealldevs(devices);
    
    return EXIT_SUCCESS;
}