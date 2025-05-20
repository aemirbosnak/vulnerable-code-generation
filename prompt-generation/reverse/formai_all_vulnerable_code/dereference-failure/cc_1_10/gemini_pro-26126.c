//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: asynchronous
#include <pcap.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>

#define SNAP_LEN 1518
#define TIMEOUT_MS 1000

static volatile int keep_running = 1;

static void signal_handler(int signum)
{
    keep_running = 0;
}

static void *capture_thread(void *arg)
{
    pcap_t *handle = (pcap_t *)arg;
    struct pcap_pkthdr *header;
    const unsigned char *data;

    while (keep_running)
    {
        int res = pcap_next_ex(handle, &header, &data);
        if (res == 0)
        {
            continue;
        }
        else if (res < 0)
        {
            fprintf(stderr, "pcap_next_ex() failed: %s\n", pcap_geterr(handle));
            break;
        }

        // Process the packet here
        printf("Packet received: %d bytes\n", header->len);
    }

    return NULL;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *interface = argv[1];

    // Open the network interface
    pcap_t *handle = pcap_open_live(interface, SNAP_LEN, PCAP_OPENFLAG_PROMISCUOUS, TIMEOUT_MS, NULL);
    if (handle == NULL)
    {
        fprintf(stderr, "pcap_open_live() failed: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Set up signal handling to stop the capture when CTRL+C is pressed
    signal(SIGINT, signal_handler);

    // Create a thread to handle packet capture
    pthread_t tid;
    int ret = pthread_create(&tid, NULL, capture_thread, (void *)handle);
    if (ret != 0)
    {
        fprintf(stderr, "pthread_create() failed: %s\n", strerror(ret));
        pcap_close(handle);
        return EXIT_FAILURE;
    }

    // Wait for the capture thread to finish
    pthread_join(tid, NULL);

    // Close the network interface
    pcap_close(handle);

    return EXIT_SUCCESS;
}