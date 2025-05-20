//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <pcap.h>
#include <signal.h>
#include <unistd.h>

#define MAX_PACKETS 100

volatile sig_atomic_t stop_flag = 0;
pcap_t *handle;
pthread_t packet_thread;

// Signal handler to gracefully stop the program
void handle_signal(int signal) {
    stop_flag = 1;
}

// Packet handler function
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet captured: Length: %d, Timestamp: %ld.%ld\n", header->len, header->ts.tv_sec, header->ts.tv_usec);
}

// Thread function for capturing packets
void *capture_packets(void *arg) {
    while (!stop_flag) {
        pcap_dispatch(handle, 10, packet_handler, NULL);
        usleep(100);
    }
    return NULL;
}

// Function to set up packet capture
int setup_packet_capture(const char *device) {
    char errbuf[PCAP_ERRBUF_SIZE];

    handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device, errbuf);
        return -1;
    }
    return 0;
}

// Function to list available network devices
void list_devices() {
    pcap_if_t *alldevs, *device;
    char errbuf[PCAP_ERRBUF_SIZE];

    // Obtain the device list
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Could not obtain device list: %s\n", errbuf);
        return;
    }

    printf("Available devices:\n");
    for (device = alldevs; device != NULL; device = device->next) {
        printf(" - %s\n", device->name);
    }
    pcap_freealldevs(alldevs);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Set up signal handling for graceful termination
    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);

    // List available devices
    list_devices();

    // Set up packet capture
    if (setup_packet_capture(argv[1]) < 0) {
        exit(EXIT_FAILURE);
    }

    // Create a thread for capturing packets
    if (pthread_create(&packet_thread, NULL, capture_packets, NULL) != 0) {
        fprintf(stderr, "Error creating packet capture thread\n");
        exit(EXIT_FAILURE);
    }

    // Main thread continues to run while packets are being captured
    while (!stop_flag) {
        printf("Monitoring packets on %s... Press Ctrl+C to stop.\n", argv[1]);
        sleep(2);
    }

    // Cleanup
    pthread_cancel(packet_thread);
    pthread_join(packet_thread, NULL);

    pcap_close(handle);
    printf("Packet capture stopped. Exiting program.\n");

    return 0;
}