//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: future-proof
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/time.h>
#include <pthread.h>

#define SNAPLEN        1600
#define PROMISCUOUS    1
#define TIMEOUT        1000  // milliseconds

// Packet capture thread arguments
typedef struct _pcap_args {
    char *device;
    char *filter;
} pcap_args;

// Packet capture thread
void *pcap_capture(void *args) {
    pcap_t *handle;
    struct bpf_program fp;
    bpf_u_int32 netmask, ip;
    char errbuf[PCAP_ERRBUF_SIZE];

    // Get the device and filter from the arguments
    pcap_args *pa = (pcap_args *)args;
    char *device = pa->device;
    char *filter = pa->filter;

    // Open the device for packet capture
    if ((handle = pcap_open_live(device, SNAPLEN, PROMISCUOUS, TIMEOUT, errbuf)) == NULL) {
        fprintf(stderr, "pcap_open_live(): %s\n", errbuf);
        return NULL;
    }

    // Compile the filter expression
    if (pcap_compile(handle, &fp, filter, 0, ip) == -1) {
        fprintf(stderr, "pcap_compile(): %s\n", pcap_geterr(handle));
        return NULL;
    }

    // Set the filter
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "pcap_setfilter(): %s\n", pcap_geterr(handle));
        return NULL;
    }

    // Start the packet capture loop
    int count = 0;
    while (1) {
        struct pcap_pkthdr *header;
        const u_char *packet;

        // Wait for a packet to arrive
        int rc = pcap_next_ex(handle, &header, &packet);
        if (rc == -1) {
            fprintf(stderr, "pcap_next_ex(): %s\n", pcap_geterr(handle));
            break;
        } else if (rc == 0) {
            continue;
        }

        // Print the packet header
        printf("Packet %d: len=%d, caplen=%d, sec=%ld, usec=%ld\n",
            count++, header->len, header->caplen, header->ts.tv_sec, header->ts.tv_usec);

        // Print the packet data
        for (int i = 0; i < header->caplen; i++) {
            printf("%02X ", packet[i]);
            if ((i + 1) % 16 == 0) {
                printf("\n");
            }
        }
        printf("\n");
    }

    // Close the device
    pcap_close(handle);

    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <device> <filter>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the device and filter from the command line arguments
    char *device = argv[1];
    char *filter = argv[2];

    // Create the packet capture thread arguments
    pcap_args args = {
        .device = device,
        .filter = filter,
    };

    // Create the packet capture thread
    pthread_t thread;
    if (pthread_create(&thread, NULL, pcap_capture, &args) != 0) {
        fprintf(stderr, "pthread_create(): %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Wait for the packet capture thread to exit
    pthread_join(thread, NULL);

    return EXIT_SUCCESS;
}