//Gemma-7B DATASET v1.0 Category: Intrusion detection system ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACKET_SIZE 1024

typedef struct Packet {
    char data[MAX_PACKET_SIZE];
    int length;
    struct Packet* next;
} Packet;

typedef struct IntrusionDetectionSystem {
    Packet* head;
    int threshold;
    int flag;
} IntrusionDetectionSystem;

IntrusionDetectionSystem* IntrusionDetectionSystem_create(int threshold) {
    IntrusionDetectionSystem* system = malloc(sizeof(IntrusionDetectionSystem));
    system->head = NULL;
    system->threshold = threshold;
    system->flag = 0;
    return system;
}

void IntrusionDetectionSystem_addPacket(IntrusionDetectionSystem* system, char* data, int length) {
    Packet* newPacket = malloc(sizeof(Packet));
    newPacket->length = length;
    memcpy(newPacket->data, data, length);
    newPacket->next = system->head;
    system->head = newPacket;
}

void IntrusionDetectionSystem_check(IntrusionDetectionSystem* system) {
    int total_length = 0;
    Packet* packet = system->head;
    while (packet) {
        total_length += packet->length;
        packet = packet->next;
    }
    if (total_length > system->threshold) {
        system->flag = 1;
    }
}

int main() {
    IntrusionDetectionSystem* system = IntrusionDetectionSystem_create(5000);
    IntrusionDetectionSystem_addPacket(system, "This is a normal packet", 20);
    IntrusionDetectionSystem_addPacket(system, "This is a suspicious packet", 30);
    IntrusionDetectionSystem_check(system);
    if (system->flag) {
        printf("Intrusion detected!\n");
    } else {
        printf("No intrusion detected.\n");
    }
    return 0;
}