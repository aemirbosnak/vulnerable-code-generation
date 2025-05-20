//Gemma-7B DATASET v1.0 Category: Firewall ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACKET_SIZE 1024

typedef struct Packet {
    char data[MAX_PACKET_SIZE];
    int length;
    struct Packet* next;
} Packet;

Packet* packet_add(Packet* head, int length, char* data) {
    Packet* new_packet = malloc(sizeof(Packet));
    new_packet->length = length;
    memcpy(new_packet->data, data, length);
    new_packet->next = NULL;

    if (head == NULL) {
        return new_packet;
    }

    head->next = new_packet;
    return head;
}

void packet_print(Packet* head) {
    while (head) {
        printf("Packet length: %d\n", head->length);
        printf("Packet data: ");
        for (int i = 0; i < head->length; i++) {
            printf("%c ", head->data[i]);
        }
        printf("\n");
        head = head->next;
    }
}

int main() {
    Packet* head = NULL;

    // Add some packets
    packet_add(head, 10, "Hello, world!");
    packet_add(head, 12, "This is a longer packet.");
    packet_add(head, 6, "Short packet.");

    // Print the packets
    packet_print(head);

    return 0;
}