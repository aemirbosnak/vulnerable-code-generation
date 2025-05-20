//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: multi-threaded
#include <stdio.h>
#include <pcap.h>
#include <pthread.h>
#include <stdlib.h>

#define MAX_THREADS 10
#define MAX_PACKETS_PER_THREAD 1000

typedef struct {
    pcap_t *handle;
    int thread_id;
} thread_args;

void *capture_thread(void *args) {
    thread_args *t_args = (thread_args *)args;
    int packet_count = 0;
    struct pcap_pkthdr header;

    while (packet_count < MAX_PACKETS_PER_THREAD) {
        const unsigned char *pkt_data = pcap_next(t_args->handle, &header);
        printf("Thread %d: Received packet %d with %d bytes\n", t_args->thread_id, packet_count, header.len);
        packet_count++;
    }

    pthread_exit(0);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return EXIT_FAILURE;
    }

    pcap_t *handle = pcap_open_live(argv[1], 65535, 1, 1000, NULL);
    if (handle == NULL) {
        fprintf(stderr, "Error: Couldn't open interface %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    int num_threads = MAX_THREADS;
    pthread_t threads[MAX_THREADS];

    for (int i = 0; i < num_threads; i++) {
        thread_args *t_args = malloc(sizeof(thread_args));
        t_args->handle = handle;
        t_args->thread_id = i;

        if (pthread_create(&threads[i], NULL, capture_thread, t_args) != 0) {
            fprintf(stderr, "Error: Couldn't create thread %d\n", i);
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    pcap_close(handle);

    return EXIT_SUCCESS;
}