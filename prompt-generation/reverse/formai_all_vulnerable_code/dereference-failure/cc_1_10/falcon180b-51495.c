//Falcon-180B DATASET v1.0 Category: Network Packet Monitoring ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <pthread.h>

#define TRUE 1
#define FALSE 0

#define SNAPLEN 1514
#define BUFSIZE 1024

typedef struct packet_info {
    u_char *data;
    int len;
} PacketInfo;

typedef struct thread_data {
    pcap_t *handle;
    PacketInfo packet;
} ThreadData;

void *process_packet(void *arg) {
    ThreadData *data = (ThreadData *) arg;
    PacketInfo packet = data->packet;

    // Process the packet as needed
    printf("Received packet with length %d\n", packet.len);

    // Free the packet memory
    free(packet.data);

    return NULL;
}

void capture_packets(pcap_t *handle, PacketInfo *packet) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_loop(handle, -1, process_packet, (u_char *) packet);
}

int main() {
    char dev[] = "eth0";
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    ThreadData thread_data;

    // Open the capture device
    handle = pcap_open_live(dev, BUFSIZE, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening capture device: %s\n", errbuf);
        exit(1);
    }

    // Allocate memory for the packet data
    thread_data.packet.data = (u_char *) malloc(SNAPLEN);
    thread_data.packet.len = SNAPLEN;

    // Start the capture thread
    pthread_create(&thread_data.handle, NULL, capture_packets, (void *) &thread_data);

    // Wait for the capture thread to finish
    pthread_join(thread_data.handle, NULL);

    // Close the capture device
    pcap_close(handle);

    return 0;
}