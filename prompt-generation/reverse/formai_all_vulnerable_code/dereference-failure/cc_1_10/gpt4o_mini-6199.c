//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>

volatile sig_atomic_t stop;

void handle_signal(int signum) {
    stop = 1;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    (void) args; // Suppress unused variable warning

    printf("Packet captured at: %s", ctime((const time_t *)&header->ts.tv_sec));
    printf("Packet length: %d bytes\n", header->len);
    printf("Packet contents:\n");
    
    for (int i = 0; i < header->len; i++) {
        if (i % 16 == 0) {
            if (i != 0) {
                printf("\n");
            }
            printf("%04x ", i);
        }
        printf("%02x ", packet[i]);
    }
    printf("\n\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *interface = argv[1];
    char errbuf[PCAP_ERRBUF_SIZE];

    pcap_if_t *alldevs, *device;
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    for (device = alldevs; device; device = device->next) {
        if (strcmp(device->name, interface) == 0) {
            break;
        }
    }

    if (device == NULL) {
        fprintf(stderr, "No such device found: %s\n", interface);
        pcap_freealldevs(alldevs);
        return EXIT_FAILURE;
    }

    pcap_t *handle = pcap_open_live(device->name, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device->name, errbuf);
        pcap_freealldevs(alldevs);
        return EXIT_FAILURE;
    }

    pcap_freealldevs(alldevs);
    
    signal(SIGINT, handle_signal);

    printf("Starting packet capture on %s. Press Ctrl+C to stop...\n", device->name);
    
    while (!stop) {
        int result = pcap_loop(handle, 10, packet_handler, NULL);
        if (result < 0) {
            fprintf(stderr, "Error capturing packets: %s\n", pcap_geterr(handle));
            break;
        }
    }

    pcap_close(handle);
    printf("Packet capture stopped. Exiting program.\n");
    return EXIT_SUCCESS;
}