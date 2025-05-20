//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <time.h>

// Function to process each captured packet recursively
void process_packet(const struct pcap_pkthdr *header, const u_char *packet, int duration) {
    // Define IP header structure
    struct ip *ip_header = (struct ip *)(packet + 14); // Assuming Ethernet header is 14 bytes

    char src_ip[INET_ADDRSTRLEN];
    char dest_ip[INET_ADDRSTRLEN];

    // Convert IP addresses from binary to human-readable format
    inet_ntop(AF_INET, &(ip_header->ip_src), src_ip, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &(ip_header->ip_dst), dest_ip, INET_ADDRSTRLEN);

    // Print the captured packet info
    printf("Packet captured: Source IP: %s, Destination IP: %s\n", src_ip, dest_ip);

    // Check the duration and decide whether to continue capturing
    if (duration > 0) {
        struct timespec ts;
        clock_gettime(CLOCK_MONOTONIC, &ts);
        int elapsed_time = (int)((ts.tv_sec) * 1000 + (ts.tv_nsec / 1000000)); // Convert to milliseconds
        if (elapsed_time < duration) {
            // Call the next capture to continue processing
            return; // Return here; the capture callback will reel back
        }
    }
}

// Recursive function for capturing packets
void capture_packets(pcap_t *handle, int duration) {
    struct timeval timeout = {1, 0}; // Timeout for pcap capturing: 1 second
    while (duration > 0) {
        const u_char *packet = pcap_next(handle, NULL); // Get the next packet
        if (packet != NULL) {
            struct pcap_pkthdr header; // Header structure for the packet
            header.ts = (struct timeval){0};
            header.caplen = 0;
            header.len = 0;

            // Invoke packet processing
            process_packet(&header, packet, duration);
        }
        struct timespec sleep_time = {0, 1000000}; // Sleep for 1 ms
        nanosleep(&sleep_time, NULL);
        duration--;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <interface> <duration in seconds>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *dev = argv[1];
    int duration = atoi(argv[2]) * 1000; // Convert seconds to milliseconds

    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", dev, errbuf);
        return EXIT_FAILURE;
    }

    printf("Capturing on device: %s for %d seconds\n", dev, duration / 1000);

    capture_packets(handle, duration);

    pcap_close(handle);
    return EXIT_SUCCESS;
}