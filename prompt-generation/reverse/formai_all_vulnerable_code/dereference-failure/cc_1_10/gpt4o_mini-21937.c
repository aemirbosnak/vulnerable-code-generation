//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Linus Torvalds
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <signal.h>

#define MAX_DEVICES 10
#define BUFFER_SIZE 65536

void handle_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Received packet of length %d\n", header->len);
}

void list_devices() {
    pcap_if_t *alldevs;
    char errbuf[PCAP_ERRBUF_SIZE];

    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Could not find devices: %s\n", errbuf);
        return;
    }

    printf("Available devices:\n");
    for (pcap_if_t *d = alldevs; d != NULL; d = d->next) {
        printf(" - %s\n", d->name);
    }

    pcap_freealldevs(alldevs);
}

void sigint_handler(int sig) {
    printf("Exiting gracefully...\n");
    exit(0);
}

int main() {
    signal(SIGINT, sigint_handler);
    
    list_devices();

    char device[100];
    printf("Enter device name to capture packets: ");
    fgets(device, sizeof(device), stdin);
    device[strcspn(device, "\n")] = 0; // Remove newline

    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live(device, BUFFER_SIZE, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device, errbuf);
        return 1;
    }

    printf("Capturing packets on %s...\n", device);

    if (pcap_loop(handle, 0, handle_packet, NULL) < 0) {
        fprintf(stderr, "Error capturing packets: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        return 1;
    }

    pcap_close(handle);
    return 0;
}