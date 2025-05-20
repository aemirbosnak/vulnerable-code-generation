//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    int promisc_mode = 0;
    char *iface_name;

    printf("Initializing network packet monitoring program in post-apocalyptic world...\n");
    printf("Scavenging for available network devices...\n");

    // Find available network devices
    pcap_if_t *alldevs, *d;
    if(pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return EXIT_FAILURE;
    }
    // Print available network devices
    int i = 0;
    for(d = alldevs; d != NULL; d = d->next) {
        printf("%d. %s", ++i, d->name);
        if(d->description)
            printf(" (%s)\n", d->description);
        else
            printf(" (No description available)\n");
    }
    // Select a network device for monitoring
    printf("Enter the interface number (1-%d) of the device you want to monitor: ", i);
    int select_num;
    scanf("%d", &select_num);
    if(select_num < 1 || select_num > i) {
        printf("Invalid interface number\n");
        return EXIT_FAILURE;
    }
    // Get the name of the selected network device
    for(d = alldevs, i = 0; i < select_num-1; d = d->next, i++);
    iface_name = d->name;
    printf("Selected network device: %s\n", iface_name);
    // Open a handle to the selected network device for monitoring
    pcap_t *handle = pcap_open_live(iface_name, BUFSIZ, promisc_mode, 1000, errbuf);
    if(handle == NULL) {
        fprintf(stderr, "Error opening handle: %s\n", errbuf);
        return EXIT_FAILURE;
    }
    printf("Monitoring network traffic on device %s...\n", iface_name);

    // Start packet capture loop
    struct pcap_pkthdr header;
    const u_char* packet;
    while(1) {
        packet = pcap_next(handle, &header);
        if(packet != NULL) {
            printf("Packet captured with size %d\n", header.len);
        }
    }

    return EXIT_SUCCESS;
}