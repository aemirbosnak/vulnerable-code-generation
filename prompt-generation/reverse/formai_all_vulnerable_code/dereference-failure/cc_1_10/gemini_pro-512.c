//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <pcap.h>

#define MAX_PACKET_SIZE 1024

struct packet_info {
    int len;
    char *data;
};

struct thread_info {
    pcap_t *handle;
    pthread_t thread;
    struct packet_info *info;
};

void *capture_thread(void *arg) {
    struct thread_info *info = (struct thread_info *)arg;

    while (1) {
        struct pcap_pkthdr *header;
        const u_char *data;

        int res = pcap_next_ex(info->handle, &header, &data);
        if (res == 1) {
            info->info->len = header->len;
            info->info->data = malloc(header->len);
            memcpy(info->info->data, data, header->len);
        } else if (res == -1) {
            perror("pcap_next_ex");
            break;
        }
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return -1;
    }

    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live(argv[1], MAX_PACKET_SIZE, 0, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live: %s\n", errbuf);
        return -1;
    }

    struct packet_info info;
    memset(&info, 0, sizeof(info));

    struct thread_info thread_info;
    thread_info.handle = handle;
    thread_info.info = &info;

    pthread_create(&thread_info.thread, NULL, capture_thread, &thread_info);

    while (1) {
        if (info.len > 0) {
            printf("Packet length: %d\n", info.len);
            printf("Packet data: %s\n", info.data);
            free(info.data);
            info.len = 0;
        }
    }

    pcap_close(handle);
    pthread_join(thread_info.thread, NULL);

    return 0;
}