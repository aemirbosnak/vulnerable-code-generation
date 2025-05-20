//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: scalable
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>
#include <pthread.h>

#define NUM_THREADS 4
#define PACKET_BUF_SIZE 2048

struct packet_info {
    char *data;
    size_t len;
    struct pcap_pkthdr hdr;
};

void *capture_thread(void *arg) {
    pcap_t *handle = (pcap_t *)arg;
    while (true) {
        struct pcap_pkthdr hdr;
        const uint8_t *data;
        int res = pcap_next_ex(handle, &hdr, &data);
        if (res == 1) {
            struct packet_info *packet = malloc(sizeof(struct packet_info));
            packet->data = malloc(hdr.len);
            memcpy(packet->data, data, hdr.len);
            packet->len = hdr.len;
            packet->hdr = hdr;
            // Process the packet here
            free(packet->data);
            free(packet);
        } else if (res == -1) {
            perror("pcap_next_ex");
            break;
        }
    }
    return NULL;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s <interface>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live(argv[1], PACKET_BUF_SIZE, 0, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, capture_thread, (void *)handle) != 0) {
            perror("pthread_create");
            for (int j = i - 1; j >= 0; j--) {
                pthread_join(threads[j], NULL);
            }
            return EXIT_FAILURE;
        }
    }

    // Call pcap_close() when ready to stop capturing
    pcap_close(handle);

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return EXIT_SUCCESS;
}