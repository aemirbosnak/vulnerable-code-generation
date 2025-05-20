//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h> // included for packet capture lib
#include <pthread.h> // included for threads

#define MAX_PACKET_SIZE 65535 // maximum packet size
#define MAX_NUMBER_OF_PACKETS 5000 // maximum packets to capture
#define NUM_THREADS 10 // number of threads we will use

// mutex for synchronization between threads
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// structure for thread information
struct ThreadData {
    int threadID;
    char *device;
};

// function to capture packets on a device
void capturePacketsOnDevice(char *device, int threadID) {
    char errorBuffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct pcap_pkthdr packetHeader;
    const u_char *packetData;

    // open device for packet sniffing
    handle = pcap_open_live(device, MAX_PACKET_SIZE , 1 , 0 , errorBuffer);
    if (handle == NULL) {
        printf("\nUnable to open device: %s\n", errorBuffer);
        exit(1);
    }

    // continue to capture packets until we reach our maximum number
    while (1) {
        // capture packet
        packetData = pcap_next(handle, &packetHeader);
        if (packetData == NULL) {
            continue;
        }

        // lock mutex to access shared variables
        pthread_mutex_lock(&mutex);

        // do something with packet data
        printf("Thread %d: Packet captured on device %s\n", threadID, device);

        // release mutex
        pthread_mutex_unlock(&mutex);
    }
}

int main(int argc, char *argv[]) {
    int i;
    char *device;
    struct ThreadData threadData[NUM_THREADS];
    pthread_t threads[NUM_THREADS];

    if (argc < 2) {
        printf("Usage: %s <device>\n", argv[0]);
        exit(1);
    }

    device = argv[1];

    // create threads and start capturing packets
    for (i = 0; i < NUM_THREADS; i++) {
        threadData[i].threadID = i;
        threadData[i].device = device;

        if (pthread_create(&threads[i], NULL, (void *)capturePacketsOnDevice, (void *)&threadData[i])) {
            printf("Error creating thread!\n");
            exit(1);
        }
    }

    // wait for threads to finish
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}