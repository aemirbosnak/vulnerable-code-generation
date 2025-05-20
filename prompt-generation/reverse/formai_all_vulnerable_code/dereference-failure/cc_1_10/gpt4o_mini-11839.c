//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_PACKETS 100
#define SNAP_LEN 65535

typedef struct {
    pcap_t *handle;
    FILE *output_file;
} capture_param_t;

void *capture_packets(void *param) {
    capture_param_t *capture_param = (capture_param_t *)param;
    struct pcap_pkthdr header;
    const u_char *packet;
    int packet_count = 0;

    // Capture loop
    while (packet_count < MAX_PACKETS) {
        packet = pcap_next(capture_param->handle, &header);
        if (packet) {
            fprintf(capture_param->output_file, "Packet %d: \n", packet_count + 1);
            fprintf(capture_param->output_file, "Timestamp: %ld.%06ld\n", header.ts.tv_sec, header.ts.tv_usec);
            fprintf(capture_param->output_file, "Packet Length: %d bytes\n", header.len);
            fprintf(capture_param->output_file, "Data: ");
            for (int i = 0; i < header.len && i < 16; i++) {
                fprintf(capture_param->output_file, "%02x ", packet[i]);
            }
            fprintf(capture_param->output_file, "\n\n");
            packet_count++;
        }
    }
    
    return NULL;
}

void start_capture(const char *device) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    FILE *output_file = fopen("captured_packets.txt", "w");
    
    // Open the capture interface
    handle = pcap_open_live(device, SNAP_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device, errbuf);
        return;
    }
    
    printf("Listening on %s for packets...\n", device);
    
    capture_param_t capture_param;
    capture_param.handle = handle;
    capture_param.output_file = output_file;

    // Create thread for packet capturing
    pthread_t capture_thread;
    pthread_create(&capture_thread, NULL, capture_packets, (void *)&capture_param);

    // Wait for the thread to finish
    pthread_join(capture_thread, NULL);

    // Cleanup
    pcap_close(handle);
    fclose(output_file);
    printf("Packet capturing completed! Output written to captured_packets.txt\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    start_capture(argv[1]);
    
    return 0;
}