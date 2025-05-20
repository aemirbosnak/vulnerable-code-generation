//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <string.h>
#include <time.h>

#define MAX_PACKETS 100
#define SNAP_LEN 65535

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    (void)args; // Just here for fun, we won't use this!
    
    // Get the time of the packet capture
    time_t ltime = (time_t)header->ts.tv_sec;
    char *time_str = ctime(&ltime);

    // Trim off the newline character from ctime
    time_str[strlen(time_str) - 1] = '\0';

    // Packet captured! Let's express our excitement
    printf("Packets caught in the wild! 🐾 \n");
    printf("Time: %s | Length: %d bytes\n", time_str, header->len);
    printf("Packet Data: ");
    
    for (int i = 0; i < header->len; i++) {
        printf("%02x ", packet[i]);
        if ((i + 1) % 16 == 0) // To avoid cramming, we break it down into lines
            printf("\n                ");
    }
    printf("\n\n");
}

void start_capturing(pcap_if_t *dev) {
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];

    // Let's host a party for packets to join!
    handle = pcap_open_live(dev->name, SNAP_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Uh-oh! Party failed to start on %s: %s\n", dev->name, errbuf);
        return;
    }
    
    printf("Party started, capturing packets! 🎉\n");
    
    // Catch the packets until the party gets shut down
    pcap_loop(handle, MAX_PACKETS, packet_handler, NULL);

    // Once the party is over, let’s pack up
    pcap_close(handle);
    printf("Party's over! Time to go home! 🚪\n");
}

int main() {
    pcap_if_t *alldevs;
    pcap_if_t *device;

    printf("👋 Welcome to the Packet-Capturing Funhouse! 🎪\n");
    printf("Let's find some fun network devices...\n");

    if (pcap_findalldevs(&alldevs, NULL) == -1) {
        fprintf(stderr, "Oops! Couldn't find devices: %s\n", pcap_geterr(NULL));
        return EXIT_FAILURE;
    }

    printf("Found the following devices:\n");
    for (device = alldevs; device; device = device->next) {
        printf(" - %s\n", device->name);
        if (device->description) {
            printf("   Description: %s\n", device->description);
        }
    }

    // Select the first device to party with (because who wouldn't want to?)
    device = alldevs;
    if (device == NULL) {
        fprintf(stderr, "No devices found! That’s like a clown with no balloons! 🎈\n");
        return EXIT_FAILURE;
    }
    
    printf("Let's start capturing packets on %s!\n", device->name);
    start_capturing(device);

    // Now let’s clean up after the party
    pcap_freealldevs(alldevs);
    printf("All cleaned up! Thanks for joining the fun! ✌️\n");

    return EXIT_SUCCESS;
}