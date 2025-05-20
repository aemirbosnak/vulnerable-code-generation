//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <stdbool.h>
#include <pthread.h>

struct thread_args {
    pcap_t *handle;
    int id;
};

void* capture_thread(void *arg) {
    struct thread_args *args = (struct thread_args *)arg;
    while (true) {
        int res = pcap_dispatch(args->handle, -1, NULL, NULL);
        if (res == -1) {
            perror("pcap_dispatch() error");
            exit(EXIT_FAILURE);
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *interface = argv[1];
    char errbuf[PCAP_ERRBUF_SIZE];

    pcap_t *handle = pcap_open_live(interface, 65535, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live() error: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    int num_threads = 4;
    pthread_t threads[num_threads];

    for (int i = 0; i < num_threads; i++) {
        struct thread_args *args = malloc(sizeof(struct thread_args));
        args->handle = handle;
        args->id = i;

        if (pthread_create(&threads[i], NULL, capture_thread, (void *)args) != 0) {
            perror("pthread_create() error");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < num_threads; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join() error");
            exit(EXIT_FAILURE);
        }
    }

    pcap_close(handle);

    return EXIT_SUCCESS;
}