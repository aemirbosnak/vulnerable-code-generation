//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_PACKET_SIZE 1024
#define MAX_PACKETS 50

// Structure for holding packet data
struct Packet {
    int id;
    int size;
    int priority;
};

// Determine which packets to send first based on priority
int comparePackets(const void *p1, const void *p2) {
    const struct Packet *packet1 = p1;
    const struct Packet *packet2 = p2;

    if (packet1->priority > packet2 -> priority)
        return -1;
    else if (packet1->priority < packet2 -> priority)
        return 1;
    else
        return 0;
}

int main() {
    int totalSize = 0;
    int numPackets = 0;
    int sentPackets = 0;

    // Allocate memory for Packet array
    struct Packet *packets = (struct Packet*) malloc(MAX_PACKETS * sizeof(struct Packet));

    // Fill Packet array with random data
    for(int i = 0; i < MAX_PACKETS; i++) {
        packets[i].id = i;
        packets[i].size = rand()%MAX_PACKET_SIZE;
        packets[i].priority = rand()%5;
        totalSize += packets[i].size;
        numPackets++;
    }

    // Sort packets based on priority
    qsort(packets, numPackets, sizeof(struct Packet), comparePackets);

    // Simulate sending packets
    while(sentPackets < numPackets) {
        // Check current network traffic and adjust packet priority accordingly
        int currTraffic = rand()%10;
        for(int j = 0; j < numPackets; j++) {
            if(currTraffic > 5)
                packets[j].priority -= 1;
            else
                packets[j].priority += 1;
            // Don't let priority go lower than 0
            if(packets[j].priority < 0)
                packets[j].priority = 0;
        }

        // Select highest priority packet and send it
        for(int k = 0; k < numPackets; k++) {
            if(packets[k].priority == 4) {
                printf("Packet %d (Priority %d, Size %d bytes) sent.\n", packets[k].id, packets[k].priority, packets[k].size);
                sentPackets++;
                packets[k].priority = 0;
                break;
            }
        }

        // Wait a random amount of time between sending packets
        int waitTime = rand()%3;
        sleep(waitTime);
    }

    // Free memory used by Packet array
    free(packets);

    return 0;
}