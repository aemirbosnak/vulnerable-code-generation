//Gemma-7B DATASET v1.0 Category: Firewall ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACKET_SIZE 1024

typedef struct Packet {
    char data[MAX_PACKET_SIZE];
    int length;
    struct Packet* next;
} Packet;

void firewall(Packet* packet) {
    if (packet->length < 10) {
        printf("Packet dropped: length too small\n");
        free(packet);
        return;
    }

    if (strcmp(packet->data, "HELLO") == 0) {
        printf("Packet accepted: HELLO\n");
        free(packet);
        return;
    }

    printf("Packet dropped: unknown data\n");
    free(packet);
}

int main() {
    Packet* head = NULL;

    // Simulate packet creation and insertion
    Packet* packet = malloc(sizeof(Packet));
    packet->length = 12;
    strcpy(packet->data, "HELLO");
    packet->next = head;
    head = packet;

    packet = malloc(sizeof(Packet));
    packet->length = 5;
    strcpy(packet->data, "BYE");
    packet->next = head;
    head = packet;

    packet = malloc(sizeof(Packet));
    packet->length = 15;
    strcpy(packet->data, "UNKNOWN");
    packet->next = head;
    head = packet;

    // Firewall processing
    firewall(head);

    return 0;
}