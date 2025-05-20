//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <time.h>

// A cheerful greeting to start our network monitoring journey!
void welcome() {
    printf("Rejoice! Welcome to the enchanting world of network monitoring!\n");
    printf("Let's dive into the ethereal realm of data packets and unravel their secrets.\n");
}

// A function to capture and analyze network packets
void capture_packets() {
    char *device;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct pcap_pkthdr *header;
    const u_char *packet;

    // Get the device to capture from
    device = pcap_lookupdev(errbuf);
    if (device == NULL) {
        fprintf(stderr, "Oops! Failed to find a suitable device: %s\n", errbuf);
        exit(1);
    } else {
        printf("Excellent! Capturing packets from device: %s\n", device);
    }

    // Open the device for packet capture
    handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Alas! Couldn't open the device: %s\n", errbuf);
        exit(1);
    } else {
        printf("Yay! Opened the device successfully!\n");
    }

    // Start capturing packets
    printf("Here we go! Capturing packets like a symphony...\n");
    while (1) {
        // Wait for a packet to arrive
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == 0) continue;
        if (res == -1) {
            fprintf(stderr, "Oh no! An error occurred while capturing: %s\n", pcap_geterr(handle));
            break;
        }

        // Convert the timestamp to a human-readable format
        time_t timestamp = header->ts.tv_sec;
        struct tm *tm = localtime(&timestamp);
        char time_str[26];
        strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", tm);

        // Print packet details
        printf("Eureka! Captured a packet at %s\n", time_str);
        printf("Length: %d bytes\n", header->len);
        printf("----------------------------------------\n");

        // Print the packet data in a cheerful manner
        printf("Here's the packet data, all sparkly and delightful:\n");
        for (int i = 0; i < header->len; i++) {
            if (i % 16 == 0) printf("\n");
            printf("%02X ", packet[i]);
        }
        printf("\n----------------------------------------\n");
    }

    // Close the device when done
    pcap_close(handle);
}

int main() {
    welcome();
    capture_packets();
    return 0;
}