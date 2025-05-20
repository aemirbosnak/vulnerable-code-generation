//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: post-apocalyptic
#include <pcap.h>
#include <stdio.h>
#include <signal.h>

static volatile sig_atomic_t done = 0;

void sigint_handler(int sig) {
    done = 1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s [interface]\n", argv[0]);
        return -1;
    }

    // The interface to listen on
    char *interface = argv[1];
    const char *filter = NULL; // Accept all packets

    // Create a packet capture session
    pcap_t *handle = pcap_open_live(interface, 65535, 1, 1000, NULL);
    if (handle == NULL) {
        perror("pcap_open_live");
        return -1;
    }

    // Set up the filter
    if (filter != NULL) {
        if (pcap_compile(handle, &filter, filter, 1, 0) != 0) {
            perror("pcap_compile");
            pcap_close(handle);
            return -1;
        }
        if (pcap_setfilter(handle, &filter) != 0) {
            perror("pcap_setfilter");
            pcap_close(handle);
            return -1;
        }
    }

    // Signal handler for SIGINT
    signal(SIGINT, sigint_handler);

    // Start the packet capture loop
    printf("Starting packet capture on %s\n", argv[1]);
    while (!done) {
        struct pcap_pkthdr *header;
        const u_char *data;

        // Get the next packet
        if (pcap_next_ex(handle, &header, &data) != 1) {
            continue;
        }

        // Process the packet
        printf("Packet received: %d bytes\n", header->len);
        for (int i = 0; i < header->len; i++) {
            printf("%02x ", data[i]);
        }
        printf("\n");
    }

    // Close the packet capture session
    pcap_close(handle);

    return 0;
}