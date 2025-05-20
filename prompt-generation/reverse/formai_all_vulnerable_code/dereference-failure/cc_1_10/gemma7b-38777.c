//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Packet {
    char data[MAX_BUFFER_SIZE];
    int size;
    int priority;
    struct Packet* next;
} Packet;

Packet* createPacket(int size, int priority) {
    Packet* packet = malloc(sizeof(Packet));
    packet->size = size;
    packet->priority = priority;
    packet->next = NULL;
    return packet;
}

void enqueuePacket(Packet* packet, Packet** head) {
    if (*head == NULL) {
        *head = packet;
    } else {
        ((*head)->next = packet);
        *head = packet;
    }
}

void processPackets() {
    Packet* head = NULL;
    Packet* current = NULL;

    while (head) {
        current = head;
        head = head->next;

        // Simulate processing based on priority and size
        printf("Processing packet: size %d, priority %d\n", current->size, current->priority);

        // Free the packet
        free(current);
    }
}

int main() {
    // Create a few packets
    Packet* packet1 = createPacket(512, 1);
    Packet* packet2 = createPacket(1024, 3);
    Packet* packet3 = createPacket(256, 2);

    // Enqueue the packets
    enqueuePacket(packet1, &packet1);
    enqueuePacket(packet2, &packet1);
    enqueuePacket(packet3, &packet1);

    // Process the packets
    processPackets();

    return 0;
}